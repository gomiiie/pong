#include <raylib.h>
#include <iostream>
using namespace std;

int main() {

    int screenWidth = 1080;
    int screenHeight = 720;
    int playerScore = 0;
    int CPUScore = 0;
    Rectangle p1 = {20, 300, 20, 120};
    Rectangle p2 = {1060, 300, 20, 120};

    Vector2 boundsP = {0, screenHeight - p1.height};
    Vector2 pong = {540, 360};
    Vector2 pongSpeed = {-12, 12};
    int pongR = 15;
    Vector2 pongBounds = {pongR, screenHeight - pongR};
    
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    //Game Loop
    while(WindowShouldClose() == false) {

        //1. Event Handling
        if (IsKeyDown(KEY_DOWN) && p1.y < boundsP.y) {
            p1.y += 16;
        }
        else if (IsKeyDown(KEY_UP) && p1.y > boundsP.x) {
            p1.y -= 16;
        }
        if (pong.x - pongR <= 0) {
            CPUScore++;
            pong = {540, 360};
        }
        else if (pong.x - pongR >= screenWidth) {
            playerScore++;
            pong = {540, 360};
        }
        //2. Updating Positions
        if (pong.y > pongBounds.y || pong.y < pongBounds.x) {
            pongSpeed.y *= -1;
        }
        if (CheckCollisionCircleRec(pong, pongR, p1) || CheckCollisionCircleRec(pong, pongR, p2)) {
            pongSpeed.x *= -1; 
        }
        pong.x += pongSpeed.x;
        pong.y += pongSpeed.y;
        p2.y = pong.y - 5;

        //3. Drawing
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleRounded(p1, 3, 1, WHITE);
        DrawRectangleRounded(p2, 3, 1, WHITE);
        DrawCircleV(pong, pongR, WHITE);
        DrawText(TextFormat("%i",playerScore), 270, 50, 80, WHITE);
        DrawText(TextFormat("%i",CPUScore), 810, 50, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}