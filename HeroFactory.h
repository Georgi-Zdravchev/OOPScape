#pragma once
#include <memory>
#include <string>
#include "Hero.h"
#include "Wizard.h"
#include "Sprinter.h"
#include "WallBreaker.h"
#include <stdexcept>


class HeroFactory
{
public:
	static std::unique_ptr<Hero> createHero(const std::string& choice,int x,int y);
};

