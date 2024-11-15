#include <iostream>
#include "Hero.h"
#include "Enemy.h"

using namespace std;

void showStatus(const Hero hero, const Enemy enemy);

int main() {

    srand(static_cast<unsigned int>(time(0)));

    Hero hero("俺", 50, 10, 5);
    Enemy enemy("敵", 40, 8, 4);
    char choice;

    while (hero.getHP() >= 0 && enemy.getHP() >= 0) {

        showStatus(hero, enemy);
        std::cout << "行動を選択してください(攻撃ならa、回復ならh) > ";
        std::cin >> choice;

        switch (choice) {

        case 'a':
            hero.attack(&enemy);
            break;

        case 'h':
            hero.heal();
            break;

        default:
            std::cout << "a、もしくはhを入力してください。" << std::endl;
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

        std::cout << hero.getName() << "の勝ち！" << std::endl;

    }
    else {

        std::cout << enemy.getName() << "の勝ち！" << std::endl;

    }
}


void showStatus(const Hero hero, const Enemy enemy) {

    cout << "ヒーロー: " << hero.getName() << " HP: " << hero.getHP() << "  攻撃力: " << hero.getDef() << endl;

    cout << "敵: " << enemy.getName() << "  HP: " << enemy.getHP() << "  攻撃力: " << enemy.getDef() << endl;
}

