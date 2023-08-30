#include <iostream>
#include <string>
#define FMT_HEADER_ONLY
#include "fmt/include/fmt/format.h"

#define LOG_INFO 6
#define _INFO_    LOG_INFO

struct Logger {
    ~Logger() = default;
    Logger(const std::string& module, int runtimeLevel = _INFO_)
            : module(module), runtimeLevel(runtimeLevel)
    {}

    std::string module;
    int runtimeLevel;
};

#define INFO(MSG, ...) _LOG_(MSG, INFO, __FILE__, __LINE__, ##__VA_ARGS__);

#define _LOG_(MSG, LEVEL, FILE, LINE, ...) { \
      std::string buffer = fmt::format("[{}]:{}:{}:" #LEVEL ":" MSG, _logger.module.c_str(), \
         FILE, LINE, ##__VA_ARGS__); \
      std::cout << buffer << std::endl; \
    }

int main() {
    Logger _logger("TEST", _INFO_);

    std::string message = "simple message";
    std::string buffer_message = "additional buffer";

    INFO("Hello World")
    INFO("We add message right here {}", message);
    INFO("We want to send buffer to output {}", buffer_message);
    return 0;
}