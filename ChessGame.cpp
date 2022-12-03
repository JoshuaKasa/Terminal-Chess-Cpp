#include "ChessGameFunctions.h"
#include "FENParser.h"

using namespace std;

int main()
{
    // Creating board
    string board[8][8] = {};
    int board_size = AS(board);
    int turn = 1; // 0 = black      1 = white

    decode_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR",board);
    print_board(board, board_size);

    // Getting move
    while (1 == 1)
    {
        string move;
        cout << "\n\n";
        (turn == 1) ? cout << "White's turn" : cout << "Black's turn";
        cout << "\nWhat's your move? ";
        getline(cin, move);

        if (execute_move(move, board, turn) == true)
        {
            execute_move(move, board, turn);
            print_board(board, board_size);
            turn = switch_turn(turn);
            if (king_is_checkmate(board, turn) == true)
            {
                cout << "\nCheckmate!";
                break;
            }
        }
        else
            print_board(board, board_size);
    }

    return 0;
}