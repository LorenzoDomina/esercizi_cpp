import QtQuick

Rectangle {
    id: switchAllarm
    height: 60
    width: 112
    color: active ? selectedColor : disableColor
    radius: 8
    property color disableColor: Qt.rgba(159, 170, 176, 0.12)
    property color selectedColor: Qt.rgba(0, 180, 157, 0.2)
    property bool active: false

    Image {
        id: off
        source: active ? "/assets/clock-switch-off-disable.png" : "/assets/clock-switch-off-selected.png"
        anchors {
            left: parent.left
            leftMargin: 4
            top: parent.top
            topMargin: 4
        }
    }

    Image {
        id: on
        source: active ? "/assets/clock-switch-on-selected.png" : "/assets/clock-switch-on-disable.png"
        anchors {
            right: parent.right
            rightMargin: 4
            top: parent.top
            topMargin: 4
        }
    }

    MouseArea {
        id: myMouseArea
        anchors.fill: switchAllarm
        //la traccia del esercio chiedeva di non usare gli stati cosi ho usato un if
        onClicked: {
            if (active) {
                active = false
            } else {
                active = true
            }
        }
    }
}
