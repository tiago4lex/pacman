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
    if(!isValid(&m, nextX, nextY))
        return;

    if(!isEmpty(&m, nextX, nextY))
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

    } while (!ended());

    clearMap(&m);
}
