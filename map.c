#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void navigateMap(MAP *m, int originX, int originY, int destX, int destY)
{
    char character = m->gridCells[originX][originY];
    m->gridCells[destX][destY] = character;
    m->gridCells[originX][originY] = '.';
}

int isValid(MAP *m, int x, int y)
{
    if (x >= m->rows)
        return 0;
    if (y >= m->columns)
        return 0;

    return 1;
}

int isEmpty(MAP *m, int x, int y)
{
    return m->gridCells[x][y] == '.';
}

void readMap(MAP *m)
{
    FILE *f = fopen("map.txt", "r");

    if (f == 0)
    {
        printf("The map.txt file was not found\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->rows), &(m->columns));

    allocsMap(m);

    for (int i = 0; i < m->rows; i++)
    {
        fscanf(f, "%s", m->gridCells[i]);
    }

    fclose(f);
}

void allocsMap(MAP *m)
{
    m->gridCells = malloc(sizeof(char *) * m->rows);
    for (int i = 0; i < m->rows; i++)
    {
        m->gridCells[i] = malloc(sizeof(char) * (m->columns + 1)); // +1 para '\0'
    }
}

void clearMap(MAP *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        free(m->gridCells[i]);
    }
    free(m->gridCells);
}

void printMap(MAP *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        printf("%s\n", m->gridCells[i]);
    }
}

void findMap(MAP *m, POSITION *p, char c)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->columns; j++)
        {
            if (m->gridCells[i][j] == c)
            {
                p->x = i;
                p->y = j;
                return;
            }
        }
    }
}