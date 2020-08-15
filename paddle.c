#include <stdlib.h>
#include <stdio.h>
#include "SDL2\SDL.h"
#include "paddle.h"

void drawPaddle(SDL_Renderer *render, Paddle *paddle)
{


    SDL_SetRenderDrawColor(paddle->rendi, paddle->r, paddle->g, paddle->b, paddle->o);
    SDL_RenderDrawRect(render, paddle->rect);
    SDL_RenderFillRect(render, paddle->rect);


}
void moveUp(Paddle *paddle)
{
paddle->yvel = -4;
}
void moveDown(Paddle *paddle)
{
paddle->yvel = 4;
puts("moving down");
}
void stop(Paddle *paddle)
{
    paddle->yvel = 0;
}
Paddle *createPaddle(int w, int h, SDL_Renderer *rend, Uint8 r, Uint8 g, Uint8 b, Uint8 o, int xpos, int ypos)
{
    Paddle *paddle = (Paddle*)malloc(sizeof(Paddle));
    paddle->width = w;
    paddle->height = h;
    paddle->rendi = rend;
    paddle->xpos = xpos;
    paddle->ypos = ypos;
    SDL_Rect *rec = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    rec->w = w;
    rec->h = h;
    rec->x = xpos;
    rec->y = ypos;
    paddle->rect = rec;
    paddle->r = r;
    paddle->g = g;
    paddle->b = b;
    paddle->o = o;
    paddle->score = 0;
    paddle->yvel = 0;
    return paddle;
}
void moves(SDL_Renderer *render, Paddle *paddle)
{

    paddle->ypos = paddle->ypos + paddle->yvel;
    paddle->rect->y = paddle->rect->y + paddle->yvel;
        if((paddle->ypos < 0))
    {
            paddle->ypos = 0;
            paddle->rect->y = 0;
    }
    if((paddle->ypos+paddle->height) > 600)
    {
                    paddle->ypos = 600-paddle->height - 1;
                    paddle->rect->y = 600-paddle->height - 1;
    }
    SDL_SetRenderDrawColor(paddle->rendi, paddle->r, paddle->g, paddle->b, paddle->o);
    SDL_RenderDrawRect(render, paddle->rect);
    SDL_RenderFillRect(render, paddle->rect);
}
