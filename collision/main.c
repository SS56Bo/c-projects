#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 910
#define HEIGHT 600
#define FPS 30
#define PARTICLE_RADIUS 5

typedef struct {
    float x, y, vx, vy;
} Particle;

void AddMotionUpdate(Particle *particle) {
    particle->x += particle->vx;
    particle->y += particle->vy;
    if (particle->x > WIDTH-5 || particle->x < 5) {
        particle->vx = -(particle->vx);
    }
    if (particle->y > HEIGHT-5 || particle->y < 5) {
        particle->vy = -(particle->vy);
    }
    //printf("[%f %f]\n", particle->x, particle->y);  DEBUG
}

void DrawPhysicsParticle(Particle *particle) {
    DrawCircle(particle->x, particle->y, PARTICLE_RADIUS, GREEN);
}

int main(){
    InitWindow(WIDTH, HEIGHT, "Collision Window");
    SetTargetFPS(FPS);

    Particle p = {200, 200, 5, 5};

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            AddMotionUpdate(&p);
            DrawPhysicsParticle(&p);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}