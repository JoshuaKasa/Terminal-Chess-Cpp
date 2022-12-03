#include <cmath>
#include <string>

using namespace std;

bool check_pawn_collisions(int x1, int y1, int x2, int y2, string board[8][8])
{
    int y_diff = abs(y1 - y2);

    if (y_diff == 1)
    {
        if (board[y2][x2] != ".")
            return true;
        else
            return false;
    }
    else if (y_diff == 2)
    {
        if (board[y2][x2] != "." || board[y1-1][x1] != ".")
            return true;
        else
            return false;
    }
    else return false;
}