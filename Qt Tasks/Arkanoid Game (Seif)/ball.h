#ifndef BALL_H
#define BALL_H

#include <QTimer>

class Ball : public QObject
{
    Q_OBJECT
public:
    Ball();
    ~Ball();
    void initialPos1();
    void initialPos2();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void detectCollision(int bar_x, int bar_y);
    void startMotion();
    void stopMotion();
    bool isMoving();
    int getS1();
    int getS2();

private:
    int x;
    int y;
    int dir_hor;
    int dir_ver;
    QTimer *t_ball;
    int s1;
    int s2;

private slots:
    void updateCo();
};

#endif // BALL_H
