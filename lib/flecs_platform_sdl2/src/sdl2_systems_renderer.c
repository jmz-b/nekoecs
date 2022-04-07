#include "sdl2_systems_renderer.h"

static void Sdl2CreateRenderer(ecs_iter_t *it) {
  Sdl2Window *sdl2_window = ecs_term(it, Sdl2Window, 1);

  int i;
  for (i = 0; i < it->count; i++) {
    ecs_entity_t e = it->entities[i];

    SDL_Renderer *sdl_renderer =
        SDL_CreateRenderer(sdl2_window->window, -1, SDL_RENDERER_ACCELERATED);

    if (!sdl_renderer) {
      ecs_err("SDL2 renderer creation failed: %s\n", SDL_GetError());
      ecs_quit(it->world);
    }

    ecs_set(it->world, e, Sdl2Renderer, {.renderer = sdl_renderer});
  }
}

static void Sdl2DestroyRenderer(ecs_iter_t *it) {
  Sdl2Renderer *sdl2_renderer = ecs_term(it, Sdl2Renderer, 1);

  int i;
  for (i = 0; i < it->count; i++) {
    SDL_DestroyRenderer(sdl2_renderer[i].renderer);
  }
}

void Sdl2SystemsRendererImport(ecs_world_t *world) {
  ECS_MODULE(world, Sdl2SystemsRenderer);
  ECS_IMPORT(world, Sdl2Components);

  ECS_OBSERVER(world, Sdl2CreateRenderer,
               EcsOnSet, [in] sdl2.components.Sdl2Window,
               [out] sdl2.components.Sdl2Renderer());

  ECS_OBSERVER(world, Sdl2DestroyRenderer,
               EcsOnSet, [in] sdl2.components.Sdl2Renderer());
}
