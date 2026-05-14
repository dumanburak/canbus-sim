#include "wallboxcharger.h"
#include <QProcess>

WallboxCharger::WallboxCharger(QObject *parent) : QObject(parent)
{
    m_txTimer = new QTimer(this);
    connect(m_txTimer, &QTimer::timeout, this, &WallboxCharger::onAutoSendTimer);

    setupVcan();
}

// ── can0 (sanal) kurulum ─────────────────────────────────────────────────────

void WallboxCharger::setupVcan()
{
    QProcess check;
    check.start("ip", {"link", "show", "can0"});
    check.waitForFinished(3000);

    if (check.exitCode() == 0) {
        // Interface var — UP mu kontrol et
        QString out = QString(check.readAllStandardOutput());
        if (out.contains("UP")) {
            // Zaten ayakta, direkt bağlan
            m_statusMessage = "can0 hazır";
            emit statusMessageChanged();
            initCanDevice();
            return;
        }
        // Var ama DOWN — ayağa kaldırmayı dene
    } else {
        // Interface yok — oluştur (root gerekir)
        QProcess add;
        add.start("ip", {"link", "add", "dev", "can0", "type", "vcan"});
        add.waitForFinished(3000);
        if (add.exitCode() != 0) {
            m_statusMessage = "can0 bulunamadı. Terminalde çalıştırın:\n"
                              "sudo ip link add dev can0 type vcan && sudo ip link set up can0";
            m_vcanReady = false;
            emit statusMessageChanged();
            emit vcanStatusChanged();
            return;
        }
    }

    QProcess up;
    up.start("ip", {"link", "set", "up", "can0"});
    up.waitForFinished(3000);
    if (up.exitCode() != 0) {
        m_statusMessage = "can0 up yapılamadı. Terminalde: sudo ip link set up can0";
        m_vcanReady = false;
        emit statusMessageChanged();
        emit vcanStatusChanged();
        return;
    }

    m_statusMessage = "can0 hazır";
    emit statusMessageChanged();
    initCanDevice();
}

void WallboxCharger::initCanDevice()
{
    if (m_device) {
        m_device->disconnectDevice();
        delete m_device;
        m_device = nullptr;
    }

    m_device = QCanBus::instance()->createDevice(
                   QStringLiteral("socketcan"),
                   QStringLiteral("can0"),
                   &m_errorString);

    if (!m_device) {
        m_statusMessage = "CAN cihazı oluşturulamadı: " + m_errorString;
        m_vcanReady = false;
        emit statusMessageChanged();
        emit vcanStatusChanged();
        return;
    }

    m_device->setParent(this);

    if (!m_device->connectDevice()) {
        m_statusMessage = "CAN cihazına bağlanılamadı";
        m_vcanReady = false;
        delete m_device;
        m_device = nullptr;
        emit statusMessageChanged();
        emit vcanStatusChanged();
        return;
    }

    m_vcanReady = true;
    m_statusMessage = "can0 bağlı – TX hazır";
    emit statusMessageChanged();
    emit vcanStatusChanged();
    qDebug() << "CAN TX init OK: can0";
}

// ── Auto-send ────────────────────────────────────────────────────────────────

void WallboxCharger::setAutoSend(bool v)
{
    if (m_autoSend == v) return;
    m_autoSend = v;
    if (m_autoSend)
        m_txTimer->start(100);  // 10 Hz
    else
        m_txTimer->stop();
    emit autoSendChanged();
}

void WallboxCharger::onAutoSendTimer()
{
    sendAll();
}

// ── Frame gönderme ───────────────────────────────────────────────────────────

void WallboxCharger::sendFrame(quint32 id, const QByteArray &payload, bool extended)
{
    if (!m_device) return;
    QCanBusFrame frame;
    frame.setFrameId(id);
    frame.setPayload(payload);
    frame.setExtendedFrameFormat(extended);
    m_device->writeFrame(frame);
}

