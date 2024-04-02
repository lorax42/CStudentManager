cmake_minimum_required(VERSION 3.20)
project(CStudentManager C)
file(GLOB src "src/*.c")
add_executable(${PROJECT_NAME} ${src})

