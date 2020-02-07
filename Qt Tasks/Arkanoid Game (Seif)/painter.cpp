#include "painter.h"

Painter::Painter(QObject *parent) : QObject(parent)
{

}

void Painter::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen;
    pen.setWidth(10);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setColor(Qt::white);
    p.setPen(pen);
    p.drawRect(150, 25, 900, 900);
    update();
}
