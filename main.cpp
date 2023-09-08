#include <iostream>
#include "logger.hpp"

int main() 
{
    std::string demoMessage;

    demoMessage = "This is an informational message.";
    auto demoLevel = Logger::log_level::LOG_LEVEL_INFO;
    Logger::log(demoLevel, demoMessage);

    demoMessage = "This is a warning message.";
    demoLevel = Logger::log_level::LOG_LEVEL_WARNING;
    Logger::log(demoLevel, demoMessage);
    
    demoMessage = "This is an error message.";
    demoLevel = Logger::log_level::LOG_LEVEL_ERROR;
    Logger::log(demoLevel, demoMessage);

    demoMessage = "This is a fatal message.";
    demoLevel = Logger::log_level::LOG_LEVEL_FATAL;
    Logger::log(demoLevel, demoMessage);

    demoMessage = "This is a debug message.";
    demoLevel = Logger::log_level::LOG_LEVEL_DEBUG;
    Logger::log(demoLevel, demoMessage);

    demoMessage = "This is a trace message.";
    demoLevel = Logger::log_level::LOG_LEVEL_TRACE;
    Logger::log(demoLevel, demoMessage);

    return 0;
}
