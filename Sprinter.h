#pragma once
#include "Hero.h"

class Sprinter : public Hero
{
public:
    Sprinter(int x, int y);

    bool useAbility(Board& board) override;
    const std::string getType() const override;
};