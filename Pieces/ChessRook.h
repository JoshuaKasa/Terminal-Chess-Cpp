#include <cmath>
#include <string>

using namespace std;

bool check_rook_collisions(int x1, int y1, int x2, int y2, string board[8][8])
{
    if (y1 == y2)
    {
        if (x1 < x2)
        {
            for (int i = x1 + 1; i < x2; i++)
            {
                if (board[y1][i] != ".")
                    return true;
            }
        }
        else if (x1 > x2)
        {
            for (int i = x1 - 1; i > x2; i--)
            {
                if (board[y1][i] != ".")
                    return true;
            }
        }
    }
    else if (x1 == x2)
    {
        if (y1 < y2)
        {
            for (int i = y1 + 1; i < y2; i++)
            {
                if (board[i][x1] != ".")
                    return true;
            }
        }
        else if (y1 > y2)
        {
            for (int i = y1 - 1; i > y2; i--)
            {
                if (board[i][x1] != ".")
                    return true;
            }
        }
    }

    return false;
}