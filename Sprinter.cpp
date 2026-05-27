#include "Sprinter.h"
#include <iostream>

Sprinter::Sprinter(int x, int y) : Hero(x,y)
{
}

bool Sprinter::useAbility(Board& board)
{
    const int RANGE = 3;

    int dx = 0, dy = 0;

    std::string choice;
    std::cout << "Choose direction (L/R/U/D): ";
    std::cin >> choice;

    for (char& c : choice)
    {
        c = toupper(c);
    }

    if (choice == "U") dy = -1;
    else if (choice == "D") dy = 1;
    else if (choice == "L") dx = -1;
    else if (choice == "R") dx = 1;
    else return false;

    int newX = position.x;
    int newY = position.y;

    for (int i = 0; i < RANGE; i++)
    {
        int nextX = newX + dx;
        int nextY = newY + dy;

        if (!board.isWalkable(nextX, nextY) && i == 0) {
           
            return false;
        }
        if (!board.isWalkable(nextX, nextY))
            break;

        newX = nextX;
        newY = nextY;
    }

    position.x = newX;
    position.y = newY;

    return true;
}

const std::string Sprinter::getType() const
{
	return "Sprinter";
}
