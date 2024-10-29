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
		cout << name << "��" << enemy->getName() << "��" << damage << "�_���[�W�^����" << endl;
	}
	else {
		cout << "�U�����s" << endl;
	}
}

void Hero::heal() {
	int heal = 5;
	hp += heal;
	cout << name << "��HP��" << heal << "�񕜂����I" << endl;
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
		cout << name << "��" << hero->getName() << "��" << damage << "�_���[�W�^����" << endl;
	}
	else {
		cout << "�U�����s" << endl;
	}
}

void Enemy::heal() {
	int heal = 5;
	hp += heal;
	cout << name << "��HP��" << heal << "�񕜂����I" << endl;
}

void Enemy::attacked(int damage) {
	hp -= damage;
}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Hero hero("��", 50, 10, 5);
	Enemy enemy("�G", 40, 8, 4);
	char choice;

	while (hero.getHP() >= 0 && enemy.getHP() >= 0) {
		
		cout << "�s����I�����Ă�������(�U���Ȃ�a�A�񕜂Ȃ�h) > ";
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
			cout << "a�A��������h����͂��Ă��������B" << endl;
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
			cout << "���݂�" << hero.getName() << "��HP��:" << hero.getHP() << "�A" << enemy.getName() << "��HP��:" << enemy.getHP() << endl;
		}
	}

	if (enemy.getHP() <= 0) {
		cout << hero.getName() << "�̏����I" << endl;
	}
	else {
		cout << enemy.getName() << "�̏����I" << endl;
	}
}