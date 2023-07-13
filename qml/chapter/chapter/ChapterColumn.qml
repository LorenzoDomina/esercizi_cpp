import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    id: rootLayout
    anchors.centerIn: parent

    function closeOtherDropdowns(excludedHeaderLayout) {
        for (var i = 0; i < count; i++) {
            var item = itemAt(i)
            if (item !== excludedHeaderLayout && item.hasOwnProperty(
                        "stateMachine")) {
                item.stateMachine.changeState("default")
            }
        }
    }
}
