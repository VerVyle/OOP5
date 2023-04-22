//
// Created by wwwdo on 22.04.2023.
//

#include "birds.h"
#include <iostream>
#include <string>
#include <ctime>
#include "separator.h"

using namespace std;

class Bird {
public:
    Bird() {
        cout << "Bird()" << endl;
    }

    virtual ~Bird() {
        cout << "~Bird()" << endl;
    }

    virtual void sound() {
        cout << "Bird::sound()" << endl;
    }

    virtual string classname() {
        return "Bird";
    }

    virtual bool isA(const string &who) {
        return who == "Bird";
    }
};

class Duck : public Bird {
public:
    Duck() {
        cout << "Duck()" << endl;
    }

    ~Duck() override {
        cout << "~Duck()" << endl;
    }

    void sound() override {
        cout << "Duck::sound()" << endl;
    }

    string classname() override {
        return "Duck";
    }

    void swim() {
        cout << "Duck::swim()" << endl;
    }

    bool isA(const string &who) override {
        return Bird::isA(who) || who == "Duck";
    }
};

class MallardDuck : public Duck {
public:
    MallardDuck() {
        cout << "MallardDuck()" << endl;
    }

    ~MallardDuck() override {
        cout << "~MallardDuck()" << endl;
    }

    void bePretty() {
        cout << "MallardDuck::bePretty()" << endl;
    }

    void sound() override {
        cout << "MallardDuck::sound()" << endl;
    }

    string classname() override {
        return "MallardDuck";
    }

    bool isA(const string &who) override {
        return Duck::isA(who) || who == "MallardDuck";
    }
};

class Turkey : public Bird {
public:
    Turkey() {
        cout << "Turkey()" << endl;
    }

    ~Turkey() override {
        cout << "~Turkey()" << endl;
    }

    void sound() override {
        cout << "Turkey::sound()" << endl;
    }

    string classname() override {
        return "Turkey";
    }

    void beTasty() {
        cout << "Turkey::beTasty()" << endl;
    }

    bool isA(const string &who) override {
        return Bird::isA(who) || who == "Turkey";
    }
};

void invokeBirds() {
    srand(time(nullptr));

    // использование classname()
    Bird *bird;
    if (rand() % 2 == 0) {
        bird = new Duck();
    } else {
        bird = new MallardDuck();
    }
    if (bird->classname() == "Duck" || bird->classname() == "MallardDuck") {
        static_cast<Duck *>(bird)->swim();
        ((Duck *) bird)->swim();
    }
    separate();

    // использование isA(string)
    if (bird->isA("Duck")) {
        static_cast<Duck *>(bird)->swim();
    }
    separate();

    // static_cast<>() и почему не надо
    Bird *bird1 = new Turkey();
    if (static_cast<Duck *>(bird1))
        static_cast<Duck *>(bird1)->swim();
    separate();

    // dynamic_cast<>()
    Bird *birds[10];
    int ran;
    for (auto &i: birds) {
        ran = rand() % 3;
        switch (ran) {
            case 0:
                i = new Duck();
                break;
            case 1:
                i = new MallardDuck();
                break;
            case 2:
                i = new Turkey();
                break;
            default:
                abort();
        }
    }
    separate();

    for (auto &i: birds) {
        auto bird2 = dynamic_cast<Duck *>(i);
        if (bird2) {
            bird2->swim();
            continue;
        }
        auto bird3 = dynamic_cast<MallardDuck *>(i);
        if (bird3) {
            bird3->bePretty();
            continue;
        }
        auto bird4 = dynamic_cast<Turkey *>(i);
        if (bird4) {
            bird4->beTasty();
            continue;
        }
        abort();
    }
    separate();
}