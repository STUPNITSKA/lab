#ifndef PhoneClasses_H
#define PhoneClasses_H
#include <string>

class Device
{
public:
    Device();
    Device(const std::string& brand, const std::string& model, int price);
    virtual ~Device();
    virtual void ShowInfo();
    virtual void TurnOn();

protected:
    std::string brand;
    std::string model;
    int price;
};

class SmartPhone : public Device
{
public:
    SmartPhone(const std::string& brand, const std::string& model, int price);
    void ShowInfo() override;
    void TurnOn() override;

protected:
    int batteryCapacity;
    int cameraMegapixels;
    std::string system;
};

class Iphone : public SmartPhone
{
public:
    Iphone(const std::string& brand, const std::string& model, int price);
    void ShowInfo() override;
    void TurnOn() override;

private:
    bool faceID;
};

class Samsung : public SmartPhone
{
public:
    Samsung(const std::string& brand, const std::string& model, int price);
    void ShowInfo() override;
    void TurnOn() override;

private:
    bool stylusSupport;
};

class TeslaPhone : public SmartPhone
{
public:
    TeslaPhone(const std::string& brand, const std::string& model, int price);
    void ShowInfo() override;
    void TurnOn() override;

private:
    bool solarCharging;
};

#endif
