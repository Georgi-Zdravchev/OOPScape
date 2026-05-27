#pragma once
#include "Board.h"
#include "Wizard.h"
#include "Enemy.h"
#include "Sprinter.h"
#include "HeroFactory.h"
#include <memory>
#include <vector>
#include "ConsoleUtils.h"

class Game
{
private:
    Board board;
    std::unique_ptr<Hero> hero = nullptr;
    std::vector<Enemy> enemies;
    bool running;
    bool showingTeleportRange = false;
    int difficulty;

    bool isTeleportCell(int x, int y) const;

    void render() const;
    void processInput();
    void updateEnemies();
    void checkWin();
    void checkLose();
public:
    Game(const std::string& levelFile);

    void run();
};