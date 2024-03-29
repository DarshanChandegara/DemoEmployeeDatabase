#ifndef _LOG_
#define _LOG_

#include "log.h"
#include "utility.h"
#include<string>
#include<memory>
using logging::Log;

namespace logging {

	inline auto myLogger = std::make_shared<Log>("System");

	inline std::shared_ptr<Log> default_logger() {
		return myLogger;
	}

	inline void set_default_logger(std::shared_ptr<Log> ptr) {
		myLogger = std::move(ptr);
	}

	inline std::string Log::showLevel(Log::Level l) const {
		switch (l) {
		case Level::LevelError:
			return "Error";

		case Level::LevelInfo:
			return "Info";

		case Level::LevelWarning:
			return "Warning";

		default: return "";
		}
	}

	inline std::string Log::showLevelWithColour(Log::Level l) const {
		switch (l) {
		case Level::LevelError:
			return "\x1b[31mError\x1b[0m";

		case Level::LevelInfo:
			return "\x1b[32mInfo\x1b[0m";

		case Level::LevelWarning:
			return "\x1b[33mWarning\x1b[0m";

		default: return "";
		}
	}

	template<typename... T>
	void Log::log(Log::Level l, const T& ...args) const {

		if (m_LogLevel >= l) {
			std::string str1 = string_rep();
			str1.append(" [")
				.append(showLevel(l))
				.append("] ")
				.append("[")
				.append(l_name)
				.append("] ");


			if (isDumpOnFile == true) {
				buffer.append(str1);
				getString(args...);
				//std::cout << "1 ";
				bufferCount++;

				//std::cout << "2 ";
				if (bufferCount >= 5) {
					flush(buffer);
					buffer = "";
					bufferCount = 0;
				}
			}

		}
	}

	template<typename... Args>
	void Warn(const std::string& message, Args... args) {
		default_logger()->log(Log::Level::LevelWarning, message, args...);
	}

	template<typename... Args>
	void Error(const std::string& message, Args... args) {
		default_logger()->log(Log::Level::LevelError, message, args...);
	}

	template<typename... Args>
	void Info(const std::string& message, Args... args) {
		default_logger()->log(Log::Level::LevelInfo, message, args...);
	}

}


#endif 
