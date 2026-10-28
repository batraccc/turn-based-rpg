#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"
#include <memory>

class Player
{
private:
    std::string name;
    std::unique_ptr<Character> character;

public:
    Player();
    void setName(std::string &name);
    void setCharacter(std::unique_ptr<Character> &character);
    Character *getCharacter() const;
};

#endif