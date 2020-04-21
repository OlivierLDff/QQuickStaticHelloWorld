
import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    id: window

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text
    {
        text: "hello world"
        anchors.centerIn: parent
    }
}