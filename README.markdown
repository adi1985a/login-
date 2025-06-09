# 🛡️🔑 SecureAuth Pro: C++ Login & User Management System 🔐
_A C++ console application for user registration, login, password management, and admin oversight, featuring secure (demonstration) password hashing and detailed logging._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features](#-key-features)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Core Components & Headers](#-core-components--headers)
6.  [Installation and Setup](#️-installation-and-setup)
7.  [Usage Guide](#️-usage-guide)
8.  [File Structure & Data Persistence](#-file-structure--data-persistence)
9.  [Security Note (Password Hashing)](#-security-note-password-hashing)
10. [Technical Notes](#-technical-notes)
11. [Contributing](#-contributing)
12. [License](#-license)
13. [Contact](#-contact)

## 📄 Overview

**SecureAuth Pro**, developed by Adrian Lesniak, is a robust C++ console-based user management system. It provides essential functionalities including user registration (with the first user automatically designated as an administrator), secure login authentication, password change capabilities, and an admin-exclusive feature to list all registered users. The system emphasizes security through password hashing (using `std::hash` for demonstration purposes) and persists user data in `users.dat`. All significant system events and user actions are meticulously logged to `system.log`. Designed with an object-oriented approach utilizing `UserManager` and `Logger` classes, it features a colorful Windows-specific console interface for an enhanced user experience.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   👤 **User Account Management**:
    *   `registerUser`: Securely create new user accounts. The first user registered automatically gains administrator privileges.
    *   `login`: Authenticate users based on their username and password.
    *   `changePassword`: Allows authenticated users to update their passwords after verifying their current one.
    *   `listUsers`: An **admin-only** function to display a list of all registered usernames, clearly marking administrators.
*   🔒 **Security Measures**:
    *   `hashPassword`: Implements password hashing using `std::hash` (Note: suitable for demonstration, not production-grade security).
    *   **Data Persistence**: Securely stores user credentials (username, password hash, admin status) in a binary or structured text file (`users.dat`).
*   🖥️ **Interactive Console Interface**:
    *   `displayHeader`: Presents a clear program title, author details, and a summary of features.
    *   `displayMenu`: Offers a user-friendly menu with options for registration, login, password change, user listing, and exit.
    *   **Colorful Output**: Utilizes Windows console API (e.g., `SetConsoleTextAttribute`) for distinct colors (cyan, yellow, green, red, white) to improve UI clarity.
*   ✍️ **System Event Logging**:
    *   **Logger Class**: A dedicated `Logger` class records important system events (e.g., user registrations, login attempts - successful and failed, password changes) to `system.log` with precise timestamps.
*   🗃️ **File Handling**:
    *   `loadUsers`: Efficiently reads user data from `users.dat` upon application startup.
    *   `saveUsers`: Persists updated user data to `users.dat` before exiting or after critical changes.
*   ⚙️ **Robust Operation**:
    *   The main program loop handles user input (via `_getch` for immediate keypress response) and dispatches actions.
    *   Incorporates `try-catch` blocks for graceful error handling, with errors also logged.

## 🖼️ Screenshots

_Screenshots showcasing the login screen, registration process, admin user list, password change interface, and examples of `system.log` and `users.dat` (if human-readable)._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\1a.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
</p>


## ⚙️ System Requirements

*   **Operating System**: Windows (due to dependencies like `<windows.h>` for `SetConsoleTextAttribute` and `<conio.h>` for `_getch`).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<fstream>`, `<string>`, `<vector>`, `<algorithm>`, `<functional>` (for `std::hash`).
*   **Write Permissions**: The application needs write permissions in its execution directory to create/modify `system.log` and `users.dat`.

## 🧩 Core Components & Headers

*   **`user_manager.hpp`**: (User-provided or part of the project) Header file declaring the `UserManager` class (responsible for all user-related logic like add, find, authenticate, save/load users) and likely a `User` struct/class (to hold username, password hash, admin status).
*   **`user_manager.cpp`**: (User-provided or part of the project) Implementation file for the `UserManager` class methods.
*   **`logger.hpp`**: (User-provided or part of the project) Header file declaring the `Logger` class for writing timestamped messages to `system.log`.
*   **`main.cpp`**: The main application file containing the UI logic, menu handling, and interaction with `UserManager` and `Logger`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Ensure Header and Source Files are Present**:
    *   Verify that `user_manager.hpp`, `user_manager.cpp` (implementation), and `logger.hpp` (and its potential `.cpp` implementation) are correctly placed in the project directory as per your project's structure.
    *   The main application logic should be in `main.cpp`.

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, etc.) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ main.cpp user_manager.cpp logger.cpp -o login_system.exe -std=c++11 -static-libgcc -static-libstdc++
    ```
    *(Adjust the command if `logger.cpp` is not needed (header-only logger) or if you have other source files. Ensure your compiler flags are appropriate, e.g., `-std=c++11` or newer).*

4.  **Run the Program**:
    ```bash
    .\login_system.exe
    ```
    (or `login_system.exe` in CMD)

## 💡 Usage Guide

1.  Compile and run `login_system.exe` as detailed above.
2.  **Interface**:
    *   The program will display a header and a main menu with the following options:
        1.  Register new user
        2.  Login
        3.  Change password
        4.  Display all users (Admin only)
        5.  Exit
3.  **Input**:
    *   Select a menu option (1–5) using a single keypress (handled by `_getch`).
    *   **Registration/Login/Password Change**: You will be prompted to enter a username and password(s) as required.
    *   The system provides feedback for invalid inputs (e.g., if a username already exists during registration, or if login credentials are incorrect).
    *   **List Users (Option 4)**: If logged in as an admin, this will display all registered usernames, indicating which ones have admin privileges (e.g., "user1 (Admin)", "user2").
4.  **Output**:
    *   **Registration**: "Registration successful!" or an error like "Username already exists!".
    *   **Login**: "Login successful! Welcome, [username]!" or "Invalid username or password!".
    *   **Password Change**: "Password changed successfully!" or an error like "Invalid username or current password!".
    *   **User List**: A formatted list of users.
    *   All significant events are logged with timestamps to `system.log`.
    *   User data is persisted in `users.dat`.
5.  **Actions**:
    *   After most operations, you will be prompted to press any key to return to the main menu.
    *   Select option `5` to save data and exit the application.

## 🗂️ File Structure & Data Persistence

*   `main.cpp`: Core application logic, UI, and menu handling.
*   `user_manager.hpp` & `user_manager.cpp`: Defines and implements the `UserManager` class for all user data operations.
*   `logger.hpp` (& `logger.cpp` if applicable): Defines and implements the `Logger` class for event logging.
*   `system.log`: A plain text file where system events (registrations, logins, errors, etc.) are logged with timestamps. This file is created or appended to.
*   `users.dat`: A data file (format could be binary, CSV, or custom plain text) that stores user information: typically username, hashed password, and an admin status flag. This file is read at startup and written to on exit or after critical changes.

## ⚠️ Security Note (Password Hashing)

The current implementation uses `std::hash` for password hashing. While suitable for demonstration and learning, **`std::hash` is NOT cryptographically secure and should NOT be used for storing passwords in a production environment.** For real-world applications, robust, salted hashing algorithms like **bcrypt, scrypt, or Argon2** are strongly recommended.

## 📝 Technical Notes

*   **Windows Specifics**: The project leverages Windows-specific headers (`<windows.h>`, `<conio.h>`) for functionalities like colored console output (`SetConsoleTextAttribute`) and direct keypress input (`_getch()`). Adapting for true cross-platform use would require alternative libraries or conditional compilation for these features (e.g., ANSI escape codes for colors, ncurses or similar for advanced console I/O).
*   **Object-Oriented Design**: The use of `UserManager` and `Logger` classes promotes modularity and better code organization.
*   **Admin Functionality**: The first registered user is designated as an admin. Admin privileges are currently limited to listing users. This could be expanded (e.g., delete user, reset password).
*   **Error Handling**: `try-catch` blocks are used for exception handling, with errors being logged for diagnostics.

## 🤝 Contributing

Contributions to **SecureAuth Pro** are highly encouraged! If you have ideas for strengthening security (e.g., implementing bcrypt), adding more admin features, improving cross-platform compatibility, or enhancing the user interface:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourSecurityEnhancement`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourSecurityEnhancement'`).
4.  Push to the branch (`git push origin feature/YourSecurityEnhancement`).
5.  Open a Pull Request.

Please ensure your code is well-commented, follows good security practices (where applicable), and adheres to the project's coding style.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or to report issues, please open an issue on the GitHub repository or contact the repository owner.

---
🔑 _Building secure and manageable user access, one line of C++ at a time._
