#include "flecs_components_gui.h"

ECS_COMPONENT_DECLARE(EcsCanvas);

void EcsComponentsGuiImport(ecs_world_t *world) {
  ECS_MODULE(world, EcsComponentsGui);
  ECS_COMPONENT_DEFINE(world, EcsCanvas);
}
