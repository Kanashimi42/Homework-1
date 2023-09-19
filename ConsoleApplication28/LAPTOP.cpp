#include <iostream>
#include "Laptop.h"
#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "SSD.h"

using namespace std;

unsigned int Laptop::numberOfLaptops = 0U;

Laptop::Laptop() {
	manufacturer = nullptr;
	model = nullptr;
	color = nullptr;
	price = 0;
	++numberOfLaptops;
}

Laptop::Laptop(const char* cpuBrand, const char* cpuModel, const char* cpuConnectorType, int cpuNumberOfCores, int cpuPrice,
	const char* gpuBrand, const char* gpuModel, const char* gpuMemoryType, int gpuVideoMemory, int gpuPrice,
	const char* ramBrand, const char* ramModel, const char* ramMemoryType, int ramMemory, int ramMemoryFrequency, int ramPrice, bool ramRGB_Backlight,
	const char* ssdBrand, const char* ssdModel, const char* ssdFormFactor, const char* ssdConnectorType, int ssdMemory, int ssdReadingSpeed, int ssdWriteSpeed, int ssdPrice,
	const char* laptopBrand, const char* laptopModel, const char* laptopColor) :
	cpu(cpuBrand, cpuModel, cpuConnectorType, cpuNumberOfCores, cpuPrice),
	gpu(gpuBrand, gpuModel, gpuMemoryType, gpuVideoMemory, gpuPrice),
	ram(ramBrand, ramModel, ramMemoryType, ramMemory, ramMemoryFrequency, ramPrice, ramRGB_Backlight),
	ssd(ssdBrand, ssdModel, ssdFormFactor, ssdConnectorType, ssdMemory, ssdReadingSpeed, ssdWriteSpeed, ssdPrice) {
	cout << "Full initialization by 5 classes: CPU, GPU, RAM, SSD, Laptop" << endl;

	manufacturer = new char[strlen(laptopBrand) + 1];
	strcpy_s(manufacturer, strlen(laptopBrand) + 1, laptopBrand);

	model = new char[strlen(laptopModel) + 1];
	strcpy_s(model, strlen(laptopModel) + 1, laptopModel);

	color = new char[strlen(laptopColor) + 1];
	strcpy_s(color, strlen(laptopColor) + 1, laptopColor);

	price += cpuPrice += gpuPrice += ramPrice += ssdPrice;
}

Laptop::Laptop(const char* brand) {
	manufacturer = new char[strlen(brand) + 1];
	strcpy_s(manufacturer, strlen(brand) + 1, brand);
}

Laptop::Laptop(const char* brand, const char* model) : Laptop(brand) {
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

Laptop::Laptop(const char* brand, const char* model, const char* color) : Laptop(brand, model) {
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}


Laptop::Laptop(const char* brand, const char* model, const char* color, int price) : Laptop(brand, model, color) {
	cout << "Constructor with 4 parameters" << endl;
	price = price;
	++numberOfLaptops;
}

Laptop::~Laptop() {
	delete[] manufacturer;
	delete[] model;
	delete[] color;
	--numberOfLaptops;
}

Laptop::Laptop(const Laptop& obj) :
	cpu(obj.cpu.GetBrand(), obj.cpu.GetModel(), obj.cpu.GetConnectorType(), obj.cpu.GetNumberOfCores(), obj.cpu.GetPrice()),
	gpu(obj.gpu.GetManufacturer(), obj.gpu.GetModel(), obj.gpu.GetMemoryType(), obj.gpu.GetVideoMemory(), obj.gpu.GetPrice()),
	ram(obj.ram.GetCompany(), obj.ram.GetCompany(), obj.ram.GetMemoryType(), obj.ram.GetMemory(), obj.ram.GetMemoryFrequency(), obj.ram.GetPrice(), obj.ram.GetRGB_Backlight()),
	ssd(obj.ssd.GetCompany(), obj.ssd.GetModel(), obj.ssd.GetFormFactor(), obj.ssd.GetConnectorType(), obj.ssd.GetMemory(), obj.ssd.GetReadingSpeed(), obj.ssd.GetWriteSpeed(), obj.ssd.GetPrice()) {

	manufacturer = new char[strlen(obj.manufacturer) + 1];
	strcpy_s(this->manufacturer, strlen(obj.manufacturer) + 1, obj.manufacturer);

	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);

	color = new char[strlen(obj.color) + 1];
	strcpy_s(color, strlen(obj.color) + 1, obj.color);

	price = obj.price;
}

