//
// Created by mmjaj on 2/23/2025.
//

#ifndef SUPPORT_ABILITY_H
#define SUPPORT_ABILITY_H
#include "Character_Ability.h"
#include <string>
using namespace std;


class Support_Ability : public Character_Ability{
private:
    string name;
    string description;
    //in future, add attack stat which can be buffed
    string buff;
    double hp;
    int mp;
    int amount_buff;
    public:
    /*
     *constructor
     */
    Support_Ability(string n, string d, string b, double h, int m, int a);
    /*
     *getters
     */
    string get_buff();
    double get_hp();
    int get_mp();
    int get_amount_buff();
    /*
     *setters
     */
    void set_hp (double hp);
    void set_mp (int mp); //set_hp / set_mp makes it so hp/mp is updated with curr_hp / curr_mp
    void set_buff(string b);
    void set_amount_buff(int a);
    double apply_buff(double curr_hp, int curr_mp);
    string display_string() override;

};



#endif //SUPPORT_ABILITY_H
