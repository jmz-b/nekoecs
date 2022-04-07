#include "flecs_platform_sdl2.h"

void sdl2_fini(ecs_world_t *world, void *ctx) {
  (void)world;
  (void)ctx;
  SDL_Quit();
}

void EcsPlatformSdl2Import(ecs_world_t *world) {
  ECS_MODULE(world, EcsPlatformSdl2);
  ECS_IMPORT(world, Sdl2Components);
  ECS_IMPORT(world, Sdl2SystemsInput);
  ECS_IMPORT(world, Sdl2SystemsWindow);
  ECS_IMPORT(world, Sdl2SystemsRenderer);

  /* SDL deinitialization */
  ecs_atfini(world, sdl2_fini, NULL);

  /* SDL initialization */
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    ecs_err("Unable to initialize SDL: %s", SDL_GetError());
    return;
  }
}