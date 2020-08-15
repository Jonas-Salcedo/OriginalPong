#include <stdlib.h>
#include <stdio.h>
#include "SDL2\SDL.h"
#include "paddle.h"
#include "ball.h"
#include "menu.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL_ttf.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "winner.h"
#include <time.h>
int main(int argc, char* argv[])
{
    srand(time(0));
    int PLAYER_ONE_SCORE = 0;
    int PLAYER_TWO_SCORE = 0;
    int count = 0;
    int randomnum = rand()%3;
    int randomMillisecs = rand()%50;
    bool done = false;
    bool done2 = false;
    bool trigger = false;
    char SCORESTRINGONE[80] = "";
    char SCORESTRINGTWO[80] = "";
    char SCORE_HOLDER_ONE[8] = "SCORE: ";
    char SCORE_HOLDER_TWO[8] = "SCORE: ";
    char SCORE_DISPLAY_ONE[80] = "";
    char SCORE_DISPLAY_TWO[80] = "";
    int randomPixelsAwayFromCenter = 0;
    clock_t startTime = clock();
    bool isTitle = true;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    sprintf(SCORESTRINGONE,  "%d", PLAYER_ONE_SCORE);
    sprintf(SCORESTRINGTWO,  "%d", PLAYER_TWO_SCORE);
    strcat(SCORE_DISPLAY_ONE, SCORE_HOLDER_ONE);
    strcat(SCORE_DISPLAY_ONE, SCORESTRINGONE);
    strcat(SCORE_DISPLAY_TWO, SCORE_HOLDER_TWO);
    strcat(SCORE_DISPLAY_TWO, SCORESTRINGTWO);
    SDL_Window *win = SDL_CreateWindow("PONG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, 0);

    SDL_SetRenderDrawColor(rend, 255,255,255,0);
    TTF_Font *f = TTF_OpenFont("arial.ttf",12);
    TTF_Font *f2 = TTF_OpenFont("arial.ttf",18);

    if(!f)
    {

 printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    SDL_Color c = {0,0,255,0};

    SDL_Surface *textSurface = TTF_RenderText_Solid(f, SCORE_DISPLAY_ONE, c);
    SDL_Surface *textSurface2 = TTF_RenderText_Solid(f, SCORE_DISPLAY_TWO, c);
    SDL_Surface *textSurfaceTitle = TTF_RenderText_Solid(f2, "PONG" , c);
    SDL_Surface *textSurfacePlay = TTF_RenderText_Solid(f2, "PLAY" , c);
    SDL_Surface *textSurfaceQuit = TTF_RenderText_Solid(f2, "QUIT" , c);
    SDL_Surface *textSurfacePlayAgain = TTF_RenderText_Solid(f2, "PRESS SPACE TO PLAY AGAIN" , c);
    SDL_Surface *textSurfaceWinner = TTF_RenderText_Solid(f2, "PLAYER 1 WINS" , c);
    SDL_Texture *t = SDL_CreateTextureFromSurface(rend, textSurface);
    SDL_Texture *t2 = SDL_CreateTextureFromSurface(rend, textSurface2);
     SDL_Texture *tt = SDL_CreateTextureFromSurface(rend, textSurfaceTitle);
     SDL_Texture *tp = SDL_CreateTextureFromSurface(rend, textSurfacePlay);
     SDL_Texture *tq = SDL_CreateTextureFromSurface(rend, textSurfaceQuit);
     SDL_Texture *playAgain = SDL_CreateTextureFromSurface(rend, textSurfacePlayAgain);
     SDL_Texture *winner = SDL_CreateTextureFromSurface(rend, textSurfaceWinner);
    SDL_Rect texrec = {100,0,40,40};
    SDL_Rect texrec2 = {660,0,40,40};
    SDL_Rect texrectitle = {0,0,0,0};
    SDL_Rect texrecplay = {0,0,0,0};
    SDL_Rect texrecquit = {0,0,0,0};
    SDL_Rect texrecplayagain = {0,0,0,0};
    SDL_Rect texrecwinner = {0,0,0,0};

    SDL_QueryTexture(t, NULL, NULL, &texrec.w, &texrec.h);
    SDL_QueryTexture(t2, NULL, NULL, &texrec2.w, &texrec2.h);
    SDL_QueryTexture(tt, NULL, NULL, &texrectitle.w, &texrectitle.h);
    SDL_QueryTexture(tp, NULL, NULL, &texrecplay.w, &texrecplay.h);
    SDL_QueryTexture(tq, NULL, NULL, &texrecquit.w, &texrecquit.h);
    SDL_QueryTexture(playAgain, NULL, NULL, &texrecplayagain.w, &texrecplayagain.h);
    SDL_QueryTexture(winner, NULL, NULL, &texrecwinner.w, &texrecwinner.h);
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(textSurface2);
    SDL_FreeSurface(textSurfaceTitle);
    SDL_FreeSurface(textSurfacePlay);
    SDL_FreeSurface(textSurfaceQuit);
        SDL_FreeSurface(textSurfacePlayAgain);
    SDL_FreeSurface(textSurfaceWinner);
    textSurface = NULL;
    textSurface2 = NULL;
    textSurfaceTitle = NULL;
    textSurfacePlay = NULL;
    textSurfaceQuit = NULL;
    textSurfacePlayAgain = NULL;
    textSurfaceWinner = NULL;

    SDL_SetRenderDrawColor(rend, 0xFF, 0, 0, 0);
    bool isRunning = true;
    SDL_Event e;
    //Creates paddles 1 and 2
    Paddle *p1 = createPaddle(20, 100, rend, 0,0,0,0,100,250);
    Paddle *p2 = createPaddle(20, 100, rend, 0,0,0,0,700,250);
    Ball *ball = createBall(10,rend, 0, 0, 0, 0, 400, 300);
    randomPixelsAwayFromCenter = rand()%50;
    while(e.type != SDL_QUIT)
    {
                    if(ball->xVel < 1)
                    {
                        done = false;
                        done2 = false;
                        trigger = false;
                    }
                    if(done == false)
                    {
                        randomnum = rand()%3;
                        done = true;

                    }

                    texrectitle.x = 400;
                    texrectitle.y = 300;
                    texrectitle.w = 80;
                    texrectitle.h = 35;
                    texrecplay.x = 400;
                    texrecplay.y = 400;
                    texrecplay.w = 80;
                    texrecplay.h = 35;

                    texrecquit.x = 400;
                    texrecquit.y = 500;
                    texrecquit.w = 80;
                    texrecquit.h = 35;

                    texrecwinner.x = 360;
                    texrecwinner.y = 200;
                    texrecwinner.w = 160;
                    texrecwinner.h = 70;

                    texrecplayagain.x = 295;
                    texrecplayagain.y = 300;
                    texrecplayagain.w = 160;
                    texrecplayagain.h = 70;

        PLAYER_ONE_SCORE = p1->score;
        PLAYER_TWO_SCORE = p2->score;
        SDL_Delay(1000/180);
        SDL_PollEvent(&e);
        SDL_SetRenderDrawColor(rend, 255,255,255,0);

        SDL_RenderClear(rend);
        if(isTitle == false){
        if(e.type == SDL_QUIT)
        {
            isRunning = false;
        }
        else if(e.type == SDL_KEYDOWN)
        {
            if(e.key.keysym.sym == SDLK_w)
            {

                moveUp(p1);
            }
            else if(e.key.keysym.sym == SDLK_s)
            {

                moveDown(p1);
            }
            else if(e.key.keysym.sym == SDLK_r)
            {
                isTitle = true;
                for(int b = 0; b<80; b++){
                   SCORESTRINGONE[b] = '\0';
                   SCORESTRINGONE[b] = '\0';
                   SCORE_DISPLAY_ONE[b] = '\0';
                   SCORE_DISPLAY_TWO[b] = '\0';
               }
    p1->xpos = 100;
    p1->ypos = 250;
    p1->rect->x = 100;
    p1->rect->y = 250;
    p1->score = 0;
    p1->yvel = 0;
    p2->xpos = 700;
    p2->ypos = 250;
    p2->rect->x = 700;
    p2->rect->y = 250;
    p2->score = 0;
    p2->yvel = 0;
    ball->xpos = 400;
    ball->ypos = 300;
    ball->yVel = 0;
    ball->xVel = 2;
    PLAYER_ONE_SCORE = 0;
    PLAYER_TWO_SCORE = 0;
    SDL_DestroyTexture(t);
    SDL_DestroyTexture(t2);
    sprintf(SCORESTRINGONE,  "%d", PLAYER_ONE_SCORE);
    sprintf(SCORESTRINGTWO,  "%d", PLAYER_TWO_SCORE);
    strcat(SCORE_DISPLAY_ONE, SCORE_HOLDER_ONE);
    strcat(SCORE_DISPLAY_ONE, SCORESTRINGONE);
    strcat(SCORE_DISPLAY_TWO, SCORE_HOLDER_TWO);
    strcat(SCORE_DISPLAY_TWO, SCORESTRINGTWO);
               textSurface = TTF_RenderText_Solid(f, SCORE_DISPLAY_ONE, c);
           textSurface2 = TTF_RenderText_Solid(f, SCORE_DISPLAY_TWO, c);
           t = SDL_CreateTextureFromSurface(rend, textSurface);
           t2 = SDL_CreateTextureFromSurface(rend, textSurface2);

    SDL_QueryTexture(t, NULL, NULL, &texrec.w, &texrec.h);
    SDL_QueryTexture(t2, NULL, NULL, &texrec2.w, &texrec2.h);
               SDL_FreeSurface(textSurface);
    SDL_FreeSurface(textSurface2);
               textSurface = NULL;
    textSurface2 = NULL;
            }



        }
        else if(e.type == SDL_KEYUP)
        {
        stop(p1);

        }

        if(clock()-startTime >= randomMillisecs){
                            if((ball->yVel == 0) && (ball->xVel > 1) && (done2 == false) &&((ball->ypos  < ((p2->ypos + 100)) )) && ((ball->ypos  > ((p2->ypos )) ))){
                    printf("%d", randomnum);

            if(randomnum == 0)
            {
            stop(p2);
            startTime = clock();
            randomPixelsAwayFromCenter = rand()%50;
            count = 0;
            randomMillisecs = rand()%90;
            }
            else if(randomnum == 1)
            { trigger = true;
            puts("first option");
                if(count < 7)
                {
                    p2->rect->y -= 4;
                    p2->ypos-= 4;
                    count++;
                }
                else
                {
            startTime = clock();
            randomPixelsAwayFromCenter = rand()%50;
             randomMillisecs = rand()%90;
            count = 0;
            done2 = true;
                }
            }
            else if(randomnum == 2)
            {
                trigger = true;
                puts("second option");
                if(count < 7)
                {
                    p2->rect->y += 4;
                    p2->ypos+= 4;
                    count++;
                }
                else
                {
                    puts("third option");
            startTime = clock();
            randomPixelsAwayFromCenter = rand()%50;
             randomMillisecs = rand()%90;
            count = 0;
            done2 = true;
                }
            }

            }
        else if((ball->ypos < ((p2->ypos+25) - randomPixelsAwayFromCenter)))
        {
            puts("moveup");
            moveUp(p2);

        }
        else if(ball->ypos  > ((p2->ypos + 75) + randomPixelsAwayFromCenter))
        {
            puts("movedown");
            moveDown(p2);

        }
        else
        {

puts("stop");
                stop(p2);
            startTime = clock();
            randomPixelsAwayFromCenter = rand()%50;
            randomMillisecs = rand()%90;


        }
        }
       // TTF_RenderText_Solid(f, "text", c);

        if(PLAYER_ONE_SCORE >= 9 || PLAYER_TWO_SCORE>=9)
        {
                    //SDL_DestroyTexture(winner);
                    //SDL_DestroyTexture(playAgain);
                    drawPaddle(rend, p1);
                    drawPaddle(rend, p2);
                    if(PLAYER_TWO_SCORE>=9)
                    {
                        SDL_DestroyTexture(winner);
                        textSurfaceWinner = TTF_RenderText_Solid(f2, "PLAYER 2 WINS" , c);
                        winner = SDL_CreateTextureFromSurface(rend, textSurfaceWinner);

                    }
                    else
                    {
                                                SDL_DestroyTexture(winner);
                        textSurfaceWinner = TTF_RenderText_Solid(f2, "PLAYER 1 WINS" , c);
                        winner = SDL_CreateTextureFromSurface(rend, textSurfaceWinner);
                    }

                     SDL_QueryTexture(playAgain, NULL, NULL, &texrecplayagain.w, &texrecplayagain.h);
                     SDL_QueryTexture(winner, NULL, NULL, &texrecwinner.w, &texrecwinner.h);
                    drawWinner(rend, winner, playAgain, &texrecwinner, &texrecplayagain);

                    if(e.type == SDL_KEYDOWN)
                    {

                        if(e.key.keysym.sym == SDLK_SPACE)
                    {
                        SDL_DestroyTexture(t);
                        PLAYER_ONE_SCORE = 0;
                        PLAYER_TWO_SCORE = 0;
                        p1->score = 0;
                        p2->score = 0;
                        p1->ypos = 250;
                        p1->rect->y = 250;
                        p2->ypos = 250;
                        p2->rect->y = 250;

            PLAYER_ONE_SCORE = p1->score;
            PLAYER_TWO_SCORE = p2->score;
               for(int b = 0; b<80; b++){
                   SCORESTRINGONE[b] = '\0';
                   SCORESTRINGONE[b] = '\0';
                   SCORE_DISPLAY_ONE[b] = '\0';
                   SCORE_DISPLAY_TWO[b] = '\0';
               }
              // SCORE_HOLDER_ONE[8] = "SCORE: ";
              // SCORE_HOLDER_TWO[8] = "SCORE: ";
            sprintf(SCORESTRINGONE,  "%d", PLAYER_ONE_SCORE);
            sprintf(SCORESTRINGTWO,  "%d", PLAYER_TWO_SCORE);
            strcat(SCORE_DISPLAY_ONE, SCORE_HOLDER_ONE);
            strcat(SCORE_DISPLAY_ONE, SCORESTRINGONE);
            strcat(SCORE_DISPLAY_TWO, SCORE_HOLDER_TWO);
            strcat(SCORE_DISPLAY_TWO, SCORESTRINGTWO);
           textSurface = TTF_RenderText_Solid(f, SCORE_DISPLAY_ONE, c);
           textSurface2 = TTF_RenderText_Solid(f, SCORE_DISPLAY_TWO, c);
           t = SDL_CreateTextureFromSurface(rend, textSurface);
           t2 = SDL_CreateTextureFromSurface(rend, textSurface2);
           //texrec = {100,0,40,40};
           //texrec2 = {600,0,40,40};

    SDL_QueryTexture(t, NULL, NULL, &texrec.w, &texrec.h);
    SDL_QueryTexture(t2, NULL, NULL, &texrec2.w, &texrec2.h);
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(textSurface2);
    SDL_FreeSurface(textSurfaceTitle);
    SDL_FreeSurface(textSurfacePlay);
    SDL_FreeSurface(textSurfaceQuit);
    textSurface = NULL;
    textSurface2 = NULL;


                    }

        }
                          // SDL_FreeSurface(textSurfacePlayAgain);
    //SDL_FreeSurface(textSurfaceWinner);
        }
        else
        {
        moves(rend, p1);
        moves(rend, p2);
        }
        //drawPaddle(rend, p1);
        //drawPaddle(rend, p2);
        if(!(PLAYER_ONE_SCORE >= 9 || PLAYER_TWO_SCORE>=9))
        {
        bounceAround(rend, ball);

        }
        detectCollisionWithRect(rend, ball, p1);
        detectCollisionWithRect(rend, ball, p2);
        if(collideLeftSide(rend,ball, p2)==true)
            {
                SDL_DestroyTexture(t);
            PLAYER_ONE_SCORE = p1->score;
            PLAYER_TWO_SCORE = p2->score;
               for(int b = 0; b<80; b++){
                   SCORESTRINGONE[b] = '\0';
                   SCORESTRINGONE[b] = '\0';
                   SCORE_DISPLAY_ONE[b] = '\0';
                   SCORE_DISPLAY_TWO[b] = '\0';
               }
              // SCORE_HOLDER_ONE[8] = "SCORE: ";
              // SCORE_HOLDER_TWO[8] = "SCORE: ";
            sprintf(SCORESTRINGONE,  "%d", PLAYER_ONE_SCORE);
            sprintf(SCORESTRINGTWO,  "%d", PLAYER_TWO_SCORE);
            strcat(SCORE_DISPLAY_ONE, SCORE_HOLDER_ONE);
            strcat(SCORE_DISPLAY_ONE, SCORESTRINGONE);
            strcat(SCORE_DISPLAY_TWO, SCORE_HOLDER_TWO);
            strcat(SCORE_DISPLAY_TWO, SCORESTRINGTWO);
           textSurface = TTF_RenderText_Solid(f, SCORE_DISPLAY_ONE, c);
           textSurface2 = TTF_RenderText_Solid(f, SCORE_DISPLAY_TWO, c);
           t = SDL_CreateTextureFromSurface(rend, textSurface);
           t2 = SDL_CreateTextureFromSurface(rend, textSurface2);
           //texrec = {100,0,40,40};
           //texrec2 = {600,0,40,40};

    SDL_QueryTexture(t, NULL, NULL, &texrec.w, &texrec.h);
    SDL_QueryTexture(t2, NULL, NULL, &texrec2.w, &texrec2.h);
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(textSurface2);
    SDL_FreeSurface(textSurfaceTitle);
    SDL_FreeSurface(textSurfacePlay);
    SDL_FreeSurface(textSurfaceQuit);
    textSurface = NULL;
    textSurface2 = NULL;
            SDL_Delay(1000);
        }
        if(collideRightSide(rend,ball, p1) == true)
        {
          SDL_DestroyTexture(t);
            PLAYER_ONE_SCORE = p1->score;
            PLAYER_TWO_SCORE = p2->score;
               for(int b = 0; b<80; b++){
                   SCORESTRINGONE[b] = '\0';
                   SCORESTRINGONE[b] = '\0';
                   SCORE_DISPLAY_ONE[b] = '\0';
                   SCORE_DISPLAY_TWO[b] = '\0';
               }

               //SCORE_HOLDER_ONE[8] = "SCORE: ";
               //SCORE_HOLDER_TWO[8] = "SCORE: ";
            sprintf(SCORESTRINGONE,  "%d", PLAYER_ONE_SCORE);
            sprintf(SCORESTRINGTWO,  "%d", PLAYER_TWO_SCORE);
            strcat(SCORE_DISPLAY_ONE, SCORE_HOLDER_ONE);
            strcat(SCORE_DISPLAY_ONE, SCORESTRINGONE);
            strcat(SCORE_DISPLAY_TWO, SCORE_HOLDER_TWO);
            strcat(SCORE_DISPLAY_TWO, SCORESTRINGTWO);
           textSurface = TTF_RenderText_Solid(f, SCORE_DISPLAY_ONE, c);
           textSurface2 = TTF_RenderText_Solid(f, SCORE_DISPLAY_TWO, c);
           t = SDL_CreateTextureFromSurface(rend, textSurface);
           t2 = SDL_CreateTextureFromSurface(rend, textSurface2);
           //texrec = {100,0,40,40};
          // texrec2 = {600,0,40,40};

    SDL_QueryTexture(t, NULL, NULL, &texrec.w, &texrec.h);
    SDL_QueryTexture(t2, NULL, NULL, &texrec2.w, &texrec2.h);
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(textSurface2);
    textSurface = NULL;
    textSurface2 = NULL;
            SDL_Delay(1000);
        }
        SDL_SetRenderDrawColor(rend, 0,0,0,0);
 SDL_RenderCopy(rend, t, NULL, &texrec);
  SDL_RenderCopy(rend, t2, NULL, &texrec2);
  //drawMenu(rend, tt, tp, tq, &texrectitle, &texrecplay, &texrecquit);
        SDL_RenderPresent(rend);
    }
    else
    {
        if(e.type == SDL_QUIT)
        {
            isRunning = false;
        }
                if((e.button.x >=texrecplay.x) && (e.button.x <= (texrecplay.w + texrecplay.x)) && (e.button.y >= texrecplay.y) && (e.button.y <= (texrecplay.y + texrecplay.h)))
                {
                    //f2 = TTF_OpenFont("arial.ttf",24);
                    texrecplay.x = 365;
                    texrecplay.y = 365;
                    texrecplay.w = 160;
                    texrecplay.h = 70;
                    if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                    {
                        isTitle = false;
                    }
                }
                else
                {
                    texrecplay.x = 400;
                    texrecplay.y = 400;
                    texrecplay.w = 80;
                    texrecplay.h = 35;
                }

                if((e.button.x >=texrecquit.x) && (e.button.x <= (texrecquit.w + texrecquit.x)) && (e.button.y >= texrecquit.y) && (e.button.y <= (texrecquit.y + texrecquit.h)))
                {
                    //f2 = TTF_OpenFont("arial.ttf",24);
                    texrecquit.x = 365;
                    texrecquit.y = 465;
                    texrecquit.w = 160;
                    texrecquit.h = 70;
                    if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                    {
                        e.type = SDL_QUIT;
                    }
                }
                else
                {
                    texrecquit.x = 400;
                    texrecquit.y = 500;
                    texrecquit.w = 80;
                    texrecquit.h = 35;
                }
                  drawMenu(rend, tt, tp, tq, &texrectitle, &texrecplay, &texrecquit);
        SDL_RenderPresent(rend);
            textSurfacePlayAgain = NULL;
    textSurfaceWinner = NULL;

    }

}
    SDL_DestroyRenderer(rend);
    SDL_DestroyTexture(t);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
