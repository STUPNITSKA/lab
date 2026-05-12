#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

#include <cmath>

class Dyhotomia_class
{
private:
    double a;
    double b;
    double eps;

    double df(double x);

public:
    double f(double x);

public:
    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
    double solve_dyhotomia();
    double solve_newton();
    double solve_dyhotomia_check();
    double solve_newton_check();
    Dyhotomia_class();  // конструктор
    ~Dyhotomia_class(); // деструктор
};

#endif
