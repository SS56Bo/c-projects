#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 600
#define RADIUS 15

typedef struct  
{
    float x, y;
    float vx, vy;
    float charge;
} Electron;

void DrawElectron(Electron *elec) {
    float charge = elec->charge;
    if (charge < 0) {
        DrawCircle(elec->x, elec->y, RADIUS, BLUE);
    } else {
        DrawCircle(elec->x, elec->y, RADIUS, RED);
    }
}

int main(){
  
    InitWindow(WIDTH, HEIGHT, "Electrostatic Window");
    SetTargetFPS(60);

    Electron epos = {WIDTH/2, 120, 0, 0, -6.3};
    Electron eneg = {WIDTH/2, 250, 0, 0, 2.5};

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawElectron(&epos);
            DrawElectron(&eneg);
            DrawFPS(5, 5);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}