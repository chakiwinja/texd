#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
} sdl_app;

sdl_app *new_sdl_app();
int check_sdl_app(sdl_app *app);





