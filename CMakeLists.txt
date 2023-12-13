cmake_minimum_required(VERSION 3.0)
project(opengl-c-template)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CGLM_FOLDER src/vendor/cglm-0.8.9)
set(GLAD_FOLDER src/vendor/glad-5bf3eda)
set(GLEW_FOLDER src/vendor/glew-cmake-2.2.0)
set(GLFW_FOLDER src/vendor/glfw-3.3.8)
set(LPG3D_FOLDER src/vendor/lpg3dmath)
set(STB_FOLDER src/vendor/stb-5736b15)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(${GLFW_FOLDER})

option(CGLM_SHARED "Shared build" OFF)
option(CGLM_STATIC "Static build" ON)
option(CGLM_USE_C99 "" ON) # C11
option(CGLM_USE_TEST "Enable Tests" OFF) # for make check - make test
add_subdirectory(${CGLM_FOLDER})

add_definitions(-DGLEW_STATIC)
add_subdirectory(${GLEW_FOLDER} ${CMAKE_CURRENT_BINARY_DIR}/vendor/glew-cmake-2.2.0)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

include_directories(src/
					${lpg3dmath}
					${GLAD_FOLDER}/include/
					# ${GLEW_FOLDER}/include/
					${GLFW_FOLDER}/include/
					${CGLM_FOLDER}/include/
					${STB_FOLDER})

file(GLOB VENDORS_SOURCES ${GLAD_FOLDER}/src/glad.c)
file(GLOB PROJECT_HEADERS src/*.h)
file(GLOB PROJECT_SOURCES src/*.c)
file(GLOB PROJECT_SHADERS src/shaders/*.comp
                          src/shaders/*.frag
                          src/shaders/*.geom
                          src/shaders/*.vert)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md
                         .gitattributes
                         .gitignore
                         .gitmodules)

source_group("headers" FILES ${PROJECT_HEADERS})
source_group("shaders" FILES ${PROJECT_SHADERS})
source_group("sources" FILES ${PROJECT_SOURCES})
source_group("vendors" FILES ${VENDORS_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${PROJECT_CONFIGS}
                               ${VENDORS_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw libglew_static
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/shaders $<TARGET_FILE_DIR:${PROJECT_NAME}>
    DEPENDS ${PROJECT_SHADERS})
