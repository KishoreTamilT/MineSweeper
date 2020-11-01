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
        game.showBoardHelp();

        cout << "Enter the position to play : ";
        cin >> a >> b;

        res = game.makeMove(a, b);

        if (res == 1 || res == -1)
            break;

        if (res == -2)
            cout << "\nInvalid Move. Try Again!";

        cout << "\nPress a key to continue . . . ";
        getch();
    }

    Sleep(500);

    system("cls");
    game.showBoardHelp();

    cout << "\nGAME END\n";
    if (res == 1)
        cout << "You WON the game!" << endl;
    if (res == -1)
        cout << "You LOSE the game!" << endl;

    cout << "\nPress a key to exit . . . ";
    getch();

    return 0;
}
