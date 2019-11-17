cmake_minimum_required(VERSION 3.15)
project(GLTT)

# find stuff

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics window system)
find_package(GLM REQUIRED)

# test if we found everything

if (NOT OPENGL_FOUND)
    message(FATAL_ERROR "This system doesn't seem to support OpenGL, or OpenGL wasn't found by CMake")
endif()

if (NOT GLEW_FOUND)
    message(FATAL_ERROR "Unable to find GLEW")
endif()

if (NOT SFML_FOUND)
    message(FATAL_ERROR "Unable to find SFML")
endif()

if (NOT GLM_FOUND)
    message(FATAL_ERROR "Unable to find GLM")
endif()

# directories

include_directories(include $(GLEW_INCLUDE_DIRS) $(SFML_INCLUDE_DIRS) $(GLM_INCLUDE_DIRS))

set(LIBS glew sfml-graphics sfml-window sfml-system)

if (APPLE)
    set(LIBS ${LIBS} "-framework OpenGL")
else()
    if (MSVC)
        set(LIBS ${LIBS} opengl32)
    else()
        set(LIBS ${LIBS} GL)
    endif()
endif()

# other

set(CMAKE_CXX_STANDARD 17)

# artifacts

add_executable(GLTT include/GL.hpp main.cpp include/entt/entt.hpp include/mc/DefaultEntities.hpp include/mc/RenderEntities.hpp include/mc/RenderSystems.hpp)
target_link_libraries(GLTT ${LIBS})