#include "PhoneClasses.h"
#include <iostream>
using namespace std;

Device::Device()
{
    brand = "Unknown";
    model = "Unknown";
    price = 0;
}

Device::Device(const string& brand, const string& model, int price)
{
    this->brand = brand;
    this->model = model;
    this->price = price;
}

Device::~Device()
{
}

void Device::ShowInfo()
{
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Price: $" << price << endl;
}

void Device::TurnOn()
{
    cout << "Turning on the device..." << endl;
}

SmartPhone::SmartPhone(const string& brand, const string& model, int price) : Device(brand, model, price)
{
    batteryCapacity = 0;
    cameraMegapixels = 0;
    system = "Unknown";
}

void SmartPhone::ShowInfo()
{
    Device::ShowInfo();
    cout << "Battery Capacity: " << batteryCapacity << " mAh" << endl;
    cout << "Camera: " << cameraMegapixels << " MP" << endl;
    cout << "Operating System: " << system << endl;
}

void SmartPhone::TurnOn()
{
    cout << "Booting up the smartphone..." << endl;
}

Iphone::Iphone(const string& brand, const string& model, int price) : SmartPhone(brand, model, price)
{
    faceID = true;
    system = "iOS";
    batteryCapacity = 3000;
    cameraMegapixels = 12;
}

void Iphone::ShowInfo()
{
    SmartPhone::ShowInfo();
    cout << "Face ID: " << (faceID ? "Yes" : "No") << endl;
}

void Iphone::TurnOn()
{
    cout << "Booting up the iPhone..." << endl;
}

Samsung::Samsung(const string& brand, const string& model, int price) : SmartPhone(brand, model, price)
{
    stylusSupport = true;
    batteryCapacity = 4000;
    cameraMegapixels = 16;
    system = "Android";
}

void Samsung::ShowInfo()
{
    SmartPhone::ShowInfo();
    cout << "Stylus Support: " << (stylusSupport ? "Yes" : "No") << endl;
}

void Samsung::TurnOn()
{
    cout << "Booting up the Samsung phone..." << endl;
}

TeslaPhone::TeslaPhone(const string& brand, const string& model, int price) : SmartPhone(brand, model, price)
{
    solarCharging = true;
    batteryCapacity = 5000;
    cameraMegapixels = 20;
    system = "Tesla OS";
}

void TeslaPhone::ShowInfo()
{
    SmartPhone::ShowInfo();
    cout << "Solar Charging: " << (solarCharging ? "Yes" : "No") << endl;
}

void TeslaPhone::TurnOn()
{
    cout << "Booting up the Tesla phone..." << endl;
}
