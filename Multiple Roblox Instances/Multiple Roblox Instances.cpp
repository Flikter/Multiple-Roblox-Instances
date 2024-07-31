#include <iostream>
#include <windows.h>

using namespace std;

const wstring programName = L"Multiple Roblox Instances";
const wstring mutexName = L"ROBLOX_singletonMutex";

void logFailure()
{
	printf("Failed. Please try again.\n");
	cin.get();
}

int main()
{
	SetConsoleTitle(programName.c_str());
	printf("Starting...\n");

	HANDLE existingMutex = OpenMutexW(SYNCHRONIZE, false, mutexName.c_str());

	if (existingMutex)
	{
		printf("Roblox is open, it must be closed when you open this program.\n");
		printf("Waiting for Roblox to be closed...\n");

		DWORD result = WaitForSingleObject(existingMutex, INFINITE);

		if (result != WAIT_OBJECT_0 && result != WAIT_ABANDONED)
		{
			logFailure();
			return -1;
		}
	}
	else
	{
		HANDLE newMutex = CreateMutexW(NULL, true, mutexName.c_str());

		if (!newMutex)
		{
			logFailure();
			return -1;
		}
	}

	printf("Started.\n");
	printf("If you close this window, all Roblox instances will close except for the one which was launched first.\n");
	cin.get();
	return 0;
}
