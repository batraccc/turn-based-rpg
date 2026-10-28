#include "../include/Assasin.h"

Assasin::Assasin(unsigned hp, unsigned attack, unsigned defense, unsigned speed) : Character(hp, attack, defense, speed) {}

void Assasin::Attack(Character &other)
{
    other.takeDamage(attack, "physical");
}
