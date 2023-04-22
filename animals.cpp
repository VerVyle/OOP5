//
// Created by wwwdo on 22.04.2023.
//

#include <iostream>
#include "animals.h"
#include "separator.h"

using namespace std;

class Animal {
protected:
    bool madeSound{false};
public:
    Animal() {
        cout << "Animal()" << endl;
    }

    virtual ~Animal() {
        cout << "~Animal()" << endl;
    }

    void nonVirtualMethod() {
        cout << "Animal::nonVirtualMethod()" << endl;
    }

    void _nonVirtualMethod() {
        cout << "Animal::_nonVirtualMethod()" << endl;
    }

    virtual void virtualMethod() {
        cout << "Animal::virtualMethod()" << endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        cout << "Cat()" << endl;
    }

    ~Cat() override {
        cout << "~Cat()" << endl;
    }

    void nonVirtualMethod() {
        cout << "Cat::nonVirtualMethod()" << endl;
    }

    void virtualMethod() override {
        cout << "Cat::virtualMethod()" << endl;
    }
};

void invokeAnimals() {
    // пример вызова виртуального деструктора
    Animal *animal = new Cat();
    delete animal;
    separate();

    // виртуальный и не виртуальный методы
    Animal *animal1 = new Cat();
    animal1->nonVirtualMethod();
    animal1->_nonVirtualMethod();
    animal1->virtualMethod();
    delete animal1;
    separate();

    // обращение к невиртуальному методу через указатели
    Animal *animal2 = new Cat();
    Cat *cat = new Cat();
    animal2->nonVirtualMethod();
    animal2->_nonVirtualMethod();
    cat->nonVirtualMethod();
    cat->_nonVirtualMethod();
    delete animal2;
    delete cat;
    separate();

    // обращение к виртуальному методу через указатели
    Animal *animal3 = new Cat();
    Cat *cat1 = new Cat();
    animal3->virtualMethod();
    cat1->virtualMethod();
    delete animal3;
    delete cat1;
    separate();
}
