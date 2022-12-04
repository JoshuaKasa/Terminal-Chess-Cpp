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
    int i = 0, j = 0;
    for (int k = 0; k < code.length(); k++)
    {
        if (code[k] == '/')
        {
            i++;
            j = 0;
        }
        else if (code[k] >= '1' && code[k] <= '8')
        {
            for (int u = 0; u < code[k] - '0'; u++)
            {
                board[i][j] = ".";
                j++;
            }
        }
        else
        {
            board[i][j] = piece_from_code(code[k]);
            j++;
        }
    }
}

string encode_fen(string board[8][8])
{
    string code = "";
    for (int i = 0; i < 8; i++)
    {
        int empty_count = 0;
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == ".")
            {
                empty_count++;
            }
            else
            {
                if (empty_count > 0)
                {
                    code += to_string(empty_count);
                    empty_count = 0;
                }
                code += piece_to_code(board[i][j]);
            }
        }
        if (empty_count > 0)
        {
            code += to_string(empty_count);
        }
        code += "/";
    }
    code.erase(code.length() - 1);
    return code;
}