import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: mainWindowRoot

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Shortcut {
        sequence: "ctrl+q"
        onActivated: mainWindowRoot.close()
    }

    Component.onCompleted: console.log("hello")
}
