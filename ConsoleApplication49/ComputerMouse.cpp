#include <iostream>
#include "ComputerMouse.h"

using namespace std;

ComputerMouse::ComputerMouse() {
	company = nullptr;
	model = nullptr;
	USB_Interface = nullptr;

	numberOfButtons = 0;
	responseTime = 0;
	price = 0;

	RGB_Backlight = false;
}
ComputerMouse::ComputerMouse(const char* cp, const char* md, const char* USB_Inf, int nofb, double rt, int pr, bool RGB_bl) {
	cout << "Constructor 7 params" << endl;

	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);

	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);

	USB_Interface = new char[strlen(USB_Inf) + 1];
	strcpy_s(USB_Interface, strlen(USB_Inf) + 1, USB_Inf);

	numberOfButtons = nofb;
	responseTime = rt;
	price = pr;

	RGB_Backlight = RGB_bl;
}
ComputerMouse::~ComputerMouse() {
	delete[] company;
	delete[] model;
	delete[] USB_Interface;
}

ComputerMouse::ComputerMouse(const ComputerMouse& obj) {
	company = new char[strlen(obj.company) + 1];
	strcpy_s(company, strlen(obj.company) + 1, obj.company);

	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);

	USB_Interface = new char[strlen(obj.USB_Interface) + 1];
	strcpy_s(USB_Interface, strlen(obj.USB_Interface) + 1, obj.USB_Interface);

	numberOfButtons = obj.numberOfButtons;
	responseTime = obj.responseTime;
	price = obj.price;

	RGB_Backlight = obj.RGB_Backlight;
}

void ComputerMouse::Input() {
	char buff[100];
	char log;

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

	cout << "Enter the USB interface: ";
	cin >> buff;
	if (USB_Interface != nullptr) {
		cout << "Delete USB_Interface -> " << USB_Interface << endl << endl;
		delete[] USB_Interface;
	}
	USB_Interface = new char[strlen(buff) + 1];
	strcpy_s(USB_Interface, strlen(buff) + 1, buff);

	do {
		cout << "Enter the number of buttons: ";
		cin >> numberOfButtons;
		if (numberOfButtons <= 3)
			cout << "You entered an incorrect number of buttons!" << endl << endl;
	} while (numberOfButtons <= 3);

	do {
		cout << "Enter the response time (ms): ";
		cin >> responseTime;
		if (responseTime <= 0)
			cout << "You entered an incorrect value!" << endl << endl;
	} while (responseTime <= 0);

	do {
		cout << "Will there be RGB backlight? (y - yes, n - no)\n> ";
		cin >> log;

		if (log == 'y')
			RGB_Backlight = true;
		else if (log == 'n')
			RGB_Backlight = false;
		else
			cout << "You entered an incorrect character!" << endl << endl;
	} while (log != 'y' && log != 'n');
}

void ComputerMouse::Print() const {
	cout << "Company: " << company << endl;
	cout << "Model: " << model << endl;
	cout << "USB interface: " << USB_Interface << endl;
	cout << "Number of buttons: " << numberOfButtons << endl;
	cout << "Response time: " << responseTime << "ms." << endl;
	printf("RGB backlight: %s\n", RGB_Backlight ? "present" : "absent");
	cout << "Price: " << price << endl;
}

char* ComputerMouse::GetCompany() const { return company; }
char* ComputerMouse::GetModel() const { return model; }
char* ComputerMouse::GetUSB_Interface() const { return USB_Interface; }

int ComputerMouse::GetNumberOfButtons() const { return numberOfButtons; }
double ComputerMouse::GetResponseTime() const { return responseTime; }
int ComputerMouse::GetPrice() const { return price; }

bool ComputerMouse::GetRGB_Backlight() const { return RGB_Backlight; }

void ComputerMouse::SetCompany(const char* cp) {
	if (cp != nullptr) {
		cout << "Delete company -> " << this->company << endl;
		delete[] company;
	}
	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
}

void ComputerMouse::SetModel(const char* md) {
	if (md != nullptr) {
		cout << "Delete model -> " << this->model << endl;
		delete[] model;
	}
	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
}

void ComputerMouse::SetUSB_Interface(const char* USB_Inf) {
	if (USB_Inf != nullptr) {
		cout << "Delete USB_Interface -> " << this->USB_Interface << endl;
		delete[] USB_Interface;
	}
	USB_Interface = new char[strlen(USB_Inf) + 1];
	strcpy_s(USB_Interface, strlen(USB_Inf) + 1, USB_Inf);
}

void ComputerMouse::SetNumberOfButtons(int nofb) {
	numberOfButtons = nofb;
}

void ComputerMouse::SetResponseTime(double rt) {
	responseTime = rt;
}

void ComputerMouse::SetPrice(int pr) {
	price = pr;
}

void ComputerMouse::SetRGB_Backlight(bool RGB_bl) {
	RGB_Backlight = RGB_bl;
}
