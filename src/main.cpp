#include "include/wifimanager.h"
#include "include/systemmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>
#include <QIcon>

int main(int argc, char *argv[])
{
 QGuiApplication app(argc, argv);
 app.setApplicationName("Matchbox Wallet");
 app.setApplicationVersion("0.0.1");
 app.setOrganizationName("LiberSoft");

 // Set application icon
 app.setWindowIcon(QIcon(":/WalletModule/src/img/wallet.svg"));

 // Register QML types
 qmlRegisterType<WiFiManager>("WalletModule", 1, 0, "WiFiManager");
 qmlRegisterType<SystemManager>("WalletModule", 1, 0, "SystemManager");
 QQmlApplicationEngine engine;
 // Register QML context properties if needed
 // clang-format off
 engine.rootContext()->setContextProperty("applicationVersion", app.applicationVersion());
 // clang-format on
 const QUrl url(QStringLiteral("qrc:/WalletModule/src/qml/main.qml"));
 QObject::connect(
					&engine,
					&QQmlApplicationEngine::objectCreated,
					&app,
					[url](QObject *obj, const QUrl &objUrl)
					{
						if (!obj && url == objUrl)
							QCoreApplication::exit(-1);
					},
					Qt::QueuedConnection);
 engine.load(url);
 return app.exec();
}
