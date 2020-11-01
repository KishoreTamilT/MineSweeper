#include "MineSweeperCore.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int MineSweeperCore::getCell(int x, int y)
{
    return board[x][y];
}

void MineSweeperCore::generateMines()
{
    int i;

    srand( time(NULL) );

    for(i=0; i<MINES; i++)
    {
        board[rand() % SIZE][rand() % SIZE] = mine;
    }
}

void MineSweeperCore::generateHints()
{
    int i, j;
    int m, n;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if (board[i][j] == mine)
            {
                for(m=i-1; m<=i+1; m++)
                {
                    for(n=j-1; n<=j+1; n++)
                    {
                        if (m < 0 || m >= SIZE || n < 0 || n >= SIZE)
                            continue;

                        if (board[m][n] == mine)
                            continue;

                        board[m][n]++;
                    }
                }
            }
        }
    }
}

void MineSweeperCore::showBoard()
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
                case nothing:
                    std::cout << '-';
                    break;
                default:
                    std::cout << board[i][j];
                    break;
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

