#ifndef WALLBOXCHARGER_H
#define WALLBOXCHARGER_H

#include <QObject>
#include <QCanBus>
#include <QCanBusDevice>
#include <QCanBusFrame>
#include <QTimer>
#include <QByteArray>
#include <QDebug>

class WallboxCharger : public QObject
{
    Q_OBJECT

    // ── Durum ──────────────────────────────────────────────────────────────
    Q_PROPERTY(bool vcanReady READ vcanReady NOTIFY vcanStatusChanged)
    Q_PROPERTY(QString statusMessage READ statusMessage NOTIFY statusMessageChanged)
    Q_PROPERTY(bool autoSend READ autoSend WRITE setAutoSend NOTIFY autoSendChanged)

    // ── CCS1 (Socket A) TX alanları ───────────────────────────────────────
    Q_PROPERTY(int    ccs1ChargeState         READ ccs1ChargeState         WRITE setCcs1ChargeState         NOTIFY ccs1Changed)
    Q_PROPERTY(int    ccs1PlugState           READ ccs1PlugState           WRITE setCcs1PlugState           NOTIFY ccs1Changed)
    Q_PROPERTY(double ccs1PresentVoltage      READ ccs1PresentVoltage      WRITE setCcs1PresentVoltage      NOTIFY ccs1Changed)
    Q_PROPERTY(double ccs1PresentCurrent      READ ccs1PresentCurrent      WRITE setCcs1PresentCurrent      NOTIFY ccs1Changed)
    Q_PROPERTY(double ccs1TargetVoltage       READ ccs1TargetVoltage       WRITE setCcs1TargetVoltage       NOTIFY ccs1Changed)
    Q_PROPERTY(double ccs1TargetCurrent       READ ccs1TargetCurrent       WRITE setCcs1TargetCurrent       NOTIFY ccs1Changed)
    Q_PROPERTY(double ccs1EvsePresentVoltage  READ ccs1EvsePresentVoltage  WRITE setCcs1EvsePresentVoltage  NOTIFY ccs1Changed)
    Q_PROPERTY(double ccs1EvsePresentCurrent  READ ccs1EvsePresentCurrent  WRITE setCcs1EvsePresentCurrent  NOTIFY ccs1Changed)
    Q_PROPERTY(int    ccs1SoC                 READ ccs1SoC                 WRITE setCcs1SoC                 NOTIFY ccs1Changed)
    Q_PROPERTY(bool   ccs1EvReady             READ ccs1EvReady             WRITE setCcs1EvReady             NOTIFY ccs1Changed)
    Q_PROPERTY(int    ccs1ReadyToChargeState  READ ccs1ReadyToChargeState  WRITE setCcs1ReadyToChargeState  NOTIFY ccs1Changed)
    Q_PROPERTY(double ccs1DeliveredEnergy     READ ccs1DeliveredEnergy     WRITE setCcs1DeliveredEnergy     NOTIFY ccs1Changed)
    Q_PROPERTY(quint32 ccs1ElapsedTime        READ ccs1ElapsedTime         WRITE setCcs1ElapsedTime         NOTIFY ccs1Changed)
    Q_PROPERTY(int    ccs1Errors              READ ccs1Errors              WRITE setCcs1Errors              NOTIFY ccs1Changed)
    Q_PROPERTY(int    ccs1SessionResult       READ ccs1SessionResult       WRITE setCcs1SessionResult       NOTIFY ccs1Changed)
    Q_PROPERTY(int    ccs1IsolationStatus     READ ccs1IsolationStatus     WRITE setCcs1IsolationStatus     NOTIFY ccs1Changed)
    Q_PROPERTY(double ccs1CpVolt              READ ccs1CpVolt              WRITE setCcs1CpVolt              NOTIFY ccs1Changed)
    Q_PROPERTY(int    ccs1PlugTempPos         READ ccs1PlugTempPos         WRITE setCcs1PlugTempPos         NOTIFY ccs1Changed)
    Q_PROPERTY(int    ccs1PlugTempNeg         READ ccs1PlugTempNeg         WRITE setCcs1PlugTempNeg         NOTIFY ccs1Changed)

