//
// Created by mmjaj on 1/31/2025.
//

#ifndef ANIMAL_CHARACTER_H
#define ANIMAL_CHARACTER_H
#include <iostream>
#include <string>
#include "Character_Ability.h"
#include "Melee_Ability.h"
#include "Special_Ability.h"
#include "Support_Ability.h"
using namespace std;

class Animal_Character {
    public:
        /*
         *Animal_Character constructor
         *Takes in param name, HP (health points), and 2 abilities
         */
         std::string name;
         double hp;
         std::string description;
         Melee_Ability m_ability;
         Special_Ability s_ability;
         Support_Ability sup_ability;
         //overloaded operator
         friend std::ostream& operator<<(std::ostream& os, const Animal_Character& obj);
        Animal_Character(string name, double hp, string description, Melee_Ability m_ab, Special_Ability s_ab, Support_Ability su_ab);
        /*
         *get_HP method
         *returns the total HP of a character
         */
        double get_HP();
        /*
         *get_name method
         *returns the name of the character
         */
        std::string get_name();
        /*
         *get_description method
         *returns the description of the character
         */
        std::string get_description();
        /*
         *get_Melee_Ability / get_Special_Ability methods
         *returns the melee / special ability objects tied to the character
         */
        Melee_Ability get_Melee_Ability();
        Special_Ability get_Special_Ability();
        Support_Ability get_Support_Ability();
};
#endif //ANIMAL_CHARACTER_H
