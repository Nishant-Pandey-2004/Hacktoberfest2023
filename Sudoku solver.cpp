 void solveSudoku(vector<vector<char>>& board) {
        stack<pair<int, int>> emptyCells;

        // Find and store the indices of empty cells in the stack
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.push({i, j});
                }
            }
        }

        int index = 0;

        while (!emptyCells.empty()) {
            int row = emptyCells.top().first;
            int col = emptyCells.top().second;
            emptyCells.pop();

            bool found = false;

            for (char c = '1'; c <= '9'; c++) {
                if (issafe(board, row, col, c)) {
                    board[row][col] = c;
                    found = true;
                    break;
                }
            }

            if (!found) {
                board[row][col] = '.';  // Reset cell value
                index--;
                while (index < 0) {
                    index = emptyCells.size() - 1;
                    if (index < 0) break;
                    row = emptyCells.top().first;
                    col = emptyCells.top().second;
                    emptyCells.pop();
                    board[row][col] = '.';
                }
            } else {
                index = emptyCells.size() - 1;
            }
        }
    }


    bool issafe(vector<vector<char>>& board, int row, int col, char val) {
        // Check row, column, and 3x3 subgrid
        int toprow = row - row % 3;
        int topcol = col - col % 3;

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val || board[i][col] == val || board[toprow + i / 3][topcol + i % 3] == val) {
                return false;
            }
        }
        return true;
    }