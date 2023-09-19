#include <iostream>
#include "SSD.h"

using namespace std;

SSD::SSD() {
    company = nullptr;
    model = nullptr;
    formFactor = nullptr;
    connectorType = nullptr;

    memory = 0;
    readingSpeed = 0;
    writeSpeed = 0;
    price = 0;
}

SSD::SSD(const char* cp, const char* md, const char* ff, const char* ct, int me, int rs, int ws, int pr) {
    cout << "Constructor with 7 parameters" << endl;

    company = new char[strlen(cp) + 1];
    strcpy_s(company, strlen(cp) + 1, cp);

    model = new char[strlen(md) + 1];
    strcpy_s(model, strlen(md) + 1, md);

    formFactor = new char[strlen(ff) + 1];
    strcpy_s(formFactor, strlen(ff) + 1, ff);

    connectorType = new char[strlen(ct) + 1];
    strcpy_s(connectorType, strlen(ct) + 1, ct);

    memory = me;
    readingSpeed = rs;
    writeSpeed = ws;
    price = pr;
}

SSD::~SSD() {
    delete[] company;
    delete[] model;
    delete[] formFactor;
    delete[] connectorType;
}

SSD::SSD(const SSD& obj) {
    company = new char[strlen(obj.company) + 1];
    strcpy_s(company, strlen(obj.company) + 1, obj.company);

    model = new char[strlen(obj.model) + 1];
    strcpy_s(model, strlen(obj.model) + 1, obj.model);

    formFactor = new char[strlen(obj.formFactor) + 1];
    strcpy_s(formFactor, strlen(obj.formFactor) + 1, obj.formFactor);

    connectorType = new char[strlen(obj.connectorType) + 1];
    strcpy_s(connectorType, strlen(obj.connectorType) + 1, obj.connectorType);

    memory = obj.memory;
    readingSpeed = obj.readingSpeed;
    writeSpeed = obj.writeSpeed;
    price = obj.price;
}

void SSD::Input() {
    char buff[100];

    // Company
    cout << "Enter company: ";
    cin >> buff;
    if (company != nullptr) {
        cout << "Delete company -> " << company << endl << endl;
        delete[] company;
    }
    company = new char[strlen(buff) + 1];
    strcpy_s(company, strlen(buff) + 1, buff);

    // Model
    cout << "Enter model: ";
    cin >> buff;
    if (model != nullptr) {
        cout << "Delete model -> " << model << endl << endl;
        delete[] model;
    }
    model = new char[strlen(buff) + 1];
    strcpy_s(model, strlen(buff) + 1, buff);

    // Form Factor
    cout << "Enter form factor: ";
    cin >> buff;
    if (formFactor != nullptr) {
        cout << "Delete formFactor -> " << formFactor << endl << endl;
        delete[] formFactor;
    }
    formFactor = new char[strlen(buff) + 1];
    strcpy_s(formFactor, strlen(buff) + 1, buff);

    // Connector Type
    cout << "Enter connector type: ";
    cin >> buff;
    if (connectorType != nullptr) {
        cout << "Delete connectorType -> " << connectorType << endl << endl;
        delete[] connectorType;
    }
    connectorType = new char[strlen(buff) + 1];
    strcpy_s(connectorType, strlen(buff) + 1, buff);

    // Memory Size
    cout << "Enter memory size (GB): ";
    cin >> memory;

    // Read Speed
    cout << "Enter read speed: ";
    cin >> readingSpeed;

    // Write Speed
    cout << "Enter write speed: ";
    cin >> writeSpeed;

    // Price
    cout << "Enter price: ";
    cin >> price;
}

void SSD::Print() const {
    cout << "Company: " << company << endl;
    cout << "Model: " << model << endl;
    cout << "Form Factor: " << formFactor << endl;
    cout << "Connector Type: " << connectorType << endl;

    cout << "Memory Size: " << memory << "GB" << endl;
    cout << "Read Speed: " << readingSpeed << endl;
    cout << "Write Speed: " << writeSpeed << endl;
    cout << "Price: " << price << endl;
}

char* SSD::GetCompany() const {
    return company;
}

char* SSD::GetModel() const {
    return model;
}

char* SSD::GetFormFactor() const {
    return formFactor;
}

char* SSD::GetConnectorType() const {
    return connectorType;
}

int SSD::GetMemory() const {
    return memory;
}

int SSD::GetReadingSpeed() const {
    return readingSpeed;
}

int SSD::GetWriteSpeed() const {
    return writeSpeed;
}

int SSD::GetPrice() const {
    return price;
}

void SSD::SetCompany(const char* cp) {
    if (cp != nullptr) {
        cout << "Delete company -> " << this->company << endl;
    }

    company = new char[strlen(cp) + 1];
    strcpy_s(company, strlen(cp) + 1, cp);
}

void SSD::SetModel(const char* md) {
    if (md != nullptr) {
        cout << "Delete model -> " << this->model << endl;
    }

    model = new char[strlen(md) + 1];
    strcpy_s(model, strlen(md) + 1, md);
}

void SSD::SetFormFactor(const char* ff) {
    if (ff != nullptr) {
        cout << "Delete formFactor -> " << this->formFactor << endl;
    }

    formFactor = new char[strlen(ff) + 1];
    strcpy_s(formFactor, strlen(ff) + 1, ff);
}

void SSD::SetConnectorType(const char* ct) {
    if (ct != nullptr) {
        cout << "Delete connectorType -> " << this->connectorType << endl;
    }

    connectorType = new char[strlen(ct) + 1];
    strcpy_s(connectorType, strlen(ct) + 1, ct);
}

void SSD::SetMemory(int me) {
    memory = me;
}

void SSD::SetReadingSpeed(int rs) {
    readingSpeed = rs;
}

void SSD::SetWriteSpeed(int ws) {
    writeSpeed = ws;
}

void SSD::SetPrice(int pr) {
    price = pr;
}
