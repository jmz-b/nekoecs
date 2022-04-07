cmake_minimum_required(VERSION 3.13)

project(flecs_platform_sdl2 LANGUAGES C)

include(FetchFlecs)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB_RECURSE INC include/*.h include/*.hpp)
file(GLOB_RECURSE SRC src/*.c)

add_library(flecs_platform_sdl2 SHARED ${INC} ${SRC})
add_library(flecs::flecs_platform_sdl2 ALIAS flecs_platform_sdl2)

target_include_directories(flecs_platform_sdl2
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        SDL2::Main
        SDL2::Image
        flecs::flecs
        flecs::flecs_components_gui
        flecs::flecs_components_input
)

include(GNUInstallDirs)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h")

install(TARGETS flecs_platform_sdl2
        EXPORT flecs_platform_sdl2-export
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(EXPORT flecs_platform_sdl2-export
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/flecs_platform_sdl2
        NAMESPACE flecs::
        FILE flecs_platform_sdl2-config.cmake)