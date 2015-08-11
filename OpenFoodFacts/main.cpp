#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QtQml>
#include <QDecoder.h>

int main(int argc, char *argv[])
{

    QGuiApplication a(argc, argv);
    QQuickView view;

    QDecoder decoder;
    view.rootContext()->setContextProperty("qDecoder", &decoder);
    view.engine()->addImportPath("..");

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    //view.setSource(QUrl::fromLocalFile("./Main.qml"));
    view.setSource(QUrl("qrc:/pages/Main.qml"));
    view.show();

    return a.exec();
}
