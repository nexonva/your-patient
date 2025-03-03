#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void gotoxy(int x, int y){
    COORD pos = {x, y}; // x와 y 좌표로 위치 지정
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 커서 이동
}

int main() {
    system("title my game"); // 콘솔 창 제목 설정

    // 랜덤 시드 초기화
    srand(time(NULL));

    while (1) {
        // 랜덤 좌표 생성 (x는 0~79, y는 0~24 범위)
        int xA = rand() % 80; // x좌표 (0~79)
        int yA = rand() % 25; // y좌표 (0~24)

        int xP1 = rand() % 80; // x좌표 (0~79)
        int yP1 = rand() % 25; // y좌표 (0~24)

        int xP2 = rand() % 80; // x좌표 (0~79)
        int yP2 = rand() % 25; // y좌표 (0~24)

        int xL = rand() % 80; // x좌표 (0~79)
        int yL = rand() % 25; // y좌표 (0~24)

        int xE = rand() % 80; // x좌표 (0~79)
        int yE = rand() % 25; // y좌표 (0~24)

        // 랜덤 위치에 "a", "p", "p", "l", "e" 출력
        gotoxy(xA, yA); // 랜덤 위치에 "a" 출력
        printf("a");

        gotoxy(xP1, yP1); // 랜덤 위치에 "p" 출력
        printf("p");

        gotoxy(xP2, yP2); // 랜덤 위치에 "p" 출력
        printf("p");

        gotoxy(xL, yL); // 랜덤 위치에 "l" 출력
        printf("l");

        gotoxy(xE, yE); // 랜덤 위치에 "e" 출력
        printf("e");

        // Check if "apple" is on the same line (yA == yP1 == yP2 == yL == yE)
        if (yA == yP1 && yA == yP2 && yA == yL && yA == yE) {
            printf("\napple found! Exiting program...\n");
            break;  // Exit the loop and terminate the program
        }

        Sleep(500); // 속도 조절 (500ms 대기)
    }

    return 0;
}
