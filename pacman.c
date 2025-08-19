#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"

MAP m;
POSITION hero;

int ended()
{
    return 0;
}

void moves(char direction)
{
    if (direction != 'a' &&
        direction != 'w' &&
        direction != 's' &&
        direction != 'd')
        return;

    int nextX = hero.x;
    int nextY = hero.y;

    switch (direction)
    {
    case 'a':
        nextY--;
        break;
    case 'w':
        nextX--;
        break;
    case 's':
        nextX++;
        break;
    case 'd':
        nextY++;
        break;
    }

    if (nextX >= m.rows)
        return;
    if (nextY >= m.columns)
        return;
    if (m.gridCells[nextX][nextY] != '.')
        return;

    m.gridCells[nextX][nextY] = '@';
    m.gridCells[hero.x][hero.y] = '.';
    hero.x = nextX;
    hero.y = nextY;
}

int main()
{
    readMap(&m);
    findMap(&m, &hero, '@');

    do
    {
        printMap(&m);

        char commands;
        scanf(" %c", &commands);
        moves(commands);

    } while (!ended());

    clearMap(&m);
}
