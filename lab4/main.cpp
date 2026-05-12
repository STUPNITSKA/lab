#include "PhoneClasses.h"
#include <iostream>

using namespace std;

int main()
{
    Iphone myIphone("Apple", "iPhone 14 Pro", 999);
    Samsung mySamsung("Samsung", "Galaxy S22 Ultra", 899);
    TeslaPhone myTesla("Tesla", "Model P", 1200);

    Device *device;

    cout << "=== iPhone ===" << endl;
    device = &myIphone;
    device->ShowInfo();
    device->TurnOn();

    cout << endl;

    cout << "=== Samsung ===" << endl;
    device = &mySamsung;
    device->ShowInfo();
    device->TurnOn();

    cout << endl;

    cout << "=== Tesla Phone ===" << endl;
    device = &myTesla;
    device->ShowInfo();
    device->TurnOn();

    return 0;
}