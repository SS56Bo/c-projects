#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

#define WIDTH 1080
#define HEIGHT 720
#define FPS 60
#define PARTICLE_RADIUS 5
#define TOTAL_PARTICLES 50
#define G 9.8

typedef struct {
    float x, y, vx, vy;
    Color color;
} Particle;

Particle particles[TOTAL_PARTICLES];

void AddMotionUpdate(Particle *particle) {
    float speed_gravity = particle->vy;
    particle->x += particle->vx;
    particle->y += speed_gravity;

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
    SetRandomSeed(time(NULL));

    for (int i = 0; i < TOTAL_PARTICLES; i++) {
        particles[i].x = GetRandomValue(PARTICLE_RADIUS, WIDTH-PARTICLE_RADIUS);
        particles[i].y = GetRandomValue(PARTICLE_RADIUS, HEIGHT-PARTICLE_RADIUS);
        particles[i].vx = GetRandomValue(-5, 5);
        particles[i].vy = GetRandomValue(-5, 5);
        // particles[i].color = WHITE;

        switch (GetRandomValue(0, 6))
        {
        case 1: 
            particles[i].color = WHITE;
            break;
        case 2:
            particles[i].color = RED;
            break;
        case 3:
            particles[i].color = YELLOW;
            break;
        case 4:
            particles[i].color = PURPLE;
            break;
        case 5:
            particles[i].color = PINK;
            break;
        case 6:
            particles[i].color = BLUE;
            break;
        default:
            break;
        }
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