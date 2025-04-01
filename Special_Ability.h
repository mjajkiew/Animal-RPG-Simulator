//
// Created by mmjaj on 2/21/2025.
//

#ifndef SPECIAL_ABILITY_H
#define SPECIAL_ABILITY_H
#include "Character_Ability.h"
#include <string>
using namespace std;


class Special_Ability : public Character_Ability {
private:
    string name;
    string description;
    int dmg;
    int mp;
public:
    Special_Ability(string n, string d, int dmg_amt, int m);
    int get_dmg();
    int get_mp();
    string display_string() override;

};



#endif //SPECIAL_ABILITY_H
