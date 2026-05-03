#include "Dyhotomia_class.h"
#include <iostream>

using namespace std;

int main()
{

    Dyhotomia_class *dyh = new Dyhotomia_class();

    dyh->setVolumes(0.9, 2);
    dyh->setTolerance(0.001);

    cout << "Dyhotomia method: " << dyh->solve_dyhotomia() << endl;

    cout << "Newton method: " << dyh->solve_newton() << endl;

    delete dyh;
    return 0;
}