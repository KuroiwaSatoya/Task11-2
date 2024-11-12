#include <iostream>
#include "Hero.h"
#include "Enemy.h"

using namespace std;

void showStatus(const Hero hero, const Enemy enemy);

int main() {

    srand(static_cast<unsigned int>(time(0)));

    Hero hero("‰´", 50, 10, 5);
    Enemy enemy("“G", 40, 8, 4);
    char choice;

    while (hero.getHP() >= 0 && enemy.getHP() >= 0) {

        showStatus(hero, enemy);
        std::cout << "s“®‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢(UŒ‚‚È‚çaA‰ñ•œ‚È‚çh) > ";
        std::cin >> choice;

        switch (choice) {

        case 'a':
            hero.attack(&enemy);
            break;

        case 'h':
            hero.heal();
            break;

        default:
            std::cout << "aA‚à‚µ‚­‚Íh‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;
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

        std::cout << hero.getName() << "‚ÌŸ‚¿I" << std::endl;

    }
    else {

        std::cout << enemy.getName() << "‚ÌŸ‚¿I" << std::endl;

    }
}


void showStatus(const Hero hero, const Enemy enemy) {

    cout << "ƒq[ƒ[: " << hero.getName() << " HP: " << hero.getHP() << "  UŒ‚—Í: " << hero.getDef() << endl;

    cout << "“G: " << enemy.getName() << "  HP: " << enemy.getHP() << "  UŒ‚—Í: " << enemy.getDef() << endl;
}

