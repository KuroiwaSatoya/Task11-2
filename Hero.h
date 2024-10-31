#ifndef HERO_H
#define HERO_H

class Enemy; // Forward declaration

class Hero {

private:
    int hp, atk, def;
    char* name;

public:
    Hero(const char* _name, int hp, int atk, int def);
    ~Hero();
    void attack(Enemy* enemy);
    void heal();
    void attacked(int damage);
    int getHP() const { return hp; }
    int getDef() const { return def; }
    const char* getName() const { return name; }

};

#endif // HERO_H
