#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "Character.h"

class Warrior : public Character
{
public:
    Warrior(unsigned hp, unsigned attack, unsigned defense, unsigned speed);
    virtual void Attack(Character &other) override;
};

#endif