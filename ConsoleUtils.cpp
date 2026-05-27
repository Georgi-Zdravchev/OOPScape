#include "ConsoleUtils.h"

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printColored(const std::string& s, int color)
{
    setColor(color);
    std::cout << s;
    setColor(7);
}