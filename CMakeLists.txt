cmake_minimum_required(VERSION 3.10)

# Project name
project(TaskTracker)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(task_tracker 
    src/main.cpp
    src/TaskManager/TaskManager.cpp
)