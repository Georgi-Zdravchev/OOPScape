#pragma once

#include <vector>
#include <string>
#include "Point.h"

class Board
{
private:
    static constexpr int MIN_SIZE = 2;
    static constexpr int MAX_SIZE = 64;

    std::vector<std::string> grid;
    int size;

    Point heroStart;
    Point finish;

    std::vector<Point> enemies;

public:
    Board(const std::string& filename);

    void loadFromFile(const std::string& filename);

    void print() const;

    bool isWalkable(int x, int y) const;

    int getSize() const;

    const Point& getHeroStart() const;
    const Point& getFinish() const;

    const std::vector<Point>& getEnemies() const;

    char getCell(int x, int y) const;
    void setCell(int x, int y, char symbol);
};