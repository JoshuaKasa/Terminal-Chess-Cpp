#include "ChessPawn.h"
#include "ChessKnigth.h"
#include "ChessBishop.h"
#include "ChessRook.h"
#include "ChessQueen.h"
#include "../ChessPieces.h"

bool is_king_threatened(string board[8][8], int turn)
{
    int king_x, king_y;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == PIECES[!turn * 6])
            {
                king_x = i;
                king_y = j;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == PIECES[turn * 6 + 1])
            {
                // Checking if queen move is valid
                if (check_queen_collisions(i, j, king_x, king_y, board) == false && (abs(i - king_x) == abs(j - king_y) || i == king_x || j == king_y))
                    return true;
            }
            else if (board[i][j] == PIECES[turn * 6 + 2])
            {
                if (check_rook_collisions(i, j, king_x, king_y, board) == false && (i == king_x || j == king_y))
                    return true;
            }
            else if (board[i][j] == PIECES[turn * 6 + 3])
            {
                if (check_bishop_collisions(i, j, king_x, king_y, board) == false && abs(i - king_x) == abs(j - king_y))
                    return true;
            }
            else if (board[i][j] == PIECES[turn * 6 + 4])
            {
                if (check_knight_collisions(i, j, king_x, king_y, board) == false && abs((i - king_x) * (j - king_y)) == 2)
                    return true;
            }
            else if (board[i][j] == PIECES[turn * 6 + 5] && abs(i - king_x) < 2 && abs(j - king_y) < 2)
            {
                return true;
            }
        }
    }
    return false;
}

bool piece_can_block(string board[8][8], int x1, int y1, int x2, int y2, int turn)
{
    string piece = board[y1][x1];
    board[y1][x1] = ".";
    board[y2][x2] = piece;

    if (is_king_threatened(board, turn) == false)
    {
        board[y1][x1] = piece;
        board[y2][x2] = ".";
        return true;
    }

    board[y1][x1] = piece;
    board[y2][x2] = ".";
    return false;
}