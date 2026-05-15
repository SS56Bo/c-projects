#include "raylib.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 1080
#define HEIGHT 720
#define FPS 60
#define PARTICLE_RADIUS 5
#define TOTAL_PARTICLES 800

typedef struct {
    float x, y, vx, vy;
    Color color;
} Particle;

Particle particles[TOTAL_PARTICLES];

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

void InitParticles() {
    SetRandomSeed(895);

    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        particles[i].x = GetRandomValue(PARTICLE_RADIUS, WIDTH-PARTICLE_RADIUS);
        particles[i].y = GetRandomValue(PARTICLE_RADIUS, HEIGHT-PARTICLE_RADIUS);
        particles[i].vx = GetRandomValue(-5, 10);
        particles[i].vy = GetRandomValue(-2, 15);
        particles[i].color = WHITE;
    }
}

void DrawParticles() {
    for (int i =0; i<TOTAL_PARTICLES; i++) {
        DrawPhysicsParticle(particles+i);
    }
}

void UpdateParticles() {
    for (int i =0; i<TOTAL_PARTICLES; i++) {
        AddMotionUpdate(particles+i);
    }
}

int main(){
    InitWindow(WIDTH, HEIGHT, "Particle Collision");
    SetTargetFPS(FPS);

    InitParticles();
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);  
            DrawParticles();
            UpdateParticles();
            DrawFPS(5, 5);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}