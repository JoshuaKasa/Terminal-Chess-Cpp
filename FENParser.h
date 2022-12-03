void print_board(string board[8][8], int board_size)
{
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    cout << "\n\n";
    LOOPI (i, board_size)
    {
        cout << board_size - i << " ";
        LOOPI (j, board_size)
        {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "  ";
    LOOPI (i, board_size)
    {
        cout << letters[i] << "  ";
    }
}

void decode_fen(string code, string board[8][8])
{
    int row = 7;
    int col = 0;

    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == '/')
        {
            row--;
            col = 0;
        }
        else if (isdigit(code[i]))
        {
            int num = code[i] - '0';
            for (int j = 0; j < num; j++)
            {
                board[row][col] = ".";
                col++;
            }
        }
        else
        {
            board[row][col] = piece_from_code(code[i]);
            col++;
        }
    }
}