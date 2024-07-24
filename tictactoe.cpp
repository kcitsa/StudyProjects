#include <iostream>
#include <vector>

// Constants for board dimensions and players
const int BOARD_SIZE = 3;
const char EMPTY_CELL = '-';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "+---+---+---+\n";
    for (size_t i = 0; i < board.size(); ++i) {
        std::cout << "| ";
        for (size_t j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n+---+---+---+\n";
    }
}

char checkWin(const std::vector<std::vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY_CELL) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY_CELL) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY_CELL) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY_CELL) {
        return board[0][2];
    }

    // No winner
    return EMPTY_CELL;
}

bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == EMPTY_CELL) {
                return false;
            }
        }
    }
    return true;
}

void resetBoard(std::vector<std::vector<char>>& board) {
    for (auto& row : board) {
        std::fill(row.begin(), row.end(), EMPTY_CELL);
    }
}

void ticTacToe() {
    std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, EMPTY_CELL));
    bool firstPlayerTurn = true;
    char currentPlayer;

    while (true) {
        printBoard(board);
        currentPlayer = firstPlayerTurn ? PLAYER_X : PLAYER_O;
        std::cout << "The turn of player " << (firstPlayerTurn ? '1' : '2') << " (" << currentPlayer << ")\n";
        
        int pointX, pointY;
        std::cin >> pointX >> pointY;

        // Exit condition
        if (pointX == 999) break;

        // Validate input
        if (pointX < 1 || pointX > BOARD_SIZE || pointY < 1 || pointY > BOARD_SIZE) {
            std::cout << "Invalid input! Please enter coordinates between 1 and " << BOARD_SIZE << ".\n";
            continue;
        }

        // Adjust for 0-based index
        pointX--;
        pointY--;

        // Check if cell is empty
        if (board[pointX][pointY] == EMPTY_CELL) {
            board[pointX][pointY] = currentPlayer;
            firstPlayerTurn = !firstPlayerTurn;
        } else {
            std::cout << "This cell is already occupied!\n";
            continue;
        }

        // Check for a winner
        char winner = checkWin(board);
        if (winner != EMPTY_CELL) {
            printBoard(board);
            std::cout << "Player " << (winner == PLAYER_X ? '1' : '2') << " (" << winner << ") wins!\n";
            resetBoard(board);
            firstPlayerTurn = true;
        } else if (isBoardFull(board)) {
            printBoard(board);
            std::cout << "It's a tie!\n";
            resetBoard(board);
            firstPlayerTurn = true;
        }
    }
}

int main() {
    ticTacToe();
    return 0;
}
