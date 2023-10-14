#include <iostream>
#include "FlashDrive.h"

using namespace std;

FlashDrive::FlashDrive() {
	company = nullptr;
	model = nullptr;
	USB_Interface = nullptr;

	memory = 0;
	readingSpeed = 0;
	writeSpeed = 0;
	price = 0;
}

FlashDrive::FlashDrive(const char* cp, const char* md, const char* USB_Inf, int me, int rs, int ws, int pr) {
	cout << "Constructor 7 params" << endl;

	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);

	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);

	USB_Interface = new char[strlen(USB_Inf) + 1];
	strcpy_s(USB_Interface, strlen(USB_Inf) + 1, USB_Inf);

	memory = me;
	readingSpeed = rs;
	writeSpeed = ws;
	price = pr;
}

FlashDrive::~FlashDrive() {
	delete[] company;
	delete[] model;
	delete[] USB_Interface;
}

FlashDrive::FlashDrive(const FlashDrive& obj) {
	company = new char[strlen(obj.company) + 1];
	strcpy_s(company, strlen(obj.company) + 1, obj.company);

	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);

	USB_Interface = new char[strlen(obj.USB_Interface) + 1];
	strcpy_s(USB_Interface, strlen(obj.USB_Interface) + 1, obj.USB_Interface);

	memory = obj.memory;
	readingSpeed = obj.readingSpeed;
	writeSpeed = obj.writeSpeed;
	price = obj.price;
}

void FlashDrive::Input() {
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

	cout << "Enter USB Interface: ";
	cin >> buff;
	if (USB_Interface != nullptr) {
		delete[] USB_Interface;
	}
	USB_Interface = new char[strlen(buff) + 1];
	strcpy_s(USB_Interface, strlen(buff) + 1, buff);

	do {
		cout << "Enter memory: ";
		cin >> memory;

		if (memory <= 0)
			cout << "Invalid memory size!" << endl << endl;
	} while (memory <= 0);

	do {
		cout << "Enter reading speed: ";
		cin >> readingSpeed;

		if (readingSpeed <= 0)
			cout << "Invalid reading speed!" << endl << endl;
	} while (readingSpeed <= 0);

	do {
		cout << "Enter write speed: ";
		cin >> writeSpeed;

		if (writeSpeed <= 0)
			cout << "Invalid write speed!" << endl << endl;
	} while (writeSpeed <= 0);

	do {
		cout << "Enter price: ";
		cin >> price;

		if (price <= 0)
			cout << "Invalid price!" << endl << endl;
	} while (price <= 0);
}

void FlashDrive::Print() const {
	cout << "Company: " << company << endl;
	cout << "Model: " << model << endl;
	cout << "USB Interface: " << USB_Interface << endl;
	cout << "Memory: " << memory << endl;
	cout << "Reading Speed: " << readingSpeed << endl;
	cout << "Write Speed: " << readingSpeed << endl;
	cout << "Price: " << price << endl;
}

char* FlashDrive::GetCompany() const { return company; }
char* FlashDrive::GetModel() const { return model; }
char* FlashDrive::GetUSB_Interface() const { return USB_Interface; }

int FlashDrive::GetMemory() const { return memory; }
int FlashDrive::GetReadingSpeed() const { return readingSpeed; }
int FlashDrive::GetWriteSpeed() const { return writeSpeed; }
int FlashDrive::GetPrice() const { return price; }

void FlashDrive::SetCompany(const char* cp) {
	if (cp != nullptr) {
		delete[] company;
	}
	company = new char[strlen(cp) + 1];
	strcpy_s(company, strlen(cp) + 1, cp);
}

void FlashDrive::SetModel(const char* md) {
	if (md != nullptr) {
		delete[] model;
	}
	model = new char[strlen(md) + 1];
	strcpy_s(model, strlen(md) + 1, md);
}

void FlashDrive::SetUSB_Interface(const char* USB_Inf) {
	if (USB_Inf != nullptr) {
		delete[] USB_Interface;
	}
	USB_Interface = new char[strlen(USB_Inf) + 1];
	strcpy_s(USB_Interface, strlen(USB_Inf) + 1, USB_Inf);
}

void FlashDrive::SetMemory(int me) {
	memory = me;
}

void FlashDrive::SetReadingSpeed(int rs) {
	readingSpeed = rs;
}

void FlashDrive::SetWriteSpeed(int ws) {
	writeSpeed = ws;
}

void FlashDrive::SetPrice(int pr) {
	price = pr;
}
