#include "showStatus.h"

void showStatus(const Hero hero, const Enemy enemy) {

    cout << "�q�[���[: " << hero.getName() << " HP: " << hero.getHP() << "  �U����: " << hero.getDef() << endl;

    cout << "�G: " << enemy.getName() << "  HP: " << enemy.getHP() << "  �U����: " << enemy.getDef() << endl;
}
