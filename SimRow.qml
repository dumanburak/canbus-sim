import QtQuick 2.12
import QtQuick.Controls 2.12

Row {
    readonly property color clrText:   "#f8f8f2"
    readonly property color clrBorder: "#44475a"
    readonly property color clrAccent: "#bd93f9"
    readonly property color clrYellow: "#f1fa8c"

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
        width: 300
        height: 36
        from: parent.from
        to: parent.to
        stepSize: parent.stepSize
        value: parent.currentValue
        onMoved: parent.valueEdited(value)

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

    Text {
        text: displayValue
        color: clrYellow
        font.pixelSize: 13
        font.family: "monospace"
        width: 80
        verticalAlignment: Text.AlignVCenter
        height: 36
    }
}
