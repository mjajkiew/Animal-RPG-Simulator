//Animal_Character.h//
// Created by mmjaj on 1/31/2025.
//
#include "Animal_Character.h"
#include "Character_Ability.h"
#include <string>
#include <iostream>
using namespace std;

std::ostream& operator<<(std::ostream& os, const Animal_Character& obj) {
  os << "Character: " << obj.name << "\n Description: " << obj.description;
  return os;
}

Animal_Character:: Animal_Character(string name, double hp, string description, Melee_Ability m_ab, Special_Ability s_ab, Support_Ability su_ab): m_ability(m_ab),
  s_ability(s_ab), sup_ability(su_ab) {
  this->name = name;
  this->hp = hp;
  this->description = description;
  m_ability = m_ab;
  s_ability = s_ab;
  sup_ability = su_ab;
}

string Animal_Character::get_name(){
  return name;
}
double Animal_Character::get_HP(){
  return hp;
}
string Animal_Character::get_description(){
  return description;
}
Melee_Ability Animal_Character::get_Melee_Ability(){
  return m_ability;
}
Special_Ability Animal_Character::get_Special_Ability(){
  return s_ability;
}
Support_Ability Animal_Character::get_Support_Ability() {
  return sup_ability;
}

