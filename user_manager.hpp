#pragma once
#include <string>
#include <vector>
#include <memory>

class UserManager {
private:
    struct User {
        std::string username;
        std::string passwordHash;
        bool isAdmin;
    };
    
    std::vector<std::shared_ptr<User>> users;
    std::string dataFile;
    
public:
    UserManager();
    bool registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    bool changePassword(const std::string& username, const std::string& oldPassword, const std::string& newPassword);
    std::vector<std::string> listUsers();
    
private:
    std::string hashPassword(const std::string& password);
    void loadUsers();
    void saveUsers();
};
