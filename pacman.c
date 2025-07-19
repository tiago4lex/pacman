#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

MAP m;

void clearMap()
{
    for (int i = 0; i < m.rows; i++)
    {
        free(m.gridCells[i]);
    }
    free(m.gridCells);
}

void allocsMap()
{
    // Allocates memory for the map (array of strings)
    m.gridCells = malloc(sizeof(char *) * m.rows);
    for (int i = 0; i < m.rows; i++)
    {
        // +1 to account for the null terminator '\0'
        m.gridCells[i] = malloc(sizeof(char) * (m.columns + 1));
    }
}

void readMap()
{
    // Opens the map.txt file in read mode
    FILE *f;
    f = fopen("map.txt", "r");

    // If the file doesn't exist, print an error and exit
    if (f == NULL)
    {
        printf("The map.txt file was not found\n");
        exit(1);
    }

    // Reads the first line of the file to get the map's dimensions
    fscanf(f, "%d %d", &(m.rows), &(m.columns));

    allocsMap();

    // Reads each line of the map from the file
    for (int i = 0; i < m.rows; i++)
    {
        fscanf(f, "%s", m.gridCells[i]);
    }

    // Closes the file
    fclose(f);
}

void printMap()
{
    // Prints the map to the console
    for (int i = 0; i < m.rows; i++)
    {
        printf("%s\n", m.gridCells[i]);
    }
}

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
    readMap();

    do
    {
        printMap();

        char commands;
        scanf(" %c", &commands);
        moves(commands);

    } while (!ended());

    clearMap();

    return 0;
}
