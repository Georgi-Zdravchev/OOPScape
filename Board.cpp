#include "Board.h"

#include <iostream>
#include <fstream>
#include <stdexcept>



Board::Board(const std::string& filename)
{
    loadFromFile(filename);
}

void Board::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open level file!");
    }

    file >> size;
    file.ignore();

    if (size < MIN_SIZE || size > MAX_SIZE)
    {
        throw std::runtime_error("Invalid board size!");
    }

    grid.clear();
    enemies.clear();

    int startCount = 0;
    int finishCount = 0;

    for (int row = 0; row < size; row++)
    {
        std::string line;
        std::getline(file, line);

        if (line.length() != size)
        {
            throw std::runtime_error("Invalid row length!");
        }

        for (int col = 0; col < size; col++)
        {
            char c = line[col];

            if (c != '*' &&
                c != ' ' &&
                c != 'S' &&
                c != 'F' &&
                c != 'E')
            {
                throw std::runtime_error("Invalid symbol in level!");
            }

            if (c == 'S')
            {
                heroStart = { col, row };
                startCount++;
                line[col] = ' ';
            }

            if (c == 'F')
            {
                finish = { col, row };
                finishCount++;
            }

            if (c == 'E')
            {
                enemies.push_back({ col, row });
                line[col] = ' ';
            }
        }

        grid.push_back(line);
    }

    if (startCount != 1)
    {
        throw std::runtime_error("Level must contain exactly one S!");
    }

    if (finishCount != 1)
    {
        throw std::runtime_error("Level must contain exactly one F!");
    }
}

void Board::print() const
{
    for (const std::string& row : grid)
    {
        std::cout << row << std::endl;
    }
}

bool Board::isWalkable(int x, int y) const
{
    if (x < 0 || y < 0 || x >= size || y >= size)
    {
        return false;
    }

    return grid[y][x] != '*';
}

int Board::getSize() const
{
    return size;
}

const Point& Board::getHeroStart() const
{
    return heroStart;
}

const Point& Board::getFinish() const
{
    return finish;
}

const std::vector<Point>& Board::getEnemies() const
{
    return enemies;
}

char Board::getCell(int x, int y) const
{
    return grid[y][x];
}

void Board::setCell(int x, int y, char symbol)
{
    grid[y][x] = symbol;
}