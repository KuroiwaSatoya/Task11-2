#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Hero;

class Enemy {

private:
    int hp, atk, def;
    char* name;

public:
    Enemy(const char* _name, int hp, int atk, int def);
    Enemy(const Enemy& other);
    Enemy& operator=(const Enemy& other);
    ~Enemy();

    void attack(Hero* hero);
    void heal();
    void attacked(int damage);
    int getHP() const { return hp; }
    int getDef() const { return def; }
    const char* getName() const { return name; }
};

#endif
