#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 910
#define HEIGHT 600
#define FPS 1

int main(){
    InitWindow(WIDTH, HEIGHT, 'Collision Window');
    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        /* code */
        BeginDrawing();
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}