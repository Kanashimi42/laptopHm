#pragma once
class ComputerMouse {
	char* company;
	char* model;
	char* USB_Interface;

	int numberOfButtons;
	double responseTime;
	int price;

	bool RGB_Backlight;
public:
	ComputerMouse();
	ComputerMouse(const char*, const char*, const char*, int, double, int, bool);
	~ComputerMouse();
	ComputerMouse(const ComputerMouse&);

	void Input();
	void Print() const;
	char* GetCompany() const;
	char* GetModel() const;
	char* GetUSB_Interface() const;

	int GetNumberOfButtons() const;
	double GetResponseTime() const;
	int GetPrice() const;

	bool GetRGB_Backlight() const;
	void SetCompany(const char*);
	void SetModel(const char*);
	void SetUSB_Interface(const char*);

	void SetNumberOfButtons(int);
	void SetResponseTime(double);
	void SetPrice(int);

	void SetRGB_Backlight(bool);
};