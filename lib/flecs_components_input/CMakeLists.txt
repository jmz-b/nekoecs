cmake_minimum_required(VERSION 3.13)

project(flecs_components_input LANGUAGES C)

include(FetchFlecs)

file(GLOB_RECURSE INC include/*.h include/*.hpp)
file(GLOB_RECURSE SRC src/*.c)

add_library(flecs_components_input SHARED ${INC} ${SRC})
add_library(flecs::flecs_components_input ALIAS flecs_components_input)

target_include_directories(flecs_components_input
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        flecs::flecs
)

include(GNUInstallDirs)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h")

install(TARGETS flecs_components_input
        EXPORT flecs_components_input-export
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(EXPORT flecs_components_input-export
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/flecs_components_input
        NAMESPACE flecs::
        FILE flecs_components_input-config.cmake)