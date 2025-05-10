# Login Management System

## Overview
This C++ console application, created by Adrian Lesniak, provides a user management system with registration, login, password change, and admin-only user listing. It features Windows-specific colored output, secure password hashing, logging to `system.log`, and user data storage in `users.dat`. The program uses object-oriented design with `UserManager` and `Logger` classes.

## Features
- **User Management**:
  - `registerUser`: Creates new user accounts; first user is admin.
  - `login`: Authenticates users with username and password.
  - `changePassword`: Updates user password after verification.
  - `listUsers`: Displays all usernames (admin-only, marks admins).
- **Security**:
  - `hashPassword`: Hashes passwords using `std::hash` (demonstration purposes).
  - Stores user data (username, password hash, admin status) in `users.dat`.
- **Interface**:
  - `displayHeader`: Shows program title, author, and features.
  - `displayMenu`: Lists options: register, login, change password, list users, exit.
  - Colored output (cyan, yellow, green, red, white) via Windows console API.
- **Logging**:
  - `Logger`: Logs events (e.g., registration, login attempts) to `system.log` with timestamps.
- **File Handling**:
  - `loadUsers`: Reads user data from `users.dat`.
  - `saveUsers`: Writes user data to `users.dat`.
- **Main Program**:
  - Loops until exit (5), handles input via `_getch`, and processes user actions.
  - Robust error handling with try-catch and logging.

## Requirements
- C++ compiler (e.g., g++, MSVC) with C++11 or later
- Windows OS (for `<windows.h>`, `SetConsoleTextAttribute`, `_getch`)
- Standard C++ libraries: `<iostream>`, `<fstream>`, `<string>`, `<conio.h>`, `<algorithm>`, `<functional>`
- Headers: `user_manager.hpp`, `logger.hpp`
- Write permissions for `system.log` and `users.dat`
- Operating system: Windows (due to console functions)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure `user_manager.hpp` and `logger.hpp` are in the project directory with required class definitions.
3. Save the first provided code as `main.cpp` and the second as `user_manager.cpp`.
4. Compile the program:
   ```bash
   g++ main.cpp user_manager.cpp -o login_system
   ```
5. Run the program:
   ```bash
   .\login_system
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays header and menu with options:
     1. Register new user
     2. Login
     3. Change password
     4. Display all users
     5. Exit
3. **Input**:
   - Select 1–5 via keypress.
   - For registration/login/password change:
     - Enter username and password.
     - Invalid inputs (e.g., existing username, wrong password) show error messages.
   - List users (4) shows all usernames with admin status.
4. **Output**:
   - Registration: "Registration successful!" or "Username already exists!".
   - Login: "Login successful! Welcome, <username>!" or "Invalid username or password!".
   - Password change: "Password changed successfully!" or "Invalid username or current password!".
   - User list: Lists usernames (e.g., "user1 (Admin)", "user2").
   - Events logged to `system.log` (e.g., "New user registered: user1").
   - User data saved to `users.dat`.
5. **Actions**:
   - Press any key to return to menu after each operation.
   - Select 5 to exit.

## File Structure
- `main.cpp`: Main program file with UI and user interaction logic.
- `user_manager.cpp`: Implements `UserManager` class for user data management.
- `user_manager.hpp`: Header with `UserManager` and `User` class declarations.
- `logger.hpp`: Header for `Logger` class.
- `system.log`: Log file for system events (created/appended).
- `users.dat`: Stores user data (username, password hash, admin status).
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to `<windows.h>` and `_getch`; adapt for cross-platform (e.g., ANSI colors, `system("clear")`).
- Requires `user_manager.hpp` (defines `UserManager`, `User`) and `logger.hpp` (defines `Logger`).
- Password hashing is simplified (`std::hash`); use stronger hashing (e.g., bcrypt) for production.
- Admin functionality limited to listing users; expand with more admin features.
- Extend by adding password complexity rules, session management, or a GUI.
- Ensure write permissions for `system.log` and `users.dat`.
- No external dependencies beyond standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.