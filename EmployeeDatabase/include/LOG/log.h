#ifndef log_1
#define log_1

#include "fileHelper.h"
#include<vector>
#include<iostream>
#include<string>
using logging::FileHelper;


namespace logging {
	
	class Log {
	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};

		explicit Log(const std::string& s) : l_name{s} , m_LogLevel { Level::LevelInfo } {}
		explicit Log(const std::string& s, Level l) : l_name{ s }, m_LogLevel{ l } {}
		explicit Log(const std::string& s, std::string name) : l_name{ s }, fName{ name }, m_LogLevel{ Level::LevelInfo } {
			isDumpOnFile = true;
		}
		
		void SetLogLevel(Level level) {
			m_LogLevel = level;
		}

		Level getLogLevel() const {
			return this->m_LogLevel;
		}

		void setFileFlag(bool flag) {
			isDumpOnFile = flag;
		}

		template<typename... T>
		void log(Log::Level, const T& ...args) const;

		void getString() const {
			buffer.append("\n");
		}

		template<typename T, typename... Args>
		void getString(T Arg, Args... args) const {

			buffer.append(Arg);
			buffer.append(" ");
			getString(args...);  
		}

		void flush(const std::string&) const;
		mutable int bufferCount{ 0 };

		~Log() {
			if (isDumpOnFile) {
				flush(buffer);
				buffer = "";
				bufferCount = 0;
			}
		}

	private:
		std::string l_name;
		Level m_LogLevel;
		bool isDumpOnFile = false;
		std::string fName{"default.txt"};
		mutable std::string buffer{ "" };

		
		void printArgs() const;

		template<typename T, typename... Args>
		void printArgs(T&& Arg, Args&&... args) const;

		std::string showLevelWithColour(Level) const ;
		std::string showLevel(Level) const ;
		void logConsole(std::string msg)const;
	};

	inline void Log::logConsole(std::string msg) const {
		std::cout << msg;
	}

	inline void Log::printArgs() const{
		std::cout << "\n";
	}

	template<typename T, typename... Args>
	void Log::printArgs(T&& Arg, Args&&... args) const {
		std::cout << Arg << " ";
		printArgs(args...); 
	}

	inline void Log::flush(const std::string& log) const {
		//std::cout << "3 ";
		FileHelper f{ fName };
		f.writeLine(log);
	}
}
#endif