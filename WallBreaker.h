#pragma once
#include "Hero.h"
#include "InputHelper.h"

class WallBreaker : public Hero
{
public:
    WallBreaker(int x, int y);

    bool useAbility(Board& board) override;
    const std::string getType() const override;
};