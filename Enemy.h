#ifndef ENEMY_H
#define ENEMY_H

class Hero; // Forward declaration

class Enemy {

private:
    int hp, atk, def;
    char* name;

public:
    Enemy(const char* _name, int hp, int atk, int def);
    ~Enemy();
    void attack(Hero* hero);
    void heal();
    void attacked(int damage);
    int getHP() const { return hp; }
    int getDef() const { return def; }
    const char* getName() const { return name; }

};

#endif // ENEMY_H
