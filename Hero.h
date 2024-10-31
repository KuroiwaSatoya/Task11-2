#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Enemy;

class Hero {

private:
    int hp, atk, def;
    char* name;

public:
    Hero(const char* _name, int hp, int atk, int def);
    Hero(const Hero& other);
    Hero& operator=(const Hero& other);
    ~Hero();

    void attack(Enemy* enemy);
    void heal();
    void attacked(int damage);
    int getHP() const { return hp; }
    int getDef() const { return def; }
    const char* getName() const { return name; }
};

#endif
