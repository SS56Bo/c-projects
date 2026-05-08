#include "raylib.h"
#include <stdio.h>
#include <math.h>

int main(){
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, 'Fractal Window');
    SetTargetFPS(60);

    while (!WindowShouldClose)
    {
        /* code */
        BeginDrawing();
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}