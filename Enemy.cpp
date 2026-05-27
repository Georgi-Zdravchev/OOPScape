#include "Enemy.h"
#include <vector>
#include <queue>

Enemy::Enemy(int x, int y) : Entity(x, y)
{
}

void Enemy::update(const Board& board, const Point& heroPos)
{
    moveTowardsHero(board,heroPos);
}

bool Enemy::moveTowardsHero(const Board& board, const Point& heroPos)
{
    int n = board.getSize();
    int W = n;

    std::vector<int> parent(W * W, -1);
    std::queue<Point> q;

    int start = position.y * W + position.x;
    int goal = heroPos.y * W + heroPos.x;

    parent[start] = start;
    q.push(position);

    const int dx[4] = { -1, 1, 0, 0 };
    const int dy[4] = { 0, 0, -1, 1 };

    bool found = false;

    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();

        int curIndex = cur.y * W + cur.x;

        if (curIndex == goal)
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (!board.isWalkable(nx, ny))
                continue;

            int ni = ny * W + nx;

            if (parent[ni] != -1)
                continue;

            parent[ni] = curIndex;
            q.push({ nx, ny });
        }
    }

    if (!found)
        return false;

    int cur = goal;

    while (parent[cur] != start && cur != start)
    {
        cur = parent[cur];
    }

    if (cur == start)
        return false;

    position.x = cur % W;
    position.y = cur / W;

    return true;
}
