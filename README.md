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

This command downloads the json.hpp file inside your root project. Ensure that your project's include directory is correctly set up for the compiler to find the file.
  


### Building the Project

1. **Clone the repository**:
   
   ```bash
   git clone https://github.com/your-username/task-tracker.git
   cd task-tracker

2. **Create a build directory**:
```bash
mkdir build
cd build

3. **Create a build directory**:
```bash
cmake ..
make
4. **Run the application**: 
After building the project, the task_tracker executable will be available in the build directory:
```bash
./task_tracker

### Usage
Once the application is running, you can use the following commands to interact with the task manager.

### Commands

- Add a task:
```bash
./task_tracker add "Task description"

- Update a task:
```bash
./task_tracker update <Task ID> "New task description"

- Delete a task:
```bash
./task_tracker delete <Task ID>

- Mark a task as in-progress:
```bash
./task_tracker mark-in-progress <Task ID>

- Mark a task as done:
```bash
./task_tracker mark-done <Task ID>

- List all tasks:
```bash
./task_tracker list

- List tasks with a specific filter (e.g., by status):
Where <status> can be "in-progress", "done", etc.
```bash
./task_tracker list <status>



Examples
Add a task:

bash
./task_tracker add "Complete homework"
List all tasks:

bash
./task_tracker list
Update the task with ID 1:

bash
./task_tracker update 1 "Complete math homework"
Mark the task with ID 1 as done:

bash
./task_tracker mark-done 1
List tasks with a specific status (e.g., "in-progress"):

bash
./task_tracker list "in-progress"
Delete the task with ID 1:

bash
./task_tracker delete 1



