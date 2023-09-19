#pragma once

#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "SSD.h"

// Laptop
class Laptop {
	char* manufacturer;
	char* model;
	char* color;
	int price;
	CPU cpu;
	GPU gpu;
	RAM ram;
	SSD ssd;

	// Static field
	static unsigned int numberOfLaptops;

public:
	// Constructors/Destructor
	Laptop();
	Laptop(const char* cpuBrand, const char* cpuModel, const char* cpuConnectorType, int cpuNumberOfCores, int cpuPrice,
		const char* gpuBrand, const char* gpuModel, const char* gpuMemoryType, int gpuVideoMemory, int gpuPrice,
		const char* ramBrand, const char* ramModel, const char* ramMemoryType, int ramMemory, int ramMemoryFrequency, int ramPrice, bool ramRGB_Backlight,
		const char* ssdBrand, const char* ssdModel, const char* ssdFormFactor, const char* ssdConnectorType, int ssdMemory, int ssdReadingSpeed, int ssdWriteSpeed, int ssdPrice,
		const char* laptopBrand, const char* laptopModel, const char* laptopColor);
	Laptop(const char* brand);
	Laptop(const char* brand, const char* model);
	Laptop(const char* brand, const char* model, const char* color);
	Laptop(const char* brand, const char* model, const char* color, int price);

	~Laptop();

	// Deep copy
	Laptop(const Laptop&);

	void Input();
	void InputCPU();
	void InputGPU();
	void InputRAM();
	void InputSSD();

	void Print() const;
	void FullPrint() const;
	void PrintInfoNumberOfLaptops() const;
	void PrintCPU() const;
	void PrintGPU() const;
	void PrintRAM() const;
	void PrintSSD() const;

	// Accessors
	// Getters
	const char* GetManufacturer() const;
	const char* GetModel() const;
	const char* GetColor() const;
	int GetPrice() const;


	// Setters
	void SetManufacturer(const char*);
	void SetModel(const char*);
	void SetColor(const char*);
	void SetPrice(int);
};
