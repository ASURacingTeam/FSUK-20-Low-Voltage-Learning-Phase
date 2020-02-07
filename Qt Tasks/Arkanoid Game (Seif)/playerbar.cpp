#include "playerbar.h"

PlayerBar::PlayerBar(int x, int y)
{
    this->x = x;
    this->y = y;
}

int PlayerBar::getX()
{
    return x;
}

int PlayerBar::getY()
{
    return y;
}

void PlayerBar::setX(int x)
{
    this->x = x;
}

void PlayerBar::setY(int y)
{
    this->y = y;
}
