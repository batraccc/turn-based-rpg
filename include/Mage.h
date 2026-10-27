#ifndef _MAGE_H_
#define _MAGE_H_

#include "Character.h"

class Mage : public Character
{
private:
    unsigned mana{};
    unsigned mana_regeneration{};
    unsigned magic_attack{};
    unsigned magic_defense{};

public:
    Mage(unsigned hp, unsigned attack, unsigned defense, unsigned speed, unsigned mana, unsigned mana_regeneration, unsigned magic_attack, unsigned magic_defense);
    unsigned getMana() const;
    unsigned getMagicAttack() const;
    unsigned getMagicDefense() const;

    void Attack(Character &other) override;
    void takeDamage(unsigned damage, std::string attack_type) override;
    void regenerateMana();
    void displayStats() const override;
};

#endif