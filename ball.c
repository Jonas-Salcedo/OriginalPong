#include <stdlib.h>
#include <stdio.h>
#include "SDL2\SDL.h"
#include "ball.h"
#include "paddle.h"
#include <stdbool.h>

Ball *createBall(int radius, SDL_Renderer *rendi, Uint8 r, Uint8 g, Uint8 b, Uint8 o, int xpos, int ypos)
{
    Ball *ball = (Ball*)malloc(sizeof(Ball));
    ball->radius = radius;
    ball->rendi = rendi;
    ball->r = r;
    ball->g = g;
    ball->b = b;
    ball->o = o;
    ball->xpos = xpos;
    ball->ypos = ypos;
    ball->yVel = 0;
    ball->xVel = 2;
}
void drawBall(SDL_Renderer *ren, Ball *ball)
{
    SDL_SetRenderDrawColor(ball->rendi, 255, 0, 0, 0);
    int xholder = 0;
    int yholder = ball->radius;
    int P = 1 - ball->radius;
    int xout = 0;
    int yout = ball->radius - 1;
    int mpx = 0;
    int mpy = 0;
    int tx = 1;
    int ty = 1;
   // mpx += (ball->xpos + ball->radius)/2;
    //mpy += (ball->ypos + ball->radius)/2;
    while(xout <= yout)
    {
        // SDL_SetRenderDrawColor(ball->rendi, 65, 7, 20, 0);
         SDL_RenderDrawPoint(ren, ball->xpos + xout, ball->ypos + yout);
         SDL_RenderDrawPoint(ren, ball->xpos + yout, ball->ypos + xout);
         SDL_RenderDrawPoint(ren, ball->xpos - yout, ball->ypos + xout);
         SDL_RenderDrawPoint(ren, ball->xpos - xout, ball->ypos + yout);
         SDL_RenderDrawPoint(ren, ball->xpos - xout, ball->ypos - yout);
         SDL_RenderDrawPoint(ren, ball->xpos - yout, ball->ypos - xout);
         SDL_RenderDrawPoint(ren, ball->xpos + yout, ball->ypos - xout);
         SDL_RenderDrawPoint(ren, ball->xpos + xout, ball->ypos - yout);
         xout++;
         if(P<= 0)
         {
             P = P + 2 * xout + 1;
         }
         else if(P > 0)
         {
            yout--;
            P = P + 2 * (xout-yout) + 1;

         }

    }
}

void moveVertical(SDL_Renderer *ren, Ball *ball, int num)
{

    ball->ypos = ball->ypos + num;
    drawBall(ren, ball);
}

void moveHorizontal(SDL_Renderer *ren, Ball *ball, int num)
{
    ball->xpos = ball->xpos + num;
    drawBall(ren, ball);
}
void bounceAround(SDL_Renderer *ren, Ball *b)
{
    if((b->xpos >=800) || (b->xpos <=0))
    {
        b->xVel = -b->xVel;
    }
    if((b->ypos >=600) || (b->ypos <=0))
    {
        b->yVel = -b->yVel;
    }
    moveVertical(ren, b, b->yVel);
    moveHorizontal(ren, b, b->xVel);


}
bool collideLeftSide(SDL_Renderer *ren, Ball *ball, Paddle *p2){
    if(ball->xpos<=0){
            ball->xpos = 400;
            ball->ypos = 300;
            ball->xVel = 2;
            ball->yVel = 0;
            p2->score++;
            drawBall(ren, ball);

            return true;

    }

        return false;
}
bool collideRightSide(SDL_Renderer *ren, Ball *ball, Paddle *p1){
        if(ball->xpos>=800){

            ball->xpos = 400;
            ball->ypos = 300;
            ball->xVel = -2;
            ball->yVel = 0;
            p1->score++;
            drawBall(ren, ball);
        return true;
        }
        return false;

}

void detectCollisionWithRect(SDL_Renderer *ren, Ball *b, Paddle *p)
{
    if((b->xpos >= p->xpos) && (b->xpos <= (p->xpos + p->width))&& (b->ypos >= p->ypos) && (b->ypos <= (p->ypos + p->height)))
    {

            b->xVel = -b->xVel;
            if((b->ypos>=(p->ypos + (2*((p->height)/3))))&&(b->ypos<=(p->ypos + ((p->height)))))
            {
                b->yVel = 2;
            }
            else if((b->ypos>=(p->ypos + (((p->height)/3))))&&(b->ypos<=(p->ypos + (2*((p->height)/3)))))
            {
                b->yVel = 0;
            }
            else
            {
                b->yVel = -2;
            }

    }
}

