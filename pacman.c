#include <stdio.h>
#include <stdlib.h>

// Global variables for the map and its dimensions
char **map;
int rows;
int columns;

int main()
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
    fscanf(f, "%d %d", &rows, &columns);
    printf("rows: %d columns: %d\n", rows, columns);

    // Allocates memory for the map (array of strings)
    map = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++)
    {
        // +1 to account for the null terminator '\0'
        map[i] = malloc(sizeof(char) * (columns + 1));
    }

    // Reads each line of the map from the file
    for (int i = 0; i < rows; i++)
    {
        fscanf(f, "%s", map[i]);
    }

    // Prints the map to the console
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", map[i]);
    }

    // Closes the file
    fclose(f);

    // Frees the allocated memory
    for (int i = 0; i < rows; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}
