
#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QtQml>
#include <QVideoProbe>
#include <QVideoFrame>
#include <ImageGraber.h>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QQuickView view;


    ImageGraber graber;
    view.rootContext()->setContextProperty("imgGraber", &graber);

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/pages/Main.qml"));
    view.show();


   /* QObject *object = view.rootObject();

    QObject *player = object->findChild<QObject*>("player");

    QVideoProbe *probe = new QVideoProbe;

    connect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), this, SLOT(processFrame(QVideoFrame)));

    probe->setSource(player); // Returns true, hopefully.*/

    return a.exec();
}
