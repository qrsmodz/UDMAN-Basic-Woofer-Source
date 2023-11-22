#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>
#include <chrono>
#include <vector>




class Prot
{
public:
	auto IsDebuggerValid() -> bool
	{
		if (IsDebuggerPresent())
		{
			return true;
		}
	}
	auto IsErrorValid() -> bool
	{
		SetLastError(0);
		OutputDebugStringA("hello dear reverse engineer, hows your day going?!?!?");
		if (GetLastError() != 0) return true;
		//return false;
	}
};

void InitializeAntiDebugThread()
{
	Prot* SoftwareProtection = new Prot;
	while (true)
	{
		if (SoftwareProtection->IsDebuggerValid() == true || SoftwareProtection->IsErrorValid() == true)
		{
			exit(0);
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	delete SoftwareProtection;
}