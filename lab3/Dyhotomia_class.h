#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

#include <cmath>

class Dyhotomia_class
{
private:
    double a;
    double b;
    double eps;

    double f(double x);
    double df(double x);

public:
    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
    double solve_dyhotomia();
    double solve_newton();
    Dyhotomia_class();  // конструктор
    ~Dyhotomia_class(); // деструктор
};

#endif
