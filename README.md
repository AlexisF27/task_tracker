# Task Tracker

A simple C++ task tracker application that allows you to manage your tasks through a command-line interface. It supports adding, updating, deleting, marking tasks as done or in-progress, and listing tasks. The task data is stored in a JSON file (`tasks.json`), which is automatically created if it doesn't exist.

## Features

- Add new tasks
- Update task descriptions
- Delete tasks
- Mark tasks as "in-progress" or "done"
- List all tasks or filter by status
- Tasks are stored in a JSON file for persistence

## Prerequisites

- C++11 or later
- [CMake](https://cmake.org/) for building the project
- The [nlohmann/json](https://github.com/nlohmann/json) library for JSON manipulation

### Installing Dependencies

1. **Install C++ tools**:

   On Ubuntu or other Debian-based systems, install the required tools with:
   ```bash
   sudo apt update
   sudo apt install cmake g++ make

2. **Set up the nlohmann/json library:**:
The nlohmann/json library is used to handle JSON data in the project. Follow these steps to manually include the library:
- Download the json.hpp file from the official GitHub repository:
  ```bash
  wget https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp -P include/nlohmann/
