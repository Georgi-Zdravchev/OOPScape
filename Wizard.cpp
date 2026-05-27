#include "Wizard.h"
#include <iostream>
#include <cstdlib>

Wizard::Wizard(int x, int y) : Hero(x, y)
{
}

bool Wizard::useAbility(Board& board)
{
    const int RANGE = 2;

    std::cout << "Enter teleport coordinates (x y) that are in the highlighted range: ";
    
    Point target = InputHelper::readCoordinates();

    int targetX = target.x;
    int targetY = target.y;

    int dx = std::abs(targetX - position.x);
    int dy = std::abs(targetY - position.y);

    if (dx > RANGE || dy > RANGE)
    {
        std::cout << "Target is out of range!\n";
        return false;
    }

    if (!board.isWalkable(targetX, targetY))
    {
        std::cout << "Cannot teleport there!\n";
        return false;
    }

    position.x = targetX;
    position.y = targetY;

    return true;
}

const std::string Wizard::getType() const
{
    return "Wizard";
}
