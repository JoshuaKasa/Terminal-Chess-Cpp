#include "ChessPawn.h"
#include "ChessKnigth.h"
#include "ChessBishop.h"
#include "ChessRook.h"
#include "ChessQueen.h"
#include "../ChessPieces.h"

bool is_king_threatened(string board[8][8], int turn) // white = 1 black = 0
{
    int king_x, king_y;
    string king_piece;
    if (turn == 1)
    {
        king_piece = "♚";
    }
    else
    {
        king_piece = "♔";
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == king_piece)
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
            if (board[i][j] != ".")
            {
                if (board[i][j] == PIECES[turn * 6])
                {
                    continue;
                }
                else if (board[i][j] == PIECES[turn * 6 + 2])
                {
                    if (check_rook_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 3])
                {
                    if (check_bishop_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 1])
                {
                    if (check_queen_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 4])
                {
                    if (check_knight_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 5])
                {
                    if (check_pawn_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool piece_can_block(string board[8][8], int x1, int y1, int x2, int y2, int turn)
{
    int x_diff = x2 - x1;
    int y_diff = y2 - y1;
    int x_dir = x_diff / abs(x_diff);
    int y_dir = y_diff / abs(y_diff);
    int x_pos = x1 + x_dir;
    int y_pos = y1 + y_dir;
    string piece = board[y1][x1];
    string target_piece = board[y2][x2];
    string temp_piece = board[y2][x2];
    board[y2][x2] = ".";
    board[y1][x1] = ".";

    while (x_pos != x2 || y_pos != y2)
    {
        if (is_king_threatened(board, turn) == false)
        {
            board[y1][x1] = piece;
            board[y2][x2] = temp_piece;
            return true;
        }
        x_pos += x_dir;
        y_pos += y_dir;
    }
    board[y1][x1] = piece;
    board[y2][x2] = temp_piece;

    return false;
}

bool king_is_checkmate(string board[8][8], int turn)
{
    int king_x, king_y;
    string king_piece;

    if (turn == 1)
    {
        king_piece = "♔";
    }
    else
    {
        king_piece = "♚";
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == king_piece)
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
            if (board[i][j] != ".")
            {
                if (board[i][j] == PIECES[turn * 6])
                {
                    continue;
                }
                else if (board[i][j] == PIECES[turn * 6 + 2])
                {
                    if (check_rook_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 3])
                {
                    if (check_bishop_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 1])
                {
                    if (check_queen_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 4])
                {
                    if (check_knight_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 5])
                {
                    if (check_pawn_collisions(i, j, king_x, king_y, board) == false)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}