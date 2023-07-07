import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    width: 300
    height: 40
    color: "lightgray"

    property real percentage: 0

    Behavior on percentage {
        NumberAnimation {
            duration: 500
        }
    }

    Rectangle {
        width: parent.width * percentage
        height: parent.height
        color: "green"
    }

    Text {
        anchors.centerIn: parent
        text: Math.round(percentage * 100) + "%"
    }
}
