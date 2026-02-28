#include "raylib.h"
#include <cstdlib>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Axe Game");

    SetTargetFPS(60);


    int circleX = 175;
    int circleY = 100;
    float radius = 50;
    Color circleColor = MAROON;


    int axeX = 300;
    int axeY = 0;
    int axeWidth = 50;
    int axeHeight = 50;
    float axeSpeed = 250;
    Color axeColor = RED;

    bool collisionWithAxe = false;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        axeY += axeSpeed * deltaTime;

        if (axeY > screenHeight)
        {
            axeY = -axeHeight;
            axeX = GetRandomValue(0, screenWidth - axeWidth);
        }

 
        if(IsKeyDown(KEY_D) && circleX < screenWidth - radius)
            circleX += 300 * deltaTime;

        if(IsKeyDown(KEY_A) && circleX > radius)
            circleX -= 300 * deltaTime;

        if(IsKeyDown(KEY_W) && circleY > radius)
            circleY -= 300 * deltaTime;

        if(IsKeyDown(KEY_S) && circleY < screenHeight - radius)
            circleY += 300 * deltaTime;


        Rectangle axeRec = { (float)axeX, (float)axeY, (float)axeWidth, (float)axeHeight };
        Rectangle circleRec = { circleX - radius, circleY - radius, radius * 2, radius * 2 };

        collisionWithAxe = CheckCollisionRecs(axeRec, circleRec);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (collisionWithAxe)
        {
            DrawText("Game Over!", screenWidth/2 - 100, screenHeight/2, 40, RED);
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