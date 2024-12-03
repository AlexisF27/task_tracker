#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <vector>
#include "json.hpp" 


struct Task {
    int id;                
    std::string description; 
    std::string status;      
    std::string createdAt;   
    std::string updatedAt;  
    std::string jsonFilePath;


};
class TaskManager {
public:
    TaskManager(); 
    void addTask(const std::string& description);
    void deleteTask(const int& id);
    void updateTask(const int& id, const std::string& newDescription);
    void listTasks(const std::string& filter = "") const;  
    void updateTaskStatus(const int& id, const std::string& newStatus);
    void markInDone(const int& id);
    void markInProgress(const int& id);
    TaskManager(const std::string& filePath = "tasks.json");

private:
    std::vector<Task> tasks; 
    int nextId;              
    std::string getCurrentTimestamp() const; 
    void loadFromFile();  
    void saveToFile() const;
    
};

#endif 