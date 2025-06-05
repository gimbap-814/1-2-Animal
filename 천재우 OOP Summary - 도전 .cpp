#include <iostream>
#include <cstdlib>
#include <ctime>

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

class Zoo {
private:
    Animal* animals[10];

public:
    Zoo() {
        for (int i = 0; i < 10; i++) {
            animals[i] = nullptr; // �迭 �ʱ�ȭ�� �����ڿ���!
        }
    }

    void addAnimal(Animal* animal) {
        for (int i = 0; i < 10; i++) {
            if (animals[i] == nullptr) {
                animals[i] = animal;
                break;
            }
        }
    }

    void performActions() {
        for (int i = 0; i < 10; i++) {
            if (animals[i] != nullptr) {
                animals[i]->makeSound();
            }
        }
    }

    ~Zoo() {
        for (int i = 0; i < 10; i++) {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal() {
    int randomType = rand() % 3;
    switch (randomType) {
    case 0: return new Dog();
    case 1: return new Cat();
    case 2: return new Cow();
    default: return nullptr;
    }
}

int main() {

    srand(static_cast<unsigned int>(time(0)));  // ���� �õ� �ʱ�ȭ (�� ����)

    Zoo zoo;

    // 10������ ���� ������ ���� �����Ͽ� Zoo�� �߰�
    for (int i = 0; i < 10; i++) {
        Animal* randomAnimal = createRandomAnimal();
        zoo.addAnimal(randomAnimal);
    }

    // Zoo �� ������ ��� �Ҹ�����
    zoo.performActions();

    // ���⼭ ������ ���� ��ü ���� �� ���� ���� ����ϰ� Zoo �߽����θ� ������

    return 0;
}