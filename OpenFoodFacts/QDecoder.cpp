#include <QDecoder.h>
#include <QGuiApplication>
#include <QWindow>
#include "../QZXing/QZXing.h"


QDecoder::QDecoder(QObject *parent) :
    QObject(parent),
    QQuickImageProvider(QQmlImageProviderBase::Image),
    mainWindows(0)
{
    QGuiApplication *app = qobject_cast<QGuiApplication*>(qApp);

    qDebug() << "constructing reader" << app;
    foreach (QWindow *win, app->allWindows()) {
        qDebug() << "got win" << win;
        QQuickWindow *quickWin = qobject_cast<QQuickWindow*>(win);
        if (quickWin) {
            this->mainWindows = quickWin;
        }
    }

}


void QDecoder::tryDebug()
{
    if(!mainWindows) {
        qDebug() << "main window, null";
    } else {
        qDebug() << "main window, not null";
    }
    qDebug() << "clicked";
}

void QDecoder::grabWindow()
{
    if (!mainWindows) {
        qDebug() << "unable to find main window";
        return;
    }

    qDebug() << "clicked on grab windows";
    QZXing qzxingDecoder;

}