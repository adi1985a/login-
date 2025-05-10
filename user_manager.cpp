#include "user_manager.hpp"
#include <fstream>
#include <algorithm>
#include <functional>

UserManager::UserManager() : dataFile("users.dat") {
    loadUsers();
}

bool UserManager::registerUser(const std::string& username, const std::string& password) {
    auto it = std::find_if(users.begin(), users.end(),
        [&username](const auto& user) { return user->username == username; });
    
    if (it != users.end()) return false;
    
    auto newUser = std::make_shared<User>();
    newUser->username = username;
    newUser->passwordHash = hashPassword(password);
    newUser->isAdmin = users.empty(); // First user is admin
    
    users.push_back(newUser);
    saveUsers();
    return true;
}

bool UserManager::login(const std::string& username, const std::string& password) {
    auto it = std::find_if(users.begin(), users.end(),
        [&](const auto& user) {
            return user->username == username && 
                   user->passwordHash == hashPassword(password);
        });
    return it != users.end();
}

bool UserManager::changePassword(const std::string& username, 
                               const std::string& oldPassword, 
                               const std::string& newPassword) {
    auto it = std::find_if(users.begin(), users.end(),
        [&](const auto& user) {
            return user->username == username && 
                   user->passwordHash == hashPassword(oldPassword);
        });
    
    if (it == users.end()) return false;
    
    (*it)->passwordHash = hashPassword(newPassword);
    saveUsers();
    return true;
}

std::vector<std::string> UserManager::listUsers() {
    std::vector<std::string> userList;
    for (const auto& user : users) {
        userList.push_back(user->username + (user->isAdmin ? " (Admin)" : ""));
    }
    return userList;
}

std::string UserManager::hashPassword(const std::string& password) {
    // Simple hash function for demonstration
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}

void UserManager::loadUsers() {
    std::ifstream file(dataFile);
    if (!file) return;
    
    std::string username, hash;
    bool isAdmin;
    while (file >> username >> hash >> isAdmin) {
        auto user = std::make_shared<User>();
        user->username = username;
        user->passwordHash = hash;
        user->isAdmin = isAdmin;
        users.push_back(user);
    }
}

void UserManager::saveUsers() {
    std::ofstream file(dataFile);
    for (const auto& user : users) {
        file << user->username << " " 
             << user->passwordHash << " "
             << user->isAdmin << "\n";
    }
}
