#include "MineSweeper.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

/* Generate Mines on Board */
void MineSweeper::generateMines()
{
    srand(time(NULL)); // Seed

    // Generate MINES number of mines on board
    for(int i=0; i<MINES; i++)
        board[rand() % SIZE][rand() % SIZE] = mine; // Choose random position on Board
}

/* Generate Hints on Board */
void MineSweeper::generateHints()
{
    int i, j; // Loop variables for board
    int m, n; // Loop variables for Hints

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            // If the current position has a mine
            if (board[i][j] == mine)
            {
                for(m=i-1; m<=i+1; m++)
                {
                    for(n=j-1; n<=j+1; n++)
                    {
                        // If the current position is invalid
                        // i.e. out of bound, contains mine
                        if (m < 0 || m >= SIZE || n < 0 || n >= SIZE || board[m][n] == mine)
                            continue; // go to next position

                        board[m][n]++;
                    }
                }
                // Update m,n position
            }
            // Update i,j position
        }
    }

    return; // End of Function
}

/* Displays the Minesweeper board */
void MineSweeper::showBoard()
{
    int i, j;

    std::cout << std::endl;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            switch (board[i][j])
            {
            case mine:
                std::cout << '*';
                break;
            default:
                std::cout << board[i][j];
                break;
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

