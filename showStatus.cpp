#include "showStatus.h"

void showStatus(const Hero hero, const Enemy enemy) {

    cout << "ƒq[ƒ[: " << hero.getName() << " HP: " << hero.getHP() << "  UŒ‚—Í: " << hero.getDef() << endl;

    cout << "“G: " << enemy.getName() << "  HP: " << enemy.getHP() << "  UŒ‚—Í: " << enemy.getDef() << endl;
}
