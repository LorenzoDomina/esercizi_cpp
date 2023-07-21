import QtQuick

Page {
    id: root
    signal back

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
        text: qsTr("Alarm clock list")
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

    Text {
        anchors {
            left: root.left
            top: root.top
            leftMargin: 38
            topMargin: 135
        }
        color: "#FCB647"
        font {
            family: "Buenos Aires, Regular"
            pointSize: 15
        }

        text: "Everyday"
    }

    Rectangle {
        id: rect1
        anchors {
            horizontalCenter: root.horizontalCenter
            top: root.top
            topMargin: 175
        }
        width: 424
        height: 2
        color: "#1B2F46"
    }

    //    ListModel {
    //        id: alarms

    //        ListElement {
    //            dateTime: "7:30"
    //            isActive: true
    //        }

    //        ListElement {
    //            dateTime: "20:45"
    //            isActive: false
    //        }
    //    }
    ListView {
        model: clockobject
        clip: true
        anchors {
            top: rect1.top
            left: root.left
            bottom: root.bottom
            right: root.right
        }

        delegate: Item {
            id: alarm
            anchors {
                left: parent.left
                right: parent.right
            }
            height: 20 + time.height + 20 + rect2.height
            width: root.width

            Text {
                id: time
                anchors {
                    top: alarm.top
                    left: alarm.left
                    topMargin: 20
                    leftMargin: 111
                }
                color: "#9FAAB0"
                font {
                    //family: "Buenos Aires"
                    pointSize: 32
                }
                text: model.dateTime
            }

            AlarmSwitch {
                anchors {
                    top: alarm.top
                    topMargin: 14
                    right: alarm.right
                    rightMargin: 37
                }
                active: model.isActive

                MouseArea {
                    anchors.fill: parent
                    onClicked: model.isActive = !model.isActive
                }
            }

            Rectangle {
                id: rect2
                anchors {
                    horizontalCenter: alarm.horizontalCenter
                    top: time.bottom
                    topMargin: 20
                }
                color: "#1B2F46"
                width: 424
                height: 2
            }
        }
    }
}