    // ── CCS2 (Socket B) TX alanları ───────────────────────────────────────
    Q_PROPERTY(int    ccs2ChargeState         READ ccs2ChargeState         WRITE setCcs2ChargeState         NOTIFY ccs2Changed)
    Q_PROPERTY(int    ccs2PlugState           READ ccs2PlugState           WRITE setCcs2PlugState           NOTIFY ccs2Changed)
    Q_PROPERTY(double ccs2PresentVoltage      READ ccs2PresentVoltage      WRITE setCcs2PresentVoltage      NOTIFY ccs2Changed)
    Q_PROPERTY(double ccs2PresentCurrent      READ ccs2PresentCurrent      WRITE setCcs2PresentCurrent      NOTIFY ccs2Changed)
    Q_PROPERTY(double ccs2TargetVoltage       READ ccs2TargetVoltage       WRITE setCcs2TargetVoltage       NOTIFY ccs2Changed)
    Q_PROPERTY(double ccs2TargetCurrent       READ ccs2TargetCurrent       WRITE setCcs2TargetCurrent       NOTIFY ccs2Changed)
    Q_PROPERTY(double ccs2EvsePresentVoltage  READ ccs2EvsePresentVoltage  WRITE setCcs2EvsePresentVoltage  NOTIFY ccs2Changed)
    Q_PROPERTY(double ccs2EvsePresentCurrent  READ ccs2EvsePresentCurrent  WRITE setCcs2EvsePresentCurrent  NOTIFY ccs2Changed)
    Q_PROPERTY(int    ccs2SoC                 READ ccs2SoC                 WRITE setCcs2SoC                 NOTIFY ccs2Changed)
    Q_PROPERTY(bool   ccs2EvReady             READ ccs2EvReady             WRITE setCcs2EvReady             NOTIFY ccs2Changed)
    Q_PROPERTY(int    ccs2ReadyToChargeState  READ ccs2ReadyToChargeState  WRITE setCcs2ReadyToChargeState  NOTIFY ccs2Changed)
    Q_PROPERTY(double ccs2DeliveredEnergy     READ ccs2DeliveredEnergy     WRITE setCcs2DeliveredEnergy     NOTIFY ccs2Changed)
    Q_PROPERTY(quint32 ccs2ElapsedTime        READ ccs2ElapsedTime         WRITE setCcs2ElapsedTime         NOTIFY ccs2Changed)
    Q_PROPERTY(int    ccs2Errors              READ ccs2Errors              WRITE setCcs2Errors              NOTIFY ccs2Changed)
    Q_PROPERTY(int    ccs2SessionResult       READ ccs2SessionResult       WRITE setCcs2SessionResult       NOTIFY ccs2Changed)
    Q_PROPERTY(int    ccs2IsolationStatus     READ ccs2IsolationStatus     WRITE setCcs2IsolationStatus     NOTIFY ccs2Changed)
    Q_PROPERTY(double ccs2CpVolt              READ ccs2CpVolt              WRITE setCcs2CpVolt              NOTIFY ccs2Changed)
    Q_PROPERTY(int    ccs2PlugTempPos         READ ccs2PlugTempPos         WRITE setCcs2PlugTempPos         NOTIFY ccs2Changed)
    Q_PROPERTY(int    ccs2PlugTempNeg         READ ccs2PlugTempNeg         WRITE setCcs2PlugTempNeg         NOTIFY ccs2Changed)

