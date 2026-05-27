#include "WallBreaker.h"

WallBreaker::WallBreaker(int x, int y) : Hero(x,y)
{
}

bool WallBreaker::useAbility(Board& board)
{
	bool brokeWall = false;

	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
    {
        int newX = position.x + dx[i];
        int newY = position.y + dy[i];

        if (board.getCell(newX, newY) == '*')
        {
            board.setCell(newX, newY, ' ');
            brokeWall = true;
        }
    }
    return brokeWall;
}

const std::string WallBreaker::getType() const
{
	return "WallBreaker";
}
