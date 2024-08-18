#include <iostream>
#include <windows.h>
#include "logger.h"

const std::wstring programName = L"Multiple Roblox Instances";
const std::wstring mutexName = L"ROBLOX_singletonMutex";
Logger& logger = Logger::getInstance();

int main()
{
	SetConsoleTitle(programName.c_str());
	logger.log(LogLevel::Info, "Starting...");

	HANDLE existingMutex = OpenMutexW(SYNCHRONIZE, false, mutexName.c_str());

	if (existingMutex)
	{
		logger.log(LogLevel::Warning, "Roblox is open, it must be closed.");
		logger.log(LogLevel::Warning, "Waiting for Roblox to be closed...");

		DWORD result = WaitForSingleObject(existingMutex, INFINITE);

		if (result != WAIT_OBJECT_0 && result != WAIT_ABANDONED)
		{
			logger.logFailure();
			return -1;
		}
	}
	else
	{
		HANDLE newMutex = CreateMutexW(NULL, true, mutexName.c_str());

		if (!newMutex)
		{
			logger.logFailure();
			return -1;
		}
	}

	logger.log(LogLevel::Success, "Started.");
	logger.log(LogLevel::Warning, "Closing this window will close all but the Roblox instance which was launched first.");
	std::cin.get();
	return 0;
}
