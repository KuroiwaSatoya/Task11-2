#include "Enemy.h"
#include "Hero.h"

Enemy::Enemy(const char* _name, int hp, int atk, int def){

    this->hp = hp;
    this->atk = atk;
    this->def = def;

    name = new(nothrow) char[strlen(_name) + 1];

    if (name != nullptr) {

        strcpy_s(name, strlen(_name) + 1, _name);

    }
}

Enemy::Enemy(const Enemy& other){

    hp = other.hp;
    atk = other.atk;
    def = other.def;

    name = new(nothrow) char[strlen(other.name) + 1];

    if (name != nullptr) {

        strcpy_s(name, strlen(other.name) + 1, other.name);

    }
}

Enemy& Enemy::operator=(const Enemy& other) {

    delete[] name;
    hp = other.hp;
    atk = other.atk;
    def = other.def;

    name = new(nothrow) char[strlen(other.name) + 1];

    if (name != nullptr) {

        strcpy_s(name, strlen(other.name) + 1, other.name);

    }
    return *this;
}

Enemy::~Enemy() {

    delete[] name;
    name = nullptr;

}

void Enemy::attack(Hero* hero) {

    int damage = atk - hero->getDef();

    if (damage > 0) {

        hero->attacked(damage);
        cout << name << "��" << hero->getName() << "��" << damage << "�_���[�W�^����" << endl;

    }
    else {

        cout << "�U�����s" << endl;

    }
}

void Enemy::heal() {

    int heal = 5;

    hp += heal;
    cout << name << "��HP��" << heal << "�񕜂����I" << endl;

}

void Enemy::attacked(int damage) {

    hp -= damage;

}
