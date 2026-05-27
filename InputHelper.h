#pragma once

#include "Point.h"
#include <memory>
#include "Hero.h"
#include "HeroFactory.h"

class InputHelper
{
public:
    static Point readCoordinates();
    static std::unique_ptr<Hero> chooseHero(const Point& start);
    static int chooseDifficulty();
};