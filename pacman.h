#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void moves(char direction);
int ended();
int isValidDirection(char direction);
void ghosts();
int ghostMovement(int currentX, int currentY, int *destX, int *destY);