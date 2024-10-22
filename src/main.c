#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv){
  
  if (SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0){
    fprintf(stderr, "%s", SDL_GetError());
    return -1;
  }

  
  SDL_Window *window = SDL_CreateWindow("Texd", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, 0);


  if (!window) {
    printf("Niente finestra per la maestra");
    return -1;
  }

  SDL_Surface *window_surface = SDL_GetWindowSurface(window);

  if (!window_surface) {
    printf("Niente superficie per Beatrice");
    return -1;
  }

  _Bool running = 1;  

  SDL_Event event;

  while (running){
  
    while (SDL_PollEvent(&event)){ 
     
        SDL_UpdateWindowSurface(window);
        //Check if Esc is pressed
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE){
           running = 0; 
        }
    
      }
    }
  printf("Hello, Kwasi!");  
  
  return EXIT_SUCCESS;
}

