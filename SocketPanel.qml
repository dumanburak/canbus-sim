import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    readonly property color clrBg:     "#1e1e2e"
    readonly property color clrPanel:  "#2a2a3e"
    readonly property color clrBorder: "#44475a"
    readonly property color clrAccent: "#bd93f9"
    readonly property color clrGreen:  "#50fa7b"
    readonly property color clrRed:    "#ff5555"
    readonly property color clrYellow: "#f1fa8c"
    readonly property color clrText:   "#f8f8f2"
    readonly property color clrMuted:  "#6272a4"

    // ── Gelen (display) property'ler ─────────────────────────────────────────
    property int    chargeState:        0
    property int    plugState:          0
    property double presentVoltage:     0.0
    property double presentCurrent:     0.0
    property double targetVoltage:      0.0
    property double targetCurrent:      0.0
    property double evsePresentVoltage: 0.0
    property double evsePresentCurrent: 0.0
    property int    soc:                0
    property bool   evReady:            false
    property int    errors:             0

    // ── Kullanıcı düzenlemesi sinyalleri (Qt property sinyalleriyle çakışmaz) ──
    signal editChargeState(int value)
    signal editPlugState(int value)
    signal editPresentVoltage(real value)
    signal editPresentCurrent(real value)
    signal editTargetVoltage(real value)
    signal editTargetCurrent(real value)
    signal editEvsePresentVoltage(real value)
    signal editEvsePresentCurrent(real value)
    signal editSoC(int value)
    signal editEvReady(bool value)
    signal editErrors(int value)
    signal remoteStartClicked()

    Flickable {
        anchors.fill: parent
        contentHeight: col.implicitHeight
        clip: true

        Column {
            id: col
            width: parent.width
            spacing: 6
            topPadding: 8
            bottomPadding: 8

            // ── Charge State ──────────────────────────────────────────────────
            Row {
                spacing: 12
                leftPadding: 8
                height: 36

                Text {
                    text: "Charge State"
                    color: clrText; font.pixelSize: 13
                    width: 200; height: 36; verticalAlignment: Text.AlignVCenter
                }

                ComboBox {
                    id: csBox
                    model: ["0 – Idle", "1 – Waiting Auth", "2 – Auth OK",
                            "3 – Precharge", "4 – Charging", "5 – Ending",
                            "6 – Fault", "7 – Finished"]
                    currentIndex: chargeState
                    onActivated: editChargeState(index)
                    background: Rectangle { color: clrPanel; border.color: clrBorder; radius: 4 }
                    contentItem: Text {
                        text: csBox.displayText
                        color: clrText; font.pixelSize: 13
                        leftPadding: 8; verticalAlignment: Text.AlignVCenter
                    }
                }
            }

            // ── Plug State ────────────────────────────────────────────────────
            Row {
                spacing: 12
                leftPadding: 8
                height: 36

                Text {
                    text: "Plug State"
                    color: clrText; font.pixelSize: 13
                    width: 200; height: 36; verticalAlignment: Text.AlignVCenter
                }

                ComboBox {
                    id: psBox
                    model: ["0 – Unplugged", "1 – Plugged", "2 – Locked", "3 – Fault"]
                    currentIndex: plugState
                    onActivated: editPlugState(index)
                    background: Rectangle { color: clrPanel; border.color: clrBorder; radius: 4 }
                    contentItem: Text {
                        text: psBox.displayText
                        color: clrText; font.pixelSize: 13
                        leftPadding: 8; verticalAlignment: Text.AlignVCenter
                    }
                }
            }

            // ── EV Ready ──────────────────────────────────────────────────────
            Row {
                spacing: 12
                leftPadding: 8
                height: 36

                Text {
                    text: "EV Ready"
                    color: clrText; font.pixelSize: 13
                    width: 200; height: 36; verticalAlignment: Text.AlignVCenter
                }

                Switch {
                    checked: evReady
                    onToggled: editEvReady(checked)
                }
            }

            // ── SoC ───────────────────────────────────────────────────────────
            SimRow {
                label: "SoC (%)"
                displayValue: soc
                from: 0; to: 100; stepSize: 1
                currentValue: soc
                onValueEdited: editSoC(val)
            }

            // ── Present Voltage ───────────────────────────────────────────────
            SimRow {
                label: "Present Voltage (V)"
                displayValue: presentVoltage.toFixed(1)
                from: 0; to: 1000; stepSize: 1
                currentValue: presentVoltage
                onValueEdited: editPresentVoltage(val)
            }

            // ── Present Current ───────────────────────────────────────────────
            SimRow {
                label: "Present Current (A)"
                displayValue: presentCurrent.toFixed(1)
                from: 0; to: 500; stepSize: 0.5
                currentValue: presentCurrent
                onValueEdited: editPresentCurrent(val)
            }

            // ── EVSE Present Voltage ──────────────────────────────────────────
            SimRow {
                label: "EVSE Present Voltage (V)"
                displayValue: evsePresentVoltage.toFixed(1)
                from: 0; to: 1000; stepSize: 1
                currentValue: evsePresentVoltage
                onValueEdited: editEvsePresentVoltage(val)
            }

            // ── EVSE Present Current ──────────────────────────────────────────
            SimRow {
                label: "EVSE Present Current (A)"
                displayValue: evsePresentCurrent.toFixed(1)
                from: 0; to: 500; stepSize: 0.5
                currentValue: evsePresentCurrent
                onValueEdited: editEvsePresentCurrent(val)
            }

            // ── Target Voltage ────────────────────────────────────────────────
            SimRow {
                label: "Target Voltage (V)"
                displayValue: targetVoltage.toFixed(1)
                from: 0; to: 1000; stepSize: 1
                currentValue: targetVoltage
                onValueEdited: editTargetVoltage(val)
            }

            // ── Target Current ────────────────────────────────────────────────
            SimRow {
                label: "Target Current (A)"
                displayValue: targetCurrent.toFixed(1)
                from: 0; to: 500; stepSize: 0.5
                currentValue: targetCurrent
                onValueEdited: editTargetCurrent(val)
            }

            // ── Error Flags ───────────────────────────────────────────────────
            Row {
                spacing: 12
                leftPadding: 8

                Text {
                    text: "Error Flags (0x" + errors.toString(16).toUpperCase() + ")"
                    color: errors !== 0 ? clrRed : clrMuted
                    font.pixelSize: 13
                    width: 200
                    verticalAlignment: Text.AlignVCenter
                    height: 36
                }

                Column {
                    spacing: 2

                    Repeater {
                        model: [
                            "Bit0 – NoAvailablePowerModule",
                            "Bit1 – PowerModule",
                            "Bit2 – Contactor",
                            "Bit3 – PlcBoxRxTimeout",
                            "Bit4 – CurrentSensorRxTimeout",
                            "Bit5 – CP",
                            "Bit6 – Emergency",
                            "Bit7 – BMS"
                        ]

                        CheckBox {
                            text: modelData
                            checked: (errors >> index) & 0x01
                            onToggled: {
                                var mask = errors
                                if (checked) mask |= (1 << index)
                                else         mask &= ~(1 << index)
                                editErrors(mask & 0xFF)
                            }
                            contentItem: Text {
                                text: parent.text
                                color: clrText
                                font.pixelSize: 11
                                leftPadding: parent.indicator.width + 4
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                }
            }

            // ── Remote Start ──────────────────────────────────────────────────
            Button {
                leftPadding: 8
                text: "  Remote Start (OCPP Simülasyonu)"
                onClicked: remoteStartClicked()

                background: Rectangle {
                    color: parent.pressed ? Qt.darker(clrGreen, 1.4) : clrGreen
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
}
