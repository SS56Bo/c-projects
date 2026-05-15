#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 910
#define HEIGHT 600
#define FPS 60
#define PARTICLE_RADIUS 10

typedef struct {
    float x, y, vx, vy;
    Color color;
} Particle;

void AddMotionUpdate(Particle *particle) {
    particle->x += particle->vx;
    particle->y += particle->vy;

    if (particle->x > WIDTH-PARTICLE_RADIUS || particle->x < PARTICLE_RADIUS) {
        if (particle->x > WIDTH-PARTICLE_RADIUS) {
            particle->x = WIDTH-PARTICLE_RADIUS;
        } else if (particle->x < PARTICLE_RADIUS){
            particle->x = PARTICLE_RADIUS;
        }
        particle->vx = -(particle->vx);
    }
    if (particle->y > HEIGHT-PARTICLE_RADIUS || particle->y < PARTICLE_RADIUS) {
        if (particle->y > HEIGHT-PARTICLE_RADIUS) {
            particle->y = HEIGHT-PARTICLE_RADIUS;
        } else if (particle->y < PARTICLE_RADIUS){
            particle->y = PARTICLE_RADIUS;
        }
        particle->vy = -(particle->vy); 
    }
    //printf("[%f %f]\n", particle->x, particle->y);  DEBUG
}

void DrawPhysicsParticle(Particle *particle) {
    DrawCircle(particle->x, particle->y, PARTICLE_RADIUS, particle->color);
}

void PhysicsBundle(Particle *particle) {
    DrawPhysicsParticle(particle);
    AddMotionUpdate(particle);
}

int main(){
    InitWindow(WIDTH, HEIGHT, "Particle Collision");
    SetTargetFPS(FPS);

    Particle p = {200, 200, 10, 10, RED};
    //Particle p1 = {220, 220, 14, 12, YELLOW};
       
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            PhysicsBundle(&p);
            DrawFPS(5, 5);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}