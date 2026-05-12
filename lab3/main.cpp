#include "Dyhotomia_class.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    Dyhotomia_class *dyh = new Dyhotomia_class();

    dyh->setTolerance(0.00001);

    dyh->setVolumes(0.9, 2);
    double root_d = dyh->solve_dyhotomia();
    cout << "Dyhotomia method: " << root_d << endl;

    double root_n = dyh->solve_newton();
    cout << "Newton method: " << root_n << endl;

    cout << fixed << setprecision(8);
    cout << "f(x) = " << fabs(dyh->f(root_d)) << endl;
    cout << "f(x) = " << dyh->f(root_n) << endl;



    delete dyh;
    return 0;
}