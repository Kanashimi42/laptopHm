#include <iostream>
#include "GPU.h"

using namespace std;

GPU::GPU() {
    company = nullptr;
    model = nullptr;
    memoryType = nullptr;
    videoMemory = 0;
    price = 0;
}

GPU::GPU(const char* cp, const char* md, const char* mt, int vm, int pr) {
    cout << "Constructor 5 params" << endl;
    company = new char[strlen(cp) + 1];
    strcpy_s(company, strlen(cp) + 1, cp);
    model = new char[strlen(md) + 1];
    strcpy_s(model, strlen(md) + 1, md);
    memoryType = new char[strlen(mt) + 1];
    strcpy_s(memoryType, strlen(mt) + 1, mt);
    videoMemory = vm;
    price = pr;
}

GPU::~GPU() {
    delete[] company;
    delete[] model;
    delete[] memoryType;
}

GPU::GPU(const GPU& obj) {
    company = new char[strlen(obj.company) + 1];
    strcpy_s(company, strlen(obj.company) + 1, obj.company);
    model = new char[strlen(obj.model) + 1];
    strcpy_s(model, strlen(obj.model) + 1, obj.model);
    memoryType = new char[strlen(obj.memoryType) + 1];
    strcpy_s(memoryType, strlen(obj.memoryType) + 1, obj.memoryType);
    videoMemory = obj.videoMemory;
    price = obj.price;
}

void GPU::Input() {
    char buff[100];
    cout << "Enter company: ";
    cin >> buff;
    if (company != nullptr) {
        cout << "Delete company -> " << company << endl << endl;
        delete[] company;
    }
    company = new char[strlen(buff) + 1];
    strcpy_s(company, strlen(buff) + 1, buff);

    cout << "Enter model: ";
    cin >> buff;
    if (model != nullptr) {
        cout << "Delete model -> " << model << endl << endl;
        delete[] model;
    }
    model = new char[strlen(buff) + 1];
    strcpy_s(model, strlen(buff) + 1, buff);

    cout << "Enter memory type: ";
    cin >> buff;
    if (memoryType != nullptr) {
        cout << "Delete memoryType -> " << memoryType << endl << endl;
        delete[] memoryType;
    }
    memoryType = new char[strlen(buff) + 1];
    strcpy_s(memoryType, strlen(buff) + 1, buff);

    cout << "Enter video memory: ";
    cin >> videoMemory;

    cout << "Enter price: ";
    cin >> price;
}

void GPU::Print() const {
    cout << "Company: " << company << endl;
    cout << "Model: " << model << endl;
    cout << "Memory Type: " << memoryType << endl;
    cout << "Video Memory: " << videoMemory << endl;
    cout << "Price: " << price << endl;
}

char* GPU::GetCompany() const {
    return company;
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

void GPU::SetCompany(const char* cp) {
    if (cp != nullptr) {
        cout << "Delete company -> " << this->company << endl;
    }
    company = new char[strlen(cp) + 1];
    strcpy_s(company, strlen(cp) + 1, cp);
}

void GPU::SetModel(const char* md) {
    if (md != nullptr) {
        cout << "Delete model -> " << this->model << endl;
    }
    model = new char[strlen(md) + 1];
    strcpy_s(model, strlen(md) + 1, md);
}

void GPU::SetMemoryType(const char* mt) {
    if (mt != nullptr) {
        cout << "Delete memoryType -> " << this->memoryType << endl;
    }
    memoryType = new char[strlen(mt) + 1];
    strcpy_s(memoryType, strlen(mt) + 1, mt);
}

void GPU::SetVideoMemory(int vm) {
    videoMemory = vm;
}

void GPU::SetPrice(int pr) {
    price = pr;
}
