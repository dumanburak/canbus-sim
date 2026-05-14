import QtQuick 2.12
import QtQuick.Controls 2.12

Row {
    id: simRow

    readonly property color clrText:   "#f8f8f2"
    readonly property color clrBorder: "#44475a"
    readonly property color clrAccent: "#bd93f9"
    readonly property color clrYellow: "#f1fa8c"
    readonly property color clrPanel:  "#2a2a3e"

    property string label:        ""
    property var    displayValue: 0
    property real   from:         0
    property real   to:           100
    property real   stepSize:     1
    property real   currentValue: 0

    signal valueEdited(real val)

    spacing: 12
    leftPadding: 8
    height: 36

    Text {
        text: simRow.label
        color: clrText
        font.pixelSize: 13
        width: 200
        verticalAlignment: Text.AlignVCenter
        height: 36
    }

    Slider {
        id: sldr
        width: 260
        height: 36
        from: simRow.from
        to: simRow.to
        stepSize: simRow.stepSize
        value: simRow.currentValue
        onMoved: {
            txBox.text = sldr.value.toFixed(txBox.decimals)
            simRow.valueEdited(value)
        }

        background: Rectangle {
            x: sldr.leftPadding
            y: sldr.topPadding + sldr.availableHeight / 2 - height / 2
            width: sldr.availableWidth
            height: 4
            radius: 2
            color: clrBorder

            Rectangle {
                width: sldr.visualPosition * parent.width
                height: parent.height
                color: clrAccent
                radius: 2
            }
        }

        handle: Rectangle {
            x: sldr.leftPadding + sldr.visualPosition * sldr.availableWidth - width / 2
            y: sldr.topPadding + sldr.availableHeight / 2 - height / 2
            width: 18
            height: 18
            radius: 9
            color: clrAccent
        }
    }

    TextField {
        id: txBox

        readonly property int decimals: {
            var s = simRow.stepSize
            if (s >= 1)   return 0
            if (s >= 0.1) return 1
            return 2
        }

        text: simRow.currentValue.toFixed(decimals)
        width: 80
        height: 28
        anchors.verticalCenter: parent.verticalCenter

        font.pixelSize: 13
        font.family: "monospace"
        horizontalAlignment: Text.AlignHCenter
        color: clrYellow
        selectionColor: clrAccent

        background: Rectangle {
            color: clrPanel
            border.color: txBox.activeFocus ? clrAccent : clrBorder
            radius: 4
        }

        validator: DoubleValidator {
            bottom: simRow.from
            top:    simRow.to
            notation: DoubleValidator.StandardNotation
        }

        onEditingFinished: {
            var v = parseFloat(text)
            if (isNaN(v)) { text = sldr.value.toFixed(decimals); return }
            v = Math.max(simRow.from, Math.min(simRow.to, v))
            if (simRow.stepSize > 0)
                v = Math.round(v / simRow.stepSize) * simRow.stepSize
            sldr.value = v
            text = v.toFixed(decimals)
            simRow.valueEdited(v)
        }

        Connections {
            target: simRow
            onCurrentValueChanged: {
                if (!txBox.activeFocus)
                    txBox.text = simRow.currentValue.toFixed(txBox.decimals)
            }
        }
    }
}
