// Global variables for the map and its dimensions
struct map
{
    char **gridCells;
    int rows;
    int columns;
};

typedef struct map MAP;

void clearMap(MAP *m);
void readMap(MAP *m);
void allocsMap(MAP *m);
void printMap(MAP *m);