    // ── Ortak TX alanları ─────────────────────────────────────────────────
    Q_PROPERTY(double ccuVersion     READ ccuVersion     WRITE setCcuVersion     NOTIFY commonChanged)
    Q_PROPERTY(int    rPos           READ rPos           WRITE setRPos           NOTIFY commonChanged)
    Q_PROPERTY(int    rNeg           READ rNeg           WRITE setRNeg           NOTIFY commonChanged)
    Q_PROPERTY(bool   isoFaultAcrel  READ isoFaultAcrel  WRITE setIsoFaultAcrel  NOTIFY commonChanged)

public:
    explicit WallboxCharger(QObject *parent = nullptr);

    // ── Durum ──────────────────────────────────────────────────────────────
    bool    vcanReady()     const { return m_vcanReady; }
    QString statusMessage() const { return m_statusMessage; }
    bool    autoSend()      const { return m_autoSend; }
    void    setAutoSend(bool v);

    // ── CCS1 getters ───────────────────────────────────────────────────────
    int     ccs1ChargeState()        const { return m_ccs1.chargeState; }
    int     ccs1PlugState()          const { return m_ccs1.plugState; }
    double  ccs1PresentVoltage()     const { return m_ccs1.presentVoltage; }
    double  ccs1PresentCurrent()     const { return m_ccs1.presentCurrent; }
    double  ccs1TargetVoltage()      const { return m_ccs1.targetVoltage; }
    double  ccs1TargetCurrent()      const { return m_ccs1.targetCurrent; }
    double  ccs1EvsePresentVoltage() const { return m_ccs1.evsePresentVoltage; }
    double  ccs1EvsePresentCurrent() const { return m_ccs1.evsePresentCurrent; }
    int     ccs1SoC()                const { return m_ccs1.soc; }
    bool    ccs1EvReady()            const { return m_ccs1.evReady; }
    int     ccs1ReadyToChargeState() const { return m_ccs1.readyToChargeState; }
    double  ccs1DeliveredEnergy()    const { return m_ccs1.deliveredEnergy; }
    quint32 ccs1ElapsedTime()        const { return m_ccs1.elapsedTime; }
    int     ccs1Errors()             const { return m_ccs1.errors; }
    int     ccs1SessionResult()      const { return m_ccs1.sessionResult; }
    int     ccs1IsolationStatus()    const { return m_ccs1.isolationStatus; }
    double  ccs1CpVolt()             const { return m_ccs1.cpVolt; }
    int     ccs1PlugTempPos()        const { return m_ccs1.plugTempPos; }
    int     ccs1PlugTempNeg()        const { return m_ccs1.plugTempNeg; }

    // ── CCS1 setters ───────────────────────────────────────────────────────
    void setCcs1ChargeState(int v)         { m_ccs1.chargeState = v;        emit ccs1Changed(); }
    void setCcs1PlugState(int v)           { m_ccs1.plugState = v;          emit ccs1Changed(); }
    void setCcs1PresentVoltage(double v)   { m_ccs1.presentVoltage = v;     emit ccs1Changed(); }
    void setCcs1PresentCurrent(double v)   { m_ccs1.presentCurrent = v;     emit ccs1Changed(); }
    void setCcs1TargetVoltage(double v)    { m_ccs1.targetVoltage = v;      emit ccs1Changed(); }
    void setCcs1TargetCurrent(double v)    { m_ccs1.targetCurrent = v;      emit ccs1Changed(); }
    void setCcs1EvsePresentVoltage(double v){ m_ccs1.evsePresentVoltage = v; emit ccs1Changed(); }
    void setCcs1EvsePresentCurrent(double v){ m_ccs1.evsePresentCurrent = v; emit ccs1Changed(); }
    void setCcs1SoC(int v)                 { m_ccs1.soc = v;               emit ccs1Changed(); }
    void setCcs1EvReady(bool v)            { m_ccs1.evReady = v;           emit ccs1Changed(); }
    void setCcs1ReadyToChargeState(int v)  { m_ccs1.readyToChargeState = v; emit ccs1Changed(); }
    void setCcs1DeliveredEnergy(double v)  { m_ccs1.deliveredEnergy = v;   emit ccs1Changed(); }
    void setCcs1ElapsedTime(quint32 v)     { m_ccs1.elapsedTime = v;       emit ccs1Changed(); }
    void setCcs1Errors(int v)              { m_ccs1.errors = v;            emit ccs1Changed(); }
    void setCcs1SessionResult(int v)       { m_ccs1.sessionResult = v;     emit ccs1Changed(); }
    void setCcs1IsolationStatus(int v)     { m_ccs1.isolationStatus = v;   emit ccs1Changed(); }
    void setCcs1CpVolt(double v)           { m_ccs1.cpVolt = v;            emit ccs1Changed(); }
    void setCcs1PlugTempPos(int v)         { m_ccs1.plugTempPos = v;       emit ccs1Changed(); }
    void setCcs1PlugTempNeg(int v)         { m_ccs1.plugTempNeg = v;       emit ccs1Changed(); }

