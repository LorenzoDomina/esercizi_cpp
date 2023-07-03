import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "EsBar"

    Bars {
        anchors.centerIn: parent
        width: 300
        height: 250
    }
}
