import QtQuick 2.15
import QtQuick.Controls 2.15

Column {
    spacing: 10

    Repeater {
        model: 5
        delegate: Bar {
            width: parent.width
            height: 40
            property real currentPercentage: Math.random()

            Behavior on currentPercentage {
                NumberAnimation {
                    duration: 500
                }
            }

            Timer {
                interval: Math.random() * 2000 + 500
                running: true
                repeat: true
                onTriggered: {
                    var increment = Math.random() * 0.2 - 0.1
                    currentPercentage = Math.max(
                                Math.min(currentPercentage + increment, 1), 0)
                }
            }

            onCurrentPercentageChanged: {
                percentage = currentPercentage
            }
        }
    }
}
