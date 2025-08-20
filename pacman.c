#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"

MAP m;
POSITION hero;

void ghosts()
{

    MAP copy;
    copiesMap(&copy, &m);

    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.columns; j++)
        {
            if (copy.gridCells[i][j] == GHOST)
            {
                if (isValid(&m, i, j + 1) && isEmpty(&m, i, j + 1))
                {
                    navigateMap(&m, i, j, i, j + 1);
                }
            }
        }
    }
    clearMap(&copy);
}

int ended()
{
    return 0;
}

int isValidDirection(char direction)
{
    return direction != 'a' ||
           direction != 'w' ||
           direction != 's' ||
           direction != 'd';
}

void moves(char direction)
{
    if (!isValidDirection(direction))
        return;

    int nextX = hero.x;
    int nextY = hero.y;

    switch (direction)
    {
    case LEFT:
        nextY--;
        break;
    case UP:
        nextX--;
        break;
    case DOWN:
        nextX++;
        break;
    case RIGHT:
        nextY++;
        break;
    }
    if (!isValid(&m, nextX, nextY))
        return;

    if (!isEmpty(&m, nextX, nextY))
        return;

    navigateMap(&m, hero.x, hero.y, nextX, nextY);
    hero.x = nextX;
    hero.y = nextY;
}

int main()
{
    readMap(&m);
    findMap(&m, &hero, HERO);

    do
    {
        printMap(&m);

        char commands;
        scanf(" %c", &commands);
        moves(commands);
        ghosts();

    } while (!ended());

    clearMap(&m);
}
