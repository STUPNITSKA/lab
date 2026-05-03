#include "Dyhotomia_class.h"

Dyhotomia_class::Dyhotomia_class()
{
    a = 0;
    b = 0;
    eps = 0.001;
}

Dyhotomia_class::~Dyhotomia_class()
{
}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b)
{
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps)
{
    eps = vol_eps;
}

double Dyhotomia_class::f(double x)
{
    return x - 2 + sin(1/x);
}

double Dyhotomia_class::df(double x)
{
    return  1 - cos(1/x) / (x * x);
}

double Dyhotomia_class::solve_dyhotomia()
{
    double c;
    while (b - a > eps)
    {
        c = (a + b) / 2;
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2;
}

double Dyhotomia_class::solve_newton()
{
    double x = (a + b) / 2;
    double x_old;
    do
    {
        x_old = x;
        x= x - f(x) / df(x);
    } while (fabs(x - x_old) > eps);
    return x;
}

