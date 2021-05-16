cmake_minimum_required(VERSION 3.7)
project(graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wno-deprecated")

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main.cpp ${SOURCE_FILES} shape.h shape.cpp graphics.cpp graphics.h circle.h circle.cpp CircleButton.cpp CircleButton.h Square.cpp Square.h SquareButton.cpp SquareButton.h triangle.cpp triangle.h TriangleButton.cpp TriangleButton.h)

target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})