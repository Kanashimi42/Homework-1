#pragma once

class GPU {
	char* manufacturer;
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

	char* GetManufacturer() const;
	char* GetModel() const;
	char* GetMemoryType() const;
	int GetVideoMemory() const;
	int GetPrice() const;

	void SetManufacturer(const char*);
	void SetModel(const char*);
	void SetMemoryType(const char*);
	void SetVideoMemory(int);
	void SetPrice(int);
};
