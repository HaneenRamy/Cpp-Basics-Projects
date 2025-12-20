#include <iostream>

using namespace std;

// Display the current state of the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "   1   2   3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2)
                cout << "|";
        }
        cout << endl;
        if (i < 2)
            cout << "  ---+---+---" << endl;
    }
    cout << endl;
}

// Check if the given player has won the game
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Check if the board is completely filled (tie condition)
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Initialize empty Tic-Tac-Toe board
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int row, col;
    char currentPlayer = 'X';

    // Main game loop
    while (true) {
        displayBoard(board);

        // Get player input
        cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3): ";
        cin >> row >> col;

        // Convert user input to 0-based index
        row--;
        col--;

        // Validate input and check if the selected cell is empty
        if (row < 0 || row > 2 || col < 0 || col > 2 ||  board[row][col] != ' ') {
            cout << "Invalid input! Try again." << endl;
            continue;
        }

        // Place the player's mark on the board
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for a tie
        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
