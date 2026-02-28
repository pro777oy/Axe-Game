#include "raylib.h"
#include <cstdlib>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Axe Game");
    SetTargetFPS(60);

    // Player

    const int startX = 400;
    const int startY = 400;

    int circleX = startX;
    int circleY = startY;

    float radius = 50;
    Color circleColor = BLUE;
    float circleSpeed = 600;

    // Axe
    int axeX = 300;
    int axeY = 0;
    int axeWidth = 50;
    int axeHeight = 50;
    float axeSpeed = 1000;
    Color axeColor = RED;

    bool gameOver = false;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        if (!gameOver)
        {
            axeY += axeSpeed * deltaTime;

            if (axeY > screenHeight)
            {
                axeY = -axeHeight;
                axeX = GetRandomValue(0, screenWidth - axeWidth);
            }

            if (IsKeyDown(KEY_D) && circleX < screenWidth - radius)
                circleX += circleSpeed * deltaTime;

            if (IsKeyDown(KEY_A) && circleX > radius)
                circleX -= circleSpeed * deltaTime;

            if (IsKeyDown(KEY_W) && circleY > radius)
                circleY -= circleSpeed * deltaTime;

            if (IsKeyDown(KEY_S) && circleY < screenHeight - radius)
                circleY += circleSpeed * deltaTime;

            Rectangle axeRec = { (float)axeX, (float)axeY, (float)axeWidth, (float)axeHeight };
            Rectangle circleRec = { circleX - radius, circleY - radius, radius * 2, radius * 2 };

            if (CheckCollisionRecs(axeRec, circleRec))
            {
                gameOver = true;
            }
        }
        else
        {

            if (IsKeyPressed(KEY_ENTER))
            {
                circleX = startX;
                circleY = startY;

                axeY = 0;
                axeX = GetRandomValue(0, screenWidth - axeWidth);

                gameOver = false;
            }
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (gameOver)
        {
            DrawText("GAME OVER!", screenWidth/2 - 150, screenHeight/2 - 40, 50, RED);
            DrawText("Press ENTER to try again",screenWidth/2 - 130,screenHeight/2 + 20,20,DARKGRAY);
        }
        else
        {
            DrawCircle(circleX, circleY, radius, circleColor);
            DrawRectangle(axeX, axeY, axeWidth, axeHeight, axeColor);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}