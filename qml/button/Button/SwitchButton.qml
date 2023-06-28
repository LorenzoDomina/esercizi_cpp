import QtQuick 2.0

Item {
    width: 100
    height: 50

    property bool checked: false

    Rectangle {
        width: parent.width
        height: parent.height
        color: checked ? "#00CC00" : "#CCCCCC"
        border.color: checked ? "#269839" : "#707070"
        border.width: 1.5
        radius: 10

        Behavior on color {
            PropertyAnimation {
                duration: 200
            }
        }

        Text {
            anchors.fill: parent
            text: checked ? "ON" : "OFF"
            font.family: "nunito"
            font.pointSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: checked ? "white" : "black"
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            checked = !checked
        }
    }
}
