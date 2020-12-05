#pragma once

#include <string>

class Logger {
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
	const int LogLevelDebug = 3;

	void SetLevel(int level);
	void Error(const char* message);
	void Warn(const char* message);
	void Info(const char* message);
	void Debug(const char* message);

private:
	int LogLevel = 2;
	void Log(const char* prefix, const char* message);
};