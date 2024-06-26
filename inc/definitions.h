#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#define ASSERT(cond, ...) if (!cond) { fprintf(stderr, __VA_ARGS__); exit(1); }

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define MAP_SIZE 16
extern const uint8_t MAP[MAP_SIZE * MAP_SIZE];

#define PI 3.14159265f
extern const float playerFOV;
extern const float maxDepth;

typedef enum {NorthSouth, EastWest} Side;

typedef struct {
    float x, y;
} Vec2F;

typedef struct {
    int x, y;
} Vec2I;

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface; 
    bool quit;
} State;

typedef struct {
    Vec2F pos;
    Vec2F dir;
    Vec2F plane;
} Player;

int xy2index(int x, int y, int w);

void set_pixel(State *state, int x, int y, Uint32 color);

#endif // DEFINITIONS_H
