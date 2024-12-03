#include "TaskManager.h"
#include <ctime> // For timestamp generation
#include <iostream>
#include <algorithm>

TaskManager::TaskManager() : nextId(1) {
    // In this simplified version, we'll assume tasks start empty.
    // Normally, you might load tasks from a file here.
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

void TaskManager::listTasks() const {
    std::cout << "Tasks:" << std::endl;
    for (const auto& task : tasks) {
        std::cout << "ID: " << task.id << ", Description: " << task.description << ", Status: " << task.status << ", Created At: " << task.createdAt << ", Updated At: " << task.updatedAt << std::endl;
    }
}

std::string TaskManager::getCurrentTimestamp() const {
    std::time_t now = std::time(nullptr);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buffer);
}
