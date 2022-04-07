#ifndef SDL2_COMPONENTS__H
#define SDL2_COMPONENTS__H

#include <SDL.h>
#include <flecs.h>

typedef struct Sdl2Renderer {
  SDL_Renderer *renderer;
} Sdl2Renderer;

typedef struct Sdl2Window {
  SDL_Window *window;
} Sdl2Window;

extern ECS_COMPONENT_DECLARE(Sdl2Window);
extern ECS_COMPONENT_DECLARE(Sdl2Renderer);

void Sdl2ComponentsImport(ecs_world_t *world);

#endif
