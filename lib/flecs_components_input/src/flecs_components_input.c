#include "flecs_components_input.h"

ECS_COMPONENT_DECLARE(EcsInput);

void EcsComponentsInputImport(ecs_world_t *world) {
  ECS_MODULE(world, EcsComponentsInput);
  ECS_COMPONENT_DEFINE(world, EcsInput);
}
