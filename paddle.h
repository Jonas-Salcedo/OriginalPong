#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "SDL2\SDL.h"

typedef struct
{
    int width;
    int height;
    SDL_Renderer *rendi;
    SDL_Rect *rect;
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 o;
    int xpos;
    int ypos;
    int score;
    int yvel;


}Paddle;
void drawPaddle(SDL_Renderer *render, Paddle *paddle);
Paddle *createPaddle(int width, int height, SDL_Renderer *rende, Uint8 r, Uint8 g, Uint8 b, Uint8 o, int xpos, int ypos);
void moveUp(Paddle *paddle);
void moveDown( Paddle *paddle);
void stop(Paddle *paddle);
void moves(SDL_Renderer *render, Paddle *paddle);


#endif // PADDLE_H_INCLUDED
