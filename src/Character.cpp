#include "../include/Character.h"

#include <iostream>

Character::Character(unsigned hp, unsigned attack, unsigned defense, unsigned speed) : hp{hp}, attack{attack}, defense{defense}, speed{speed}, is_alive{true} {}

unsigned Character::getHp() const
{
    return hp;
}

unsigned Character::getAttack() const
{
    return attack;
}

unsigned Character::getDefense() const
{
    return defense;
}

unsigned Character::getSpeed() const
{
    return speed;
}

bool Character::isAlive() const
{
    return is_alive;
}

void Character::displayStats() const
{
    std::cout << "====== STATS ======" << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Speed: " << speed << std::endl;
    std::cout << std::endl;
}

void Character::takeDamage(unsigned damage)
{
    if (damage >= hp)
    {
        hp = 0;
        is_alive = false;
    }
    else
    {
        hp -= damage;
    }
}