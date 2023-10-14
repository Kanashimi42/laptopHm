#include <iostream>
#include "Touchpad.h"

using namespace std;
Touchpad::Touchpad() {
	company = nullptr;
	model = nullptr;
	color = nullptr;

	width = 0;
	height = 0;
	price = 0;
}
Touchpad::Touchpad(const char* cp, const char* md, const char* cl, int wdht, int hght, int pr) {
	cout << "Constructor 6 params" << endl;

	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);

	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);

	color = new char[strlen(cl) + 1];
	strcpy_s(color, strlen(cl) + 1, cl);

	width = wdht;
	height = hght;
	price = pr;
}
Touchpad::~Touchpad() {
	delete[] company;
	delete[] model;
	delete[] color;
}

Touchpad::Touchpad(const Touchpad& obj) {
	company = new char[strlen(company) + 1];
	strcpy_s(company, strlen(obj.company) + 1, obj.company);

	model = new char[strlen(model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);

	color = new char[strlen(color) + 1];
	strcpy_s(color, strlen(obj.color) + 1, obj.color);

	width = obj.width;
	height = obj.height;
	price = obj.price;
}


void Touchpad::Input() {
	char buff[100];
	cout << "Enter company: ";
	cin >> buff;
	if (company != nullptr) {
		cout << "Delate company -> " << company << endl << endl;
		delete[] company;
	}
	company = new char[strlen(buff) + 1];
	strcpy_s(company, strlen(buff) + 1, buff);
	cout << "Enter model: ";
	cin >> buff;
	if (model != nullptr) {
		cout << "Delate model -> " << model << endl << endl;
		delete[] model;
	}
	model = new char[strlen(buff) + 1];
	strcpy_s(model, strlen(buff) + 1, buff);
	cout << "Enter color: ";
	cin >> buff;
	if (color != nullptr) {
		cout << "Delate color -> " << color << endl << endl;
		delete[] color;
	}
	color = new char[strlen(buff) + 1];
	strcpy_s(color, strlen(buff) + 1, buff);
	do {
		cout << "Enter width: ";
		cin >> width;

		if (width <= 0)
			cout << "Wrong width!" << endl << endl;
	} while (width <= 0);
	do {
		cout << "Enter height: ";
		cin >> height;

		if (height <= 0)
			cout << "Wrong Heigth!" << endl << endl;
	} while (height <= 0);
	do {
		cout << "Enter Price: ";
		cin >> price;

		if (price <= 0)
			cout << "Wrong price!" << endl << endl;
	} while (price <= 0);
}
void Touchpad::Print() const {
	cout << "Company: " << company << endl;
	cout << "Model: " << model << endl;
	cout << "Color: " << color << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "Price: " << price << endl;
}
char* Touchpad::GetCompany() const { return company; }
char* Touchpad::GetModel() const { return model; }
char* Touchpad::GetColor() const { return color; }

int Touchpad::GetWight() const { return width; }
int Touchpad::GetHeight() const { return height; }
int Touchpad::GetPrice() const { return price; }


void Touchpad::SetCompany(const char* cp) {
	if (cp != nullptr) {
		cout << "Delate company -> " << this->company << endl;
		delete[] company;
	}

	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
}
void Touchpad::SetModel(const char* md) {
	if (md != nullptr) {
		cout << "Delate model -> " << this->model << endl;
		delete[] model;
	}

	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
}
void Touchpad::SetColor(const char* cl) {
	if (cl != nullptr) {
		cout << "Delate color -> " << this->color << endl;
		delete[] color;
	}

	color = new char[strlen(cl) + 1];
	strcpy_s(color, strlen(cl) + 1, cl);
}

void Touchpad::SetWight(int wdht) { width = wdht; }
void Touchpad::SetHeight(int hght) { height = hght; }
void Touchpad::SetPrice(int pr) { price = pr; }