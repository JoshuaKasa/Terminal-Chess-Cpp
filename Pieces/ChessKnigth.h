#include <cmath>
#include <string>

using namespace std;

bool check_knight_collisions(int x1, int y1, int x2, int y2, string board[8][8])
{
    if (abs((x1 - x2) * (y1 - y2)) == 2)
    {
        return false;
    }
    return true;
}