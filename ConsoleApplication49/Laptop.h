#pragma once

#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "SSD.h"
#include "Touchpad.h"
#include "Monitor.h"
#include "Keyboard.h"
#include "FlashDrive.h"
#include "ComputerMouse.h"

class Laptop {
	CPU cpu;
	GPU gpu;
	RAM ram;
	SSD ssd;
	Touchpad touchpad;
	Monitor monitor;
	Keyboard keyboard;
	FlashDrive* flashDrive;
	ComputerMouse* computerMouse;

	char* company;
	char* model;
	char* color;

	int price;

	static unsigned int numberOfLaptops;
public:
	Laptop();
	Laptop(const char* cpuCompany, const char* cpuModel, const char* cpuConntectorType, int cpuNumberOfCores, int cpuPrice,
		const char* gpuCompany, const char* gpuModel, const char* gpuMemoryType, int gpuVideoMemory, int gpuPrice,
		const char* ramCompany, const char* ramModel, const char* ramMemoryType, int ramMemory, int ramMemoryFrequency, int ramPrice, bool ramRGB_Backlight,
		const char* ssdCompany, const char* ssdModel, const char* ssdFormFactor, const char* ssdConnetcorPrice, int ssdMemory, int ssdReadingSpeed, int ssdWriteSpeed, int ssdPrice,
		const char* touchpadCompany, const char* touchpadModel, const char* touchpadColor, int touchpadWidth, int touchpadHeight, int touchpadPrice,
		const char* monitorCompany, const char* monitorModel, const char* monitorMatrix, int monitorDiagonal, int monitorMonitorFrequency, int monitorPrice,
		const char* keyboardCompany, const char* keyboardModel, double keyboardResponseTime, int keyboardPrice, bool keyboardRGB_Backlight,
		FlashDrive* flashDriveCompany,
		ComputerMouse* computerMouseCompany,
		const char* leptopCompany, const char* leptopModel, const char* leptopColor);
	Laptop(const char*);
	Laptop(const char*, const char*);
	Laptop(const char*, const char*, const char*);
	Laptop(const char*, const char*, const char*, int);
	~Laptop();
	Laptop(const Laptop&);

	void Input();
	void InputCPU();
	void InputGPU();
	void InputRAM();
	void InputSSD();
	void InputTouchpad();
	void InputMonitor();
	void InputKeyboard();
	void InputFlashDrive();
	void InputComputerMouse();


	void Print() const;
	void FullPrint() const;
	void PrintInfoNumberOfLaptops() const;
	void PrintCPU() const;
	void PrintGPU() const;
	void PrintRAM() const;
	void PrintSSD() const;
	void PrintTouchpad() const;
	void PrintMonitor() const;
	void PrintKeyboard() const;
	void PrintFlashDrive() const;
	void PrintComputerMouse() const;
	char* GetCompany() const;
	char* GetModel() const;
	char* GetColor() const;

	int GetPrice() const;
	void SetCompany(const char*);
	void SetModel(const char*);
	void SetColor(const char*);

	void SetPrice(int);
};