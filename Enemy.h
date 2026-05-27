#pragma once
#include "Entity.h"
#include "Board.h"

class Enemy : public Entity
{
public:
    Enemy(int x, int y);

    void update(const Board& board, const Point& entityPos) override;

private:
    bool moveTowardsHero(const Board& board, const Point& entityPos);
};