#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double area() const;
    bool isDegenerate() const;

    int checkByArea(const Point &P) const;   // 0 - всередині, 1 - ззовні, 2 - межа
    int checkByVector(const Point &P) const;
};

double distance(const Point &p1, const Point &p2);
double cross(const Point &A, const Point &B, const Point &P);

#endif // TRIANGLE_H