#include "Hero.h"
#include "Enemy.h"

Hero::Hero(const char* _name, int hp, int atk, int def) : hp(hp), atk(atk), def(def) {

    name = new(nothrow) char[strlen(_name) + 1];

    if (name != nullptr) {

        strcpy_s(name, strlen(_name) + 1, _name);

    }
}

Hero::Hero(const Hero& other) : hp(other.hp), atk(other.atk), def(other.def) {

    name = new(nothrow) char[strlen(other.name) + 1];

    if (name != nullptr) {

        strcpy_s(name, strlen(other.name) + 1, other.name);

    }
}

Hero& Hero::operator=(const Hero& other) {

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

Hero::~Hero() {

    delete[] name;
    name = nullptr;

}

void Hero::attack(Enemy* enemy) {

    int damage = atk - enemy->getDef();

    if (damage > 0) {

        enemy->attacked(damage);
        cout << name << "‚ª" << enemy->getName() << "‚É" << damage << "ƒ_ƒ[ƒW—^‚¦‚½" << endl;

    }
    else {

        cout << "UŒ‚¸”s" << endl;

    }
}

void Hero::heal() {

    int heal = 5;

    hp += heal;
    cout << name << "‚ÌHP‚ª" << heal << "‰ñ•œ‚µ‚½I" << endl;

}

void Hero::attacked(int damage) {

    hp -= damage;

}
