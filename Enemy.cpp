#include "Enemy.h"
#include "Hero.h"
#include <iostream>
#include <cstring>
#include <new>

Enemy::Enemy(const char* _name, int hp, int atk, int def) {
    this->hp = hp;
    this->atk = atk;
    this->def = def;

    name = new char[strlen(_name) + 1];
    if (name != nullptr) {
        strcpy_s(name, strlen(_name) + 1, _name);

    }
}

Enemy::~Enemy() {

    if (name != nullptr) {
        delete[] name;
        name = nullptr;

    }
}

void Enemy::attack(Hero* hero) {

    int damage = atk - hero->getDef();

    if (damage > 0) {
        hero->attacked(damage);
        std::cout << name << "��" << hero->getName() << "��" << damage << "�_���[�W�^����" << std::endl;

    }
    else {
        std::cout << "�U�����s" << std::endl;
    }
}

void Enemy::heal() {

    int heal = 5;

    hp += heal;

    std::cout << name << "��HP��" << heal << "�񕜂����I" << std::endl;

}

void Enemy::attacked(int damage) {

    hp -= damage;
}
