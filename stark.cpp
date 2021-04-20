// stark.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <Lmcons.h>
#include <string>
#include <process.h>



int main(int argc, const char* argv)
{
	long startTime = GetTickCount64() / 1000;
	long endTime ;

	DWORD latency = 10;
	DWORD byteswritten = 555;
	DWORD sectorsInCluster;
	DWORD sectorsize;
	DWORD freeClustes;
	DWORD clustersCount;
	double freeSpace;
	char output[MAX_PATH];

	
	//get disk space for current drive
	GetDiskFreeSpace(
		NULL, //current drive
		&sectorsInCluster, //sectors per cluster
		&sectorsize, //bytes per sector
		&freeClustes, //free clusters
		&clustersCount //total clusters
	);

	unsigned int clusterSize = sectorsize * sectorsInCluster / 1024; 
	freeSpace = (long) clusterSize * freeClustes;
	  
	sprintf_s(output, "Free STORAGE ON C DISK: %d KBytes \n \n", freeSpace);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteConsoleA(h, output , strlen(output), NULL, NULL);


	Sleep(latency);

	int i, c = 0; for(i = 0; i < 1; i++) c++;
	
	endTime = (GetTickCount64() / 100) - startTime;

	

	sprintf_s(output, "EXECTION TIME : %f Milliseconds \n \n",(float) endTime);
	WriteConsoleA(h, output, strlen(output), NULL, NULL);

	sprintf_s(output, "PID : %d \n \n", _getpid());
	WriteConsoleA(h, output, strlen(output), NULL, NULL);

	CHAR username[UNLEN + 1];
	DWORD size = UNLEN + 1;
	GetUserNameA(username, &size);

	sprintf_s(output, "USERNAME : %s \n \n", username);
	WriteConsoleA(h, output, strlen(output), NULL, NULL);

}





// .
//DWORD ticks = GetTickCount();
//DWORD milliseconds = ticks % 1000;
//ticks /= 1000;
//DWORD seconds = ticks % 60;
//ticks /= 60;
//DWORD minutes = ticks % 60;
//ticks /= 60;
//DWORD hours = ticks; // may exceed 24 hours.
//printf("%d:%02d:%02d.%03d\n", hours, minutes, seconds, milliseconds);

//DWORD GetCurrentProcessId();

