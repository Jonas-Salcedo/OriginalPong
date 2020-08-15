#include <stdlib.h>
#include <stdio.h>
#include "SDL2\SDL.h"
#include "menu.h"
void drawMenu(SDL_Renderer *rendi, SDL_Texture *title, SDL_Texture *titlePlay, SDL_Texture *titleQuit, SDL_Rect *textbox, SDL_Rect *textboxplay, SDL_Rect *textboxquit){
    SDL_RenderCopy(rendi, title, NULL, textbox);
    SDL_RenderCopy(rendi, titlePlay, NULL, textboxplay);
    SDL_RenderCopy(rendi, titleQuit, NULL, textboxquit);
}

