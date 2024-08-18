#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

enum class LogLevel
{
	Info,
	Success,
	Warning,
	Error,
};

class Logger
{
public:
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
	static Logger& getInstance();
	void log(LogLevel level, std::string output);
	void logFailure();
private:
	Logger();
	void updateColor(LogLevel level);
};

#endif // LOGGER_H
