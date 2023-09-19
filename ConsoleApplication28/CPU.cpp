#include <iostream>
#include "CPU.h"

using namespace std;

CPU::CPU() {
	brand = nullptr;
	model = nullptr;
	connectorType = nullptr;
	numberOfCores = 0;
	price = 0;
}

CPU::CPU(const char* brand, const char* model, const char* connectorType, int numberOfCores, int price) {
	cout << "Constructor with 5 parameters" << endl;

	this->brand = new char[strlen(brand) + 1];
	strcpy_s(this->brand, strlen(brand) + 1, brand);

	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);

	this->connectorType = new char[strlen(connectorType) + 1];
	strcpy_s(this->connectorType, strlen(connectorType) + 1, connectorType);

	this->numberOfCores = numberOfCores;
	this->price = price;
}

CPU::~CPU() {
	delete[] brand;
	delete[] model;
	delete[] connectorType;
}

CPU::CPU(const CPU& obj) {
	brand = new char[strlen(obj.brand) + 1];
	strcpy_s(brand, strlen(obj.brand) + 1, obj.brand);

	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);

	connectorType = new char[strlen(obj.connectorType) + 1];
	strcpy_s(connectorType, strlen(obj.connectorType) + 1, obj.connectorType);

	numberOfCores = obj.numberOfCores;
	price = obj.price;
}

void CPU::Input() {
	char buffer[100];

	// Brand
	cout << "Enter the brand: ";
	cin >> buffer;
	if (brand != nullptr) {
		cout << "Delete brand -> " << brand << endl << endl;
		delete[] brand;
	}
	brand = new char[strlen(buffer) + 1];
	strcpy_s(brand, strlen(buffer) + 1, buffer);

	// Model
	cout << "Enter the model: ";
	cin >> buffer;
	if (model != nullptr) {
		cout << "Delete model -> " << model << endl << endl;
		delete[] model;
	}
	model = new char[strlen(buffer) + 1];
	strcpy_s(model, strlen(buffer) + 1, buffer);

	// Connector Type
	cout << "Enter the connector type: ";
	cin >> buffer;
	if (connectorType != nullptr) {
		cout << "Delete connector type -> " << connectorType << endl << endl;
		delete[] connectorType;
	}
	connectorType = new char[strlen(buffer) + 1];
	strcpy_s(connectorType, strlen(buffer) + 1, buffer);

	// Number of Cores
	cout << "Enter the number of cores: ";
	cin >> numberOfCores;

	// Price
	cout << "Enter the price: ";
	cin >> price;
}

void CPU::Print() const {
	cout << "Brand: " << brand << endl;
	cout << "Model: " << model << endl;
	cout << "Connector Type: " << connectorType << endl;
	cout << "Number of Cores: " << numberOfCores << endl;
	cout << "Price: " << price << endl;
}

char* CPU::GetBrand() const {
	return brand;
}

char* CPU::GetModel() const {
	return model;
}

char* CPU::GetConnectorType() const {
	return connectorType;
}

int CPU::GetNumberOfCores() const {
	return numberOfCores;
}

int CPU::GetPrice() const {
	return price;
}

void CPU::SetBrand(const char* brand) {
	if (brand != nullptr) {
		cout << "Delete brand -> " << this->brand << endl;
	}

	this->brand = new char[strlen(brand) + 1];
	strcpy_s(this->brand, strlen(brand) + 1, brand);
}

void CPU::SetModel(const char* model) {
	if (model != nullptr) {
		cout << "Delete model -> " << this->model << endl;
	}

	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void CPU::SetConnectorType(const char* connectorType) {
	if (connectorType != nullptr) {
		cout << "Delete connector type -> " << this->connectorType << endl;
	}

	this->connectorType = new char[strlen(connectorType) + 1];
	strcpy_s(this->connectorType, strlen(connectorType) + 1, connectorType);
}

void CPU::SetNumberOfCores(int numberOfCores) {
	this->numberOfCores = numberOfCores;
}

void CPU::SetPrice(int price) {
	this->price = price;
}
