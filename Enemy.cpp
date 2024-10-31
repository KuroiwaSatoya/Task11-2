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
        std::cout << name << "が" << hero->getName() << "に" << damage << "ダメージ与えた" << std::endl;

    }
    else {
        std::cout << "攻撃失敗" << std::endl;
    }
}

void Enemy::heal() {

    int heal = 5;

    hp += heal;

    std::cout << name << "のHPが" << heal << "回復した！" << std::endl;

}

void Enemy::attacked(int damage) {

    hp -= damage;
}
