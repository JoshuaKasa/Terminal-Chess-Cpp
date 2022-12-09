#include "ChessGameFunctions.h"
#include "FENParser.h"

using namespace std;

int main()
{
    // Creating board
    string board[8][8] = {};
    int board_size = AS(board);
    int turn = 1; // 0 = black      1 = white

    decode_fen("rnb1kbnr/pppppppp/8/8/8/2qP4/PPP1PPPP/RNBQKBNR",board);
    print_board(board, board_size);

    // Getting move
    EL
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
        }
        else
            print_board(board, board_size);

        if (move == "exit") break;
    }
}