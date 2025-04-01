//
// Created by mmjaj on 2/21/2025.
//

#ifndef MELEE_ABILITY_H
#define MELEE_ABILITY_H
#include "Character_Ability.h"
#include <string>
using namespace std;


class Melee_Ability : public Character_Ability {
    private:
        string name;
        string description;
        int dmg_lower_bound;
        int dmg_upper_bound;
        int total_dmg;
        string curr_range; //the current range of the character, skews randomizer depending on "far" "near" or "close"
    public:
    /*
     *constructor
     *initializes name, description, lower_bound of dmg, and upper_bound of dmg
     */
        Melee_Ability(string n, string d, int lower_bound, int upper_bound);
        int get_lower_bound();
        int get_upper_bound();
        string get_range();
        int get_dmg(); //calculates total dmg using range, lower, and higher bound
        void set_range(); //randomly sets character's range - may be too random? test
        string display_string() override;
};



#endif //MELEE_ABILITY_H
