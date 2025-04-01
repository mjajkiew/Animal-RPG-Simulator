//
// Created by mmjaj on 2/21/2025.
//

#include "Melee_Ability.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Melee_Ability::Melee_Ability(string n, string d, int lower_bound, int upper_bound) : Character_Ability(n, d){
    name = n;
    description = d;
    dmg_lower_bound = lower_bound;
    dmg_upper_bound = upper_bound;
}
int Melee_Ability::get_lower_bound(){
  return dmg_lower_bound;
}
int Melee_Ability::get_upper_bound(){
  return dmg_upper_bound;
}
string Melee_Ability::get_range(){
  return curr_range;
}
int Melee_Ability::get_dmg(){
  srand(time(0));
  //skewed lower
  if(curr_range == "far"){
    total_dmg = ((rand()%((dmg_upper_bound - 10)-dmg_lower_bound)) + dmg_lower_bound);
  }
  //normally skewed
  else if(curr_range == "near"){
    total_dmg = ((rand()%(dmg_upper_bound-dmg_lower_bound)) + dmg_lower_bound);
  }
  else{
    //skewed higher
    total_dmg = ((rand()%(dmg_upper_bound-dmg_lower_bound)) + (dmg_lower_bound + 10));
  }
  return total_dmg;
}
void Melee_Ability::set_range(){
  srand(time(0));
  int random_number = rand() % 3;
  if(random_number == 0){
    curr_range = "far";
  }
  else if(random_number == 1){
    curr_range = "near";
  }
  else{
    curr_range = "close";
  }

}
string Melee_Ability::display_string(){
  return "Melee Ability: " + name + "\n" + "DMG: " + to_string(dmg_lower_bound) + "-" + to_string(dmg_upper_bound) + "\n" + "Description: " + description + "\n";
}
