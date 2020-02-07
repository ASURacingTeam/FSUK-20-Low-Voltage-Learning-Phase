#include "ball.h"

Ball::Ball()
{
    initialPos1();
    dir_hor = -1;
    dir_ver = 1;
    t_ball = new QTimer;
    connect(t_ball, SIGNAL(timeout()), this, SLOT(updateCo()));
    s1 = 0;
    s2 = 0;
}

Ball::~Ball()
{

}

bool Ball::isMoving()
{
    return (t_ball->isActive());
}

void Ball::initialPos1()
{
    x = 1020;
    y = 550;
}

void Ball::initialPos2()
{
    x = 175;
    y = 550;
}

void Ball::startMotion()
{
    t_ball->start(18);
}

void Ball::stopMotion()
{
    t_ball->stop();
}

void Ball::detectCollision(int bar_x, int bar_y)
{
    if ((x + 10 >= bar_x && x <= (bar_x + 10)) && (y >= bar_y && (y <= bar_y + 150)))
    {
        if (x >= 600)
        {
            dir_hor = -1;
        }
        else {
            dir_hor = 1;
        }
    }
}

void Ball::updateCo()
{
//    if (x == 1030 && dir_hor == 1)
//    {
//        dir_hor = -1;
//        x -= 10;
//    }
//    if(x == 150 && dir_hor == -1){
//        dir_hor = 1;
//        x += 10;
//    }

    if (dir_hor == 1)
    {
        x += 10;
    }
    else if (dir_hor == -1)
    {
        x -= 10;
    }

    if (x >= 1100)
    {
        initialPos1();
        stopMotion();
        dir_hor = -1;
        s2++;
    }
    else if (x <= 100)
    {
        initialPos2();
        stopMotion();
        dir_hor = 1;
        s1++;
    }

    if (y >= 900 && dir_ver == 1)
    {
        dir_ver = -1;
        y -= 15;
    }
    else if (y <= 45 && dir_ver == -1)
    {
        dir_ver = 1;
        y += 15;
    }
    else if (dir_ver == 1)
    {
        y += 15;
    }
    else {
        y -= 15;
    }
}

int Ball::getX()
{
    return x;
}

int Ball::getY()
{
    return y;
}

void Ball::setX(int x)
{
    this->x = x;
}

void Ball::setY(int y)
{
    this->y = y;
}

int Ball::getS1()
{
    return s1;
}

int Ball::getS2()
{
    return s2;
}
