import QtQuick 2.12
import QtQuick.Controls 2.12

Row {
    readonly property color clrText:   "#f8f8f2"
    readonly property color clrBorder: "#44475a"
    readonly property color clrAccent: "#bd93f9"
    readonly property color clrYellow: "#f1fa8c"
    readonly property color clrPanel:  "#2a2a3e"
    readonly property color clrRed:    "#ff5555"

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
        text: label
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
        from: parent.from
        to: parent.to
        stepSize: parent.stepSize
        value: parent.currentValue
        onMoved: {
            txBox.text = sldr.value.toFixed(txBox.decimals)
            parent.valueEdited(value)
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

    // Ondalık basamak sayısı: stepSize'a göre otomatik
    TextField {
        id: txBox

        readonly property int decimals: {
            var s = parent.stepSize
            if (s >= 1)   return 0
            if (s >= 0.1) return 1
            return 2
        }

        text: parent.currentValue.toFixed(decimals)
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
            bottom: parent.parent.from
            top:    parent.parent.to
            notation: DoubleValidator.StandardNotation
        }

        onEditingFinished: {
            var v = parseFloat(text)
            if (isNaN(v)) { text = sldr.value.toFixed(decimals); return }
            v = Math.max(parent.parent.from, Math.min(parent.parent.to, v))
            // stepSize'a snap
            if (parent.parent.stepSize > 0) {
                v = Math.round(v / parent.parent.stepSize) * parent.parent.stepSize
            }
            sldr.value = v
            text = v.toFixed(decimals)
            parent.valueEdited(v)
        }

        // currentValue dışarıdan değişince (örn. reset) güncelle
        Connections {
            target: txBox.parent
            onCurrentValueChanged: {
                if (!txBox.activeFocus)
                    txBox.text = txBox.parent.currentValue.toFixed(txBox.decimals)
            }
        }
    }
}
