#include "triangle.h"
#include <cmath>

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double cross(const Point &A, const Point &B, const Point &P) {
    return (B.x - A.x) * (P.y - A.y) -
           (B.y - A.y) * (P.x - A.x);
}

// Герон
double Triangle::area() const {
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);

    double s = (a + b + c) / 2;
    double val = s * (s - a) * (s - b) * (s - c);

    if (val < 0) val = 0;

    return sqrt(val);
}

bool Triangle::isDegenerate() const {
    return area() < 1e-9;
}

// метод площ
int Triangle::checkByArea(const Point &P) const {
    const double eps = 1e-9;

    if (isDegenerate()) return 1;

    Triangle t1{A, B, P};
    Triangle t2{B, C, P};
    Triangle t3{C, A, P};

    double S = area();
    double Ssum = t1.area() + t2.area() + t3.area();

    if (fabs(S - Ssum) < eps) {
        if (t1.area() < eps || t2.area() < eps || t3.area() < eps)
            return 2; // межа
        return 0; // всередині
    }

    return 1; // ззовні
}

// векторний метод
int Triangle::checkByVector(const Point &P) const {
    const double eps = 1e-9;

    double c1 = cross(A, B, P);
    double c2 = cross(B, C, P);
    double c3 = cross(C, A, P);

    if (fabs(c1) < eps || fabs(c2) < eps || fabs(c3) < eps)
        return 2; // межа

    if ((c1 > 0 && c2 > 0 && c3 > 0) ||
        (c1 < 0 && c2 < 0 && c3 < 0))
        return 0; // всередині

    return 1; // ззовні
}