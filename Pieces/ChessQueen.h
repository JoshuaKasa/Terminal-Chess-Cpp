#include <cmath>
#include <string>

using namespace std;

bool check_queen_collisions(int x1, int y1, int x2, int y2, string board[8][8])
{
    if (check_rook_collisions(x1, y1, x2, y2, board) == true || check_bishop_collisions(x1, y1, x2, y2, board) == true)
        return true;
    else
        return false;
}