#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/sdl_utils.h"

int main (int argc, char **argv){
  
  if (SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0){
    fprintf(stderr, "%s", SDL_GetError());
    return EXIT_FAILURE;
  }


  sdl_app *app = new_sdl_app();
  if (check_sdl_app(app) < 0){
    return EXIT_FAILURE;
  }
  
  _Bool running = 1;  

  SDL_Event event;

  
  while (running){
  
    while (SDL_PollEvent(&event)){          
        SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);
        SDL_RenderClear(app->renderer);
        SDL_RenderPresent(app->renderer);
        //SDL_UpdateWindowSurface(app->window);
        //Check if Esc is pressed
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE){
          running = 0;
          SDL_DestroyWindow(app->window);
          SDL_DestroyRenderer(app->renderer); 
        }
    
      }
    }
  SDL_Quit();
  printf("Hello, Kwasi!");  
  
  return EXIT_SUCCESS;
}

