/****************************************************************************
** Meta object code from reading C++ file 'wallboxcharger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wallboxcharger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wallboxcharger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WallboxCharger_t {
    QByteArrayData data[107];
    char stringdata0[1737];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WallboxCharger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WallboxCharger_t qt_meta_stringdata_WallboxCharger = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WallboxCharger"
QT_MOC_LITERAL(1, 15, 6), // "notify"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "notice"
QT_MOC_LITERAL(4, 30, 4), // "data"
QT_MOC_LITERAL(5, 35, 12), // "updateResult"
QT_MOC_LITERAL(6, 48, 7), // "message"
QT_MOC_LITERAL(7, 56, 15), // "updateResultCCU"
QT_MOC_LITERAL(8, 72, 17), // "logMessageChanged"
QT_MOC_LITERAL(9, 90, 21), // "remoteStartSignalCCS1"
QT_MOC_LITERAL(10, 112, 21), // "remoteStartSignalCCS2"
QT_MOC_LITERAL(11, 134, 10), // "CANReceive"
QT_MOC_LITERAL(12, 145, 11), // "canSendCCS1"
QT_MOC_LITERAL(13, 157, 15), // "chargeStateCCS1"
QT_MOC_LITERAL(14, 173, 11), // "canSendCCS2"
QT_MOC_LITERAL(15, 185, 15), // "chargeStateCCS2"
QT_MOC_LITERAL(16, 201, 20), // "isOCPPProcessRunning"
QT_MOC_LITERAL(17, 222, 12), // "readFromFifo"
QT_MOC_LITERAL(18, 235, 9), // "updateCCU"
QT_MOC_LITERAL(19, 245, 13), // "readFileLines"
QT_MOC_LITERAL(20, 259, 8), // "filePath"
QT_MOC_LITERAL(21, 268, 21), // "getEthernetMacAddress"
QT_MOC_LITERAL(22, 290, 20), // "getEthernetIpAddress"
QT_MOC_LITERAL(23, 311, 10), // "createFile"
QT_MOC_LITERAL(24, 322, 15), // "checkFileExists"
QT_MOC_LITERAL(25, 338, 13), // "updateTXTLine"
QT_MOC_LITERAL(26, 352, 8), // "newValue"
QT_MOC_LITERAL(27, 361, 13), // "updateTXTFile"
QT_MOC_LITERAL(28, 375, 19), // "updateRemoteTXTFile"
QT_MOC_LITERAL(29, 395, 3), // "key"
QT_MOC_LITERAL(30, 399, 12), // "clearTXTFile"
QT_MOC_LITERAL(31, 412, 22), // "readFirstAndSecondLine"
QT_MOC_LITERAL(32, 435, 12), // "rebootSystem"
QT_MOC_LITERAL(33, 448, 14), // "updateJSONFile"
QT_MOC_LITERAL(34, 463, 14), // "updateSoftware"
QT_MOC_LITERAL(35, 478, 10), // "updateOCPP"
QT_MOC_LITERAL(36, 489, 19), // "updateStationConfig"
QT_MOC_LITERAL(37, 509, 19), // "updateLocalRfidList"
QT_MOC_LITERAL(38, 529, 21), // "configureNetworkFiles"
QT_MOC_LITERAL(39, 551, 23), // "configureNetworkFilesOn"
QT_MOC_LITERAL(40, 575, 15), // "writeHmiVersion"
QT_MOC_LITERAL(41, 591, 7), // "version"
QT_MOC_LITERAL(42, 599, 10), // "logMessage"
QT_MOC_LITERAL(43, 610, 10), // "CCUVersion"
QT_MOC_LITERAL(44, 621, 22), // "EvsePresentVoltageCCS1"
QT_MOC_LITERAL(45, 644, 22), // "EvsePresentCurrentCCS1"
QT_MOC_LITERAL(46, 667, 19), // "EvTargetVoltageCCS1"
QT_MOC_LITERAL(47, 687, 19), // "EvTargetCurrentCCS1"
QT_MOC_LITERAL(48, 707, 24), // "evReadyToChargeStateCCS1"
QT_MOC_LITERAL(49, 732, 11), // "evReadyCCS1"
QT_MOC_LITERAL(50, 744, 9), // "evSocCCS1"
QT_MOC_LITERAL(51, 754, 13), // "evVoltageCCS1"
QT_MOC_LITERAL(52, 768, 13), // "evCurrentCCS1"
QT_MOC_LITERAL(53, 782, 17), // "evChargeStateCCS1"
QT_MOC_LITERAL(54, 800, 15), // "evPlugStateCCS1"
QT_MOC_LITERAL(55, 816, 16), // "evChargeTimeCCS1"
QT_MOC_LITERAL(56, 833, 21), // "evDeliveredEnergyCCS1"
QT_MOC_LITERAL(57, 855, 11), // "evStateCCS1"
QT_MOC_LITERAL(58, 867, 11), // "evPowerCCS1"
QT_MOC_LITERAL(59, 879, 4), // "RPOS"
QT_MOC_LITERAL(60, 884, 4), // "RNEG"
QT_MOC_LITERAL(61, 889, 13), // "ISOFAULTACREL"
QT_MOC_LITERAL(62, 903, 25), // "evseSessionResultCodeCCS1"
QT_MOC_LITERAL(63, 929, 29), // "errNoAvailablePowerModuleCCS1"
QT_MOC_LITERAL(64, 959, 18), // "errPowerModuleCCS1"
QT_MOC_LITERAL(65, 978, 16), // "errContactorCCS1"
QT_MOC_LITERAL(66, 995, 22), // "errPlcBoxRxTimeoutCCS1"
QT_MOC_LITERAL(67, 1018, 29), // "errCurrentSensorRxTimeoutCCS1"
QT_MOC_LITERAL(68, 1048, 9), // "errCpCCS1"
QT_MOC_LITERAL(69, 1058, 18), // "emergencyStateCCS1"
QT_MOC_LITERAL(70, 1077, 10), // "errBMSCCS1"
QT_MOC_LITERAL(71, 1088, 22), // "errPlugTemperatureCCS1"
QT_MOC_LITERAL(72, 1111, 16), // "errIsolationCCS1"
QT_MOC_LITERAL(73, 1128, 19), // "isolationStatusCCS1"
QT_MOC_LITERAL(74, 1148, 10), // "cpVoltCCS1"
QT_MOC_LITERAL(75, 1159, 15), // "plugTempPOSCCS1"
QT_MOC_LITERAL(76, 1175, 15), // "plugTempNegCCS1"
QT_MOC_LITERAL(77, 1191, 22), // "EvsePresentVoltageCCS2"
QT_MOC_LITERAL(78, 1214, 22), // "EvsePresentCurrentCCS2"
QT_MOC_LITERAL(79, 1237, 19), // "EvTargetVoltageCCS2"
QT_MOC_LITERAL(80, 1257, 19), // "EvTargetCurrentCCS2"
QT_MOC_LITERAL(81, 1277, 24), // "evReadyToChargeStateCCS2"
QT_MOC_LITERAL(82, 1302, 11), // "evReadyCCS2"
QT_MOC_LITERAL(83, 1314, 9), // "evSocCCS2"
QT_MOC_LITERAL(84, 1324, 13), // "evVoltageCCS2"
QT_MOC_LITERAL(85, 1338, 13), // "evCurrentCCS2"
QT_MOC_LITERAL(86, 1352, 17), // "evChargeStateCCS2"
QT_MOC_LITERAL(87, 1370, 15), // "evPlugStateCCS2"
QT_MOC_LITERAL(88, 1386, 16), // "evChargeTimeCCS2"
QT_MOC_LITERAL(89, 1403, 21), // "evDeliveredEnergyCCS2"
QT_MOC_LITERAL(90, 1425, 11), // "evStateCCS2"
QT_MOC_LITERAL(91, 1437, 11), // "evPowerCCS2"
QT_MOC_LITERAL(92, 1449, 25), // "evseSessionResultCodeCCS2"
QT_MOC_LITERAL(93, 1475, 29), // "errNoAvailablePowerModuleCCS2"
QT_MOC_LITERAL(94, 1505, 18), // "errPowerModuleCCS2"
QT_MOC_LITERAL(95, 1524, 16), // "errContactorCCS2"
QT_MOC_LITERAL(96, 1541, 22), // "errPlcBoxRxTimeoutCCS2"
QT_MOC_LITERAL(97, 1564, 29), // "errCurrentSensorRxTimeoutCCS2"
QT_MOC_LITERAL(98, 1594, 9), // "errCpCCS2"
QT_MOC_LITERAL(99, 1604, 18), // "emergencyStateCCS2"
QT_MOC_LITERAL(100, 1623, 10), // "errBMSCCS2"
QT_MOC_LITERAL(101, 1634, 22), // "errPlugTemperatureCCS2"
QT_MOC_LITERAL(102, 1657, 16), // "errIsolationCCS2"
QT_MOC_LITERAL(103, 1674, 19), // "isolationStatusCCS2"
QT_MOC_LITERAL(104, 1694, 10), // "cpVoltCCS2"
QT_MOC_LITERAL(105, 1705, 15), // "plugTempPOSCCS2"
QT_MOC_LITERAL(106, 1721, 15) // "plugTempNegCCS2"

    },
    "WallboxCharger\0notify\0\0notice\0data\0"
    "updateResult\0message\0updateResultCCU\0"
    "logMessageChanged\0remoteStartSignalCCS1\0"
    "remoteStartSignalCCS2\0CANReceive\0"
    "canSendCCS1\0chargeStateCCS1\0canSendCCS2\0"
    "chargeStateCCS2\0isOCPPProcessRunning\0"
    "readFromFifo\0updateCCU\0readFileLines\0"
    "filePath\0getEthernetMacAddress\0"
    "getEthernetIpAddress\0createFile\0"
    "checkFileExists\0updateTXTLine\0newValue\0"
    "updateTXTFile\0updateRemoteTXTFile\0key\0"
    "clearTXTFile\0readFirstAndSecondLine\0"
    "rebootSystem\0updateJSONFile\0updateSoftware\0"
    "updateOCPP\0updateStationConfig\0"
    "updateLocalRfidList\0configureNetworkFiles\0"
    "configureNetworkFilesOn\0writeHmiVersion\0"
    "version\0logMessage\0CCUVersion\0"
    "EvsePresentVoltageCCS1\0EvsePresentCurrentCCS1\0"
    "EvTargetVoltageCCS1\0EvTargetCurrentCCS1\0"
    "evReadyToChargeStateCCS1\0evReadyCCS1\0"
    "evSocCCS1\0evVoltageCCS1\0evCurrentCCS1\0"
    "evChargeStateCCS1\0evPlugStateCCS1\0"
    "evChargeTimeCCS1\0evDeliveredEnergyCCS1\0"
    "evStateCCS1\0evPowerCCS1\0RPOS\0RNEG\0"
    "ISOFAULTACREL\0evseSessionResultCodeCCS1\0"
    "errNoAvailablePowerModuleCCS1\0"
    "errPowerModuleCCS1\0errContactorCCS1\0"
    "errPlcBoxRxTimeoutCCS1\0"
    "errCurrentSensorRxTimeoutCCS1\0errCpCCS1\0"
    "emergencyStateCCS1\0errBMSCCS1\0"
    "errPlugTemperatureCCS1\0errIsolationCCS1\0"
    "isolationStatusCCS1\0cpVoltCCS1\0"
    "plugTempPOSCCS1\0plugTempNegCCS1\0"
    "EvsePresentVoltageCCS2\0EvsePresentCurrentCCS2\0"
    "EvTargetVoltageCCS2\0EvTargetCurrentCCS2\0"
    "evReadyToChargeStateCCS2\0evReadyCCS2\0"
    "evSocCCS2\0evVoltageCCS2\0evCurrentCCS2\0"
    "evChargeStateCCS2\0evPlugStateCCS2\0"
    "evChargeTimeCCS2\0evDeliveredEnergyCCS2\0"
    "evStateCCS2\0evPowerCCS2\0"
    "evseSessionResultCodeCCS2\0"
    "errNoAvailablePowerModuleCCS2\0"
    "errPowerModuleCCS2\0errContactorCCS2\0"
    "errPlcBoxRxTimeoutCCS2\0"
    "errCurrentSensorRxTimeoutCCS2\0errCpCCS2\0"
    "emergencyStateCCS2\0errBMSCCS2\0"
    "errPlugTemperatureCCS2\0errIsolationCCS2\0"
    "isolationStatusCCS2\0cpVoltCCS2\0"
    "plugTempPOSCCS2\0plugTempNegCCS2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WallboxCharger[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
      65,  248, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  174,    2, 0x06 /* Public */,
       3,    1,  175,    2, 0x06 /* Public */,
       5,    1,  178,    2, 0x06 /* Public */,
       7,    1,  181,    2, 0x06 /* Public */,
       8,    0,  184,    2, 0x06 /* Public */,
       9,    0,  185,    2, 0x06 /* Public */,
      10,    0,  186,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  187,    2, 0x08 /* Private */,
      12,    1,  188,    2, 0x0a /* Public */,
      14,    1,  191,    2, 0x0a /* Public */,
      16,    0,  194,    2, 0x0a /* Public */,
      17,    0,  195,    2, 0x0a /* Public */,
      18,    0,  196,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      19,    1,  197,    2, 0x02 /* Public */,
      21,    0,  200,    2, 0x02 /* Public */,
      22,    0,  201,    2, 0x02 /* Public */,
      23,    1,  202,    2, 0x02 /* Public */,
      24,    1,  205,    2, 0x02 /* Public */,
      25,    2,  208,    2, 0x02 /* Public */,
      27,    2,  213,    2, 0x02 /* Public */,
      28,    3,  218,    2, 0x02 /* Public */,
      30,    1,  225,    2, 0x02 /* Public */,
      31,    1,  228,    2, 0x02 /* Public */,
      32,    0,  231,    2, 0x02 /* Public */,
      33,    3,  232,    2, 0x02 /* Public */,
      34,    0,  239,    2, 0x02 /* Public */,
      35,    0,  240,    2, 0x02 /* Public */,
      36,    0,  241,    2, 0x02 /* Public */,
      37,    0,  242,    2, 0x02 /* Public */,
      38,    0,  243,    2, 0x02 /* Public */,
      39,    0,  244,    2, 0x02 /* Public */,
      40,    1,  245,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,   13,
    QMetaType::Void, QMetaType::QVariant,   15,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QStringList, QMetaType::QString,   20,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QString,   20,
    QMetaType::Bool, QMetaType::QString,   20,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   20,   26,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   20,   26,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,   20,   29,   26,
    QMetaType::Bool, QMetaType::QString,   20,
    QMetaType::QStringList, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,   20,   29,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   41,

 // properties: name, type, flags
      42, QMetaType::QString, 0x00495001,
      43, QMetaType::Double, 0x00495001,
      44, QMetaType::Double, 0x00495001,
      45, QMetaType::Double, 0x00495001,
      46, QMetaType::Double, 0x00495001,
      47, QMetaType::Double, 0x00495001,
      48, QMetaType::Int, 0x00495001,
      49, QMetaType::Int, 0x00495001,
      50, QMetaType::Int, 0x00495001,
      51, QMetaType::QString, 0x00495001,
      52, QMetaType::QString, 0x00495001,
      53, QMetaType::UChar, 0x00495001,
      54, QMetaType::UChar, 0x00495001,
      55, QMetaType::QString, 0x00495001,
      56, QMetaType::QString, 0x00495001,
      57, QMetaType::SChar, 0x00495001,
      58, QMetaType::QString, 0x00495001,
      59, QMetaType::Int, 0x00495001,
      60, QMetaType::Int, 0x00495001,
      61, QMetaType::Int, 0x00495001,
      62, QMetaType::UChar, 0x00495001,
      63, QMetaType::UChar, 0x00495001,
      64, QMetaType::UChar, 0x00495001,
      65, QMetaType::UChar, 0x00495001,
      66, QMetaType::UChar, 0x00495001,
      67, QMetaType::UChar, 0x00495001,
      68, QMetaType::UChar, 0x00495001,
      69, QMetaType::UChar, 0x00495001,
      70, QMetaType::UChar, 0x00495001,
      71, QMetaType::UChar, 0x00495001,
      72, QMetaType::UChar, 0x00495001,
      73, QMetaType::UChar, 0x00495001,
      74, QMetaType::Double, 0x00495001,
      75, QMetaType::UChar, 0x00495001,
      76, QMetaType::UChar, 0x00495001,
      77, QMetaType::Double, 0x00495001,
      78, QMetaType::Double, 0x00495001,
      79, QMetaType::Double, 0x00495001,
      80, QMetaType::Double, 0x00495001,
      81, QMetaType::Int, 0x00495001,
      82, QMetaType::Int, 0x00495001,
      83, QMetaType::Int, 0x00495001,
      84, QMetaType::QString, 0x00495001,
      85, QMetaType::QString, 0x00495001,
      86, QMetaType::UChar, 0x00495001,
      87, QMetaType::UChar, 0x00495001,
      88, QMetaType::QString, 0x00495001,
      89, QMetaType::QString, 0x00495001,
      90, QMetaType::SChar, 0x00495001,
      91, QMetaType::QString, 0x00495001,
      92, QMetaType::UChar, 0x00495001,
      93, QMetaType::UChar, 0x00495001,
      94, QMetaType::UChar, 0x00495001,
      95, QMetaType::UChar, 0x00495001,
      96, QMetaType::UChar, 0x00495001,
      97, QMetaType::UChar, 0x00495001,
      98, QMetaType::UChar, 0x00495001,
      99, QMetaType::UChar, 0x00495001,
     100, QMetaType::UChar, 0x00495001,
     101, QMetaType::UChar, 0x00495001,
     102, QMetaType::UChar, 0x00495001,
     103, QMetaType::UChar, 0x00495001,
     104, QMetaType::Double, 0x00495001,
     105, QMetaType::UChar, 0x00495001,
     106, QMetaType::UChar, 0x00495001,

 // properties: notify_signal_id
       4,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void WallboxCharger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WallboxCharger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->notify(); break;
        case 1: _t->notice((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->updateResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateResultCCU((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->logMessageChanged(); break;
        case 5: _t->remoteStartSignalCCS1(); break;
        case 6: _t->remoteStartSignalCCS2(); break;
        case 7: _t->CANReceive(); break;
        case 8: _t->canSendCCS1((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 9: _t->canSendCCS2((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 10: { bool _r = _t->isOCPPProcessRunning();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->readFromFifo(); break;
        case 12: _t->updateCCU(); break;
        case 13: { QStringList _r = _t->readFileLines((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->getEthernetMacAddress();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->getEthernetIpAddress();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->createFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->checkFileExists((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->updateTXTLine((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->updateTXTFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->updateRemoteTXTFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->clearTXTFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { QStringList _r = _t->readFirstAndSecondLine((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->rebootSystem(); break;
        case 24: { bool _r = _t->updateJSONFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->updateSoftware(); break;
        case 26: _t->updateOCPP(); break;
        case 27: _t->updateStationConfig(); break;
        case 28: _t->updateLocalRfidList(); break;
        case 29: _t->configureNetworkFiles(); break;
        case 30: _t->configureNetworkFilesOn(); break;
        case 31: { bool _r = _t->writeHmiVersion((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WallboxCharger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WallboxCharger::notify)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WallboxCharger::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WallboxCharger::notice)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WallboxCharger::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WallboxCharger::updateResult)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WallboxCharger::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WallboxCharger::updateResultCCU)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WallboxCharger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WallboxCharger::logMessageChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WallboxCharger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WallboxCharger::remoteStartSignalCCS1)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WallboxCharger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WallboxCharger::remoteStartSignalCCS2)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WallboxCharger *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getLogMessage(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->GetCCUVersion(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->GetEvsePresentVoltageCCS1(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->GetEvsePresentCurrentCCS1(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->GetEvTargetVoltageCCS1(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->GetEvTargetCurrentCCS1(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->GetEvReadyToChargeStateCCS1(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->GetEvReadyCCS1(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->GetSoCCCS1(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->GetVoltageCCS1(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->GetCurrentCCS1(); break;
        case 11: *reinterpret_cast< quint8*>(_v) = _t->GetChargeStateCCS1(); break;
        case 12: *reinterpret_cast< quint8*>(_v) = _t->GetPlugStateCCS1(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->GetElapsedTimeCCS1(); break;
        case 14: *reinterpret_cast< QString*>(_v) = _t->GetEnergyCCS1(); break;
        case 15: *reinterpret_cast< qint8*>(_v) = _t->GetStateCCS1(); break;
        case 16: *reinterpret_cast< QString*>(_v) = _t->GetPowerCCS1(); break;
        case 17: *reinterpret_cast< int*>(_v) = _t->GetrPos(); break;
        case 18: *reinterpret_cast< int*>(_v) = _t->GetrNeg(); break;
        case 19: *reinterpret_cast< int*>(_v) = _t->GetisoFaultAcrel(); break;
        case 20: *reinterpret_cast< quint8*>(_v) = _t->GetevseSessionResultCodeCCS1(); break;
        case 21: *reinterpret_cast< quint8*>(_v) = _t->GeterrNoAvailablePowerModuleCCS1(); break;
        case 22: *reinterpret_cast< quint8*>(_v) = _t->GeterrPowerModuleCCS1(); break;
        case 23: *reinterpret_cast< quint8*>(_v) = _t->GeterrContactorCCS1(); break;
        case 24: *reinterpret_cast< quint8*>(_v) = _t->GeterrPlcBoxRxTimeoutCCS1(); break;
        case 25: *reinterpret_cast< quint8*>(_v) = _t->GeterrCurrentSensorRxTimeoutCCS1(); break;
        case 26: *reinterpret_cast< quint8*>(_v) = _t->GeterrCpCCS1(); break;
        case 27: *reinterpret_cast< quint8*>(_v) = _t->GetemergencyStateCCS1(); break;
        case 28: *reinterpret_cast< quint8*>(_v) = _t->GeterrBMSCCS1(); break;
        case 29: *reinterpret_cast< quint8*>(_v) = _t->GeterrPlugTemperatureCCS1(); break;
        case 30: *reinterpret_cast< quint8*>(_v) = _t->GeterrIsolationCCS1(); break;
        case 31: *reinterpret_cast< quint8*>(_v) = _t->GetisolationStatusCCS1(); break;
        case 32: *reinterpret_cast< double*>(_v) = _t->GetcpVoltCCS1(); break;
        case 33: *reinterpret_cast< quint8*>(_v) = _t->GetplugTempPOSCCS1(); break;
        case 34: *reinterpret_cast< quint8*>(_v) = _t->GetplugTempNegCCS1(); break;
        case 35: *reinterpret_cast< double*>(_v) = _t->GetEvsePresentVoltageCCS2(); break;
        case 36: *reinterpret_cast< double*>(_v) = _t->GetEvsePresentCurrentCCS2(); break;
        case 37: *reinterpret_cast< double*>(_v) = _t->GetEvTargetVoltageCCS2(); break;
        case 38: *reinterpret_cast< double*>(_v) = _t->GetEvTargetCurrentCCS2(); break;
        case 39: *reinterpret_cast< int*>(_v) = _t->GetEvReadyToChargeStateCCS2(); break;
        case 40: *reinterpret_cast< int*>(_v) = _t->GetEvReadyCCS2(); break;
        case 41: *reinterpret_cast< int*>(_v) = _t->GetSoCCCS2(); break;
        case 42: *reinterpret_cast< QString*>(_v) = _t->GetVoltageCCS2(); break;
        case 43: *reinterpret_cast< QString*>(_v) = _t->GetCurrentCCS2(); break;
        case 44: *reinterpret_cast< quint8*>(_v) = _t->GetChargeStateCCS2(); break;
        case 45: *reinterpret_cast< quint8*>(_v) = _t->GetPlugStateCCS2(); break;
        case 46: *reinterpret_cast< QString*>(_v) = _t->GetElapsedTimeCCS2(); break;
        case 47: *reinterpret_cast< QString*>(_v) = _t->GetEnergyCCS2(); break;
        case 48: *reinterpret_cast< qint8*>(_v) = _t->GetStateCCS2(); break;
        case 49: *reinterpret_cast< QString*>(_v) = _t->GetPowerCCS2(); break;
        case 50: *reinterpret_cast< quint8*>(_v) = _t->GetevseSessionResultCodeCCS2(); break;
        case 51: *reinterpret_cast< quint8*>(_v) = _t->GeterrNoAvailablePowerModuleCCS2(); break;
        case 52: *reinterpret_cast< quint8*>(_v) = _t->GeterrPowerModuleCCS2(); break;
        case 53: *reinterpret_cast< quint8*>(_v) = _t->GeterrContactorCCS2(); break;
        case 54: *reinterpret_cast< quint8*>(_v) = _t->GeterrPlcBoxRxTimeoutCCS2(); break;
        case 55: *reinterpret_cast< quint8*>(_v) = _t->GeterrCurrentSensorRxTimeoutCCS2(); break;
        case 56: *reinterpret_cast< quint8*>(_v) = _t->GeterrCpCCS2(); break;
        case 57: *reinterpret_cast< quint8*>(_v) = _t->GetemergencyStateCCS2(); break;
        case 58: *reinterpret_cast< quint8*>(_v) = _t->GeterrBMSCCS2(); break;
        case 59: *reinterpret_cast< quint8*>(_v) = _t->GeterrPlugTemperatureCCS2(); break;
        case 60: *reinterpret_cast< quint8*>(_v) = _t->GeterrIsolationCCS2(); break;
        case 61: *reinterpret_cast< quint8*>(_v) = _t->GetisolationStatusCCS2(); break;
        case 62: *reinterpret_cast< double*>(_v) = _t->GetcpVoltCCS2(); break;
        case 63: *reinterpret_cast< quint8*>(_v) = _t->GetplugTempPOSCCS2(); break;
        case 64: *reinterpret_cast< quint8*>(_v) = _t->GetplugTempNegCCS2(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject WallboxCharger::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_WallboxCharger.data,
    qt_meta_data_WallboxCharger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WallboxCharger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WallboxCharger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WallboxCharger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WallboxCharger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 65;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 65;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 65;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 65;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 65;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WallboxCharger::notify()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WallboxCharger::notice(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WallboxCharger::updateResult(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WallboxCharger::updateResultCCU(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WallboxCharger::logMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WallboxCharger::remoteStartSignalCCS1()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WallboxCharger::remoteStartSignalCCS2()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
