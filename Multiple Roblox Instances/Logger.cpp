#include <windows.h>
#include "logger.h"

HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

Logger::Logger() {}

Logger& Logger::getInstance()
{
	static Logger instance;
	return instance;
}

void Logger::log(LogLevel level, std::string output)
{
	updateColor(level);
	printf("%s\n", output.c_str());
}

void Logger::logFailure()
{
	log(LogLevel::Error, "Failed. Please try again.");
	std::cin.get();
}

void Logger::updateColor(LogLevel level)
{
	int colorCode = 0;

	switch (level)
	{
	case LogLevel::Info:
		colorCode = 15;
		break;
	case LogLevel::Success:
		colorCode = 2;
		break;
	case LogLevel::Warning:
		colorCode = 14;
		break;
	case LogLevel::Error:
		colorCode = 4;
		break;
	}

	SetConsoleTextAttribute(outputHandle, colorCode);
}
