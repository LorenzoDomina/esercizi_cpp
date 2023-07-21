import QtQuick

Page {
    id: root
    signal openAlarmPage
    signal openPageAlarmList

    Button {
        textButton: "TIMER"
        anchors {
            left: root.left
            right: root.horizontalCenter
            bottom: root.bottom
            leftMargin: 18
            rightMargin: 32
            bottomMargin: 108
        }
    }

    Button {
        textButton: "ALARM"
        anchors {
            left: root.horizontalCenter
            right: root.right
            bottom: root.bottom
            leftMargin: 32
            rightMargin: 18
            bottomMargin: 108
        }
        onClick: openAlarmPage()
    }

    Text {
        id: name
        anchors {
            top: root.top
            horizontalCenter: root.horizontalCenter
            topMargin: 40
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: 20
            bold: true
            family: "Buenos Aires"
        }
        color: "#9FAAB0"
        text: "DeveClock"
    }

    Image {
        id: alarm
        anchors {
            top: root.top
            right: root.right
            topMargin: 33
            rightMargin: 27
        }

        MouseArea {
            id: alarmMouseArea
            anchors.fill: alarm
            onClicked: openPageAlarmList()
        }

        source: "/assets/alarm-on-feedback.svg"
    }
}
