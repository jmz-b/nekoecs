#ifndef ECS_COMPONENTS_GUI_H
#define ECS_COMPONENTS_GUI_H

#include <flecs.h>

typedef struct EcsCanvas {
  char *title;
  int32_t width;
  int32_t height;
} EcsCanvas;

extern ECS_COMPONENT_DECLARE(EcsCanvas);

void EcsComponentsGuiImport(ecs_world_t *world);

#endif
