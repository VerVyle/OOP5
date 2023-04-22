//
// Created by wwwdo on 22.04.2023.
//

#include "points.h"
#include "separator.h"
#include <iostream>
#include <memory>

using namespace std;

class Point {
private:
    int x{0};
    int y{0};
public:
    Point() {
        cout << "Point()" << endl;
    }

    virtual ~Point() {
        cout << "~Point()" << endl;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

void func1() {
    auto *var = new Point(); // не удалится при выходе из области видимости, вообще не удалится.
}

void func2() {
    unique_ptr<Point> var(new Point()); // удалится при выходе из области видимости
}

void func3(shared_ptr<Point> &sharedPtr) {
    shared_ptr<Point> sharedNew = sharedPtr; // удалится при выходе из области видимости последнего из указателей
}

void invokePoints() {
    func1();
    separate();
    func2();
    separate();
    shared_ptr<Point> sharedPtr = make_shared<Point>();
    func3(sharedPtr);
    separate();
}
