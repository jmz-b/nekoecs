#include "sdl2_components.h"

ECS_COMPONENT_DECLARE(Sdl2Window);
ECS_COMPONENT_DECLARE(Sdl2Renderer);

void Sdl2ComponentsImport(ecs_world_t *world) {
  ECS_MODULE(world, Sdl2Components);
  ECS_COMPONENT_DEFINE(world, Sdl2Window);
  ECS_COMPONENT_DEFINE(world, Sdl2Renderer);
}
