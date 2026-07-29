# 1. Set the minimum CMake version required to build this project
cmake_minimum_required(VERSION 3.15)

# 2. Define the project name and programming language (defaults to C/C++)
project(MyProject LANGUAGES CXX)

# 3. Create an executable target named 'MyApp' from the source file 'main.cpp'
add_executable(MyApp main.cpp)