void Laptop::Input() {
	char buffer[100];
	int tempPrice = 0;

	cout << "Enter CPU details: " << endl;
	cpu.Input();
	cout << endl << endl;

	cout << "Enter GPU details: " << endl;
	gpu.Input();
	cout << endl << endl;

	cout << "Enter RAM details: " << endl;
	ram.Input();
	cout << endl << endl;

	cout << "Enter SSD details: " << endl;
	ssd.Input();
	cout << endl << endl;

	cout << "Enter manufacturer: ";
	cin >> buffer;
	if (manufacturer != nullptr) {
		cout << "Delete manufacturer -> " << manufacturer << endl << endl;
		delete[] manufacturer;
	}
	manufacturer = new char[strlen(buffer) + 1];
	strcpy_s(manufacturer, strlen(buffer) + 1, buffer);

	cout << "Enter model: ";
	cin >> buffer;
	if (model != nullptr) {
		cout << "Delete model -> " << model << endl << endl;
		delete[] model;
	}
	model = new char[strlen(buffer) + 1];
	strcpy_s(model, strlen(buffer) + 1, buffer);

	cout << "Enter color: ";
	cin >> buffer;
	if (color != nullptr) {
		cout << "Delete color -> " << color << endl << endl;
		delete[] color;
	}
	color = new char[strlen(buffer) + 1];
	strcpy_s(color, strlen(buffer) + 1, buffer);

	tempPrice += cpu.GetPrice();
	tempPrice += gpu.GetPrice();
	tempPrice += ram.GetPrice();
	tempPrice += ssd.GetPrice();

	price = tempPrice;
}

void Laptop::InputCPU() {
	cpu.Input();
}

void Laptop::InputGPU() {
	gpu.Input();
}

void Laptop::InputRAM() {
	ram.Input();
}

void Laptop::InputSSD() {
	ssd.Input();
}

void Laptop::Print() const {
	cout << "Manufacturer: " << manufacturer << endl;
	cout << "Model: " << model << endl;
	cout << "Color: " << color << endl;
	cout << "Price: " << price << endl;
}

void Laptop::FullPrint() const {
	cout << "Laptop: " << endl;
	cout << "Manufacturer: " << manufacturer << endl;
	cout << "Model: " << model << endl;
	cout << "Color: " << color << endl;
	cout << endl;

	cout << "CPU: " << endl;
	cpu.Print();
	cout << endl;

	cout << "GPU: " << endl;
	gpu.Print();
	cout << endl;

	cout << "RAM: " << endl;
	ram.Print();
	cout << endl;

	cout << "SSD: " << endl;
	ssd.Print();
	cout << endl;

	cout << "Laptop Price: " << price << endl;
}

void Laptop::PrintInfoNumberOfLaptops() const {
	cout << "Number of Laptops: " << numberOfLaptops << endl;
}

void Laptop::PrintCPU() const {
	cpu.Print();
}

void Laptop::PrintGPU() const {
	gpu.Print();
}

void Laptop::PrintRAM() const {
	ram.Print();
}

void Laptop::PrintSSD() const {
	ssd.Print();
}

const char* Laptop::GetManufacturer() const {
	return manufacturer;
}

const char* Laptop::GetModel() const {
	return model;
}

const char* Laptop::GetColor() const {
	return color;
}

int Laptop::GetPrice() const {
	return price;
}

void Laptop::SetManufacturer(const char* brand) {
	if (brand != nullptr) {
		cout << "Delete manufacturer -> " << manufacturer << endl;
	}

	manufacturer = new char[strlen(brand) + 1];
	strcpy_s(manufacturer, strlen(brand) + 1, brand);
}

void Laptop::SetModel(const char* model) {
	if (model != nullptr) {
		cout << "Delete model -> " << this->model << endl;
	}

	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void Laptop::SetColor(const char* color) {
	if (color != nullptr) {
		cout << "Delete color -> " << this->color << endl;
	}

	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

void Laptop::SetPrice(int price) {
	this->price = price;
}
