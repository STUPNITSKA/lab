#include "Dyhotomia_class.h"
#include <iostream>

using namespace std;

int main()
{

    Dyhotomia_class *dyh = new Dyhotomia_class();

    dyh->setTolerance(0.00001);

    dyh->setVolumes(0.9, 2);
    cout << "Dyhotomia method: " << dyh->solve_dyhotomia() << endl;

    dyh->setVolumes(0.9, 2);
    cout << "Newton method: " << dyh->solve_newton() << endl;

    delete dyh;
    return 0;
}