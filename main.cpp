#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtPlugin>

#include <iostream>



//Q_IMPORT_PLUGIN(qtquick2plugin)
Q_IMPORT_PLUGIN(QtQuick2Plugin)
Q_IMPORT_PLUGIN(QtQuickControls2Plugin)
Q_IMPORT_PLUGIN(QtQuickTemplates2Plugin)
Q_IMPORT_PLUGIN(QtQuick2WindowPlugin)
Q_IMPORT_PLUGIN(QtQuickLayoutsPlugin)
//Q_IMPORT_PLUGIN(QtQuickControls2Plugin);
//Q_IMPORT_PLUGIN(QtQuickTemplates2Plugin);
//Q_IMPORT_PLUGIN(QtQuick2WindowPlugin);
//Q_IMPORT_PLUGIN(QtQuickControls2MaterialStylePlugin);
//Q_IMPORT_PLUGIN(QmlSettingsPlugin);
//Q_IMPORT_PLUGIN(QtQuickControls2FusionStylePlugin);
//Q_IMPORT_PLUGIN(QtQuickControls2UniversalStylePlugin);
//Q_IMPORT_PLUGIN(QtQuickControls2ImagineStylePlugin);
//Q_IMPORT_PLUGIN(QtGraphicalEffectsPlugin);
//Q_IMPORT_PLUGIN(QtGraphicalEffectsPrivatePlugin);
//Q_IMPORT_PLUGIN(QWindowsPrinterSupportPlugin)
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
//Q_IMPORT_PLUGIN(QDDSPlugin)
//Q_IMPORT_PLUGIN(QICNSPlugin)
//Q_IMPORT_PLUGIN(QICOPlugin)
//Q_IMPORT_PLUGIN(QMngPlugin)
//Q_IMPORT_PLUGIN(QTgaPlugin)
//Q_IMPORT_PLUGIN(QTiffPlugin)
//Q_IMPORT_PLUGIN(QWbmpPlugin)
//Q_IMPORT_PLUGIN(QWebpPlugin)
//Q_IMPORT_PLUGIN(QGeoPositionInfoSourceFactoryGeoclue)
//Q_IMPORT_PLUGIN(QGeoPositionInfoSourceFactoryPoll)
//Q_IMPORT_PLUGIN(QGenericEnginePlugin)
//Q_IMPORT_PLUGIN(QNativeWifiEnginePlugin)

int main(int argc, char *argv[])
{
    std::cout << "hello\n" << std::flush;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qDebug() << "hello world";

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        std::cout << "obj created\n" << std::flush;
        if (!obj && url == objUrl)
        {
            std::cout << "exit\n" << std::flush;
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);

    QObject::connect(&engine, &QQmlApplicationEngine::warnings,
                     [=](const QList<QQmlError> &warnings) {
        std::cout << "errors\n" << std::flush;
        for(auto& w : warnings)
        {
            std::cout << w.toString().toStdString() << std::endl << std::flush;
        }
    });
    engine.load(url);

    return app.exec();
}
