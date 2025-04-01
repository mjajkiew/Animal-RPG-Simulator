//
// Created by mmjaj on 2/1/2025.
//
#include "Character_Ability.h"
#include <string>
#include <iostream>
#include <utility>
using namespace std;

Character_Ability::Character_Ability(string n, string d){
    name = n;
    description = d;
}
string Character_Ability::get_name(){
    return name;
}
string Character_Ability::get_description(){
    return description;
}
void Character_Ability::set_description(string d){
    description = d;
}





