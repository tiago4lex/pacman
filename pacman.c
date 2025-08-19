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
    m.gridCells[hero.x][hero.y] = '.';

    switch (direction)
    {
    case 'a':
        m.gridCells[hero.x][hero.y - 1] = '@';
        hero.y--;
        break;
    case 'w':
        m.gridCells[hero.x - 1][hero.y] = '@';
        hero.x--;
        break;
    case 's':
        m.gridCells[hero.x + 1][hero.y] = '@';
        hero.x++;
        break;
    case 'd':
        m.gridCells[hero.x][hero.y + 1] = '@';
        hero.y++;
        break;
    }
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
