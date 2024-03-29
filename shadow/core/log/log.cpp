#include "log.h"

#include <spdlog/sinks/stdout_sinks.h>

namespace Shadow {

std::shared_ptr<spdlog::logger> Log::mCoreLogger;
std::shared_ptr<spdlog::logger> Log::mClientLogger;

void Log::Init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    mCoreLogger = spdlog::stdout_color_mt("Core");
    mCoreLogger->set_level(spdlog::level::trace);

    mClientLogger = spdlog::stdout_color_mt("Client");
    mClientLogger->set_level(spdlog::level::trace);
}

}