void WallboxCharger::sendSocketFrames(const SocketData &s,
                                      quint32 statusId,
                                      quint32 measId,
                                      quint32 timeEnergyId,
                                      quint32 evStatusId,
                                      quint32 targetId,
                                      quint32 evsePresentId)
{
    // ── Status frame (0x600 / 0x610) ─────────────────────────────────────
    // payload[0] = chargeState
    // payload[1] = sessionResultCode
    // payload[2] = error flags (8 bit)
    // payload[3] = plugState<<3 | isolationStatus<<6 | errPlugTemp<<0 | errIso<<1
    // payload[4-5] = cpVolt uint16 LE
    // payload[6] = plugTempPos
    // payload[7] = plugTempNeg
    {
        QByteArray p(8, 0x00);
        p[0] = static_cast<char>(s.chargeState & 0xFF);
        p[1] = static_cast<char>(s.sessionResult & 0xFF);
        p[2] = static_cast<char>(s.errors & 0xFF);
        quint8 b3 = static_cast<quint8>((s.plugState & 0x07) << 3);
        b3 |= static_cast<quint8>((s.isolationStatus & 0x03) << 6);
        p[3] = static_cast<char>(b3);
        quint16 cpv = static_cast<quint16>(s.cpVolt);
        p[4] = static_cast<char>(cpv & 0xFF);
        p[5] = static_cast<char>((cpv >> 8) & 0xFF);
        p[6] = static_cast<char>(s.plugTempPos & 0xFF);
        p[7] = static_cast<char>(s.plugTempNeg & 0xFF);
        sendFrame(statusId, p, false);
    }

    // ── Measurements frame (0x601 / 0x611) ───────────────────────────────
    // payload[0-1] = presentVoltage * 10  (uint16 LE)
    // payload[2-3] = (presentCurrent + 1000) * 10  (uint16 LE)
    // payload[4-5] = targetVoltage * 10  (uint16 LE)
    // payload[6-7] = (targetCurrent + 1000) * 10  (uint16 LE)
    {
        QByteArray p(8, 0x00);
        quint16 volt = static_cast<quint16>(s.presentVoltage * 10.0);
        quint16 curr = static_cast<quint16>((s.presentCurrent + 1000.0) * 10.0);
        quint16 tvolt = static_cast<quint16>(s.targetVoltage * 10.0);
        quint16 tcurr = static_cast<quint16>((s.targetCurrent + 1000.0) * 10.0);
        p[0] = static_cast<char>(volt & 0xFF);
        p[1] = static_cast<char>((volt >> 8) & 0xFF);
        p[2] = static_cast<char>(curr & 0xFF);
        p[3] = static_cast<char>((curr >> 8) & 0xFF);
        p[4] = static_cast<char>(tvolt & 0xFF);
        p[5] = static_cast<char>((tvolt >> 8) & 0xFF);
        p[6] = static_cast<char>(tcurr & 0xFF);
        p[7] = static_cast<char>((tcurr >> 8) & 0xFF);
        sendFrame(measId, p, false);
    }

    // ── Time/Energy frame (0x602 / 0x612) ────────────────────────────────
    // payload[0-3] = elapsedTime seconds (uint32 LE)
    // payload[4-7] = deliveredEnergy * 1000  (uint32 LE, Wh*1000 = mWh)
    {
        QByteArray p(8, 0x00);
        quint32 t = s.elapsedTime;
        p[0] = static_cast<char>(t & 0xFF);
        p[1] = static_cast<char>((t >> 8) & 0xFF);
        p[2] = static_cast<char>((t >> 16) & 0xFF);
        p[3] = static_cast<char>((t >> 24) & 0xFF);
        quint32 e = static_cast<quint32>(s.deliveredEnergy * 1000.0);
        p[4] = static_cast<char>(e & 0xFF);
        p[5] = static_cast<char>((e >> 8) & 0xFF);
        p[6] = static_cast<char>((e >> 16) & 0xFF);
        p[7] = static_cast<char>((e >> 24) & 0xFF);
        sendFrame(timeEnergyId, p, false);
    }

    // ── EV Status frame (0x15100007 / 0x15100107) ─────────────────────────
    // payload[0] bit0 = evReady
    // payload[2]      = SoC
    // payload[7]      = readyToChargeState
    {
        QByteArray p(8, 0x00);
        p[0] = static_cast<char>(s.evReady ? 0x01 : 0x00);
        p[2] = static_cast<char>(s.soc & 0xFF);
        p[7] = static_cast<char>(s.readyToChargeState & 0xFF);
        sendFrame(evStatusId, p, true);   // extended frame
    }

    // ── EV Target frame (0x15110009 / 0x15110109) ─────────────────────────
    // payload[4-5] = targetVoltage * 10  (uint16 LE, unsigned)
    // payload[6-7] = targetCurrent * 10  (int16 LE, signed, no offset)
    {
        QByteArray p(8, 0x00);
        quint16 tv = static_cast<quint16>(s.targetVoltage * 10.0);
        qint16  tc = static_cast<qint16>(s.targetCurrent * 10.0);
        p[4] = static_cast<char>(tv & 0xFF);
        p[5] = static_cast<char>((tv >> 8) & 0xFF);
        p[6] = static_cast<char>(tc & 0xFF);
        p[7] = static_cast<char>((tc >> 8) & 0xFF);
        sendFrame(targetId, p, true);   // extended frame
    }

    // ── EVSE Present frame (0x15100008 / 0x15100108) ──────────────────────
    // payload[0-1] = evsePresentVoltage * 10  (uint16 LE)
    // payload[2-3] = evsePresentCurrent * 10  (uint16 LE)
    {
        QByteArray p(8, 0x00);
        quint16 ev = static_cast<quint16>(s.evsePresentVoltage * 10.0);
        quint16 ec = static_cast<quint16>(s.evsePresentCurrent * 10.0);
        p[0] = static_cast<char>(ev & 0xFF);
        p[1] = static_cast<char>((ev >> 8) & 0xFF);
        p[2] = static_cast<char>(ec & 0xFF);
        p[3] = static_cast<char>((ec >> 8) & 0xFF);
        sendFrame(evsePresentId, p, true);   // extended frame
    }
}

