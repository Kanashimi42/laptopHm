#pragma once
class FlashDrive {
	char* company;
	char* model;
	char* USB_Interface;

	int memory;
	int readingSpeed;
	int writeSpeed;
	int price;
public:
	FlashDrive();
	FlashDrive(const char*, const char*, const char*, int, int, int, int);
	~FlashDrive();
	FlashDrive(const FlashDrive&);

	void Input();
	void Print() const;
	char* GetCompany() const;
	char* GetModel() const;
	char* GetUSB_Interface() const;

	int GetMemory() const;
	int GetReadingSpeed() const;
	int GetWriteSpeed() const;
	int GetPrice() const;
	void SetCompany(const char*);
	void SetModel(const char*);
	void SetUSB_Interface(const char*);

	void SetMemory(int);
	void SetReadingSpeed(int);
	void SetWriteSpeed(int);
	void SetPrice(int);
};