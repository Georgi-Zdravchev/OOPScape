#pragma once
#include "Entity.h"
#include "Board.h"

class Hero : public Entity
{
public:
    Hero(int x, int y);
    ~Hero() = default;

    bool move(const std::string& command,Board& board);

    void update(const Board& board, const Point& entityPos) override;

    virtual bool useAbility(Board& board) = 0;
    virtual const std::string getType() const = 0;
};