#include "Constants.h"

using namespace std;

int check_piece(char piece)
{
    switch (piece)
    {
        case 'k': return 6; break;
        case 'q': return 5; break;
        case 'r': return 4; break;
        case 'b': return 3; break;
        case 'n': return 2; break;
        case 'p': return 1; break;
    }
}

int piece_is_on_spot(int x, int y, string board[8][8])
{
    return board[y][x] != ".";
}

int white_piece_is_on_spot(int x, int y, string board[8][8])
{
    string piece = board[y][x];

    LOOPI (i, AS(BLACK_PIECES))
    {
        if (piece == BLACK_PIECES[i])
            return true;
    }

    return false;
}

int black_piece_is_on_spot(int x, int y, string board[8][8])
{
    string piece = board[y][x];

    LOOPI (i, AS(WHITE_PIECES))
    {
        if (piece == WHITE_PIECES[i])
            return true;
    }

    return false;
}

string piece_from_code(char piece)
{
    switch (piece)
    {
        case 'K': return "♔"; break;
        case 'Q': return "♕"; break;
        case 'R': return "♖"; break;
        case 'B': return "♗"; break;
        case 'N': return "♘"; break;
        case 'P': return "♙"; break;

        case 'k': return "♚"; break;
        case 'q': return "♛"; break;
        case 'r': return "♜"; break;
        case 'b': return "♝"; break;
        case 'n': return "♞"; break;
        case 'p': return "♟"; break;
    }
}

bool check_target_pos(int x, int y, int turn, string board[8][8])
{
    string target_pos = board[y][x];

    if (turn == 1)
    {
        if (white_piece_is_on_spot(x,y, board) == true)
            return false;
        return true;
    }
    else if (turn == 0)
    {
        if (black_piece_is_on_spot(x,y, board) == true)
            return false;
        return true;
    }
}

bool is_piece(string str)
{
    for (short int i = 0; i < AS(PIECES); i++)
    {
        if (str == PIECES[i]) return true;
    }
    return false;
}