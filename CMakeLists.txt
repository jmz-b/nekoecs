cmake_minimum_required(VERSION 3.13)

project(nekoecs LANGUAGES C)

file(GLOB MODS lib/cmake/* LIST_DIRECTORIES true)
list(APPEND CMAKE_MODULE_PATH ${MODS})

include(FetchFlecs)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(lib/flecs_components_gui)
add_subdirectory(lib/flecs_components_input)
add_subdirectory(lib/flecs_platform_sdl2)

file(GLOB_RECURSE INC include/*.h include/*.hpp)
file(GLOB_RECURSE SRC src/*.c)

add_executable(nekoecs ${INC} ${SRC})

target_include_directories(nekoecs
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(nekoecs
    PRIVATE
        flecs
        flecs_components_gui
        flecs_components_input
        flecs_platform_sdl2
)

include(GNUInstallDirs)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h")

install(TARGETS nekoecs
        EXPORT nekoecs-export
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(EXPORT nekoecs-export
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/nekoecs
        NAMESPACE nekoecs::
        FILE nekoecs-config.cmake)