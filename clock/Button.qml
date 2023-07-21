import QtQuick

Rectangle {
    id: button
    height: 64
    color: "transparent"
    radius: height / 2
    state: "default"
    border {
        color: "#FCB647"
        width: 1
    }
    property alias textButton: text.text
    signal click

    Text {
        id: text
        anchors {
            top: button.top
            right: button.right
            left: button.left
            bottom: button.bottom
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: 20
            bold: true
            family: "Buenos Aires"
        }
        color: "#FCB647"
    }

    MouseArea {
        id: myMouseArea
        anchors.fill: button
        hoverEnabled: true
        onClicked: click()
    }

    states: [
        State {
            name: "hover"
            when: myMouseArea.containsMouse
            PropertyChanges {
                target: text
                color: "#151B2E"
            }
            PropertyChanges {
                target: button
                color: "#FCB647"
            }
        }
    ]
    transitions: [
        Transition {
            from: ""
            to: "hover"
            reversible: true

            ColorAnimation {
                target: button
                duration: 300
            }
            ColorAnimation {
                target: text
                duration: 300
            }
        }
    ]
}
