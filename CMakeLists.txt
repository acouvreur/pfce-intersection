cmake_minimum_required(VERSION 3.12)
project(pfce_intersection)

set(CMAKE_CXX_STANDARD 14)
SET(GCC_COVERAGE_COMPILE_FLAGS "-lglut -lGLU -lGL -lm -lstdc++")

add_executable(pfce_intersection main.cpp Segment.cpp Segment.h)

find_package(OpenGL)
find_package(GLUT)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(pfce_intersection ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})