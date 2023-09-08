#include <string>
#pragma once

#define LOG_WARNING_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if HF_RELEASE == 1
#undef LOG_DEBUG_ENABLED
#undef LOG_TRACE_ENABLED
#undef LOG_INFO_ENABLED

#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#define LOG_INFO_ENABLED 0
#endif



class Logger 
{
    public:
        enum log_level {
        LOG_LEVEL_FATAL = 0,
        LOG_LEVEL_ERROR = 1,
        LOG_LEVEL_WARNING = 2,
        LOG_LEVEL_INFO = 3,
        LOG_LEVEL_DEBUG = 4,
        LOG_LEVEL_TRACE = 5
        };

    private:
        static std::string getDateTime();
        std::string levelStr;

    public:
        static void log(log_level level, std::string message, std::string date_time = "");


};
