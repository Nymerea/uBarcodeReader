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

void QDecoder::grabWindow()
{
    if (!mainWindows) {
        qDebug() << "unable to find main window";
        return;
    }

    qDebug() << "clicked on grab windows";
    QImage img;

    QImage window = mainWindows->grabWindow();
    if (m_scanRect.isValid()) {
        qDebug() << "try to remove application windows into image";
        img = window.copy(m_scanRect);
    }

    QZXing qzxingDecoder;
    QObject::connect(&qzxingDecoder, SIGNAL(decodingStarted()), this, SLOT(decodingImage()));
    QObject::connect(&qzxingDecoder, SIGNAL(decodingFinished(bool)), this, SLOT(imageDecoded(bool)));
    QObject::connect(&qzxingDecoder, SIGNAL(tagFound(QString)), this, SLOT(tagFound(QString)));
    qzxingDecoder.decodeImage(img,1000,1000,true);
   // qzxingDecoder.decodeImageFromFile("/home/morgan/qt/uBarcodeReader/OpenFoodFacts/barcode.jpg", 1000,1000, true);
    //emit barcodeFound();


}

QRect QDecoder::scanRect() const
{
    return m_scanRect;
}

void QDecoder::setScanRect(const QRect &rect)
{
    qDebug() << "new ScanRect setted";

    if (m_scanRect != rect) {
        m_scanRect = rect;
        emit scanRectChanged();
    }
}


QString QDecoder::barCode()
{
    return this->barcode;
}

void QDecoder::decodingImage()
{
    qDebug() << "decoding image started";
}

void QDecoder::tagFound(QString tag)
{
    qDebug() << "tag found : " << tag;
}

void QDecoder::imageDecoded(bool succeeded)
{
    qDebug() << "decoding image finished";
}
