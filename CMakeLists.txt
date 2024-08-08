cmake_minimum_required(VERSION 3.30)

project(BGEIC)

include_directories(BGEIC include/)
set(BGEIC_SOURCES sources/main.cpp
                  sources/Window.cpp)

add_executable(BGEIC ${BGEIC_SOURCES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TEST OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/glfw-3.4)
target_link_libraries(BGEIC glfw)

add_subdirectory(deps/glad)
target_link_libraries(BGEIC glad)

add_subdirectory(deps/lua-5.3.4)
target_link_libraries(BGEIC LuaLib)

add_subdirectory(deps/json-parser)
target_link_libraries(BGEIC nlohmann_json)