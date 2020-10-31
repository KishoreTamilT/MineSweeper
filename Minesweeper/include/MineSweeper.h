#ifndef MINESWEEPER_H
#define MINESWEEPER_H

// SIZE  - Size of Board
// MINES - Number of Mines
#define SIZE  10
#define MINES 10

/* Enumerations for Minesweeper */
enum {mine = -1, nothing = 0};

class MineSweeper
{
    public:
        /* Constructor - Creates the Minesweeper Board */
        MineSweeper() : board {0}
        {
            generateMines(); // Generate Mines on Board
            generateHints(); // Generate Hints on Board
        }

        /* Displays the Minesweeper board */
        void showBoard();

    protected:
        // Minesweeper Board
        int board[SIZE][SIZE];

    private:
        /* Generate Mines on Board */
        void generateMines();
        /* Generate Hints on Board */
        void generateHints();
};

#endif // MINESWEEPER_H
