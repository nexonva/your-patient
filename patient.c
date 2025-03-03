#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void gotoxy(int x, int y) {
    COORD pos = {x, y}; // Set the x and y coordinates for position
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // Move the cursor
}

int main() {
    system("title my game"); // Set the console window title

    // Initialize random seed
    srand(time(NULL));

    while (1) {
        // Generate random coordinates (x: 0~79, y: 0~24)
        int xA = rand() % 80; // x-coordinate (0~79)
        int yA = rand() % 25; // y-coordinate (0~24)

        int xP1 = rand() % 80; // x-coordinate (0~79)
        int yP1 = rand() % 25; // y-coordinate (0~24)

        int xP2 = rand() % 80; // x-coordinate (0~79)
        int yP2 = rand() % 25; // y-coordinate (0~24)

        int xL = rand() % 80; // x-coordinate (0~79)
        int yL = rand() % 25; // y-coordinate (0~24)

        int xE = rand() % 80; // x-coordinate (0~79)
        int yE = rand() % 25; // y-coordinate (0~24)

        // Output "a", "p", "p", "l", "e" at random positions
        gotoxy(xA, yA); // Output "a" at random position
        printf("a");

        gotoxy(xP1, yP1); // Output "p" at random position
        printf("p");

        gotoxy(xP2, yP2); // Output "p" at random position
        printf("p");

        gotoxy(xL, yL); // Output "l" at random position
        printf("l");

        gotoxy(xE, yE); // Output "e" at random position
        printf("e");

        // Check if "apple" is on the same line (yA == yP1 == yP2 == yL == yE)
        if (yA == yP1 && yA == yP2 && yA == yL && yA == yE) {
            printf("\napple found! Exiting program...\n");
            break;  // Exit the loop and terminate the program
        }

        Sleep(500); // Adjust speed (wait for 500ms)
    }

    return 0;
}
