#include "Hero.h"
#include "Enemy.h"
#include <iostream>
#include <cstring>
#include <new>

Hero::Hero(const char* _name, int hp, int atk, int def) {
    this->hp = hp;
    this->atk = atk;
    this->def = def;

    name = new char[strlen(_name) + 1];
    if (name != nullptr) {
        strcpy_s(name, strlen(_name) + 1, _name);

    }
}

Hero::~Hero() {

    if (name != nullptr) {
        delete[] name;
        name = nullptr;

    }
}

void Hero::attack(Enemy* enemy) {

    int damage = atk - enemy->getDef();

    if (damage > 0) {
        enemy->attacked(damage);
        std::cout << name << "が" << enemy->getName() << "に" << damage << "ダメージ与えた" << std::endl;

    }
    else {
        std::cout << "攻撃失敗" << std::endl;
    }
}

void Hero::heal() {
    int heal = 5;
    hp += heal;
    std::cout << name << "のHPが" << heal << "回復した！" << std::endl;

}

void Hero::attacked(int damage) {
    hp -= damage;

}
