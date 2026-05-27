#include "InputHelper.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

Point InputHelper::readCoordinates()
{
    while (true)
    {
        try
        {
            std::string line;
            std::getline(std::cin >> std::ws, line);

            std::stringstream ss(line);

            int x, y;

            if (!(ss >> x >> y))
            {
                throw std::invalid_argument("Invalid coordinates!");
            }

            std::string extra;

            if (ss >> extra)
            {
                throw std::invalid_argument("Too many arguments!");
            }

            return { x, y };
        }
        catch (const std::invalid_argument& )
        {
            std::cout << "Invalid coordinates. Enter again: ";
        }
    }
}

std::unique_ptr<Hero> InputHelper::chooseHero(const Point& start)
{
    while (true)
    {
       
        std::string choice;
        std::cin >> choice;

        std::unique_ptr<Hero> hero = HeroFactory::createHero(choice,start.x,start.y);

        if (hero)
        {
            return hero;
        }

        std::cout << "Invalid hero choice. Try again.\n";
    }
}

int InputHelper::chooseDifficulty()
{
    while (true)
    {
        std::string choice;
        std::cin >> choice;

        if (choice == "1")
        {
            return 1;
        }

        if (choice == "2")
        {
            return 2;
        }

        if (choice == "3")
        {
            return 3;
        }

        std::cout << "Invalid difficulty. Try again.\n";
    }
}
