#include <iostream>
#include <cstdlib>
using namespace std;

char gameBoard[10] = {'0','1','2','3','4','5','6','7','8','9'};

int checkWin() {
    if (gameBoard[1] == gameBoard[2] && gameBoard[2] == gameBoard[3]) {
        return 1;
    } else if (gameBoard[4] == gameBoard[5] && gameBoard[5] == gameBoard[6]) {
        return 1;
    } else if (gameBoard[7] == gameBoard[8] && gameBoard[8] == gameBoard[9]) {
        return 1;
    } else if (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7]) {
        return 1;
    } else if (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8]) {
        return 1;
    } else if (gameBoard[3] == gameBoard[6] && gameBoard[6] == gameBoard[9]) {
        return 1;
    } else if (gameBoard[1] == gameBoard[5] && gameBoard[5] == gameBoard[9]) {
        return 1;
    } else if (gameBoard[3] == gameBoard[5] && gameBoard[5] == gameBoard[7]) {
        return 1;
    } else if (gameBoard[1] != '1' && gameBoard[2] != '2' && gameBoard[3] != '3' &&
               gameBoard[4] != '4' && gameBoard[5] != '5' && gameBoard[6] != '6' &&
               gameBoard[7] != '7' && gameBoard[8] != '8' && gameBoard[9] != '9') {
        return 0;
    } else {
        return -1;
    }
}

void displayBoard() {
    system("clear"); // For Linux or macOS; use "cls" for Windows
    
    cout << "PLAYER 1: (X)  PLAYER 2: (O)" << endl;
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << gameBoard[1] << "  | " << gameBoard[2] << "  |  " << gameBoard[3] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << gameBoard[4] << "  | " << gameBoard[5] << "  |  " << gameBoard[6] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << gameBoard[7] << "  | " << gameBoard[8] << "  |  " << gameBoard[9] << " \n";
    cout << "\t\t     |     |     \n";
}

int main() {
    int currentPlayer = 1;
    int gameStatus, selectedCell;
    char mark;

    do {
        displayBoard();
        currentPlayer = (currentPlayer % 2) ? 1 : 2;
        cout << "Player " << currentPlayer << ", choose a cell: ";
        cin >> selectedCell;
        mark = (currentPlayer == 1) ? 'X' : 'O';

        if (selectedCell >= 1 && selectedCell <= 9 && gameBoard[selectedCell] == char(selectedCell + '0')) {
            gameBoard[selectedCell] = mark;
        } else {
            cout << "Invalid move. Try again." << endl;
            currentPlayer--;
            cin.ignore();
            cin.get();
        }
        currentPlayer++;
        gameStatus = checkWin();
    } while (gameStatus == -1);

    displayBoard();

    if (gameStatus == 1) {
        currentPlayer--;
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
  return 0 ;
}