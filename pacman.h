void clearMap();
void readMap();
void allocsMap();

void moves(char direction);
int ended();
void printMap();

// Global variables for the map and its dimensions
struct map
{
    char **gridCells;
    int rows;
    int columns;
};
