#include "sdl2_systems_window.h"

static void Sdl2CreateWindow(ecs_iter_t *it) {
  EcsCanvas *ecs_window = ecs_term(it, EcsCanvas, 1);

  int i;
  for (i = 0; i < it->count; i++) {
    ecs_entity_t e = it->entities[i];

    const char *title = ecs_window[i].title;

    if (!title) {
      title = "SDL2 Window";
    }

    SDL_Window *sdl_window = SDL_CreateWindow(
        title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        ecs_window[i].width, ecs_window[i].height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);

    if (!sdl_window) {
      ecs_err("SDL2 window creation failed: %s\n", SDL_GetError());
      ecs_quit(it->world);
    }

    ecs_set(it->world, e, Sdl2Window, {.window = sdl_window});
  }
}

static void Sdl2DestroyWindow(ecs_iter_t *it) {
  Sdl2Window *sdl2_window = ecs_term(it, Sdl2Window, 1);

  int i;
  for (i = 0; i < it->count; i++) {
    ecs_entity_t e = it->entities[i];

    ecs_remove(it->world, e, Sdl2Renderer);
    SDL_DestroyWindow(sdl2_window[i].window);
  }
}

void Sdl2SystemsWindowImport(ecs_world_t *world) {
  ECS_MODULE(world, Sdl2SystemsWindow);
  ECS_IMPORT(world, Sdl2Components);
  ECS_IMPORT(world, EcsComponentsGui);

  ECS_OBSERVER(world, Sdl2CreateWindow,
               EcsOnSet, [in] ecs.components.gui.Canvas,
               [out] sdl2.components.Sdl2Window());

  ECS_OBSERVER(world, Sdl2DestroyWindow,
               EcsUnSet, [in] sdl2.components.Sdl2Window());
}
