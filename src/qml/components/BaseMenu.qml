import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import WalletModule 1.0

Item {
	id: root
	property string title: ""
	default property alias buttons: menuContainer.buttons
	signal backRequested
	signal powerOffRequested

	MenuContainer {
		id: menuContainer
		anchors.fill: parent
		anchors.leftMargin: root.width * 0.05
		anchors.rightMargin: root.width * 0.05
		anchors.topMargin: root.height * 0.03
	}
}
