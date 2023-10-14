#include <iostream>
#include "Keyboard.h"

using namespace std;

Keyboard::Keyboard() {
	company = nullptr;
	model = nullptr;
	responseTime = 0;
	price = 0;
	RGB_Backlight = false;
}

Keyboard::Keyboard(const char* cp, const char* md, double rt, int pr, bool RGB_bl) {
	cout << "Constructor 5 params" << endl;
	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
	responseTime = rt;
	price = pr;
	RGB_Backlight = RGB_bl;
}

Keyboard::~Keyboard() {
	delete[] company;
	delete[] model;
}

Keyboard::Keyboard(const Keyboard& obj) {
	company = new char[strlen(obj.company) + 1];
	strcpy_s(company, strlen(obj.company) + 1, obj.company);
	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);
	responseTime = obj.responseTime;
	price = obj.price;
	RGB_Backlight = obj.RGB_Backlight;
}

void Keyboard::Input() {
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

	do {
		cout << "Enter response time (ms): ";
		cin >> responseTime;
		if (responseTime <= 0)
			cout << "You entered an incorrect value!" << endl << endl;
	} while (responseTime <= 0);

	do {
		cout << "Enter the price: ";
		cin >> price;
		if (price <= 0)
			cout << "You entered an incorrect price!" << endl << endl;
	} while (price <= 0);

	do {
		cout << "Does it have RGB backlight? (y - yes, n - no)\n> ";
		cin >> log;
		if (log == 'y')
			RGB_Backlight = true;
		else if (log == 'n')
			RGB_Backlight = false;
		else
			cout << "You entered an incorrect character!" << endl << endl;
	} while (log != 'y' && log != 'n)');
}

void Keyboard::Print() const {
	cout << "Company: " << company << endl;
	cout << "Model: " << model << endl;
	cout << "Response Time: " << responseTime << "ms." << endl;
	printf("RGB Backlight: %s\n", RGB_Backlight == true ? "present" : "absent");
	cout << "Price: " << price << endl;
}

char* Keyboard::GetCompany() const { return company; }
char* Keyboard::GetModel() const { return model; }

double Keyboard::GetResponseTime() const { return responseTime; }
int Keyboard::GetPrice() const { return price; }

bool Keyboard::GetRGB_Backlight() const { return RGB_Backlight; }

void Keyboard::SetCompany(const char* cp) {
	if (cp != nullptr) {
		cout << "Delete company -> " << this->company << endl;
		delete[] company;
	}
	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
}

void Keyboard::SetModel(const char* md) {
	if (md != nullptr) {
		cout << "Delete model -> " << this->model << endl;
		delete[] model;
	}
	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
}

void Keyboard::SetResponseTime(double rt) {
	responseTime = rt;
}

void Keyboard::SetPrice(int pr) {
	price = pr;
}

void Keyboard::SetRGB_Backlight(bool RGB_bl) {
	RGB_Backlight = RGB_bl;
}
