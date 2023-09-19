#pragma once

// CPU
class CPU {
	char* brand;
	char* model;
	char* connectorType;
	int numberOfCores;
	int price;

public:
	// Constructors/Destructor
	CPU();
	CPU(const char*, const char*, const char*, int, int);
	~CPU();

	// Deep copy
	CPU(const CPU&);

	void Input();
	void Print() const;

	// Accessors
	// Getters
	char* GetBrand() const;
	char* GetModel() const;
	char* GetConnectorType() const;
	int GetNumberOfCores() const;
	int GetPrice() const;

	// Setters
	void SetBrand(const char*);
	void SetModel(const char*);
	void SetConnectorType(const char*);
	void SetNumberOfCores(int);
	void SetPrice(int);
};
