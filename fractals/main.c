#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 910
#define HEIGHT 600
#define FPS 1

#define TREE_COLOR RAYWHITE
#define THICKNESS 20
#define BRANCH_OFF_ANGLE 20*DEG2RAD

void DrawBranch(float x, float y, float length, float angle, float thickness) {

    if (length < 1) {
        return; 
    }
    Vector2 start = {x, y};

    float x_end = x + sinf(angle)*length;
    float y_end = y - cosf(angle)*length;
    Vector2 end = {x_end, y_end};

    DrawLineEx(start, end, thickness, TREE_COLOR);

    float new_length = length*0.7;
    float new_R_angle = angle + BRANCH_OFF_ANGLE;
    float new_L_angle = angle - BRANCH_OFF_ANGLE;
    float new_thickness = thickness*0.7;
    DrawBranch(x_end, y_end, new_length, new_L_angle, new_thickness);
    DrawBranch(x_end, y_end, new_length, new_R_angle, new_thickness);
}

int main(){
    InitWindow(WIDTH, HEIGHT, "Fractal Tree");
    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(BLACK);
            DrawBranch(WIDTH/2, HEIGHT-20, 150, 0, THICKNESS);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}