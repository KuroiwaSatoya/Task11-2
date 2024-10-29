#include<iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

class Hero;
class Enemy;

class Hero {
private:
	int hp, atk, def;
	char* name;

public:
	Hero(const char* _name, int hp, int atk, int def): hp(hp), atk(atk), def(def) {
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}

	~Hero();
	void attack(Enemy* enemy);
	void heal();
	void attacked(int damage);
	int getHP() const { return hp; }
	int getDef() const { return def; }
	const char* getName() const { return name; }
};

class Enemy {
private:
	int hp, atk, def;
	char* name;

public:
	Enemy(const char* _name, int hp, int atk, int def): hp(hp), atk(atk), def(def) {
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}

	~Enemy();
	void attack(Hero* hero);
	void heal();
	void attacked(int damage);
	int getHP() const { return hp; }
	int getDef() const { return def; }
	const char* getName() const { return name; }
};



Hero::~Hero()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

void Hero::attack(Enemy* enemy) {
	int damage = atk - enemy->getDef();
	if (damage > 0) {
		enemy->attacked(damage);
		cout << name << "が" << enemy->getName() << "に" << damage << "ダメージ与えた" << endl;
	}
	else {
		cout << "攻撃失敗" << endl;
	}
}

void Hero::heal() {
	int heal = 5;
	hp += heal;
	cout << name << "のHPが" << heal << "回復した！" << endl;
}

void Hero::attacked(int damage) {
	hp -= damage;
}

Enemy::~Enemy()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
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

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Hero hero("俺", 50, 10, 5);
	Enemy enemy("敵", 40, 8, 4);
	char choice;

	while (hero.getHP() >= 0 && enemy.getHP() >= 0) {
		
		cout << "行動を選択してください(攻撃ならa、回復ならh) > ";
		cin >> choice;

		switch (choice)
		{
		case 'a':
			hero.attack(&enemy);
			break;
		case 'h':
			hero.heal();
			break;
		default:
			cout << "a、もしくはhを入力してください。" << endl;
			continue;
		}

		if (enemy.getHP() >= 0) {
			int enemyChoice = rand() % 2;
			if (enemyChoice == 0) {
				enemy.attack(&hero);
			}
			else{
				enemy.heal();
			}
		}
		if (hero.getHP() >= 0 && enemy.getHP() >= 0) {
			cout << "現在の" << hero.getName() << "のHPは:" << hero.getHP() << "、" << enemy.getName() << "のHPは:" << enemy.getHP() << endl;
		}
	}

	if (enemy.getHP() <= 0) {
		cout << hero.getName() << "の勝ち！" << endl;
	}
	else {
		cout << enemy.getName() << "の勝ち！" << endl;
	}
}