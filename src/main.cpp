#include <raylib.h>
#include <iostream>
using namespace std;

int main() {

    int screenWidth = 1080;
    int screenHeight = 720;
    int ballX = 540;
    int ballY = 360;
    int ballR = 20;
    int ballXspeed = 20;
    int ballYspeed = 10;
    int count = 0;
    int boundXpos = screenWidth - ballR;
    int boundneg = ballR;
    int boundYpos = screenHeight - ballR; 
    Color green = {20, 160, 133, 255}; 

    InitWindow(screenWidth, screenHeight, "YO");
    SetTargetFPS(60);

    //Game Loop
    while(WindowShouldClose() == false) {

        //1. Event Handling
        if(IsKeyDown(KEY_RIGHT) && ballX < boundXpos) {
            ballXspeed = 20;
        }
        else if(IsKeyDown(KEY_LEFT) && ballX > boundneg) {
            ballXspeed = -20;
        }
        else {
            ballXspeed = 0;
        }

        if(IsKeyDown(KEY_UP) && ballY > boundneg) {
            ballYspeed = -10;
        }
        else if(IsKeyDown(KEY_DOWN) && ballY < boundYpos) {
            ballYspeed = 10;
        }
        else {
            ballYspeed = 0;
        }
        //2. Updating Positions
        ballX += ballXspeed;
        ballY += ballYspeed;

        //ballY += ballYspeed;
        /*if (ballX >= 1080) {
            ballXspeed = -20;
        }
        if (ballX <= 0) {
            ballXspeed = 20;
        }
        if (ballY >= 720) {
            ballYspeed = -10;
        }
        if (ballY <= 0) {
            ballYspeed = 10;
        }*/

        //3. Drawing
        BeginDrawing();
        ClearBackground(green);
        DrawCircle(ballX, ballY, ballR, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}