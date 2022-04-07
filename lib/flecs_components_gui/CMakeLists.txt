cmake_minimum_required(VERSION 3.13)

project(flecs_components_gui LANGUAGES C)

include(FetchFlecs)

file(GLOB_RECURSE INC include/*.h include/*.hpp)
file(GLOB_RECURSE SRC src/*.c)

add_library(flecs_components_gui SHARED ${INC} ${SRC})
add_library(flecs::flecs_components_gui ALIAS flecs_components_gui)

target_include_directories(flecs_components_gui
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

install(TARGETS flecs_components_gui
        EXPORT flecs_components_gui-export
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(EXPORT flecs_components_gui-export
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/flecs_components_gui
        NAMESPACE flecs::
        FILE flecs_components_gui-config.cmake)

