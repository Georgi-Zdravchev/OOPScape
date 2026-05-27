#include "HeroFactory.h"

std::unique_ptr<Hero> HeroFactory::createHero(const std::string& choice,int x,int y)
{
    if (choice == "1")
    {
        return std::make_unique<Wizard>(x, y);
    }
    else if (choice == "2")
    {
        return std::make_unique<Sprinter>(x, y);
    }
    else if (choice == "3")
    {
        return std::make_unique<WallBreaker>(x, y);
    }
    else {
        return nullptr;
    }
}
