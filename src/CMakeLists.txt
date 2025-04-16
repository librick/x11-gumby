cmake_minimum_required(VERSION 3.30)
project(X11CursorTest)

set(CMAKE_CXX_STANDARD 11)

find_package(X11 REQUIRED)

add_executable(cursor main.cpp)

target_include_directories(cursor PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(cursor ${X11_LIBRARIES})

