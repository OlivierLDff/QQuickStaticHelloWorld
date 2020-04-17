import QtQuick 2.14
import QtQuick.Window 2.14

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
