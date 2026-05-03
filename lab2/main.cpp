#include <iostream>
#include <limits>
#include <windows.h>
#include "triangle.h"

using namespace std;

bool inputPoint(Point &p) {
    if (!(cin >> p.x >> p.y)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Triangle t;

    cout << "Введіть координати A (x y): ";
    if (!inputPoint(t.A)) {
        cout << "Помилка вводу\n";
        return 1;
    }

    cout << "Введіть координати B (x y): ";
    if (!inputPoint(t.B)) {
        cout << "Помилка вводу\n";
        return 1;
    }

    cout << "Введіть координати C (x y): ";
    if (!inputPoint(t.C)) {
        cout << "Помилка вводу\n";
        return 1;
    }

    if (t.isDegenerate()) {
        cout << "Трикутник вироджений (площа = 0)\n";
    } else {
    cout << "Трикутник коректний\n";
    }

    cout << "\nВийшов трикутник з вершинами: { " << t.A.x << " , " << t.A.y
        << " },  { " << t.B.x << " , " << t.B.y << " },  { " << t.C.x << " , "
        << t.C.y << " }\n"
        << endl;

    while (true) {
        Point p;

        cout << "\nВведіть точку (x y) або будь-що для виходу: ";

        if (!inputPoint(p)) {
            cout << "Завершення програми\n";
            break;
        }

        int resArea = t.checkByArea(p);
        int resVector = t.checkByVector(p);

        cout << "Точка (" << p.x << ", " << p.y << "):\n";

        // площа
        if (resArea == 0) cout << "  Площа: всередині\n";
        else if (resArea == 1) cout << "  Площа: ззовні\n";
        else cout << "  Площа: на межі\n";

        // вектор
        if (resVector == 0) cout << "  Вектор: всередині\n";
        else if (resVector == 1) cout << "  Вектор: ззовні\n";
        else cout << "  Вектор: на межі\n";
    }

    return 0;
}