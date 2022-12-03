#include <cmath>
#include <string>

using namespace std;

bool check_queen_collisions(int x1,int y1, int x2,int y2, string board[8][8])
{
    int x_diff = x1 - x2;
    int y_diff = y1 - y2;

    if (x_diff == 0)
    {
        if (y_diff > 0)
        {
            for (int i = 1; i < y_diff; i++)
            {
                if (board[y1 - i][x1] != ".")
                    return true;
            }
            return false;
        }

        else if (y_diff < 0)
        {
            for (int i = 1; i < abs(y_diff); i++)
            {
                if (board[y1 + i][x1] != ".")
                    return true;

                return false;
            }
        }
    }
    else if (y_diff == 0)
    {
        if (x_diff > 0)
        {
            for (int i = 1; i < x_diff; i++)
            {
                if (board[y1][x1 - i] != ".")
                    return true;

                return false;
            }
        }
        else if (x_diff < 0)
        {
            for (int i = 1; i < abs(x_diff); i++)
            {
                if (board[y1][x1 + i] != ".")
                    return true;

                return false;
            }
        }
    }
    else if ((abs(x_diff) == abs(y_diff)) && x_diff > 0 && y_diff > 0)
    {
        for (int i = 1; i < x_diff; i++)
        {
            if (board[y1 - i][x1 - i] != ".")
                return true;

            return false;
        }
    }
    else if ((abs(x_diff) == abs(y_diff)) && x_diff > 0 && y_diff < 0)
    {
        for (int i = 1; i < x_diff; i++)
        {
            if (board[y1 + i][x1 - i] != ".")
                return true;

            return false;
        }
    }
    else if ((abs(x_diff) == abs(y_diff)) && x_diff < 0 && y_diff > 0)
    {
        for (int i = 1; i < abs(x_diff); i++)
        {
            if (board[y1 - i][x1 + i] != ".")
                return true;

            return false;
        }
    }
    else if ((abs(x_diff) == abs(y_diff)) && x_diff < 0 && y_diff < 0)
    {
        for (int i = 1; i < abs(x_diff); i++)
        {
            if (board[y1 +i][x1 +i] != ".")
                return true;

            return false;
        }
    }
}