void WallboxCharger::sendCommonFrames()
{
    // ── CCU Version frame (0x300 = 768) ──────────────────────────────────
    // payload[7] = ccuVersion * 10
    {
        QByteArray p(8, 0x00);
        p[7] = static_cast<char>(static_cast<quint8>(m_ccuVersion * 10.0));
        sendFrame(768, p, false);
    }

    // ── ISO isolation frame (0x900 = 2304) ────────────────────────────────
    // payload[0-1] = rPos (uint16 LE)
    // payload[2-3] = rNeg (uint16 LE), bit0 of byte[3] = isoFaultAcrel
    {
        QByteArray p(8, 0x00);
        quint16 rp = static_cast<quint16>(m_rPos);
        quint16 rn = static_cast<quint16>(m_rNeg);
        p[0] = static_cast<char>(rp & 0xFF);
        p[1] = static_cast<char>((rp >> 8) & 0xFF);
        p[2] = static_cast<char>(rn & 0xFF);
        quint8 b3 = static_cast<quint8>((rn >> 8) & 0xFF);
        if (m_isoFaultAcrel) b3 |= 0x01;
        p[3] = static_cast<char>(b3);
        sendFrame(2304, p, false);
    }
}

// ── Genel gönderim ───────────────────────────────────────────────────────────

void WallboxCharger::sendAll()
{
    if (!m_vcanReady || !m_device) return;

    // CCS1 — ID'ler DBC (evseson.dbc + EV_PLC.dbc) doğrulandı
    sendSocketFrames(m_ccs1,
                     1536,        // 0x600  status
                     1537,        // 0x601  measurements
                     1538,        // 0x602  time/energy
                     0x15110007,  // EV status  (SECC_MSG4)
                     0x15110009,  // EV target  (SECC_MSG6)
                     0x15100008); // EVSE present (EVSE_MSG5)

    // CCS2
    sendSocketFrames(m_ccs2,
                     1552,        // 0x610  status
                     1553,        // 0x611  measurements
                     1554,        // 0x612  time/energy
                     0x15110107,  // EV status  (SECC1_MSG4)
                     0x15110109,  // EV target  (SECC1_MSG6)
                     0x15100108); // EVSE present (EVSE1_MSG5)

    sendCommonFrames();
}

// ── Remote start simülasyonu ─────────────────────────────────────────────────

void WallboxCharger::triggerRemoteStartCCS1()
{
    // HMI 0x4000 frame'i alınca remoteStartSignalCCS1 emit eder
    sendFrame(0x4000, QByteArray(1, 0x01), false);
    qDebug() << "Remote Start CCS1 gönderildi (0x4000)";
}

void WallboxCharger::triggerRemoteStartCCS2()
{
    sendFrame(0x4100, QByteArray(1, 0x01), false);
    qDebug() << "Remote Start CCS2 gönderildi (0x4100)";
}
