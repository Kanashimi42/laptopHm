#include <iostream>
#include "Laptop.h"
#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "SSD.h"
#include "Touchpad.h"
#include "Monitor.h"
#include "Keyboard.h"
#include "FlashDrive.h"
#include "ComputerMouse.h"

using namespace std;

unsigned int Laptop::numberOfLaptops = 0U;

Laptop::Laptop() {
	company = nullptr;
	model = nullptr;
	color = nullptr;

	price = 0;
	++numberOfLaptops;
}

Laptop::Laptop(const char* cpuCompany, const char* cpuModel, const char* cpuConnectorType, int cpuNumberOfCores, int cpuPrice,
	const char* gpuCompany, const char* gpuModel, const char* gpuMemoryType, int gpuVideoMemory, int gpuPrice,
	const char* ramCompany, const char* ramModel, const char* ramMemoryType, int ramMemory, int ramMemoryFrequency, int ramPrice, bool ramRGB_Backlight,
	const char* ssdCompany, const char* ssdModel, const char* ssdFormFactor, const char* ssdConnectorPrice, int ssdMemory, int ssdReadingSpeed, int ssdWriteSpeed, int ssdPrice,
	const char* touchpadCompany, const char* touchpadModel, const char* touchpadColor, int touchpadWidth, int touchpadHeight, int touchpadPrice,
	const char* monitorCompany, const char* monitorModel, const char* monitorMatrix, int monitorDiagonal, int monitorMonitorFrequency, int monitorPrice,
	const char* keyboardCompany, const char* keyboardModel, double keyboardResponseTime, int keyboardPrice, bool keyboardRGB_Backlight,
	FlashDrive* flashDrive,
	ComputerMouse* computerMouse,
	const char* laptopCompany, const char* laptopModel, const char* laptopColor) :
	cpu(cpuCompany, cpuModel, cpuConnectorType, cpuNumberOfCores, cpuPrice),
	gpu(gpuCompany, gpuModel, gpuMemoryType, gpuVideoMemory, gpuPrice),
	ram(ramCompany, ramModel, ramMemoryType, ramMemory, ramMemoryFrequency, ramPrice, ramRGB_Backlight),
	ssd(ssdCompany, ssdModel, ssdFormFactor, ssdConnectorPrice, ssdMemory, ssdReadingSpeed, ssdWriteSpeed, ssdPrice),
	touchpad(touchpadCompany, touchpadModel, touchpadColor, touchpadWidth, touchpadHeight, touchpadPrice),
	monitor(monitorCompany, monitorModel, monitorMatrix, monitorDiagonal, monitorMonitorFrequency, monitorPrice),
	keyboard(keyboardCompany, keyboardModel, keyboardResponseTime, keyboardPrice, keyboardRGB_Backlight),
	flashDrive(flashDrive),
	computerMouse(computerMouse) {
	cout << "Full initialization by 10 classes: CPU, GPU, RAM, SSD, touchpad, monitor, keyboard, flashDrive, computerMouse, laptop" << endl;

	company = new char[strlen(laptopCompany) + 1];
	strcpy_s(company, strlen(laptopCompany) + 1, laptopCompany);

	model = new char[strlen(laptopModel) + 1];
	strcpy_s(model, strlen(laptopModel) + 1, laptopModel);

	color = new char[strlen(laptopColor) + 1];
	strcpy_s(color, strlen(laptopColor) + 1, laptopColor);

	int temp = flashDrive->GetPrice();
	temp += computerMouse->GetPrice();

	price += cpuPrice += gpuPrice += ramPrice += ssdPrice += touchpadPrice += monitorPrice += keyboardPrice += temp;
}

Laptop::Laptop(const char* cp) {
	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
}

Laptop::Laptop(const char* cp, const char* md) : Laptop(cp) {
	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
}

Laptop::Laptop(const char* cp, const char* md, const char* cl) : Laptop(cp, md) {
	color = new char[strlen(cl) + 1];
	strcpy_s(color, strlen(cl) + 1, cl);
}

