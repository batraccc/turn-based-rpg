#include "../include/Character.h"
#include "../include/Warrior.h"
#include "../include/Mage.h"
#include "../include/Assasin.h"
#include "../include/Player.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdlib>

void displayInitialPromptMessage()
{
    std::cout << "======================= TURN - BASED RPG =======================" << std::endl;
    std::cout << "Welcome! To get started please choose one of the classes bellow: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Warrior" << std::endl;
    std::cout << "2. Mage" << std::endl;
    std::cout << "3. Assasin" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your choice: ";
}

void displayStartMessage(const Player &player)
{
    std::cout << "Great choice!" << std::endl;
    std::cout << std::endl;
    player.getCharacter()->displayStats();
    std::cout << std::endl;
    std::cout << "Your advanture starts in: ";
    for (int i = 5; i > 0; i--)
    {
        std::cout << i << "... " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Go!" << std::endl;
}

void displayMoveChoice()
{
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Dodge" << std::endl;
    std::cout << "3. Use Item" << std::endl;
    std::cout << "4. Run" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{
    srand(time(0));
    const int numberOfClasses{3};
    displayInitialPromptMessage();
    Player player;
    int choice{};
    std::string name{};

    while (!(std::cin >> choice))
    {
        std::cout << "Invalid input, please try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    switch (choice)
    {
    case 1:
    {
        std::unique_ptr<Character> character_ptr = std::make_unique<Warrior>(100, 25, 10, 32);
        player.setName(name);
        player.setCharacter(character_ptr);
        break;
    }
    case 2:
    {
        std::unique_ptr<Character> character_ptr = std::make_unique<Mage>(80, 5, 10, 28, 100, 15, 35, 20);
        player.setName(name);
        player.setCharacter(character_ptr);
        break;
    }
    case 3:
    {
        std::unique_ptr<Character> character_ptr = std::make_unique<Assasin>(60, 38, 5, 70);
        player.setName(name);
        player.setCharacter(character_ptr);
        break;
    }
    default:
    {
        break;
    }
    }

    displayStartMessage(player);

    bool exit{false};
    do
    {
        int randomNum = (rand() % numberOfClasses) + 1;
        Player enemy;
        switch (randomNum)
        {
        case 1:
        {
            std::string name{"Warrior"};
            std::unique_ptr<Character> character_ptr = std::make_unique<Warrior>(100, 25, 10, 32);
            enemy.setName(name);
            enemy.setCharacter(character_ptr);
            break;
        }
        case 2:
        {
            std::string name{"Mage"};
            std::unique_ptr<Character> character_ptr = std::make_unique<Mage>(100, 5, 5, 28, 100, 15, 35, 20);
            enemy.setName(name);
            enemy.setCharacter(character_ptr);
            break;
        }
        case 3:
        {
            std::string name{"Assasin"};
            std::unique_ptr<Character> character_ptr = std::make_unique<Assasin>(60, 38, 5, 70);
            enemy.setName(name);
            enemy.setCharacter(character_ptr);
            break;
        }
        default:
            break;
        }
        std::cout << "Your stats: " << std::endl;
        player.getCharacter()->displayStats();
        std::cout << "Enemy stats: " << std::endl;
        enemy.getCharacter()->displayStats();
        bool run_away{false};
        do
        {
            int enemyChoice = (rand() % 2) + 1;

            if (player.getCharacter()->getSpeed() >= enemy.getCharacter()->getSpeed())
            {
                std::cout << "You are faster, you move first. Select your move: " << std::endl;
                displayMoveChoice();
                int choice{};
                while (!(std::cin >> choice))
                {
                    std::cout << "Invalid choice, try again: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                switch (choice)
                {
                case 1:
                {
                    if (enemyChoice == 1)
                    {
                        std::cout << "Attacking enemy!" << std::endl;
                        player.getCharacter()->Attack(*enemy.getCharacter());
                        std::cout << "Enemy HP remaining: " << enemy.getCharacter()->getHp() << std::endl;
                        if (enemy.getCharacter()->isAlive())
                        {
                            std::cout << "Enemy attacks you!" << std::endl;
                            enemy.getCharacter()->Attack(*player.getCharacter());
                        }
                    }
                    else if (enemyChoice == 2)
                    {
                        std::cout << "Enemy is trying to dodge your attack!" << std::endl;
                        int chance = (rand() % 100) + 1;
                        if (chance > 50)
                        {
                            std::cout << "Enemy dodged your attack!" << std::endl;
                        }
                        else
                        {
                            std::cout << "Enemy was not able to dodge your attack!" << std::endl;
                            player.getCharacter()->Attack(*enemy.getCharacter());
                            std::cout << "Enemy HP remaining: " << enemy.getCharacter()->getHp() << std::endl;
                        }
                    }
                    break;
                }
                case 2:
                {
                    if (enemyChoice == 1)
                    {
                        std::cout << "You try to dodge an enemy attack!" << std::endl;
                        int chance = (rand() % 100 + 1);
                        if (chance > 50)
                        {
                            std::cout << "Successful dodge! You take 0 damage!" << std::endl;
                        }
                        else
                        {
                            std::cout << "You were not able to dodge!" << std::endl;
                            std::cout << "Enemy attacks you!" << std::endl;
                            enemy.getCharacter()->Attack(*player.getCharacter());
                        }
                    }
                    else if (enemyChoice == 2)
                    {
                        std::cout << "You both tried to dodge an attack, nothing happens!" << std::endl;
                    }
                    break;
                }
                case 3:
                {
                    break;
                }
                case 4:
                {
                    std::cout << "Attemping to run!" << std::endl;
                    int chance = (rand() % 100) + 1;
                    if (chance > 75)
                    {
                        run_away = true;
                    }
                    else
                    {
                        std::cout << "Was not able to run away!" << std::endl;
                        if (enemyChoice == 1)
                        {
                            std::cout << "Enemy attacks you!" << std::endl;
                            enemy.getCharacter()->Attack(*player.getCharacter());
                        }
                        else if (enemyChoice == 2)
                        {
                            std::cout << "Enemy was trying to dodge, you were lucky!" << std::endl;
                        }
                    }
                    break;
                }
                default:
                    break;
                }
            }
            else
            {
                std::cout << "Enemy is faster, it moves first! Select your choice: " << std::endl;
                displayMoveChoice();
                int choice{};
                while (!(std::cin >> choice))
                {
                    std::cout << "Invalid choice, try again: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                switch (choice)
                {
                case 1:
                {
                    if (enemyChoice == 1)
                    {
                        std::cout << "Enemy attacks you!" << std::endl;
                        enemy.getCharacter()->Attack(*player.getCharacter());
                        if (player.getCharacter()->isAlive())
                        {
                            std::cout << "You attack the enemy!" << std::endl;
                            player.getCharacter()->Attack(*enemy.getCharacter());
                            std::cout << "Enemy HP remaining: " << enemy.getCharacter()->getHp() << std::endl;
                        }
                    }
                    else if (enemyChoice == 2)
                    {
                        std::cout << "Enemy will try to dodge your attack!" << std::endl;
                        int chance = (rand() % 100) + 1;
                        if (chance > 50)
                        {
                            std::cout << "Enemy dodged your attack!" << std::endl;
                        }
                        else
                        {
                            std::cout << "Enemy was not able to dodge your attack!" << std::endl;
                            std::cout << "You attack the enemy!" << std::endl;
                            player.getCharacter()->Attack(*enemy.getCharacter());
                            std::cout << "Enemy HP remaining: " << enemy.getCharacter()->getHp() << std::endl;
                        }
                    }
                    break;
                }
                case 2:
                {
                    if (enemyChoice == 1)
                    {
                        std::cout << "You will try to dodge enemy attack!" << std::endl;
                        int chance = (rand() % 100) + 1;
                        if (chance > 50)
                        {
                            std::cout << "Successful dodge! You take 0 damage!" << std::endl;
                        }
                        else
                        {
                            std::cout << "You were not able to dodge!" << std::endl;
                            std::cout << "Enemy attacks you!" << std::endl;
                            enemy.getCharacter()->Attack(*player.getCharacter());
                        }
                    }
                    else if (enemyChoice == 2)
                    {
                        std::cout << "You both tried to dodge an attack, nothing happens!" << std::endl;
                    }
                    break;
                }
                case 3:
                {
                    break;
                }
                case 4:
                {
                    std::cout << "Attemping to run!" << std::endl;
                    int chance = (rand() % 100) + 1;
                    if (chance > 75)
                    {
                        run_away = true;
                    }
                    else
                    {
                        std::cout << "Was not able to run away!" << std::endl;
                        if (enemyChoice == 1)
                        {
                            std::cout << "Enemy attacks you!" << std::endl;
                            enemy.getCharacter()->Attack(*player.getCharacter());
                        }
                        else if (enemyChoice == 2)
                        {
                            std::cout << "Enemy was trying to dodge, you were lucky!" << std::endl;
                        }
                    }
                    break;
                }
                default:
                    break;
                }
            }
            player.getCharacter()->displayStats();
            enemy.getCharacter()->displayStats();
        } while (player.getCharacter()->isAlive() && enemy.getCharacter()->isAlive() && !run_away);
        if (player.getCharacter()->isAlive() && !run_away)
        {
            std::cout << "Congratulations, you won!" << std::endl;
            std::cout << "Would you like to continue the run? [Yes/No]: ";
            std::string choice{};
            std::getline(std::cin, choice);
            if (choice == "No")
                exit = true;
        }
        else if (player.getCharacter()->isAlive() && run_away)
        {
            std::cout << "You ran away!" << std::endl;
            std::cout << "Would you like to continue the run? [Yes/No]: ";
            std::string choice{};
            std::getline(std::cin, choice);
            if (choice == "No")
                exit = true;
        }
        else
        {
            std::cout << "Sorry, you lost! Your run comes to an end!" << std::endl;
            exit = true;
        }
    } while (exit == false);

    return 0;
}