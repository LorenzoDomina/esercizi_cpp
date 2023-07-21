#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "clockobject.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("clock", "Main");

    ClockObject clockobject;
    engine.rootContext()->setContextProperty("clockobject", &clockobject);

    return app.exec();
}
