#include <iostream>
#include <string>
#include "TaskManager/TaskManager.h"

int main(int argc, char* argv[]) {
    TaskManager taskManager;

    if (argc < 2) {
        std::cerr << "Error: No command provided. Available commands are: add, update, delete, mark-in-progress, mark-done, list." << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "add") {
        if (argc < 3) {
            std::cerr << "Error: Description is required for the 'add' command." << std::endl;
            return 1;
        }
        std::string description = argv[2];
        taskManager.addTask(description);

    } else if (command == "update") {
        if (argc < 4) {
            std::cerr << "Error: Task ID and new description are required for the 'update' command." << std::endl;
            return 1;
        }
        int id = std::stoi(argv[2]);
        std::string newDescription = argv[3];
        taskManager.updateTask(id, newDescription);

    } else if (command == "delete") {
        if (argc < 3) {
            std::cerr << "Error: Task ID is required for the 'delete' command." << std::endl;
            return 1;
        }
        int id = std::stoi(argv[2]);
        taskManager.deleteTask(id);

    } else if (command == "mark-in-progress") {
        if (argc < 3) {
            std::cerr << "Error: Task ID is required for the 'mark-in-progress' command." << std::endl;
            return 1;
        }
        int id = std::stoi(argv[2]);
        taskManager.markInProgress(id);

    } else if (command == "mark-done") {
        if (argc < 3) {
            std::cerr << "Error: Task ID is required for the 'mark-done' command." << std::endl;
            return 1;
        }
        int id = std::stoi(argv[2]);
        taskManager.markInDone(id);

    } else if (command == "list") {
        if (argc == 2) {
            taskManager.listTasks();
        } else {
            std::string filter = argv[2];
            taskManager.listTasks(filter);
        }

    } else {
        std::cerr << "Error: Unknown command '" << command << "'. Available commands are: add, update, delete, mark-in-progress, mark-done, list." << std::endl;
        return 1;
    }

    return 0;
}
