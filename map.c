#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void clearMap(MAP *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        free(m->gridCells[i]);
    }
    free(m->gridCells);
}

void allocsMap(MAP *m)
{
    m->gridCells = malloc(sizeof(char *) * m->rows);
    for (int i = 0; i < m->rows; i++)
    {
        m->gridCells[i] = malloc(sizeof(char) * (m->columns + 1)); // +1 para '\0'
    }
}

void readMap(MAP *m)
{
    FILE *f = fopen("map.txt", "r");

    if (f == NULL)
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

void printMap(MAP *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        printf("%s\n", m->gridCells[i]);
    }
}