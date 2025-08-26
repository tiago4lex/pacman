#define HERO '@'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define GHOST 'G'

// Global variables for the map and its dimensions
struct map
{
    char **gridCells;
    int rows;
    int columns;
};

typedef struct map MAP;

void allocsMap(MAP *m);
void readMap(MAP *m);
void clearMap(MAP *m);
void printMap(MAP *m);

struct position
{
    int x;
    int y;
};

typedef struct position POSITION;

int findMap(MAP *m, POSITION *p, char c);

int isValid(MAP *m, int x, int y);
int walls(MAP *m, int x, int y);
int isHero(MAP *m, char hero, int x, int y);

void navigateMap(MAP *m, int originX, int originY, int destX, int destY);

void copiesMap(MAP *dest, MAP *origin);

int canMove(MAP* m, char hero, int x, int y);