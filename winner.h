#ifndef WINNER_H_INCLUDED
#define WINNER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "SDL2\SDL.h"
#include <stdbool.h>
void drawWinner(SDL_Renderer *rendi, SDL_Texture *winner, SDL_Texture *playAgain,  SDL_Rect *winnertextbox, SDL_Rect *playagaintextbox);

#endif // WINNER_H_INCLUDED
