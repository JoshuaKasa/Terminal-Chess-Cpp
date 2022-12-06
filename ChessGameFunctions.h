#include <algorithm>
#include <iostream>
#include "Pieces/ChessKing.h"
#include "PiecesFunctions.h"

using namespace std;

bool validate_turn(int turn, string piece_moved)
{
    if (turn == 0)
    {
        LOOPI (i, AS(BLACK_PIECES))
        {
            if (piece_moved == BLACK_PIECES[i])
                return false;
        }
        return true;
    }
    else if (turn == 1)
    {
        LOOPI (i, AS(WHITE_PIECES))
        {
            if (piece_moved == WHITE_PIECES[i])
                return false;
        }
        return true;
    }
    return true;
}

bool execute_move(string move, string board[8][8], int turn)
{
    move.erase(remove(move.begin(), move.end(), ' '), move.end());
    int x1 = LTN(move[0]) - 1;
    int y1 = 8 - ((int)move[1] - '0');
    int x2 = LTN(move[2]) - 1;
    int y2 = 8 - (int)(move[3] - '0');
    int piece = check_piece(tolower(move[4]));
    string moved_piece = board[y1][x1];

    if (board[y1][x1] == "." || is_piece(moved_piece) == false)
    {
        cout << "\nInvalid piece";
        return false;
    }

    if (validate_turn(turn, moved_piece) == true && check_target_pos(x2,y2, turn, board) == true)
    {
        if (is_king_threatened(board, turn) == false)
        {
            switch (piece)
            {
                // Pawn
                case 1:
                {
                    if (x1 == x2 && abs(y1 - y2) < 3 && abs(y1 - y2) > 0  && check_pawn_collisions(x1,y1, x2,y2, board) == false)
                    {
                        board[y1][x1] = ".";
                        board[y2][x2] = moved_piece;
                        return true;
                    }
                    else
                    {
                        cout << "\nMove not valid";
                        return false;
                    }
                }
                break;

                // Knight
                case 2:
                {
                    if (abs((x1 - x2) * (y1 - y2)) == 2)
                    {
                        board[y1][x1] = ".";
                        board[y2][x2] = moved_piece;
                        return true;
                    }
                    else
                    {
                        cout << "\nMove not valid";
                        return false;
                    }
                }
                break;

                // Bishop
                case 3:
                {
                    if (abs(x1 - x2) == abs(y1 - y2) && check_bishop_collisions(x1,y1, x2,y2, board) == false)
                    {
                        board[y1][x1] = ".";
                        board[y2][x2] = moved_piece;
                        return true;
                    }
                    else
                    {
                        cout << "\nMove not valid";
                        return false;
                    }
                }
                break;

                // Rook
                case 4:
                {
                    if ((x1 == x2 || y1 == y2) && check_rook_collisions(x1,y1, x2,y2, board) == false)
                    {
                        board[y1][x1] = ".";
                        board[y2][x2] = moved_piece;
                        return true;
                    }
                    else
                    {
                        cout << "\nMove not valid";
                        return false;
                    }
                }
                break;

                // Queen
                case 5:
                {
                    if (((abs(x1 - x2) == abs(y1 - y2)) || ((x1 == x2 || y1 == y2))) && check_queen_collisions(x1,y1, x2,y2, board) == false)
                    {
                        board[y1][x1] = ".";
                        board[y2][x2] = moved_piece;
                        return true;
                    }
                    else
                    {
                        cout << "\nMove not valid";
                        return false;
                    }
                }
                break;

                // King
                case 6:
                {
                    if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2 && piece_is_on_spot(x2,y2, board) == false)
                    {
                        board[y1][x1] = ".";
                        board[y2][x2] = moved_piece;
                        return true;
                    }
                    else
                    {
                        cout << "\nMove not valid";
                        return false;
                    }
                }
                break;
            }
        }
        else
        {
            if (piece_can_block(board, x1,y1, x2,y2, turn) == true)
            {
                board[y1][x1] = ".";
                board[y2][x2] = moved_piece;
                return true;
            }
            else
            {
                cout << "\nPiece can't block";
                return false;
            }
            cout << "\nKing is threatened";
            return false;
        }
    }
    cout << "\nMove not valid";
    return false;
}

int switch_turn(int turn)
{
    return !turn;
}