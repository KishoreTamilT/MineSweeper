#ifndef MINESWEEPERGAME_H
#define MINESWEEPERGAME_H

#include <MineSweeper.h>

// Opened position
enum {opened = -2, danger = -3, vdanger = -4};

class MineSweeperGame : public MineSweeper
{
    public:
        /* Constructor - Creates the layer */
        MineSweeperGame() : layer {0} { }

        /**
        Makes move at position (x, y)

            Returning 0 indicates continue playing
                     -1 indicates try again (i.e. invalid move)
                     -2 indicates game over (i.e. mine)
                      1 indicates won the game
        */
        int makeMove(int x, int y);

        /* Displays the Minesweeper board */
        void showBoard();
        void showBoardwithInstructions();

    protected:

    private:
        // Layer of the board
        int layer[SIZE][SIZE];

        /* Clear the current position and its adjacent position recursively */
        void clearMove(int x, int y);

        /* Reveal all the mines */
        void revealMines();

        // Check for won
        bool isWon();
};

#endif // MINESWEEPERGAME_H
