#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "SDL2\SDL.h"
void drawMenu(SDL_Renderer *rendi, SDL_Texture *title, SDL_Texture *titlePlay, SDL_Texture *titleQuit, SDL_Rect *textbox, SDL_Rect *textboxplay, SDL_Rect *textboxquit);
//void ifClicked();

#endif // MENU_H_INCLUDED
