#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>


struct Task {
    int id;                 // Unique identifier
    std::string description; // Task description
    std::string status;      // Status: "todo" by default
    std::string createdAt;   // Creation timestamp
    std::string updatedAt;   // Last updated timestamp
};
class TaskManager {
public:
    TaskManager(); // Constructor

    // Task operations
    void addTask(const std::string& description);
    void deleteTask(const int& id);
    void updateTask(const int& id, const std::string& newDescription);
    void listTasks() const;

private:
    std::vector<Task> tasks; // In-memory list of tasks
    int nextId;              // To generate unique IDs for tasks

    // Helper functions
    std::string getCurrentTimestamp() const; // Generate current timestamp
};

#endif // TASKMANAGER_H