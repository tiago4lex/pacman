#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"

MAP m;

int ended()
{
    return 0;
}

void moves(char direction)
{
    int x;
    int y;

    // Finds hero position
    int found = 0;

    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.columns; j++)
        {
            if (m.gridCells[i][j] == '@')
            {
                x = i;
                y = j;
                found = 1;
                break;
            }
        }
    }

    if (!found)
        return;

    switch (direction)
    {
    case 'a':
        m.gridCells[x][y - 1] = '@';
        break;
    case 'w':
        m.gridCells[x - 1][y] = '@';
        break;
    case 's':
        m.gridCells[x + 1][y] = '@';
        break;
    case 'd':
        m.gridCells[x][y + 1] = '@';
        break;
    }

    m.gridCells[x][y] = '.';
}

int main()
{
    readMap(&m);

    do
    {
        printMap(&m);

        char commands;
        scanf(" %c", &commands);
        moves(commands);

    } while (!ended());

    clearMap(&m);

    return 0;
}
