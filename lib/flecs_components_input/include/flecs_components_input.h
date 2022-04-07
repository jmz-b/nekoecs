#ifndef ECS_COMPONENTS_INPUT_H
#define ECS_COMPONENTS_INPUT_H

#include <flecs.h>

typedef struct ecs_key_state_t {
  bool pressed;
  bool state;
  bool current;
} ecs_key_state_t;

typedef struct ecs_mouse_coord_t {
  float x;
  float y;
} ecs_mouse_coord_t;

typedef struct mouse_state_t {
  ecs_key_state_t left;
  ecs_key_state_t right;
  ecs_mouse_coord_t wnd;
  ecs_mouse_coord_t rel;
  ecs_mouse_coord_t view;
  ecs_mouse_coord_t scroll;
} mouse_state_t;

typedef struct EcsInput {
  ecs_key_state_t keys[128];
  mouse_state_t mouse;
} EcsInput;

#define ECS_KEY_UNKNOWN ((int)0)
#define ECS_KEY_RETURN ((int)'\r')
#define ECS_KEY_ESCAPE ((int)'\033')
#define ECS_KEY_BACKSPACE ((int)'\b')
#define ECS_KEY_TAB ((int)'\t')
#define ECS_KEY_SPACE ((int)' ')
#define ECS_KEY_EXCLAIM ((int)'!')
#define ECS_KEY_QUOTEDBL ((int)'"')
#define ECS_KEY_HASH ((int)'#')
#define ECS_KEY_PERCENT ((int)'%')
#define ECS_KEY_DOLLAR ((int)'$')
#define ECS_KEY_AMPERSAND ((int)'&')
#define ECS_KEY_QUOTE ((int)'\'')
#define ECS_KEY_LEFTPAREN ((int)'(')
#define ECS_KEY_RIGHTPAREN ((int)')')
#define ECS_KEY_ASTERISK ((int)'*')
#define ECS_KEY_PLUS ((int)'+')
#define ECS_KEY_COMMA ((int)',')
#define ECS_KEY_MINUS ((int)'-')
#define ECS_KEY_PERIOD ((int)'.')
#define ECS_KEY_SLASH ((int)'/')
#define ECS_KEY_0 ((int)'0')
#define ECS_KEY_1 ((int)'1')
#define ECS_KEY_2 ((int)'2')
#define ECS_KEY_3 ((int)'3')
#define ECS_KEY_4 ((int)'4')
#define ECS_KEY_5 ((int)'5')
#define ECS_KEY_6 ((int)'6')
#define ECS_KEY_7 ((int)'7')
#define ECS_KEY_8 ((int)'8')
#define ECS_KEY_9 ((int)'9')
#define ECS_KEY_COLON ((int)':')
#define ECS_KEY_SEMICOLON ((int)';')
#define ECS_KEY_LESS ((int)'<')
#define ECS_KEY_EQUALS ((int)'=')
#define ECS_KEY_GREATER ((int)'>')
#define ECS_KEY_QUESTION ((int)'?')
#define ECS_KEY_AT ((int)'@')
#define ECS_KEY_LEFTBRACKET ((int)'[')
#define ECS_KEY_BACKSLASH ((int)'\\')
#define ECS_KEY_RIGHTBRACKET ((int)']')
#define ECS_KEY_CARET ((int)'^')
#define ECS_KEY_UNDERSCORE ((int)'_')
#define ECS_KEY_BACKQUOTE ((int)'`')
#define ECS_KEY_A ((int)'a')
#define ECS_KEY_B ((int)'b')
#define ECS_KEY_C ((int)'c')
#define ECS_KEY_D ((int)'d')
#define ECS_KEY_E ((int)'e')
#define ECS_KEY_F ((int)'f')
#define ECS_KEY_G ((int)'g')
#define ECS_KEY_H ((int)'h')
#define ECS_KEY_I ((int)'i')
#define ECS_KEY_J ((int)'j')
#define ECS_KEY_K ((int)'k')
#define ECS_KEY_L ((int)'l')
#define ECS_KEY_M ((int)'m')
#define ECS_KEY_N ((int)'n')
#define ECS_KEY_O ((int)'o')
#define ECS_KEY_P ((int)'p')
#define ECS_KEY_Q ((int)'q')
#define ECS_KEY_R ((int)'r')
#define ECS_KEY_S ((int)'s')
#define ECS_KEY_T ((int)'t')
#define ECS_KEY_U ((int)'u')
#define ECS_KEY_V ((int)'v')
#define ECS_KEY_W ((int)'w')
#define ECS_KEY_X ((int)'x')
#define ECS_KEY_Y ((int)'y')
#define ECS_KEY_Z ((int)'z')
#define ECS_KEY_DELETE ((int)127)

#define ECS_KEY_RIGHT ((int)'R')
#define ECS_KEY_LEFT ((int)'L')
#define ECS_KEY_DOWN ((int)'D')
#define ECS_KEY_UP ((int)'U')
#define ECS_KEY_CTRL ((int)'C')
#define ECS_KEY_SHIFT ((int)'S')
#define ECS_KEY_ALT ((int)'A')

extern ECS_COMPONENT_DECLARE(EcsInput);

void EcsComponentsInputImport(ecs_world_t *world);

#endif
