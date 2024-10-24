#include "../include/sdl_utils.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>


int check_sdl_app(sdl_app *app){
  
  if (!app->window | !app->renderer) {
    fprintf(stderr,"%s\n", SDL_GetError());
    return -1;
  } else {
    return 0;
  }
}


sdl_app *new_sdl_app() {
  sdl_app *app = malloc(sizeof(sdl_app));
  app->window = SDL_CreateWindow("Texd", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, 0);
  app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
  return app;
}


