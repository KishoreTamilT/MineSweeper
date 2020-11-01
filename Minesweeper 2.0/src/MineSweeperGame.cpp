#include "MineSweeperGame.h"

#include <iostream>
#include <iomanip>

void MineSweeperGame::clearMove(int x, int y)
{
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        return;
    if (layer[x][y] == opened)
        return;

    layer[x][y] = opened;

    if (getCell(x, y) != nothing)
        return;

    clearMove(x - 1, y    );
    clearMove(x + 1, y    );
    clearMove(x    , y - 1);
    clearMove(x    , y + 1);
}

bool MineSweeperGame::checkWon()
{
    int i, j;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if (getCell(i, j) != mine)
                if (layer[i][j] != opened)
                    return false;
        }
    }

    return true;
}

void MineSweeperGame::revealMines()
{
    int i, j;

    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            if (getCell(i, j) == mine)
                layer[i][j] = opened;
        }
    }
}

/** Returning
       0 -> indicates Continue playing
       1 -> indicates Won the game
      -1 -> indicates Lose the game
      -2 -> Invalid move. Try Again!
*/
int MineSweeperGame::makeMove(int x, int y)
{
    /// Try Again
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        return -2;

    if (layer[x][y] == opened)
        return -2;

    /// Game Over
    if (getCell(x, y) == mine)
    {
        revealMines();

        layer[x][y] = danger;

        return -1;
    }

    /// Valid Move
    clearMove(x, y);

    /// Won the Game
    if (checkWon())
    {
        revealMines();
        return 1;
    }

    /// Continue Playing
    return 0;
}

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
                switch (getCell(i, j))
                {
                    case mine:
                        std::cout << '*';
                        break;
                    case nothing:
                        std::cout << ' ';
                        break;
                    default:
                        std::cout << getCell(i, j);
                        break;
                }
            }
            else if (layer[i][j] == danger)
                std::cout << 'X';
            else
                std::cout << '-';

            std::cout << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}


void MineSweeperGame::showBoardHelp()
{
    int i, j;

    std::cout << std::endl;

    std::cout << std::setw(4) << ' ' << "    ";
    for(i=0; i<SIZE; i++)
        std::cout << std::setw(3) << i << ' ';

    std::cout << '\n' << '\n' << '\n';
    for(i=0; i<SIZE; i++)
    {
        std::cout << std::setw(4) << i << "    ";
        for(j=0; j<SIZE; j++)
        {
            if (layer[i][j] == opened)
            {
                switch (getCell(i, j))
                {
                    case mine:
                        std::cout << std::setw(3) << '*';
                        break;
                    case nothing:
                        std::cout << std::setw(3) << ' ';
                        break;
                    default:
                        std::cout << std::setw(3) << getCell(i, j);
                        break;
                }
            }
            else if (layer[i][j] == danger)
                std::cout << std::setw(3) << 'X';
            else
                std::cout << std::setw(3) << '-';

            std::cout << ' ';
        }
        std::cout << '\n' << '\n';
    }
    std::cout << std::endl;
}

