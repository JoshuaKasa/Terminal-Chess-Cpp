#include <cmath>
#include <string>

using namespace std;

bool check_knight_collisions(int x1, int y1, int x2, int y2, string board[8][8])
{
    int x_diff = x1 - x2;
    int y_diff = y1 - y2;

    if (abs(x_diff) == 2 && abs(y_diff) == 1)
    {
        return false;
    }
    else if (abs(x_diff) == 1 && abs(y_diff) == 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}