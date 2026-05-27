#pragma once
#include "Point.h"
#include "Board.h"

class Entity
{
protected:
    Point position;

public:
    Entity(int x, int y);
    virtual ~Entity() = default;

    Point getPosition() const;

    int getX() const;
    int getY() const;

    virtual void update(const Board& board, const Point& entityPos) = 0;
};

