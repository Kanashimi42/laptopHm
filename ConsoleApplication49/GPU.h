#pragma once
class GPU {
	char* company;
	char* model;
	char* memoryType;

	int videoMemory;
	int price;
public:
	GPU();
	GPU(const char*, const char*, const char*, int, int);
	~GPU();
	GPU(const GPU&);

	void Input();
	void Print() const;
	char* GetCompany() const;
	char* GetModel() const;
	char* GetMemoryType() const;

	int GetVideoMemory() const;
	int GetPrice() const;
	void SetCompany(const char*);
	void SetModel(const char*);
	void SetMemoryType(const char*);

	void SetVideoMemory(int);
	void SetPrice(int);
};
