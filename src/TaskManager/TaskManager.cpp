#include "TaskManager.h"
#include <ctime> // For timestamp generation
#include <iostream>
#include <algorithm>
#include <fstream>

TaskManager::TaskManager() : nextId(1) {
    loadTasks();
}

void TaskManager::addTask(const std::string& description) {
    Task newTask;
    newTask.id = nextId++;
    newTask.description = description;
    newTask.status = "todo"; 
    newTask.createdAt = getCurrentTimestamp();
    newTask.updatedAt = newTask.createdAt;
    tasks.push_back(newTask);
    std::cout << "Task added successfully (ID: " << newTask.id << ")" << std::endl;
}

void TaskManager::deleteTask(const int& id) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.id == id; 
    });
    if (it != tasks.end()) {
        tasks.erase(it);
        std::cout << "Task with ID " << id << " has been deleted." << std::endl;
    } else {
        std::cout << "Task with ID " << id << " not found." << std::endl;
    }
}

void TaskManager::updateTask(const int& id, const std::string& newDescription) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.id == id; 
    });
    if (it != tasks.end()) {
        it->description = newDescription;
        it->updatedAt = getCurrentTimestamp();
        std::cout << "Task with ID " << id << " has been updated." << std::endl;
    } else {
        std::cout << "Task with ID " << id << " not found." << std::endl;
    }
}

void TaskManager::updateTaskStatus(const int& id, const std::string& newStatus) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.id == id; 
    });

    if (it != tasks.end()) {
        it->status = newStatus;
        it->updatedAt = getCurrentTimestamp();
        std::cout << "Task with ID " << id << " has been updated to status '" << newStatus << "'." << std::endl;
    } else {
        std::cout << "Task with ID " << id << " not found." << std::endl;
    }
}


void TaskManager::markInProgress(const int& id) {
    updateTaskStatus(id, "in_progress");
}

void TaskManager::markInDone(const int& id) {
    updateTaskStatus(id, "done");
}

void TaskManager::listTasks(const std::string& filter) const {
    if (filter.empty()) {
        std::cout << "All Tasks:" << std::endl;
        for (const auto& task : tasks) {
            std::cout << "ID: " << task.id
                      << ", Description: " << task.description
                      << ", Status: " << task.status
                      << ", Created At: " << task.createdAt
                      << ", Updated At: " << task.updatedAt
                      << std::endl;
        }
    } else {
        std::cout << "Tasks (" << filter << "):" << std::endl;
        for (const auto& task : tasks) {
            if (task.status == filter) {
                std::cout << "ID: " << task.id
                          << ", Description: " << task.description
                          << ", Status: " << task.status
                          << ", Created At: " << task.createdAt
                          << ", Updated At: " << task.updatedAt
                          << std::endl;
            }
        }
    }
}
std::string TaskManager::getCurrentTimestamp() const {
    std::time_t now = std::time(nullptr);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buffer);
}

void TaskManager::loadTasks() {
    std::ifstream file("tasks.json");
    if (file.is_open()) {
        nlohmann::json jsonData;
        file >> jsonData;
        file.close();

        // Load tasks from the JSON data
        for (const auto& taskData : jsonData) {
            Task task;
            task.id = taskData["id"];
            task.description = taskData["description"];
            task.status = taskData["status"];
            task.createdAt = taskData["createdAt"];
            task.updatedAt = taskData["updatedAt"];
            tasks.push_back(task);

            // Update nextId to be the next available ID
            if (task.id >= nextId) {
                nextId = task.id + 1;
            }
        }
    } else {
        // If the file doesn't exist, create a new file with an empty JSON array
        std::ofstream newFile("tasks.json");
        newFile << "[]";  // Initialize with an empty JSON array
        newFile.close();
    }
}

// Save tasks to tasks.json
void TaskManager::saveTasks() {
    nlohmann::json jsonData;

    for (const auto& task : tasks) {
        jsonData.push_back({
            {"id", task.id},
            {"description", task.description},
            {"status", task.status},
            {"createdAt", task.createdAt},
            {"updatedAt", task.updatedAt}
        });
    }

    // Write the JSON data to tasks.json with indentation
    std::ofstream file("tasks.json");
    file << jsonData.dump(4);  // Dump JSON with 4 spaces of indentation
    file.close();
}