#ifndef MINESWEEPERCORE_H
#define MINESWEEPERCORE_H

#define SIZE  10
#define MINES 10

enum {mine = -1, nothing = 0};

class MineSweeperCore
{
    public:
        MineSweeperCore() : board {0}
        {
            generateMines();
            generateHints();
        }
        void showBoard();

    protected:
        int getCell(int x, int y);

    private:
        int board[SIZE][SIZE];

        void generateMines();
        void generateHints();
};

#endif // MINESWEEPERCORE_H
