#include "logger.hpp"
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <algorithm>

std::string Logger::getDateTime() 
{
    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&time_now);
}

void Logger::log(log_level level, std::string message, std::string date_time) 
{
    std::string levelStr;
    
    if (date_time == "")
        date_time = getDateTime();
        date_time.erase(std::remove(date_time.begin(), date_time.end(), '\n'), date_time.cend());
        {
            switch (level)
            {
            case LOG_LEVEL_FATAL:
                levelStr = "[FATAL]";
                break;

            case LOG_LEVEL_ERROR:
                levelStr = "[ERROR]";
                break;

            case LOG_LEVEL_WARNING:
                levelStr ="[WARNING]";
                break;

            case LOG_LEVEL_INFO:
                levelStr = "[INFO]";
                break;

            case LOG_LEVEL_DEBUG:
                levelStr = "[DEBUG]";
                break;

            case LOG_LEVEL_TRACE:
                levelStr = "[TRACE]";
                break;

            default: 
                levelStr = "[UNKNOWN]";
                break;
        }
        std::string logMessage = "[" + date_time + "] - " + levelStr + " - " + message + "\n";
        std::ofstream logFile;

        logFile.open("Logs/log.log", std::ios_base::out | std::ios_base::app);
        logFile << logMessage;
        logFile.close();
    }
};