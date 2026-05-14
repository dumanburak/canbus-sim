import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import com.wallboxcharger 1.0

Window {
    id: root
    width: 1100
    height: 720
    minimumWidth: 900
    minimumHeight: 600
    visible: true
    title: "CAN Bus Simülatör – vcan0"
    color: "#1e1e2e"

    WallboxCharger { id: can }

    readonly property color clrBg:     "#1e1e2e"
    readonly property color clrPanel:  "#2a2a3e"
    readonly property color clrBorder: "#44475a"
    readonly property color clrAccent: "#bd93f9"
    readonly property color clrGreen:  "#50fa7b"
    readonly property color clrRed:    "#ff5555"
    readonly property color clrYellow: "#f1fa8c"
    readonly property color clrText:   "#f8f8f2"
    readonly property color clrMuted:  "#6272a4"

    // ── Durum çubuğu ──────────────────────────────────────────────────────────
    Rectangle {
        id: statusBar
        anchors { top: parent.top; left: parent.left; right: parent.right }
        height: 48
        color: clrPanel
        border.color: clrBorder
        border.width: 1

        Row {
            anchors { verticalCenter: parent.verticalCenter; left: parent.left; right: parent.right
                      leftMargin: 16; rightMargin: 16 }
            spacing: 16

            Rectangle {
                width: 14; height: 14; radius: 7
                anchors.verticalCenter: parent.verticalCenter
                color: can.vcanReady ? clrGreen : clrRed
                Behavior on color { ColorAnimation { duration: 200 } }
            }

            Text {
                text: can.statusMessage || "Başlatılıyor..."
                color: clrText; font.pixelSize: 13
                anchors.verticalCenter: parent.verticalCenter
            }

            Item { width: 1; height: 1; Layout.fillWidth: true }

            Row {
                spacing: 8
                anchors.verticalCenter: parent.verticalCenter

                Text {
                    text: "Auto TX (100 ms)"
                    color: clrMuted; font.pixelSize: 12
                    anchors.verticalCenter: parent.verticalCenter
                }

                Switch {
                    checked: can.autoSend
                    enabled: can.vcanReady
                    onToggled: can.autoSend = checked
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Button {
                text: "Tüm Mesajları Gönder"
                enabled: can.vcanReady
                anchors.verticalCenter: parent.verticalCenter
                onClicked: can.sendAll()
                background: Rectangle {
                    color: parent.pressed ? Qt.darker(clrAccent, 1.3) : clrAccent
                    radius: 6
                }
                contentItem: Text {
                    text: parent.text
                    color: "#1e1e2e"; font.pixelSize: 12; font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Button {
                text: "vcan0 Kur"
                anchors.verticalCenter: parent.verticalCenter
                onClicked: can.setupVcan()
                background: Rectangle {
                    color: parent.pressed ? Qt.darker(clrYellow, 1.3) : clrYellow
                    radius: 6
                }
                contentItem: Text {
                    text: parent.text
                    color: "#1e1e2e"; font.pixelSize: 12; font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }

    // ── Sekme çubuğu ──────────────────────────────────────────────────────────
    TabBar {
        id: tabBar
        anchors { top: statusBar.bottom; left: parent.left; right: parent.right }
        height: 40
        background: Rectangle { color: clrPanel }

        Repeater {
            model: ["Socket A – CCS1", "Socket B – CCS2", "Ortak (CCU / ISO)"]
            TabButton {
                text: modelData
                width: implicitWidth + 40
                contentItem: Text {
                    text: parent.text
                    color: tabBar.currentIndex === index ? clrAccent : clrMuted
                    font.pixelSize: 13
                    font.bold: tabBar.currentIndex === index
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    color: "transparent"
                    Rectangle {
                        anchors.bottom: parent.bottom
                        width: parent.width; height: 2
                        color: tabBar.currentIndex === index ? clrAccent : "transparent"
                    }
                }
            }
        }
    }

    // ── İçerik ────────────────────────────────────────────────────────────────
    StackLayout {
        currentIndex: tabBar.currentIndex
        anchors {
            top: tabBar.bottom; bottom: parent.bottom
            left: parent.left; right: parent.right
            margins: 12
        }

        // ── CCS1 paneli ───────────────────────────────────────────────────────
        SocketPanel {
            chargeState:        can.ccs1ChargeState
            plugState:          can.ccs1PlugState
            presentVoltage:     can.ccs1PresentVoltage
            presentCurrent:     can.ccs1PresentCurrent
            targetVoltage:      can.ccs1TargetVoltage
            targetCurrent:      can.ccs1TargetCurrent
            evsePresentVoltage: can.ccs1EvsePresentVoltage
            evsePresentCurrent: can.ccs1EvsePresentCurrent
            soc:                can.ccs1SoC
            evReady:            can.ccs1EvReady
            errors:             can.ccs1Errors

            onEditChargeState:        can.ccs1ChargeState        = value
            onEditPlugState:          can.ccs1PlugState          = value
            onEditPresentVoltage:     can.ccs1PresentVoltage     = value
            onEditPresentCurrent:     can.ccs1PresentCurrent     = value
            onEditTargetVoltage:      can.ccs1TargetVoltage      = value
            onEditTargetCurrent:      can.ccs1TargetCurrent      = value
            onEditEvsePresentVoltage: can.ccs1EvsePresentVoltage = value
            onEditEvsePresentCurrent: can.ccs1EvsePresentCurrent = value
            onEditSoC:                can.ccs1SoC                = value
            onEditEvReady:            can.ccs1EvReady            = value
            onEditErrors:             can.ccs1Errors             = value
            onRemoteStartClicked:     can.triggerRemoteStartCCS1()
        }

        // ── CCS2 paneli ───────────────────────────────────────────────────────
        SocketPanel {
            chargeState:        can.ccs2ChargeState
            plugState:          can.ccs2PlugState
            presentVoltage:     can.ccs2PresentVoltage
            presentCurrent:     can.ccs2PresentCurrent
            targetVoltage:      can.ccs2TargetVoltage
            targetCurrent:      can.ccs2TargetCurrent
            evsePresentVoltage: can.ccs2EvsePresentVoltage
            evsePresentCurrent: can.ccs2EvsePresentCurrent
            soc:                can.ccs2SoC
            evReady:            can.ccs2EvReady
            errors:             can.ccs2Errors

            onEditChargeState:        can.ccs2ChargeState        = value
            onEditPlugState:          can.ccs2PlugState          = value
            onEditPresentVoltage:     can.ccs2PresentVoltage     = value
            onEditPresentCurrent:     can.ccs2PresentCurrent     = value
            onEditTargetVoltage:      can.ccs2TargetVoltage      = value
            onEditTargetCurrent:      can.ccs2TargetCurrent      = value
            onEditEvsePresentVoltage: can.ccs2EvsePresentVoltage = value
            onEditEvsePresentCurrent: can.ccs2EvsePresentCurrent = value
            onEditSoC:                can.ccs2SoC                = value
            onEditEvReady:            can.ccs2EvReady            = value
            onEditErrors:             can.ccs2Errors             = value
            onRemoteStartClicked:     can.triggerRemoteStartCCS2()
        }

        // ── Ortak panel ───────────────────────────────────────────────────────
        Flickable {
            contentHeight: commonCol.implicitHeight
            clip: true

            Column {
                id: commonCol
                width: parent.width
                spacing: 10
                topPadding: 8

                SimRow {
                    label: "CCU Version"
                    displayValue: can.ccuVersion.toFixed(1)
                    from: 0; to: 25; stepSize: 0.1
                    currentValue: can.ccuVersion
                    onValueEdited: can.ccuVersion = val
                }

                SimRow {
                    label: "rPos (Ω)"
                    displayValue: can.rPos
                    from: 0; to: 65535; stepSize: 10
                    currentValue: can.rPos
                    onValueEdited: can.rPos = val
                }

                SimRow {
                    label: "rNeg (Ω)"
                    displayValue: can.rNeg
                    from: 0; to: 65535; stepSize: 10
                    currentValue: can.rNeg
                    onValueEdited: can.rNeg = val
                }

                Row {
                    spacing: 12
                    leftPadding: 8
                    height: 36

                    Text {
                        text: "ISO Fault ACREL"
                        color: clrText; font.pixelSize: 13
                        width: 200; height: 36; verticalAlignment: Text.AlignVCenter
                    }

                    Switch {
                        checked: can.isoFaultAcrel
                        onToggled: can.isoFaultAcrel = checked
                    }
                }
            }
        }
    }
}
