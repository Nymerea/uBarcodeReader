#include <QtQml>
#include "qzxing_plugin.h"
#include "QZXing.h"

void QZXingPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQmlExtensionPlugin::initializeEngine(engine, uri);
}

void QZXingPlugin::registerTypes(const char *uri)
{
    // @uri QZXing
    qmlRegisterType<QZXing>(uri,
                            QZXING_PLUGIN_VERSION_MAJOR,
                            QZXING_PLUGIN_VERSION_MINOR,
                            QZXING_PLUGIN_QML_NAME);
}
