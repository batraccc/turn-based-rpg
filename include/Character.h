#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

class Character
{
protected:
    unsigned hp{};
    unsigned attack{};
    unsigned defense{};
    unsigned speed{};
    bool is_alive{};

public:
    Character(unsigned hp, unsigned attack, unsigned defense, unsigned speed);
    virtual ~Character() = default;
    unsigned getHp() const;
    unsigned getAttack() const;
    unsigned getDefense() const;
    unsigned getSpeed() const;
    bool isAlive() const;
    virtual void displayStats() const;
    virtual void Attack(Character &other) = 0;
    virtual void takeDamage(unsigned damage, std::string attack_type);
};

#endif