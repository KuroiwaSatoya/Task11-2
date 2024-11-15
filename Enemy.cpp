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
        cout << name << "が" << hero->getName() << "に" << damage << "ダメージ与えた" << endl;

    }
    else {

        cout << "攻撃失敗" << endl;

    }
}

void Enemy::heal() {

    int heal = 5;

    hp += heal;
    cout << name << "のHPが" << heal << "回復した！" << endl;

}

void Enemy::attacked(int damage) {

    hp -= damage;

}
