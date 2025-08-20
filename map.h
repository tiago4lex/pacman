#define HERO '@'
#define GHOST 'G'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

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

struct position
{
    int x;
    int y;
};

typedef struct position POSITION;
void findMap(MAP *m, POSITION *p, char c);

int isValid(MAP *m, int x, int y);
int isEmpty(MAP *m, int x, int y);
void navigateMap(MAP *m, int originX, int originY, int destX, int destY);

void copiesMap(MAP *dest, MAP *origin);