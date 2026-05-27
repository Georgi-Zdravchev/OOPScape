#include "Hero.h"

Hero::Hero(int x, int y) : Entity(x, y)
{
}

bool Hero::move(const std::string& command, Board& board)
{
    int newX = position.x;
    int newY = position.y;

    if (command == "U")
    {
        newY--;
    }
    else if (command == "D")
    {
        newY++;
    }
    else if (command == "L")
    {
        newX--;
    }
    else if (command == "R")
    {
        newX++;
    }
    else if (command == "OOP")
    {
        return useAbility(board);
    }
    else
    {
        return false;
    }

    if (!board.isWalkable(newX, newY))
    {
        return false;
    }

    position.x = newX;
    position.y = newY;

    return true;
}

void Hero::update(const Board& board, const Point& HeroPos) {}