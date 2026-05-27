#pragma once
#include "Hero.h"
#include "InputHelper.h"

class Wizard : public Hero
{
public:
    Wizard(int x, int y);

    bool useAbility(Board& board) override;
    const std::string getType() const override;
};