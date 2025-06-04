#include <iostream>
using namespace std;

// 기본 클래스: Animal
class Animal {
public:
    virtual void makeSound() = 0; // 순수 가상 함수
};

// 파생 클래스: Dog
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

// 파생 클래스: Cat
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows: Meow! Meow!" << endl;
    }
};

// 새로 추가할 파생 클래스: Cow
class Cow : public Animal {
public:
    void makeSound() override {
        cout << "Cow moos: Moo! Moo!" << endl;
    }
};

int main() {
    // 각각의 동물 객체 생성
    Dog myDog;
    Cat myCat;
    Cow myCow;

    // Animal 타입의 포인터 배열 선언
    Animal* animals[3];

    // 배열에 각각의 객체 주소 저장
    animals[0] = &myDog;
    animals[1] = &myCat;
    animals[2] = &myCow;

    // 배열을 순회하며 각 동물의 소리를 출력
    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();  // 다형성(polymorphism) 활용
    }

    return 0;
}
