#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MineSweeperGame.h"

using namespace std;

int main()
{
    MineSweeperGame game;
    int a, b, res;

    while (true)
    {
        system("cls");

        game.showBoardwithInstructions();

        cout << "Enter the position to make move : ";
        cin >> a >> b;

        res = game.makeMove(a, b);

        if (res == -2)
            break; // Game Over

        if (res == 1)
            break; // Won the game

        if (res == -1)
        {
            // Try Again
            cout << "\nInvalid Move! Try Again..." << endl;
        }

        cout << "\nPress a key to continue..." << endl;
        getch();
    }

    system("cls");
    game.showBoard();

    Sleep(200); // Sleeping

    cout << "\nGAME END!" << endl;

    if (res == -2)
    {
        cout << "\nYou Lose!" << endl;
    }
    if (res == 1)
    {
        cout << "\nYou are the WINNER!!!" << endl;
    }

    cout << "\nPress a key to exit..." << endl;
    getch();

    return 0;
}
