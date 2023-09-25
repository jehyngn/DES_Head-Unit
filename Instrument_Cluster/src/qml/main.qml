import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: mytext
        text: "Hello World"
        visible: false
    }

    Connections {
        target: server
        onImageActivated: {
            mytext.visible = true
        }
    }
}

