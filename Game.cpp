#include "Game.h"
#include <iostream>

Game::Game(const std::string& levelFile)
    : board(levelFile), running(true)
{
    Point start = board.getHeroStart();

    std::cout << "Choose hero:\n";
    std::cout << "1. Wizard(Special ability: teleportation)\n";
    std::cout << "2. Sprinter(Special ability: dash)\n";
    std::cout << "3. WallBreaker(Special ability: breaks all adjacent walls)\n";

    hero = InputHelper::chooseHero(
        board.getHeroStart());

    for (const Point& p : board.getEnemies())
    {
        enemies.emplace_back(p.x, p.y);
    }
    std::cout << "Choose difficulty:\n";
    std::cout << "1. Easy(Enemy moves 1 square.)\n";
    std::cout << "2. Medium(Enemy moves 2 squares.)\n";
    std::cout << "3. Hard(Enemy moves 3 squares.)\n";

    difficulty = InputHelper::chooseDifficulty();
}

void Game::run()
{
    while (running)
    {
        system("cls");

        render();

        processInput();

        checkWin();
        if (!running) break;

        checkLose();
    }
}

bool Game::isTeleportCell(int x, int y) const
{
    const int RANGE = 2;

    int dx = abs(hero->getX() - x);
    int dy = abs(hero->getY() - y);

    if (dx > RANGE || dy > RANGE)
        return false;

    if (!board.isWalkable(x, y))
        return false;

    return true;
}

void Game::processInput()
{
    while (true) {
        std::cout << "Command (L/R/U/D or OOP):";
        std::string cmd;
        std::cin >> cmd;

        for (char& c : cmd)
        {
            c = toupper(c);
        }

        if (cmd == "OOP")
        {
            if (hero->getType() == "Wizard") {
                showingTeleportRange = true;
                render();
                showingTeleportRange = false;
            }

        }
        
        bool moved = hero->move(cmd, board);

        if (!moved)
        {
            printColored("Invalid move! Try again.\n",12);
        }
        else {
            updateEnemies();
            break;
        }
    }
}

void Game::updateEnemies()
{
    Point heroPos = hero->getPosition();
    for (int i = 0; i < difficulty; i++) {
        for (Enemy& e : enemies)
        {
            e.update(board, heroPos);
        }
    }
}

void Game::checkWin()
{
    Point h = hero->getPosition();
    Point f = board.getFinish();

    if (h.x == f.x && h.y == f.y)
    {
        printColored("YOU WIN!\n", 10);
        running = false;
    }
}

void Game::checkLose()
{
    Point h = hero->getPosition();

    for (Enemy& e : enemies)
    {
        Point ep = e.getPosition();

        if (ep.x == h.x && ep.y == h.y)
        {
            printColored("YOU LOSE!\n", 12);
            running = false;
        }
    }
}

void Game::render() const
{
    std::cout << "Y/X";
    for (int x = 0; x < board.getSize(); x++)
    {
        if (x < 10) std::cout << ' ' << x << ' ';
        else std::cout << ' ' << x;
    }
    std::cout << std::endl << "   ";
    for (int x = 0; x < board.getSize(); x++)
    {
        printColored("---",9);
    }
    std::cout << "\n";
    for (int y = 0; y < board.getSize(); y++)
    {
        std::cout << y;
        if(y<10) printColored(" | ", 9);
        else printColored("| ", 9);
        for (int x = 0; x < board.getSize(); x++)
        {
            char c = board.getCell(x, y);

            Point h = hero->getPosition();
            if (h.x == x && h.y == y)
            {
                printColored("H  ", 10);
                continue;
            }

            bool enemyHere = false;

            for (const Enemy& e : enemies)
            {
                if (e.getX() == x && e.getY() == y)
                {
                    enemyHere = true;
                    break;
                }
            }

            if (enemyHere)
            {
                printColored("E  ", 12);
                continue;
            }

            else if (showingTeleportRange && isTeleportCell(x, y))
            {
                setColor(32);
                std::cout << "   ";
                setColor(7);
                continue;
            }

            std::cout << c << "  ";
        }
        std::cout << "\n";
    }
}