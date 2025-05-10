#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "user_manager.hpp"
#include "logger.hpp"

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayHeader() {
    system("cls");
    setColor(11);
    std::cout << "===============================================\n";
    std::cout << "           Login Management System\n";
    std::cout << "           by Adrian Lesniak\n";
    std::cout << "===============================================\n";
    setColor(14);
    std::cout << "\nProgram features:\n";
    std::cout << "- User registration and login\n";
    std::cout << "- Secure password storage\n";
    std::cout << "- User data management\n";
    setColor(7);
    std::cout << "\n-----------------------------------------------\n\n";
}

void displayMenu() {
    setColor(10);
    std::cout << "Available options:\n";
    std::cout << "1. Register new user (Create new account)\n";
    std::cout << "2. Login (Access your account)\n";
    std::cout << "3. Change password (For existing users)\n";
    std::cout << "4. Display all users (Admin only)\n";
    std::cout << "5. Exit program\n\n";
    setColor(7);
    std::cout << "Enter your choice (1-5): ";
}

void handleRegistration(UserManager& userManager, Logger& logger) {
    std::string username, password;
    setColor(11);
    std::cout << "\n=== User Registration ===\n";
    setColor(7);
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    
    if (userManager.registerUser(username, password)) {
        setColor(10);
        std::cout << "\nRegistration successful!\n";
        logger.log("New user registered: " + username);
    } else {
        setColor(12);
        std::cout << "\nUsername already exists!\n";
        logger.log("Failed registration attempt: " + username);
    }
}

void handleLogin(UserManager& userManager, Logger& logger) {
    std::string username, password;
    setColor(11);
    std::cout << "\n=== User Login ===\n";
    setColor(7);
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    
    if (userManager.login(username, password)) {
        setColor(10);
        std::cout << "\nLogin successful! Welcome, " << username << "!\n";
        logger.log("Successful login: " + username);
    } else {
        setColor(12);
        std::cout << "\nInvalid username or password!\n";
        logger.log("Failed login attempt: " + username);
    }
}

void handlePasswordChange(UserManager& userManager, Logger& logger) {
    std::string username, oldPassword, newPassword;
    setColor(11);
    std::cout << "\n=== Change Password ===\n";
    setColor(7);
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter current password: ";
    std::cin >> oldPassword;
    std::cout << "Enter new password: ";
    std::cin >> newPassword;
    
    if (userManager.changePassword(username, oldPassword, newPassword)) {
        setColor(10);
        std::cout << "\nPassword changed successfully!\n";
        logger.log("Password changed for user: " + username);
    } else {
        setColor(12);
        std::cout << "\nInvalid username or current password!\n";
        logger.log("Failed password change attempt: " + username);
    }
}

void handleUserList(UserManager& userManager, Logger& logger) {
    setColor(11);
    std::cout << "\n=== User List ===\n";
    setColor(7);
    
    auto users = userManager.listUsers();
    if (users.empty()) {
        std::cout << "No users registered.\n";
    } else {
        for (const auto& user : users) {
            std::cout << "- " << user << "\n";
        }
    }
    logger.log("User list displayed");
}

int main() {
    UserManager userManager;
    Logger logger("system.log");
    
    while (true) {
        displayHeader();
        displayMenu();
        
        char choice = _getch();
        system("cls");
        
        try {
            switch (choice) {
                case '1':
                    handleRegistration(userManager, logger);
                    break;
                case '2':
                    handleLogin(userManager, logger);
                    break;
                case '3':
                    handlePasswordChange(userManager, logger);
                    break;
                case '4':
                    handleUserList(userManager, logger);
                    break;
                case '5':
                    setColor(11);
                    std::cout << "\nThank you for using the program!\n";
                    return 0;
                default:
                    setColor(12);
                    std::cout << "\nInvalid option! Please choose 1-5.\n";
                    break;
            }
        } catch (const std::exception& e) {
            logger.log("Error: " + std::string(e.what()));
            setColor(12);
            std::cout << "\nError: " << e.what() << std::endl;
        }
        
        setColor(7);
        std::cout << "\nPress any key to continue...";
        _getch();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return 0;
}
