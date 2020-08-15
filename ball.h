#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include "paddle.h"
#include <stdbool.h>
typedef struct{
    int radius;
    SDL_Renderer *rendi;
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 o;
    int xpos;
    int ypos;
    int xVel;
    int yVel;
}Ball;
void drawBall(SDL_Renderer *ren, Ball *b);
Ball *createBall(int radius, SDL_Renderer *rendi, Uint8 r, Uint8 g, Uint8 b, Uint8 o, int xpos, int ypos);
void moveVertical(SDL_Renderer *render, Ball *ball, int num);
void moveHorizontal(SDL_Renderer *render, Ball *ball, int num);
void bounceAround(SDL_Renderer *ren, Ball *b);
void detectCollisionWithRect(SDL_Renderer *ren, Ball *b, Paddle *p);
bool collideLeftSide(SDL_Renderer *ren, Ball *ball, Paddle *p2);
bool collideRightSide(SDL_Renderer *ren, Ball *ball, Paddle *p1);
#endif // BALL_H_INCLUDED
