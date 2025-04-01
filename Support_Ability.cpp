//
// Created by mmjaj on 2/23/2025.
//

#include "Support_Ability.h"
#include "Character_Ability.h"
#include <string>
using namespace std;

Support_Ability::Support_Ability(string n, string d, string b, double h, int m, int a): Character_Ability(n, d) {
  name = n;
  description = d;
  buff = b;
  hp = h;
  mp = m;
  amount_buff = a;
}
string Support_Ability::get_buff(){
  return buff;
}
double Support_Ability::get_hp(){
  return hp;
}
int Support_Ability::get_mp(){
  return mp;
}
int Support_Ability::get_amount_buff() {
  return amount_buff;
}
void Support_Ability::set_hp (double h){
  hp = h;
}
void Support_Ability::set_mp (int m){ //set_hp / set_mp makes it so hp/mp is updated with curr_hp / curr_mp
  mp = m;
 }
void Support_Ability::set_buff(string b){
  buff = b; //buff can only be "hp" or "mp"
}
void Support_Ability::set_amount_buff(int a){
  amount_buff = a;
}
double Support_Ability::apply_buff(double curr_hp, int curr_mp){
  if(buff == "HP"){
    return curr_hp + amount_buff;
  }
  else{
    return curr_mp + amount_buff; // generally, in this case, amount_buff should equal 1
  }
}
string Support_Ability::display_string(){
  return "Support Ability: " + name + "\n" + "Buff: " + buff + "\n" + "MP: " + to_string(mp) + "/" + to_string(mp) + "\n" + "Description: " + description + "\n";
}