import QtQuick

Rectangle {
    id: padre

    width: 1280
    height: title.height

    radius: 18
    color: "#050e37"

    state: "default"

    property string titolo: value
    property string contenuto: value

    property double chapterHeight: 50

    signal close

    Column {

        anchors {
            left: padre.left
            leftMargin: 5
            bottom: padre.Bottom
            bottomMargin: 5
        }

        Text {
            id: title

            width: padre.width
            horizontalAlignment: Text.AlignHLeft
            font.pointSize: 28
            color: "white"
            text: titolo
        }

        Text {
            id: content

            anchors {
                top: title.bottom
                topMargin: 15
            }

            width: padre.width - 8
            horizontalAlignment: Text.AlignHLeft
            wrapMode: Text.Wrap
            font.pointSize: 18
            color: "white"
            text: contenuto

            Behavior on opacity {
                NumberAnimation {
                    duration: 300
                }
            }
        }
    }

    MouseArea {
        id: myMouseArea

        anchors.fill: padre
        onClicked: {
            if (padre.state === "default") {
                close()
            } else
                padre.state = "default"
        }
    }

    Behavior on height {
        NumberAnimation {
            duration: 300
        }
    }

    states: [
        State {
            name: "default"

            PropertyChanges {
                target: content
                opacity: 0
                anchors.topMargin: 50
            }
        },
        State {
            name: "expanded"

            PropertyChanges {
                target: padre
                height: title.height + content.height + 20
            }
        }
    ]
}
