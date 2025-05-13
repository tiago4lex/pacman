#include <stdio.h>
#include <stdlib.h>

int main()
{
    char map[5][10+1];

    FILE *f;
    f = fopen("map.txt", "r");

    if (f == NULL)
    {
        printf("The map.txt file was not found");
        exit(1);
    }

    for (int i = 0; i < 4; i++)
    {
        fscanf(f, "$s", map[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("%s\n", map[i]);
    }

    fclose(f);
}