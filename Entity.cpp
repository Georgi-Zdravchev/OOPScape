#include "Entity.h"

Entity::Entity(int x, int y)
{
    position.x = x;
    position.y = y;
}

Point Entity::getPosition() const
{
    return position;
}

int Entity::getX() const
{
    return position.x;
}

int Entity::getY() const
{
    return position.y;
}
