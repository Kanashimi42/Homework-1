#include <iostream>
#include "GPU.h"

using namespace std;

GPU::GPU() {
    manufacturer = nullptr;
    model = nullptr;
    memoryType = nullptr;
    videoMemory = 0;
    price = 0;
}

GPU::GPU(const char* manufacturer, const char* model, const char* memoryType, int videoMemory, int price) {
    cout << "Constructor with 5 parameters" << endl;

    this->manufacturer = new char[strlen(manufacturer) + 1];
    strcpy_s(this->manufacturer, strlen(manufacturer) + 1, manufacturer);

    this->model = new char[strlen(model) + 1];
    strcpy_s(this->model, strlen(model) + 1, model);

    this->memoryType = new char[strlen(memoryType) + 1];
    strcpy_s(this->memoryType, strlen(memoryType) + 1, memoryType);

    this->videoMemory = videoMemory;
    this->price = price;
}

GPU::~GPU() {
    delete[] manufacturer;
    delete[] model;
    delete[] memoryType;
}

GPU::GPU(const GPU& obj) {
    manufacturer = new char[strlen(obj.manufacturer) + 1];
    strcpy_s(manufacturer, strlen(obj.manufacturer) + 1, obj.manufacturer);

    model = new char[strlen(obj.model) + 1];
    strcpy_s(model, strlen(obj.model) + 1, obj.model);

    memoryType = new char[strlen(obj.memoryType) + 1];
    strcpy_s(memoryType, strlen(obj.memoryType) + 1, obj.memoryType);

    videoMemory = obj.videoMemory;
    price = obj.price;
}

void GPU::Input() {
    char buffer[100];

    // Manufacturer
    cout << "Enter the manufacturer: ";
    cin >> buffer;
    if (manufacturer != nullptr) {
        cout << "Delete manufacturer -> " << manufacturer << endl << endl;
        delete[] manufacturer;
    }
    manufacturer = new char[strlen(buffer) + 1];
    strcpy_s(manufacturer, strlen(buffer) + 1, buffer);

    // Model
    cout << "Enter the model: ";
    cin >> buffer;
    if (model != nullptr) {
        cout << "Delete model -> " << model << endl << endl;
        delete[] model;
    }
    model = new char[strlen(buffer) + 1];
    strcpy_s(model, strlen(buffer) + 1, buffer);

    // Memory Type
    cout << "Enter the memory type: ";
    cin >> buffer;
    if (memoryType != nullptr) {
        cout << "Delete memory type -> " << memoryType << endl << endl;
        delete[] memoryType;
    }
    memoryType = new char[strlen(buffer) + 1];
    strcpy_s(memoryType, strlen(buffer) + 1, buffer);

    // Video Memory
    cout << "Enter the video memory: ";
    cin >> videoMemory;

    // Price
    cout << "Enter the price: ";
    cin >> price;
}

void GPU::Print() const {
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Model: " << model << endl;
    cout << "Memory Type: " << memoryType << endl;
    cout << "Video Memory: " << videoMemory << endl;
    cout << "Price: " << price << endl;
}

char* GPU::GetManufacturer() const {
    return manufacturer;
}

char* GPU::GetModel() const {
    return model;
}

char* GPU::GetMemoryType() const {
    return memoryType;
}

int GPU::GetVideoMemory() const {
    return videoMemory;
}

int GPU::GetPrice() const {
    return price;
}

void GPU::SetManufacturer(const char* manufacturer) {
    if (manufacturer != nullptr) {
        cout << "Delete manufacturer -> " << this->manufacturer << endl;
    }

    this->manufacturer = new char[strlen(manufacturer) + 1];
    strcpy_s(this->manufacturer, strlen(manufacturer) + 1, manufacturer);
}

void GPU::SetModel(const char* model) {
    if (model != nullptr) {
        cout << "Delete model -> " << this->model << endl;
    }

    this->model = new char[strlen(model) + 1];
    strcpy_s(this->model, strlen(model) + 1, model);
}

void GPU::SetMemoryType(const char* memoryType) {
    if (memoryType != nullptr) {
        cout << "Delete memory type -> " << this->memoryType << endl;
    }

    this->memoryType = new char[strlen(memoryType) + 1];
    strcpy_s(this->memoryType, strlen(memoryType) + 1, memoryType);
}

void GPU::SetVideoMemory(int videoMemory) {
    this->videoMemory = videoMemory;
}

void GPU::SetPrice(int price) {
    this->price = price;
}
