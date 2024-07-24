#include <iostream>
#include <vector>

void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "+---+---+---+\n";
    for (size_t i = 0; i < board.size(); ++i) {
        std::cout << "| ";
        for (size_t j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n";
        if (i < board.size() - 1) {
            std::cout << "+---+---+---+\n";
        }
    }
    std::cout << "+---+---+---+\n";
}

char checkWin(const std::vector<std::vector<char>>& board) {
    // Проверка строк
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return board[i][0];
        }
    }

    // Проверка столбцов
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return board[0][i];
        }
    }

    // Проверка диагоналей
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return board[0][2];
    }

    // Если нет победителя
    return '-';
}

bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

void ticTacToe()
{
    std::vector<std::vector<char>> board = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    std::vector<std::vector<char>> boardCopy = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    bool gameOver = false;
    bool firstPlayerMoved = false;
    char playerFirst = 'X';
    char playerSecond = 'Y';

    while (true)
    {
        printBoard(board);
        int pointX, pointY;
        std::cout << "The turn of " << (firstPlayerMoved ? '2' : '1') << " player\n";
        std::cin >> pointX >> pointY;
        if (pointX == 999) break;
        if (pointX > 3 || pointX < 0 || pointY > 3 || pointY < 0)
        {
            std::cout << "Wrond point!\n";
            continue;
        }
        if (board[pointX - 1][pointY - 1] == '-')
        {
            board[pointX - 1][pointY - 1] = firstPlayerMoved ? playerSecond : playerFirst;
            firstPlayerMoved = firstPlayerMoved ? false : true;
        }
        else
        {
            std::cout << "This field is already occupied!\n";
            continue;
        }
        char winner = checkWin(board);
        if (winner != '-')
        {
            if (isBoardFull(board))
            {
                std::cout << "Tie!\n";
                board.clear();
                board = boardCopy;
                firstPlayerMoved = false;
            }
            else
            {
                std::cout << (winner == playerFirst ? "First" : "Second") << " player win!\n";
                board.clear();
                board = boardCopy;
                firstPlayerMoved = false;
            }
        }
    }
}

int main() {
    ticTacToe();

    return 0;
}