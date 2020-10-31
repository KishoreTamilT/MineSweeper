#include "MineSweeperGame.h"

#include <iostream>
#include <iomanip>

/**
Makes move at position (x, y)

    Returning 0 indicates continue playing
             -1 indicates try again (i.e. invalid move)
             -2 indicates game over (i.e. mine)
              1 indicates won the game
*/
int MineSweeperGame::makeMove(int x, int y)
{
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || layer[x][y] == opened)
    {
        /// Invalid Move! Try Again!
        return -1;
    }

    if (board[x][y] == mine)
    {
        /// Game Over

        revealMines(); // Reveal mines
        layer[x][y] = vdanger;

        return -2;
    }

    if (board[x][y] == nothing)
    {
        // Clear it and its adjacent position
        clearMove(x, y);
    }
    else
    {
        // Clear it only
        layer[x][y] = opened;
    }

    // Is won
    if (isWon())
        return 1;

    /** Continue the GAME */
    return 0;
}

/* Clear the current position and its adjacent position recursively */
void MineSweeperGame::clearMove(int x, int y)
{
    // Revisiting opened
    if (layer[x][y] == opened)
    {
        return;
    }

    // Out of bound
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
    {
        return;
    }

    // Make opened this position
    layer[x][y] = opened;

    // End of open space
    if (board[x][y] != nothing)
    {
        return;
    }

    // Clear its adjacent positions recursively
    clearMove(x - 1, y    );
    clearMove(x + 1, y    );
    clearMove(x    , y - 1);
    clearMove(x    , y + 1);
}

/* Displays the Minesweeper board */
void MineSweeperGame::showBoard()
{
    int i, j;

    std::cout << std::endl;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if (layer[i][j] == opened)
            {
                std::cout << board[i][j];
            }
            else if (layer[i][j] == danger)
            {
                std::cout << '*';
            }
            else if (layer[i][j] == vdanger)
            {
                std::cout << 'X';
            }
            else
            {
                std::cout << '-';
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/* Displays the Minesweeper board with Instructions */
void MineSweeperGame::showBoardwithInstructions()
{
    int i, j;

    std::cout << std::endl;
    std::cout << "        ";
    for(j=0; j<SIZE; j++)
        std::cout << j << ' ';

    std::cout << std::endl << std::endl;
    for(i=0; i<SIZE; i++)
    {
        std::cout << std::setw(4) << i << "    ";
        for(j=0; j<SIZE; j++)
        {
            if (layer[i][j] == opened)
            {
                std::cout << board[i][j];
            }
            else if (layer[i][j] == danger)
            {
                std::cout << '*';
            }
            else if (layer[i][j] == vdanger)
            {
                std::cout << 'X';
            }
            else
            {
                std::cout << '-';
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/* Reveal all the mines */
void MineSweeperGame::revealMines()
{
    int i, j;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if (board[i][j] == mine)
                layer[i][j] = danger;
        }
    }
}

// Check for won
bool MineSweeperGame::isWon()
{
    int i, j;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            // skip mines
            if (board[i][j] == mine)
                continue;

            // Other than mines, it must be opened
            if (layer[i][j] != opened)
                return false;
        }
    }

    return true;
}

