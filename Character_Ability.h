//
// Created by mmjaj on 2/1/2025.
//

#ifndef CHARACTER_ABILITY_H
#define CHARACTER_ABILITY_H
#include <iostream>
#include <string>
using namespace std;
/*
 *future child classes can separate melee/special abilities, or dmg/buff/healing abilities
 */
class Character_Ability{
private:
    string name;
    string description;
public:
    /*
     *Ability constructor
     *Takes in param name, description
     */
    Character_Ability(string n, string d);
    /*
     *get_name method
     *returns the name of the ability
     */
    string get_name();
    /*
     *get_description method
     *returns description of ability (what it is / amount of dmg it does)
     */
    string get_description();
    /*
     *set_description method
     *sets the description of the ability. they might be long, so setting it outside
     *of object declaration might be necessary
     */
    void set_description(string d);
    /*
     *get_dmg_amount method
     *returns the amount of dmg the ability deals
     */

    virtual string display_string()=0;

};
#endif //CHARACTER_ABILITY_H
