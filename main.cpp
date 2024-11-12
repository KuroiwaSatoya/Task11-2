#include <iostream>
#include "Hero.h"
#include "Enemy.h"

using namespace std;

void showStatus(const Hero hero, const Enemy enemy);

int main() {

    srand(static_cast<unsigned int>(time(0)));

    Hero hero("��", 50, 10, 5);
    Enemy enemy("�G", 40, 8, 4);
    char choice;

    while (hero.getHP() >= 0 && enemy.getHP() >= 0) {

        showStatus(hero, enemy);
        std::cout << "�s����I�����Ă�������(�U���Ȃ�a�A�񕜂Ȃ�h) > ";
        std::cin >> choice;

        switch (choice) {

        case 'a':
            hero.attack(&enemy);
            break;

        case 'h':
            hero.heal();
            break;

        default:
            std::cout << "a�A��������h����͂��Ă��������B" << std::endl;
            continue;

        }

        if (enemy.getHP() > 0) {

            int enemyChoice = rand() % 2;

            if (enemyChoice == 0) {

                enemy.attack(&hero);

            }
            else {

                enemy.heal();

            }
        }
    }

    if (enemy.getHP() < 0) {

        std::cout << hero.getName() << "�̏����I" << std::endl;

    }
    else {

        std::cout << enemy.getName() << "�̏����I" << std::endl;

    }
}


void showStatus(const Hero hero, const Enemy enemy) {

    cout << "�q�[���[: " << hero.getName() << " HP: " << hero.getHP() << "  �U����: " << hero.getDef() << endl;

    cout << "�G: " << enemy.getName() << "  HP: " << enemy.getHP() << "  �U����: " << enemy.getDef() << endl;
}

