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
- [nlohmann/json](https://github.com/nlohmann/json) library (for JSON manipulation)

### Installation

Follow these steps to set up and run the project:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/task-tracker.git
   cd task-tracker
