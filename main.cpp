#include "Game.h"
#include <iostream>

int main()
{
    try {
        Game game("Levels/level3.txt");
        game.run();
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << "\n";
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}