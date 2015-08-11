#ifndef QDECODER_H
#define QDECODER_H
#include <QDebug>
#include <QObject>
#include <QtQuick/QQuickView>
#include <QQuickImageProvider>

class QDecoder : public QObject, public QQuickImageProvider
{
    Q_OBJECT

public :
    explicit QDecoder(QObject *parent=0);
    Q_INVOKABLE void tryDebug();
    Q_INVOKABLE void grabWindow();

private:
    QQuickWindow *mainWindows;
};
#endif // QDECODER_H
