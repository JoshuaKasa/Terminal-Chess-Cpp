#include <cmath>
#include <string>

using namespace std;

bool check_queen_collisions(int x1, int y1, int x2, int y2, string board[8][8])
{
    if (abs(x1 - x2) == abs(y1 - y2))
    {
        if (x1 < x2 && y1 < y2)
        {
            for (int i = 1; i < abs(x1 - x2); i++)
            {
                if (board[y1 + i][x1 + i] != ".")
                {
                    return true;
                }
            }
        }
        else if (x1 > x2 && y1 > y2)
        {
            for (int i = 1; i < abs(x1 - x2); i++)
            {
                if (board[y1 - i][x1 - i] != ".")
                {
                    return true;
                }
            }
        }
        else if (x1 < x2 && y1 > y2)
        {
            for (int i = 1; i < abs(x1 - x2); i++)
            {
                if (board[y1 - i][x1 + i] != ".")
                {
                    return true;
                }
            }
        }
        else if (x1 > x2 && y1 < y2)
        {
            for (int i = 1; i < abs(x1 - x2); i++)
            {
                if (board[y1 + i][x1 - i] != ".")
                {
                    return true;
                }
            }
        }
    }
    else if (x1 == x2)
    {
        if (y1 < y2)
        {
            for (int i = 1; i < abs(y1 - y2); i++)
            {
                if (board[y1 + i][x1] != ".")
                {
                    return true;
                }
            }
        }
        else if (y1 > y2)
        {
            for (int i = 1; i < abs(y1 - y2); i++)
            {
                if (board[y1 - i][x1] != ".")
                {
                    return true;
                }
            }
        }
    }
    else if (y1 == y2)
    {
        if (x1 < x2)
        {
            for (int i = 1; i < abs(x1 - x2); i++)
            {
                if (board[y1][x1 + i] != ".")
                {
                    return true;
                }
            }
        }
        else if (x1 > x2)
        {
            for (int i = 1; i < abs(x1 - x2); i++)
            {
                if (board[y1][x1 - i] != ".")
                {
                    return true;
                }
            }
        }
    }
    return false;
}
