#ifndef PLAYERBAR_H
#define PLAYERBAR_H

#include <QObject>

class PlayerBar : public QObject
{
    Q_OBJECT
public:
    explicit PlayerBar(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

signals:

private:
    int x;
    int y;

private slots:
};

#endif // PLAYERBAR_H
