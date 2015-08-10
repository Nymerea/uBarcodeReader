#ifndef IMAGEGRABER_H
#define IMAGEGRABER_H
#include <QDebug>
#include <QObject>


class ImageGraber : public QObject
{
    Q_OBJECT

 public :
     Q_INVOKABLE void tryDebug();
};
#endif // IMAGEGRABER_H
