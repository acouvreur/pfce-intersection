cmake_minimum_required(VERSION 3.12)
project(pfce_intersection)

set(CMAKE_CXX_STANDARD 14)
SET(GCC_COVERAGE_COMPILE_FLAGS "-g -lglut -lGLU -lGL -lm -lstdc++ -lrt -O3")


add_library(libGraph "")

target_sources(libGraph PUBLIC

        "${CMAKE_CURRENT_LIST_DIR}/libGraph/GameEngineBase.h"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/GraphicEngineBase.h"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/GraphicPrimitives.h"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/TextureManager.h"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/Stopwatch.h"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/libGraphicInclude.h"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/Engine.h"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/GameEngineBase.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/GraphicEngineBase.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/GraphicPrimitives.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/TextureManager.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/libGraph/Engine.cpp"

        )

add_executable(pfce_intersection main.cpp Segment.cpp Segment.h MyGraphicEngine.cpp MyGraphicEngine.h MyGameEngine.cpp MyGameEngine.h)

find_package(OpenGL)
find_package(GLUT)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

target_link_libraries(pfce_intersection ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} libGraph -lpthread)

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})