#pragma once
#include <string>
#include "kv/result.hpp"

namespace kv {

enum class LogLevel {
        Debug,
        Info,
        Warn,
        Error,
        Fatal
};

struct Config {
	LogLevel log_level;
	std::string data_dir;
	int port;	
};

Result<Config> load_config(const std::string& path);

}
