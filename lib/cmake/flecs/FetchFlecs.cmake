include(FetchContent)

FetchContent_Declare(
  flecs
  GIT_REPOSITORY git@github.com:SanderMertens/flecs.git
  GIT_TAG        master
)

FetchContent_MakeAvailable(flecs)