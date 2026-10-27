#include "../include/Mage.h"

#include <iostream>

Mage::Mage(unsigned hp, unsigned attack, unsigned defense, unsigned speed, unsigned mana, unsigned mana_regeneration, unsigned magic_attack, unsigned magic_defense) : Character(hp, attack, defense, speed), mana{mana}, mana_regeneration{mana_regeneration}, magic_attack{magic_attack}, magic_defense{magic_defense} {}

unsigned Mage::getMana() const
{
    return mana;
}

unsigned Mage::getMagicAttack() const
{
    return magic_attack;
}

unsigned Mage::getMagicDefense() const
{
    return magic_defense;
}

void Mage::Attack(Character &other)
{
    if (mana >= 20)
    {
        other.takeDamage(magic_attack, "magic");
        mana -= 20;
    }
    else
    {
        std::cout << "All out of mana, using regular attack!" << std::endl;
        other.takeDamage(attack, "physical");
        mana += mana_regeneration;
    }
}

void Mage::takeDamage(unsigned damage, std::string attack_type)
{
    if (attack_type == "physical")
    {
        if ((damage - defense) >= hp)
        {
            hp = 0;
            is_alive = false;
        }
        else
        {
            hp -= (damage - defense);
        }
    }
}

void Mage::regenerateMana()
{
    mana += mana_regeneration;
}

void Mage::displayStats() const
{
    std::cout << "====== STATS ======" << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "Mana regeneration: " << mana_regeneration << std::endl;
    std::cout << "Magic attack: " << magic_attack << std::endl;
    std::cout << "Magic defense: " << magic_defense << std::endl;
    std::cout << std::endl;
}