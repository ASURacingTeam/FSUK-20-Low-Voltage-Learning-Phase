#ifndef PAINTER_H
#define PAINTER_H

#include <QObject>
#include <ball.h>
#include <QPainter>
#include <QPaintEvent>
#include <QMainWindow>

class Painter : public QObject, public QPaintDevice
{
    Q_OBJECT
public:
    explicit Painter(QObject *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // PAINTER_H
