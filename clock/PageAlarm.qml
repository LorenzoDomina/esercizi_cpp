import QtQuick

Page {
    id: root

    signal back

    Button {
        textButton: "SET ALARM"
        anchors {
            left: root.left
            bottom: root.bottom
            right: root.right
            leftMargin: 23
            bottomMargin: 30
            rightMargin: 23
        }
        onClick: {
            let time = new Date()
            time.setHours(hoursItem.numCount)
            time.setMinutes(minutesItem.numCount)
            time.setSeconds(0)
            clockobject.addAlarm(time)
            root.back()
        }
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
        text: "Alarm"
    }

    Image {
        id: arrowBack
        anchors {
            left: root.left
            verticalCenter: name.verticalCenter
            leftMargin: 28
        }
        source: "/assets/btn-back-active.svg"

        MouseArea {
            id: myMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: back()
        }

        states: [
            State {
                name: "hover"
                when: myMouseArea.containsMouse
                PropertyChanges {
                    target: arrowBack
                    source: "/assets/btn-back-hover.svg"
                }
            }
        ]
    }

    Counter {
        id: hoursItem
        anchors {
            top: root.top
            right: root.horizontalCenter
            topMargin: 160
            rightMargin: 22
        }
        max: 23
        numberType: "hours"
    }

    Text {
        id: colon
        anchors {
            top: root.top
            topMargin: 52 + 160
            horizontalCenter: root.horizontalCenter
        }
        color: "#707070"
        font {
            //family: "SF Pro Display"
            pointSize: 85
        }
        text: qsTr(":")
    }

    Counter {

        id: minutesItem
        anchors {
            top: root.top
            left: root.horizontalCenter
            topMargin: 160
            leftMargin: 22
        }
        max: 59
        numberType: "mins"
    }
}
