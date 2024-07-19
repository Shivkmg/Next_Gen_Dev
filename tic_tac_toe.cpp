#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    int moves;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        moves = 0;
    }

    void displayBoard() {
        cout << "  0 1 2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "  -----\n";
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        moves++;
        return true;
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool isDraw() {
        return moves == 9;
    }

    void reset() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        moves = 0;
    }

    void play() {
        int row, col;
        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }
                if (isDraw()) {
                    displayBoard();
                    cout << "The game is a draw!\n";
                    break;
                }
                switchPlayer();
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }
    }

    bool playAgain() {
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        return choice == 'y' || choice == 'Y';
    }
};

int main() {
    TicTacToe game;
    do {
        game.play();
        game.reset();
    } while (game.playAgain());

    return 0;
}