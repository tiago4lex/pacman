#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"
#include "map.h"

MAP m;
POSITION hero;

int ghostMovement(int currentX, int currentY, int *destX, int *destY)
{
    int options[4][2] = {
        {currentX, currentY + 1},
        {currentX, currentY - 1},
        {currentX + 1, currentY},
        {currentX - 1, currentY}};

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int position = rand() % 4;

        if (canMove(&m, options[position][0], options[position][1]))
        {
            *destX = options[position][0];
            *destY = options[position][1];
            return 1;
        }
    }
    return 0;
}

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
                int destX;
                int destY;

                int moved = ghostMovement(i, j, &destX, &destY);
                if (moved)
                {
                    navigateMap(&m, i, j, destX, destY);
                }

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
    POSITION position;
    int pacmanMap = findMap(&m, &position, HERO);
    return  !pacmanMap;
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
    if (!canMove(&m, nextX, nextY))
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
