#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO)<0)
    {
        printf("Unable to initialize SDL: %s \n", SDL_GetError());
        exit(1);
    }
    SDL_Window *win = SDL_CreateWindow("Hello, world!", 100, 100, 640,480,SDL_WINDOW_SHOWN);
    if(win == NULL) {
        printf("SDL_CreateWindow Error: %s \n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        SDL_DestroyWindow(win);

        printf("SDL_CreateRenderer Error: %s \n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Surface *bmp = SDL_LoadBMP("test.bmp");
    if(bmp == NULL) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if(tex == NULL) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        printf("SDL_CreateTextureFromSurface Error: %s \n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    for (int i = 0; i < 3; ++i) {
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, NULL, NULL);
        SDL_RenderPresent(ren);
        SDL_Delay(1000);
    }
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
