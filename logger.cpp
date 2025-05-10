#include "logger.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

Logger::Logger(const std::string& filename) : logFile(filename) {}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    std::ofstream file(logFile, std::ios::app);
    if (file) {
        file << getCurrentTimestamp() << " - " << message << std::endl;
    }
}

std::string Logger::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
