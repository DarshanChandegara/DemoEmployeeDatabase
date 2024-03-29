#ifndef _UTIL_
#define _UTIL_

#include<string>
#include<chrono>
#include<ctime>

using namespace std::chrono;

inline std::string string_rep() {
	auto now = system_clock::now();
	std::time_t currentTime = system_clock::to_time_t(now);
	std::tm localTime;
	localtime_s(&localTime, &currentTime);

	std::string dateTime = std::to_string(localTime.tm_mday);
	dateTime.append("/")
		.append(std::to_string(localTime.tm_mon + 1))
		.append("/")
		.append(std::to_string(localTime.tm_year + 1900))
		.append(" :: ")
		.append(std::to_string(localTime.tm_hour))
		.append(":")
		.append(std::to_string(localTime.tm_min))
		.append(":")
		.append(std::to_string(localTime.tm_sec));

	return dateTime;
}

#endif