    // ── CCS2 getters ───────────────────────────────────────────────────────
    int     ccs2ChargeState()        const { return m_ccs2.chargeState; }
    int     ccs2PlugState()          const { return m_ccs2.plugState; }
    double  ccs2PresentVoltage()     const { return m_ccs2.presentVoltage; }
    double  ccs2PresentCurrent()     const { return m_ccs2.presentCurrent; }
    double  ccs2TargetVoltage()      const { return m_ccs2.targetVoltage; }
    double  ccs2TargetCurrent()      const { return m_ccs2.targetCurrent; }
    double  ccs2EvsePresentVoltage() const { return m_ccs2.evsePresentVoltage; }
    double  ccs2EvsePresentCurrent() const { return m_ccs2.evsePresentCurrent; }
    int     ccs2SoC()                const { return m_ccs2.soc; }
    bool    ccs2EvReady()            const { return m_ccs2.evReady; }
    int     ccs2ReadyToChargeState() const { return m_ccs2.readyToChargeState; }
    double  ccs2DeliveredEnergy()    const { return m_ccs2.deliveredEnergy; }
    quint32 ccs2ElapsedTime()        const { return m_ccs2.elapsedTime; }
    int     ccs2Errors()             const { return m_ccs2.errors; }
    int     ccs2SessionResult()      const { return m_ccs2.sessionResult; }
    int     ccs2IsolationStatus()    const { return m_ccs2.isolationStatus; }
    double  ccs2CpVolt()             const { return m_ccs2.cpVolt; }
    int     ccs2PlugTempPos()        const { return m_ccs2.plugTempPos; }
    int     ccs2PlugTempNeg()        const { return m_ccs2.plugTempNeg; }

    // ── CCS2 setters ───────────────────────────────────────────────────────
    void setCcs2ChargeState(int v)         { m_ccs2.chargeState = v;        emit ccs2Changed(); }
    void setCcs2PlugState(int v)           { m_ccs2.plugState = v;          emit ccs2Changed(); }
    void setCcs2PresentVoltage(double v)   { m_ccs2.presentVoltage = v;     emit ccs2Changed(); }
    void setCcs2PresentCurrent(double v)   { m_ccs2.presentCurrent = v;     emit ccs2Changed(); }
    void setCcs2TargetVoltage(double v)    { m_ccs2.targetVoltage = v;      emit ccs2Changed(); }
    void setCcs2TargetCurrent(double v)    { m_ccs2.targetCurrent = v;      emit ccs2Changed(); }
    void setCcs2EvsePresentVoltage(double v){ m_ccs2.evsePresentVoltage = v; emit ccs2Changed(); }
    void setCcs2EvsePresentCurrent(double v){ m_ccs2.evsePresentCurrent = v; emit ccs2Changed(); }
    void setCcs2SoC(int v)                 { m_ccs2.soc = v;               emit ccs2Changed(); }
    void setCcs2EvReady(bool v)            { m_ccs2.evReady = v;           emit ccs2Changed(); }
    void setCcs2ReadyToChargeState(int v)  { m_ccs2.readyToChargeState = v; emit ccs2Changed(); }
    void setCcs2DeliveredEnergy(double v)  { m_ccs2.deliveredEnergy = v;   emit ccs2Changed(); }
    void setCcs2ElapsedTime(quint32 v)     { m_ccs2.elapsedTime = v;       emit ccs2Changed(); }
    void setCcs2Errors(int v)              { m_ccs2.errors = v;            emit ccs2Changed(); }
    void setCcs2SessionResult(int v)       { m_ccs2.sessionResult = v;     emit ccs2Changed(); }
    void setCcs2IsolationStatus(int v)     { m_ccs2.isolationStatus = v;   emit ccs2Changed(); }
    void setCcs2CpVolt(double v)           { m_ccs2.cpVolt = v;            emit ccs2Changed(); }
    void setCcs2PlugTempPos(int v)         { m_ccs2.plugTempPos = v;       emit ccs2Changed(); }
    void setCcs2PlugTempNeg(int v)         { m_ccs2.plugTempNeg = v;       emit ccs2Changed(); }

