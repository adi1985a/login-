#pragma once
#include <string>
#include <fstream>
#include <mutex>

class Logger {
private:
    std::string logFile;
    std::mutex logMutex;
    
public:
    explicit Logger(const std::string& filename);
    void log(const std::string& message);
    
private:
    std::string getCurrentTimestamp();
};
