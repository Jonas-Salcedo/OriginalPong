#include <stdlib.h>
#include <stdio.h>
#include "SDL2\SDL.h"
#include "winner.h"
#include <stdbool.h>
void drawWinner(SDL_Renderer *rendi, SDL_Texture *winner, SDL_Texture *playAgain,  SDL_Rect *winnertextbox, SDL_Rect *playagaintextbox)
{
    SDL_RenderCopy(rendi, winner, NULL, winnertextbox);
    SDL_RenderCopy(rendi, playAgain, NULL, playagaintextbox);
}
