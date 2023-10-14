#pragma once
class Monitor {
	char* company;
	char* model;
	char* matrix;

	int diagonal;
	int monitorFrequency;
	int price;
public:
	Monitor();
	Monitor(const char*, const char*, const char*, int, int, int);
	~Monitor();
	Monitor(const Monitor&);

	void Input();
	void Print() const;
	char* GetCompany() const;
	char* GetModel() const;
	char* GetMatrix() const;

	int GetDiagonal() const;
	int GetMonitorFrequency() const;
	int GetPrice() const;
	void SetCompany(const char*);
	void SetModel(const char*);
	void SetMatrix(const char*);

	void SetDiagonal(int);
	void SetMonitorFrequency(int);
	void SetPrice(int);
};
