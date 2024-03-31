#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 10

char maze[HEIGHT][WIDTH] = {
    "+-+-+-+-+-+-+-+-+",
    "|0|     |       |",
    "+-+ +-+ + +-+-+ +",
    "|   |   |     | |",
    "+-+ + + +-+-+ + +",
    "| | | |       | |",
    "+ + + +-+-+-+ + +",
    "| | |         | |",
    "+-+-+ + +-+-+ + +",
    "|     |       |X|",
};

int playerX = 1;
int playerY = 1;

void printMaze() {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

void movePlayer(int dx, int dy) {
    int newPosX = playerX + dx;
    int newPosY = playerY + dy;
    if (maze[newPosY][newPosX] == ' ') {
        maze[playerY][playerX] = ' ';
        playerX = newPosX;
        playerY = newPosY;
        maze[playerY][playerX] = '0';
    }
}

void pauseGame() {
    printf("Game paused. Press any key to continue...\n");
    getchar();
}

int main() {
    char command = ' ';
    while (command != 'Q') {
        printMaze();
        printf("Use WASD to move, P to pause, Q to quit.\n");
        command = getchar();
        getchar();
        
        switch (command) {
            case 'w': movePlayer(0, -1); break;
            case 's': movePlayer(0, 1); break;
            case 'a': movePlayer(-1, 0); break;
            case 'd': movePlayer(1, 0); break;
            case 'P': pauseGame(); break;
            case 'Q': printf("Game Over!\n"); break;
            default: printf("Invalid command!\n"); break;
        }
    }
    return 0;
}
