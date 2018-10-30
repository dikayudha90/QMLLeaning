import QtQuick 2.6
import QtQuick.Controls 1.0
import io.qt.examples.backend 1.0
import QtMultimedia 5.0

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Minimal Qml")

    Button {
        id: okButton
        x: 18
        y: 30
        text: qsTr("Button")
    }

    BackEnd{
        id: backend;
    }

    TextField {
        text: backend.userName
        anchors.verticalCenterOffset: -139
        anchors.horizontalCenterOffset: -251
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onTextChanged: backend.userName = text
    }
}
