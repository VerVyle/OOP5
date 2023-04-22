//
// Created by wwwdo on 22.04.2023.
//

#include "../headers/base.h"
#include "../headers/separator.h"
#include <iostream>

using namespace std;

class Base {
private:
    int i{0};
public:
    Base() {
        cout << "Base()" << endl;
    }

    Base(const Base &base) {
        cout << "Base(const Base &)" << endl;
    }

    explicit Base(Base *base) {
        cout << "Base(Base *)" << endl;
    }

    virtual ~Base() {
        cout << "~Base()" << endl;
    }

    void sayHello() {
        cout << "Hello " << i << endl;
    }
};

class Desc : public Base {
public:
    Desc() {
        cout << "Desc()" << endl;
    }

    Desc(const Desc &desc) {
        cout << "Desc(const Desc &)" << endl;
    }

    explicit Desc(Desc *base) {
        cout << "Desc(Desc *)" << endl;
    }

    ~Desc() {
        cout << "~Desc()" << endl;
    }
};

void func1(Base base) {
    cout << "func1(Base)" << endl;
}

void func2(Base *base) {
    if (dynamic_cast<Desc *>(base))
        cout << "func2(Base *) casted" << endl;
    else
        cout << "func2(Base *)" << endl;
}

void func3(Base &base) {
    if (dynamic_cast<Desc *>(&base))
        cout << "func3(Base &) casted" << endl;
    else
        cout << "func3(Base &)" << endl;
}

Base staticCreate1() {
    cout << "Base staticCreate1()" << endl;
    Base var;
    return var;
}

Base &staticCreate2() {
    cout << "Base &staticCreate2()" << endl;
    Base var;
    return var;
}

Base *staticCreate3() {
    cout << "Base *staticCreate3()" << endl;
    Base var;
    return &var;
}

Base dynamicCreate1() {
    cout << "Base dynamicCreate1()" << endl;
    Base *var = new Base();
    return *var;
}

Base &dynamicCreate2() {
    cout << "Base &dynamicCreate2()" << endl;
    Base *var = new Base();
    return *var;
}

Base *dynamicCreate3() {
    cout << "Base *dynamicCreate3()" << endl;
    Base *var = new Base();
    return var;
}

void invokeBase() {
    Base base;
    Desc desc;
    separate();
    separate();

    func1(base); // передается копия base
    separate();
    func2(&base);
    separate();
    func3(base);
    separate();
    separate();

    func1(desc); // передается копия desc, но типа Base
    separate();
    func2(&desc);
    separate();
    func3(desc);
    separate();
    separate();

    separate2();

    Base var1 = staticCreate1();
    var1.sayHello();
    separate();
    Base &var2 = staticCreate2(); // объект создается в функции и в ней же удаляется
    //var2.sayHello(); нельзя
    delete &var2; // ничего не происходит
    separate();
    Base *var3 = staticCreate3(); // объект создается в функции и в ней же удаляется
    //var3->sayHello(); нельзя
    delete var3; // ничего не происходит
    separate();
    Base var4 = dynamicCreate1(); // динамический объект в функции не уничтожится, но скопируется и вернется
    var4.sayHello();
    separate();
    Base &var5 = dynamicCreate2();
    var5.sayHello();
    delete &var5;
    separate();
    Base *var6 = dynamicCreate3();
    var6->sayHello();
    delete var6;
    separate();
}