#include <flecs.h>
#include <flecs_components_gui.h>
#include <flecs_components_input.h>
#include <flecs_platform_sdl2.h>

#define TARGET_FPS 60
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[]) {
  /* Set Up World */
  ecs_world_t *world = ecs_init_w_args(argc, argv);
  ecs_set_target_fps(world, TARGET_FPS);

  /* Import Modules */
  ECS_IMPORT(world, EcsComponentsGui);
  ECS_IMPORT(world, EcsComponentsInput);
  ECS_IMPORT(world, EcsPlatformSdl2);

  /* Activate Input SYstem */
  ecs_singleton_add(world, EcsInput);

  /* Create Window System */
  ecs_set(world, 0, EcsCanvas,
          {.title = "nekoecs", .width = SCREEN_WIDTH, .height = SCREEN_HEIGHT});

  /* Run */
  ecs_app_run(world, &(ecs_app_desc_t){.enable_rest = true});

  /* Shutdown */
  return ecs_fini(world);
}
