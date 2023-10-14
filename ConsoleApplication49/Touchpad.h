#pragma once

// Тачпад
class Touchpad {
	char* company;
	char* model;
	char* color;
	int width;
	int height;
	int price;
public:
	Touchpad();
	Touchpad(const char*, const char*, const char*, int, int, int);
	~Touchpad();
	Touchpad(const Touchpad&);

	void Input();
	void Print() const;
	char* GetCompany() const;
	char* GetModel() const;
	char* GetColor() const;

	int GetWight() const;
	int GetHeight() const;
	int GetPrice() const;
	void SetCompany(const char*);
	void SetModel(const char*);
	void SetColor(const char*);

	void SetWight(int);
	void SetHeight(int);
	void SetPrice(int);
};