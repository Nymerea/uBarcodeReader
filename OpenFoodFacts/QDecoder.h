#ifndef QDECODER_H
#define QDECODER_H
#include <QDebug>
#include <QObject>
#include <QtQuick/QQuickView>
#include <QQuickImageProvider>

class QDecoder : public QObject, public QQuickImageProvider
{
    Q_OBJECT
    Q_PROPERTY(QRect scanRect READ scanRect WRITE setScanRect NOTIFY scanRectChanged)
    Q_PROPERTY(QString barCode READ barCode NOTIFY barcodeFound)
public :
    explicit QDecoder(QObject *parent=0);
    Q_INVOKABLE void grabWindow();
    Q_INVOKABLE QRect scanRect() const;
    Q_INVOKABLE void setScanRect(const QRect &rect);
    Q_INVOKABLE QString barCode() ;
private:
    QQuickWindow *mainWindows;
    QRect m_scanRect;
    QString barcode;


signals:
    void scanRectChanged();
    void barcodeFound();

public slots:

    void decodingImage();
    void tagFound(QString tag);
    void imageDecoded(bool succeeded);
};
#endif // QDECODER_H
