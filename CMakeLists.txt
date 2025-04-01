cmake_minimum_required(VERSION 3.15)
project(Animal-RPG-Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Animal-RPG-Simulator main.cpp Animal_Character.h Character_Ability.h
        Melee_Ability.h
        Special_Ability.h
        Support_Ability.h)