    // ── Ortak getters / setters ────────────────────────────────────────────
    double ccuVersion()    const { return m_ccuVersion; }
    int    rPos()          const { return m_rPos; }
    int    rNeg()          const { return m_rNeg; }
    bool   isoFaultAcrel() const { return m_isoFaultAcrel; }

    void setCcuVersion(double v)    { m_ccuVersion = v;    emit commonChanged(); }
    void setRPos(int v)             { m_rPos = v;          emit commonChanged(); }
    void setRNeg(int v)             { m_rNeg = v;          emit commonChanged(); }
    void setIsoFaultAcrel(bool v)   { m_isoFaultAcrel = v; emit commonChanged(); }

    // ── QML'den çağrılabilir metodlar ─────────────────────────────────────
    Q_INVOKABLE void setupVcan();
    Q_INVOKABLE void sendAll();
    Q_INVOKABLE void triggerRemoteStartCCS1();
    Q_INVOKABLE void triggerRemoteStartCCS2();

signals:
    void vcanStatusChanged();
    void statusMessageChanged();
    void autoSendChanged();
    void ccs1Changed();
    void ccs2Changed();
    void commonChanged();

private slots:
    void onAutoSendTimer();

private:
    struct SocketData {
        int     chargeState        = 0;
        int     plugState          = 0;
        double  presentVoltage     = 0.0;
        double  presentCurrent     = 0.0;
        double  targetVoltage      = 0.0;
        double  targetCurrent      = 0.0;
        double  evsePresentVoltage = 0.0;
        double  evsePresentCurrent = 0.0;
        int     soc                = 0;
        bool    evReady            = false;
        int     readyToChargeState = 0;
        double  deliveredEnergy    = 0.0;
        quint32 elapsedTime        = 0;
        int     errors             = 0;
        int     sessionResult      = 0;
        int     isolationStatus    = 0;
        double  cpVolt             = 0.0;
        int     plugTempPos        = 25;
        int     plugTempNeg        = 25;
    };

    void initCanDevice();
    void sendFrame(quint32 id, const QByteArray &payload, bool extended = false);
    void sendSocketFrames(const SocketData &s, quint32 statusId, quint32 measId,
                          quint32 timeEnergyId, quint32 evStatusId, quint32 targetId,
                          quint32 evsePresentId);
    void sendCommonFrames();

    QCanBusDevice *m_device      = nullptr;
    QString        m_errorString;
    bool           m_vcanReady   = false;
    QString        m_statusMessage;

    SocketData m_ccs1;
    SocketData m_ccs2;

    double m_ccuVersion   = 1.0;
    int    m_rPos         = 0;
    int    m_rNeg         = 0;
    bool   m_isoFaultAcrel = false;

    bool    m_autoSend = false;
    QTimer *m_txTimer  = nullptr;
};

#endif // WALLBOXCHARGER_H
