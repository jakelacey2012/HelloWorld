#include <iostream>
#include <chrono>
#include <ctime>

#include "Log.h"

void Logger::SetLevel(int level) {
	LogLevel = level;
}

void Logger::Error(const char* message) {
	if (LogLevel >= LogLevelError) {
		Log("[Error]: ", message);
	}
}

void Logger::Warn(const char* message) {
	if (LogLevel >= LogLevelWarning) {
		Log("[WARNING]: ", message);
	}
}

void Logger::Info(const char* message) {
	if (LogLevel >= LogLevelInfo) {
		Log("[INFO]: ", message);
	}
}

void Logger::Debug(const char* message) {
	if (LogLevel >= LogLevelDebug) {
		Log("[DEBUG]: ", message);
	}
}

void Logger::Log(const char* prefix, const char* message) 
{
	std::cout << prefix << "DISPLAY TIME - " << message << std::endl;
}

