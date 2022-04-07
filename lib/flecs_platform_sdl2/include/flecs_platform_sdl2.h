#ifndef FLECS_PLATFORM_SDL2_H
#define FLECS_PLATFORM_SDL2_H

#include <SDL.h>
#include <flecs.h>

#include "sdl2_components.h"
#include "sdl2_systems_input.h"
#include "sdl2_systems_renderer.h"
#include "sdl2_systems_window.h"

void EcsPlatformSdl2Import(ecs_world_t *world);

#endif
