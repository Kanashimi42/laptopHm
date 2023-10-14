#pragma once
class Keyboard {
	char* company;
	char* model;

	double responseTime;
	int price;

	bool RGB_Backlight;
public:
	Keyboard();
	Keyboard(const char*, const char*, double, int, bool);
	~Keyboard();
	Keyboard(const Keyboard&);

	void Input();
	void Print() const;
	char* GetCompany() const;
	char* GetModel() const;

	double GetResponseTime() const;
	int GetPrice() const;

	bool GetRGB_Backlight() const;
	void SetCompany(const char*);
	void SetModel(const char*);

	void SetResponseTime(double);
	void SetPrice(int);

	void SetRGB_Backlight(bool);
};