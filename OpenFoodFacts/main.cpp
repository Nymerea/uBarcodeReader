
#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QtQml>
#include <QVideoProbe>
#include <QVideoFrame>
int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QQuickView view;


    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl::fromLocalFile("Main.qml"));
    view.show();

   /* QObject *object = view.rootObject();

    QObject *player = object->findChild<QObject*>("player");

    QVideoProbe *probe = new QVideoProbe;

    connect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), this, SLOT(processFrame(QVideoFrame)));

    probe->setSource(player); // Returns true, hopefully.*/

    return a.exec();
}
