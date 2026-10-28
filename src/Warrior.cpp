#include "../include/Warrior.h"

Warrior::Warrior(unsigned hp, unsigned attack, unsigned defense, unsigned speed) : Character(hp, attack, defense, speed) {}

void Warrior::Attack(Character &other)
{
    other.takeDamage(attack, "physical");
}