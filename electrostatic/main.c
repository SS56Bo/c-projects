#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 1200
#define HEIGHT 720
#define RADIUS 5
#define TOTAL_ELECTRONS 2

typedef struct  
{
    float x, y;
    float vx, vy;
    float charge;
} Electron;

Electron electrons[TOTAL_ELECTRONS];

void DrawElectron(Electron *elec) {
    float charge = elec->charge;
    if (charge < 0) {
        DrawCircle(elec->x, elec->y, RADIUS, BLUE);
    } else {
        DrawCircle(elec->x, elec->y, RADIUS, RED);
    } 
}

void InitElectrons() {
    SetRandomSeed(52);

    for (int i = 0; i<TOTAL_ELECTRONS; i++) {
        electrons[i].x = GetRandomValue(RADIUS, WIDTH-RADIUS);
        electrons[i].y = GetRandomValue(RADIUS, HEIGHT-RADIUS);
        electrons[i].vx = 2;
        electrons[i].vy = 2;
        electrons[i].charge = GetRandomValue(-50, 50);
    }
}

void DrawElectrons() {
    for (int i = 0; i<TOTAL_ELECTRONS; i++) {
        DrawElectron(electrons+i);
    }
}
int main(){
  
    InitWindow(WIDTH, HEIGHT, "Electrostatic Window");
    SetTargetFPS(60);

    InitElectrons();
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawElectrons();
            DrawFPS(5, 5);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}