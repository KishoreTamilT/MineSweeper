#ifndef MINESWEEPERGAME_H
#define MINESWEEPERGAME_H

#include <MineSweeperCore.h>

enum {closed = 0, opened = 1, danger = 2};

class MineSweeperGame : protected MineSweeperCore
{
    public:
        MineSweeperGame() : layer {0} { }

        /** Displays the Minesweeper Board */
        void showBoard();
        void showBoardHelp();

        /** Returning
                   0 -> indicates Continue playing
                   1 -> indicates Won the game
                  -1 -> indicates Lose the game
                  -2 -> Invalid move. Try Again!
        */
        int makeMove(int x, int y);

    protected:

    private:
        int layer[SIZE][SIZE];

        void clearMove(int x, int y);
        bool checkWon();
        void revealMines();
};

#endif // MINESWEEPERGAME_H
