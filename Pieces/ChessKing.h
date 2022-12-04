#include "ChessPawn.h"
#include "ChessKnigth.h"
#include "ChessBishop.h"
#include "ChessRook.h"
#include "ChessQueen.h"
#include "../ChessPieces.h"

bool is_king_threatened(string board[8][8], int turn)
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
            if (board[i][j] != "." && board[i][j] != king_piece)
            {
                if (board[i][j] == PIECES[turn * 6 + 5])
                {
                    if (check_pawn_collisions(i,j, king_x,king_y, board) == true)
                    {
                        return true;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 4])
                {
                    if (check_knight_collisions(i,j, king_x + 1,king_y + 1, board) == true)
                    {
                        return true;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 3])
                {
                    if (check_bishop_collisions(i,j, king_x + 1,king_y + 1, board) == true)
                    {
                        return true;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 2])
                {
                    if (check_rook_collisions(i,j, king_x,king_y, board) == true)
                    {
                        return true;
                    }
                }
                else if (board[i][j] == PIECES[turn * 6 + 1])
                {
                    if (check_queen_collisions(i,j, king_x,king_y, board) == true)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool piece_can_block(string board[8][8], int x1, int y1, int x2, int y2, int turn)
{
    string piece = board[y1][x1];
    string target_piece = board[y2][x2];
    board[y1][x1] = ".";
    board[y2][x2] = piece;

    if (is_king_threatened(board, turn) == true)
    {
        board[y1][x1] = piece;
        board[y2][x2] = target_piece;
        return false;
    }

    board[y1][x1] = piece;
    board[y2][x2] = target_piece;
    return true;
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