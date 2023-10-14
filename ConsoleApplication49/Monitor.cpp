#include <iostream>
#include "Monitor.h"

using namespace std;
Monitor::Monitor() {
	company = nullptr;
	model = nullptr;
	matrix = nullptr;

	diagonal = 0;
	monitorFrequency = 0;
	price = 0;
}

Monitor::Monitor(const char* cp, const char* md, const char* mt, int dg, int mf, int pr) {
	cout << "Constructor 6 params" << endl;

	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);

	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);

	matrix = new char[strlen(mt) + 1];
	strcpy_s(matrix, strlen(mt) + 1, mt);

	diagonal = dg;
	monitorFrequency = mf;
	price = pr;
}

Monitor::~Monitor() {
	delete[] company;
	delete[] model;
	delete[] matrix;
}
Monitor::Monitor(const Monitor& obj) {
	company = new char[strlen(obj.company) + 1];
	strcpy_s(company, strlen(obj.company) + 1, obj.company);

	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);

	matrix = new char[strlen(obj.matrix) + 1];
	strcpy_s(matrix, strlen(obj.matrix) + 1, obj.matrix);

	diagonal = obj.diagonal;
	monitorFrequency = obj.monitorFrequency;
	price = obj.price;
}

void Monitor::Input() {
	char buff[100];
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

	cout << "Enter the matrix type: ";
	cin >> buff;
	if (matrix != nullptr) {
		cout << "Delete matrix -> " << matrix << endl << endl;
		delete[] matrix;
	}
	matrix = new char[strlen(buff) + 1];
	strcpy_s(matrix, strlen(buff) + 1, buff);

	do {
		cout << "Enter the diagonal: ";
		cin >> diagonal;

		if (diagonal <= 0 || diagonal >= 34)
			cout << "You entered an incorrect diagonal!" << endl << endl;
	} while (diagonal <= 0 || diagonal >= 34);

	do {
		cout << "Enter the screen refresh rate: ";
		cin >> monitorFrequency;

		if (monitorFrequency != 60 && monitorFrequency != 90 && monitorFrequency != 120 && monitorFrequency != 144 && monitorFrequency != 240)
			cout << "You entered an incorrect screen refresh rate!" << endl << endl;
	} while (monitorFrequency != 60 && monitorFrequency != 90 && monitorFrequency != 120 && monitorFrequency != 144 && monitorFrequency != 240);

	do {
		cout << "Enter the price: ";
		cin >> price;

		if (price <= 0)
			cout << "You entered an incorrect price!" << endl << endl;
	} while (price <= 0);
}

void Monitor::Print() const {
	cout << "Company: " << company << endl;
	cout << "Model: " << model << endl;
	cout << "Matrix: " << matrix << endl;
	cout << "Diagonal: " << diagonal << endl;
	cout << "Monitor Frequency: " << monitorFrequency << endl;
	cout << "Price: " << price << endl;
}
char* Monitor::GetCompany() const { return company; }
char* Monitor::GetModel() const { return model; }
char* Monitor::GetMatrix() const { return matrix; }

int Monitor::GetDiagonal() const { return diagonal; }
int Monitor::GetMonitorFrequency() const { return monitorFrequency; }
int Monitor::GetPrice() const { return price; }
void Monitor::SetCompany(const char* cp) {
	if (cp != nullptr) {
		cout << "Delete company -> " << this->company << endl;
		delete[] company;
	}

	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
}

void Monitor::SetModel(const char* md) {
	if (md != nullptr) {
		cout << "Delete model -> " << this->model << endl;
		delete[] model;
	}

	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
}

void Monitor::SetMatrix(const char* mt) {
	if (mt != nullptr) {
		cout << "Delete matrix -> " << this->matrix << endl;
		delete[] matrix;
	}

	matrix = new char[strlen(mt) + 1];
	strcpy_s(matrix, strlen(mt) + 1, mt);
}

void Monitor::SetDiagonal(int dg) { diagonal = dg; }
void Monitor::SetMonitorFrequency(int mf) { monitorFrequency = mf; }
void Monitor::SetPrice(int pr) { price = pr; }