Laptop::Laptop(const char* cp, const char* md, const char* cl, int pr) : Laptop(cp, md, cl) {
	cout << "Constructor with 4 parameters" << endl;

	price = pr;
	++numberOfLaptops;
}

Laptop::~Laptop() {
	delete[] company;
	delete[] model;
	delete[] color;

	--numberOfLaptops;
}

Laptop::Laptop(const Laptop& obj) :
	cpu(obj.cpu.GetCompany(), obj.cpu.GetModel(), obj.cpu.GetConnectorType(), obj.cpu.GetNumberOfCores(), obj.cpu.GetPrice()),
	gpu(obj.gpu.GetCompany(), obj.gpu.GetModel(), obj.gpu.GetMemoryType(), obj.gpu.GetVideoMemory(), obj.gpu.GetPrice()),
	ram(obj.ram.GetCompany(), obj.ram.GetCompany(), obj.ram.GetMemoryType(), obj.ram.GetMemory(), obj.ram.GetMemoryFrequency(), obj.ram.GetPrice(), obj.ram.GetRGB_Backlight()),
	ssd(obj.ssd.GetCompany(), obj.ssd.GetModel(), obj.ssd.GetFormFactor(), obj.ssd.GetConnectorType(), obj.ssd.GetMemory(), obj.ssd.GetReadingSpeed(), obj.ssd.GetWriteSpeed(), obj.ssd.GetPrice()),
	touchpad(obj.touchpad.GetCompany(), obj.touchpad.GetModel(), obj.touchpad.GetColor(), obj.touchpad.GetWidth(), obj.touchpad.GetHeight(), obj.touchpad.GetPrice()),
	monitor(obj.monitor.GetCompany(), obj.monitor.GetModel(), obj.monitor.GetMatrix(), obj.monitor.GetDiagonal(), obj.monitor.GetMonitorFrequency(), obj.monitor.GetPrice()),
	keyboard(obj.keyboard.GetCompany(), obj.keyboard.GetModel(), obj.keyboard.GetResponseTime(), obj.keyboard.GetPrice(), obj.keyboard.GetRGB_Backlight()),
	flashDrive(obj.flashDrive),
	computerMouse(obj.computerMouse) {
	company = new char[strlen(obj.company) + 1];
	strcpy_s(this->company, strlen(obj.company) + 1, obj.company);

	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);

	color = new char[strlen(obj.color) + 1];
	strcpy_s(color, strlen(obj.color) + 1, obj.color);

	price = obj.price;
}

void Laptop::Input() {
	char buff[100];
	int TempPrice = 0;

	cout << "Input data about the CPU: " << endl;
	cpu.Input();
	cout << endl << endl;

	cout << "Input data about the GPU: " << endl;
	gpu.Input();
	cout << endl << endl;

	cout << "Input data about RAM: " << endl;
	ram.Input();
	cout << endl << endl;

	cout << "Input data about SSD: " << endl;
	ssd.Input();
	cout << endl << endl;

	cout << "Input data about the touchpad: " << endl;
	touchpad.Input();
	cout << endl << endl;

	cout << "Input data about the monitor: " << endl;
	monitor.Input();
	cout << endl << endl;

	cout << "Input data about the USB flash drive: " << endl;
	flashDrive->Input();
	cout << endl << endl;

	cout << "Input data about the computer mouse: " << endl;
	computerMouse->Input();
	cout << endl << endl;

	cout << "Enter the company: ";
	cin >> buff;
	if (company != nullptr) {
		cout << "Delete company -> " << company << endl << endl;
		delete[] company;
	}
	company = new char[strlen(buff) + 1];
	strcpy_s(company, strlen(buff) + 1, buff);

	cout << "Enter the model: ";
	cin >> buff;
	if (model != nullptr) {
		cout << "Delete model -> " << model << endl << endl;
		delete[] model;
	}
	model = new char[strlen(buff) + 1];
	strcpy_s(model, strlen(buff) + 1, buff);

	cout << "Enter the color: ";
	cin >> buff;
	if (color != nullptr) {
		cout << "Delete color -> " << color << endl << endl;
		delete[] color;
	}
	color = new char[strlen(buff) + 1];
	strcpy_s(color, strlen(buff) + 1, buff);

	TempPrice += cpu.GetPrice();
	TempPrice += gpu.GetPrice();
	TempPrice += ram.GetPrice();
	TempPrice += ssd.GetPrice();

	price = TempPrice;
}

