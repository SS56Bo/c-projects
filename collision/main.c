#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 910
#define HEIGHT 600
#define FPS 30
#define PARTICLE_RADIUS 5

typedef struct {
    float x, y, vx, vy;
    Color color;
} Particle;

void AddMotionUpdate(Particle *particle) {
    particle->x += particle->vx;
    particle->y += particle->vy;
    if (particle->x > WIDTH-PARTICLE_RADIUS || particle->x < PARTICLE_RADIUS) {
        particle->vx = -(particle->vx);
    }
    if (particle->y > HEIGHT-PARTICLE_RADIUS || particle->y < PARTICLE_RADIUS) {
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
    InitWindow(WIDTH, HEIGHT, "Collision Window");
    SetTargetFPS(FPS);

    Particle p = {200, 200, 10, 10, GREEN};
    Particle p1 = {110, 60, 10, 8, PURPLE};
    Particle p2 = {120, 120, 9, 15, YELLOW};
    Particle p3 = {400, 400, 5, 8, RED};
    Particle p4 = {90, 90, 6, 8, MAGENTA};
    Particle p5 = {100, 80, 5, 4, MAROON};
    Particle p6 = {50, 200, 10, 10, LIME };
    Particle p7 = {180, 180, 18, 8, LIGHTGRAY};

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            PhysicsBundle(&p);
            PhysicsBundle(&p1);
            PhysicsBundle(&p2);
            PhysicsBundle(&p3);
            PhysicsBundle(&p4);
            PhysicsBundle(&p5);
            PhysicsBundle(&p6);
            PhysicsBundle(&p7);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}