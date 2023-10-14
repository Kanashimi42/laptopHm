#include <iostream>
#include "CPU.h"

using namespace std;

CPU::CPU() {
	company = nullptr;
	model = nullptr;
	connectorType = nullptr;
	numberOfCores = 0;
	price = 0;
}

CPU::CPU(const char* cp, const char* md, const char* ct, int noc, int pr) {
	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);

	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);

	connectorType = new char[strlen(ct) + 1];
	strcpy_s(connectorType, strlen(ct) + 1, ct);

	numberOfCores = noc;
	price = pr;
}

CPU::~CPU() {
	delete[] company;
	delete[] model;
	delete[] connectorType;
}

CPU::CPU(const CPU& obj) {
	company = new char[strlen(obj.company) + 1];
	strcpy_s(company, strlen(obj.company) + 1, obj.company);

	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);

	connectorType = new char[strlen(obj.connectorType) + 1];
	strcpy_s(connectorType, strlen(obj.connectorType) + 1, obj.connectorType);

	numberOfCores = obj.numberOfCores;
	price = obj.price;
}

void CPU::Input() {
	char buff[100];

	cout << "Enter company: ";
	cin >> buff;
	if (company != nullptr) {
		delete[] company;
	}
	company = new char[strlen(buff) + 1];
	strcpy_s(company, strlen(buff) + 1, buff);

	cout << "Enter model: ";
	cin >> buff;
	if (model != nullptr) {
		delete[] model;
	}
	model = new char[strlen(buff) + 1];
	strcpy_s(model, strlen(buff) + 1, buff);

	cout << "Enter connector type: ";
	cin >> buff;
	if (connectorType != nullptr) {
		delete[] connectorType;
	}
	connectorType = new char[strlen(buff) + 1];
	strcpy_s(connectorType, strlen(buff) + 1, buff);

	cout << "Enter number of cores: ";
	cin >> numberOfCores;

	cout << "Enter price: ";
	cin >> price;
}

void CPU::Print() const {
	cout << "Company: " << company << endl;
	cout << "Model: " << model << endl;
	cout << "Connector Type: " << connectorType << endl;
	cout << "Number of Cores: " << numberOfCores << endl;
	cout << "Price: " << price << endl;
}

char* CPU::GetCompany() const {
	return company;
}

char* CPU::GetModel() const {
	return model;
}

char* CPU::GetConnectorType() const {
	return connectorType;
}

int CPU::GetNumberOfCores() const {
	return numberOfCores;
}

int CPU::GetPrice() const {
	return price;
}

void CPU::SetCompany(const char* cp) {
	if (cp != nullptr) {
		delete[] company;
	}
	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
}

void CPU::SetModel(const char* md) {
	if (md != nullptr) {
		delete[] model;
	}
	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
}

void CPU::SetConnectorType(const char* ct) {
	if (ct != nullptr) {
		delete[] connectorType;
	}
	connectorType = new char[strlen(ct) + 1];
	strcpy_s(connectorType, strlen(ct) + 1, ct);
}

void CPU::SetNumberOfCores(int noc) {
	numberOfCores = noc;
}

void CPU::SetPrice(int pr) {
	price = pr;
}
