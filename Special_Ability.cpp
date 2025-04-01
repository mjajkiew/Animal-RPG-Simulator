//
// Created by mmjaj on 2/21/2025.
//

#include "Special_Ability.h"
#include <string>
using namespace std;

Special_Ability::Special_Ability(string n, string d, int dmg_amt, int m) : Character_Ability(n, d){
  name = n;
  description = d;
  dmg = dmg_amt;
  mp = m;
}
int Special_Ability::get_dmg(){
  return dmg;
}
int Special_Ability::get_mp(){
  return mp;
}
string Special_Ability::display_string(){
  return "Special Ability: " + name + "\n" + "DMG: " + to_string(dmg) + "\n" + "MP: " + to_string(mp) + "/" + to_string(mp) + "\n" + "Description: " + description + "\n";
}