void Laptop::InputCPU() { cpu.Input(); }
void Laptop::InputGPU() { gpu.Input(); }
void Laptop::InputRAM() { ram.Input(); }
void Laptop::InputSSD() { ssd.Input(); }
void Laptop::InputTouchpad() { touchpad.Input(); }
void Laptop::InputMonitor() { monitor.Input(); }
void Laptop::InputKeyboard() { keyboard.Input(); }
void Laptop::InputFlashDrive() { flashDrive->Input(); }
void Laptop::InputComputerMouse() { computerMouse->Input(); }

void Laptop::Print() const {
	cout << "Company: " << company << endl;
	cout << "Model: " << model << endl;
	cout << "Color: " << color << endl;
	cout << "Price: " << price << endl;
}

void Laptop::FullPrint() const {
	cout << "Laptop: " << endl;
	cout << "Company: " << company << endl;
	cout << "Model: " << model << endl;
	cout << "Color: " << color << endl;
	cout << endl;

	cout << "CPU: " << endl;
	cpu.Print();
	cout << endl;

	cout << "GPU: " << endl;
	gpu.Print();
	cout << endl;

	cout << "RAM: " << endl;
	ram.Print();
	cout << endl;

	cout << "SSD: " << endl;
	ssd.Print();
	cout << endl;

	cout << "Touchpad: " << endl;
	touchpad.Print();
	cout << endl;

	cout << "Monitor: " << endl;
	monitor.Print();
	cout << endl;

	cout << "Keyboard: " << endl;
	keyboard.Print();
	cout << endl;

	cout << "USB flash drive: " << endl;
	flashDrive->Print();
	cout << endl;

	cout << "Computer mouse: " << endl;
	computerMouse->Print();
	cout << endl;

	cout << "Laptop price: " << price << endl;
}

void Laptop::PrintInfoNumberOfLaptops() const {
	cout << "Number of laptops: " << numberOfLaptops << endl;
}

void Laptop::PrintCPU() const { cpu.Print(); }
void Laptop::PrintGPU() const { gpu.Print(); }
void Laptop::PrintRAM() const { ram.Print(); }
void Laptop::PrintSSD() const { ssd.Print(); }
void Laptop::PrintTouchpad() const { touchpad.Print(); }
void Laptop::PrintMonitor() const { monitor.Print(); }
void Laptop::PrintKeyboard() const { keyboard.Print(); }
void Laptop::PrintFlashDrive() const { flashDrive->Print(); }
void Laptop::PrintComputerMouse() const { computerMouse->Print(); }

char* Laptop::GetCompany() const { return company; }
char* Laptop::GetModel() const { return model; }
char* Laptop::GetColor() const { return color; }
int Laptop::GetPrice() const { return price; }

void Laptop::SetCompany(const char* cp) {
	if (cp != nullptr) {
		cout << "Delete company -> " << this->company << endl;
	}

	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
}

void Laptop::SetModel(const char* md) {
	if (md != nullptr) {
		cout << "Delete model -> " << this->model << endl;
	}

	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
}

void Laptop::SetColor(const char* cl) {
	if (cl != nullptr) {
		cout << "Delete color -> " << this->color << endl;
	}

	color = new char[strlen(cl) + 1];
	strcpy_s(color, strlen(cl) + 1, cl);
}

void Laptop::SetPrice(int pr) {
	price = pr;
}
