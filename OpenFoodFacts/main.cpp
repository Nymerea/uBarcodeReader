
#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QtQml>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QQuickView view;


    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl::fromLocalFile("Main.qml"));
    view.show();

    return a.exec();
}
