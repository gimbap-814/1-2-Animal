#include <iostream>
#include <cstdlib>
#include <ctime>

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

class Zoo {
private:
    Animal* animals[10];

public:
    Zoo() {
        for (int i = 0; i < 10; i++) {
            animals[i] = nullptr; // 배열 초기화는 생성자에서!
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

    srand(static_cast<unsigned int>(time(0)));  // 랜덤 시드 초기화 (한 번만)

    Zoo zoo;

    // 10마리의 랜덤 동물을 동적 생성하여 Zoo에 추가
    for (int i = 0; i < 10; i++) {
        Animal* randomAnimal = createRandomAnimal();
        zoo.addAnimal(randomAnimal);
    }

    // Zoo 안 동물들 모두 소리내기
    zoo.performActions();

    // 여기서 별도의 스택 객체 생성 및 관리 없이 깔끔하게 Zoo 중심으로만 관리함

    return 0;
}