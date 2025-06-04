#include <iostream>
using namespace std;

// �⺻ Ŭ����: Animal
class Animal {
public:
    virtual void makeSound() = 0; // ���� ���� �Լ�
};

// �Ļ� Ŭ����: Dog
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

// �Ļ� Ŭ����: Cat
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows: Meow! Meow!" << endl;
    }
};

// ���� �߰��� �Ļ� Ŭ����: Cow
class Cow : public Animal {
public:
    void makeSound() override {
        cout << "Cow moos: Moo! Moo!" << endl;
    }
};

int main() {
    // ������ ���� ��ü ����
    Dog myDog;
    Cat myCat;
    Cow myCow;

    // Animal Ÿ���� ������ �迭 ����
    Animal* animals[3];

    // �迭�� ������ ��ü �ּ� ����
    animals[0] = &myDog;
    animals[1] = &myCat;
    animals[2] = &myCow;

    // �迭�� ��ȸ�ϸ� �� ������ �Ҹ��� ���
    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();  // ������(polymorphism) Ȱ��
    }

    return 0;
}
