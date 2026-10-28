#ifndef _ASSASIN_H_
#define _ASSASIN_H_

#include "Character.h"

class Assasin : public Character
{
public:
    Assasin(unsigned hp, unsigned attack, unsigned defense, unsigned speed);
    void Attack(Character &other) override;
};

#endif