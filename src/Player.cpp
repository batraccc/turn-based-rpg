#include "../include/Player.h"

#include <stdexcept>

Player::Player() {}

void Player::setName(std::string &name)
{
    this->name = name;
}

void Player::setCharacter(std::unique_ptr<Character> &character)
{
    this->character = std::move(character);
}

Character *Player::getCharacter() const
{
    if (character)
        return character.get();
    else
        throw std::runtime_error("Player character not set!");
}
