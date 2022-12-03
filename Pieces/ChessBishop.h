#include <cmath>
#include <string>

using namespace std;

bool check_bishop_collisions(int x1, int y1, int x2, int y2, string board[8][8])
{
    int x_diff = x2 - x1;
    int y_diff = y2 - y1;

    if (x_diff > 0 && y_diff > 0)
    {
        for (int i = 1; i < x_diff; i++)
        {
            if (board[y1 + i][x1 + i] != ".")
                return true;
        }
    }
    else if (x_diff < 0 && y_diff > 0)
    {
        for (int i = 1; i < abs(x_diff); i++)
        {
            if (board[y1 + i][x1 - i] != ".")
                return true;
        }
    }
    else if (x_diff > 0 && y_diff < 0)
    {
        for (int i = 1; i < abs(y_diff); i++)
        {
            if (board[y1 - i][x1 + i] != ".")
                return true;
        }
    }
    else if (x_diff < 0 && y_diff < 0)
    {
        for (int i = 1; i < abs(x_diff); i++)
        {
            if (board[y1 - i][x1 - i] != ".")
                return true;
        }
    }

    return false;
}