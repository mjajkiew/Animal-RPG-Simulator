
// Created by mmjaj on 1/31/2025.
//
#include <algorithm>
#include <string>
#include "Character_Ability.cpp"
#include "Animal_Character.cpp"
#include "Melee_Ability.cpp"
#include "Special_Ability.cpp"
#include "Support_Ability.cpp"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <memory>
#include <cstdlib>
using namespace std;
string sword_shield_magic_player_choice;
string sword_shield_magic_cpu_choice;
//did the player win rock/paper/scissors?
string ssm_player_winner;
string ssm_cpu_winner;
bool game_start = true;
//Characters:
//Chuck
unique_ptr<Melee_Ability> chuck_melee_ab = make_unique<Melee_Ability>("Colossal Stomp", "A Huge Stomp That Shatters The Ground", 60, 90);
unique_ptr<Special_Ability> chuck_special_ab = make_unique<Special_Ability>("Maximum Horsepower", "Full force attack on the opponent", 80, 5);
unique_ptr<Support_Ability> chuck_support_ab = make_unique<Support_Ability>("Equine Meditation", "A short rest that restores 25 HP", "HP", 300, 5, 25);
unique_ptr<Animal_Character> chuck_ch = make_unique<Animal_Character>("Chuck the Horse", 300, "A powerful kickboxing horse unlike any other!", *chuck_melee_ab, *chuck_special_ab, *chuck_support_ab);

//Odin
unique_ptr<Melee_Ability> odin_melee_ab = make_unique<Melee_Ability>("Ravage Pierce", "Devastating Stab with a Spear", 40, 95);
unique_ptr<Special_Ability> odin_special_ab = make_unique<Special_Ability>("Bursting Waves", "Pushes a Gigantic Wave Against the Opponent", 90, 2);
unique_ptr<Support_Ability> odin_support_ab = make_unique<Support_Ability>("Soothing Aqua", "Use the power of water to heal 30 HP", "HP", 280, 2, 30);
unique_ptr<Animal_Character> odin_ch = make_unique<Animal_Character>("Odin the Otter", 310, "An otter warrior trained in the art of the spear!", *odin_melee_ab, *odin_special_ab, *odin_support_ab);

//Screech
unique_ptr<Melee_Ability> screech_melee_ab = make_unique<Melee_Ability>("Hell Bite", "A Deep Bite That Aches For Years", 60, 75);
unique_ptr<Special_Ability> screech_special_ab = make_unique<Special_Ability>("Everlasting Scream", "A Scream so Loud It Bursts Most Organism's Eardrums", 180, 1);
unique_ptr<Support_Ability> screech_support_ab = make_unique<Support_Ability>("Rejuvenating Rations", "A stockpile of rations which restores 1 MP", "MP", 280, 1, 1);
unique_ptr<Animal_Character> screech_ch = make_unique<Animal_Character>("Screech the Bat", 280, "A lone cave dwelling bat with unparalleled power!", *screech_melee_ab, *screech_special_ab, *screech_support_ab);

//Default to Chuck
Animal_Character player = *chuck_ch;
Animal_Character cpu = *chuck_ch;
int player_curr_mp = chuck_special_ab->get_mp();
int cpu_curr_mp = chuck_special_ab->get_mp();
double player_curr_hp = chuck_ch->get_HP();
double cpu_curr_hp = chuck_ch->get_HP();

/*
 *method for how a player's turn operates
 */
void player_turn() {
    player.get_Melee_Ability().set_range();
    string ability_used;
    double damage_dealt = 0;
    cout << "Player's turn!" << endl;
    if(ssm_player_winner == "magic") {
        //ssm magic advantage
        player_curr_hp += 10;
    }
    string player_choice;
    while(true) {
        cout << "Choose your move:" << endl;
        cout << "HP: " << player_curr_hp << "/" << player.get_HP() << endl;
        /*
         *not displaying correctly, fix make sure to add (1) and (2)
         */
        cout << "(1) " << player.get_Melee_Ability().get_name() << " // DMG: " << player.get_Melee_Ability().get_lower_bound() << "-" << player.get_Melee_Ability().get_upper_bound() << endl;
        cout << "(2) " << player.get_Special_Ability().get_name() << " // DMG: " << player.get_Special_Ability().get_dmg() << " // MP: " << player_curr_mp << "/" << player.get_Special_Ability().get_mp() << endl;
        cout << "(3) " << player.get_Support_Ability().get_name() << " // Buff: " << player.get_Support_Ability().get_buff() << endl;
        cout << "(4) " << "Display Detailed Information" << endl;
        cin >> player_choice;
        if (player_choice == "1" || player_choice == "2" || player_choice == "3") {
            //MELEE
            if(player_choice == "1") {
                ability_used = player.get_Melee_Ability().get_name();
                //ssm shield advantage for cpu
                if(ssm_cpu_winner == "shield") {
                    cpu_curr_hp -= (player.get_Melee_Ability().get_dmg() * .25);
                    damage_dealt = player.get_Melee_Ability().get_dmg() * .25;
                }
                else{
                    cpu_curr_hp -= player.get_Melee_Ability().get_dmg();
                    damage_dealt = player.get_Melee_Ability().get_dmg();
                    //ssm sword advantage
                    if(ssm_player_winner == "sword") {
                        cpu_curr_hp -= player.get_Melee_Ability().get_dmg() *.2;
                        damage_dealt += player.get_Melee_Ability().get_dmg() * .2;
                    }
                    cin.clear();
                    break;
                }
            }
            //SPECIAL ABILITY
            else if(player_choice == "2") {
                ability_used = player.get_Special_Ability().get_name();
                /*
                 *if there is 0 mp left, then loop doesn't break and cin is cleared
                 */
                if(player_curr_mp > 0) {
                    //ssm shield advantage for cpu
                    if(ssm_cpu_winner == "shield") {
                        cpu_curr_hp -= (player.get_Special_Ability().get_dmg() * .25);
                        damage_dealt = player.get_Special_Ability().get_dmg() * .25;
                        player_curr_mp--;
                        cin.clear();
                        break;
                    }
                    else {
                        cpu_curr_hp -= player.get_Special_Ability().get_dmg();
                        damage_dealt = player.get_Special_Ability().get_dmg();
                        if(ssm_player_winner == "sword") {
                            cpu_curr_hp -= player.get_Special_Ability().get_dmg() *.2;
                            damage_dealt += player.get_Special_Ability().get_dmg() * .2;
                        }
                        player_curr_mp--; //can subtract more, need to find efficient way for mp to regen?
                        cin.clear();
                        break;
                    }
                }
            }
            //SUPPORT
            else if(player_choice == "3") {
                ability_used = player.get_Support_Ability().get_name();
                //does math of applying buff, returns correct value to curr_hp/curr_mp
                if(player.get_Support_Ability().get_buff() == "HP") {
                    player_curr_hp = player.get_Support_Ability().apply_buff(player_curr_hp, player_curr_mp);

                }
                else {
                    player_curr_mp = int(player.get_Support_Ability().apply_buff(player_curr_hp, player_curr_mp));
                }
                break;
            }
        }
        //INFO
        else if(player_choice == "4") {
            cout << "------------------------------------------\n" << endl;
            cout << player.get_Melee_Ability().display_string() << "\n" << player.get_Special_Ability().display_string() << "\n" << player.get_Support_Ability().display_string() << endl;
            cout << "------------------------------------------" << endl;
            cin.clear();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else {
            cout << "Invalid input, please try again" << endl;
            cin.clear();
        }
    }
    //pause for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Player used " << ability_used << "! " << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if(damage_dealt != 0) {
        cout << "Player dealt " << damage_dealt << " damage! " << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    //if damage_dealt is 0, then a support ability was used.
    else {
        cout << "Player restored " << player.get_Support_Ability().get_amount_buff() << " " << player.get_Support_Ability().get_buff() << "! " << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    cout << "Player HP: " << player_curr_hp << "/" << player.get_HP() << endl;
    cout << "CPU HP: " << cpu_curr_hp << "/" << cpu.get_HP() << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if(cpu_curr_hp <= 0) {
        game_start = false;
        cout << "CPU has fallen! Player Wins!";
        exit(1);
    }
    cout << "" << endl;
}

void cpu_turn() {
    cpu.get_Melee_Ability().set_range();
    srand(time(0));
    //cpu turn doesn't print anything aside from it being its turn
    string ability_used;
    double damage_dealt = 0;
    cout << "CPU's Turn!" <<endl;
    if(ssm_cpu_winner == "magic") {
        cpu_curr_hp += 10;
    }
    //randomly choose between abilities (later can become more intelligent, ie focusing on healing when low health
    string cpu_choice = "null";
    if(cpu_curr_mp == 0) {
        cpu_choice = "1";
    }
    else {
        int random_number = rand() % (3) + 1;
        cpu_choice = to_string(random_number);
    }
    if(cpu_choice == "1") {
        ability_used = cpu.get_Melee_Ability().get_name();
        //ssm shield advantage for player
        if(ssm_player_winner == "shield") {
            player_curr_hp -= (cpu.get_Melee_Ability().get_dmg() * 0.25);
            damage_dealt = cpu.get_Melee_Ability().get_dmg() * .25;
        }
        player_curr_hp -= cpu.get_Melee_Ability().get_dmg();
        damage_dealt = cpu.get_Melee_Ability().get_dmg();
        //ssm sword advantage
        if(ssm_cpu_winner == "sword") {
            player_curr_hp -= cpu.get_Melee_Ability().get_dmg() *.2;
            damage_dealt = cpu.get_Melee_Ability().get_dmg();
        }
    }
    else if(cpu_choice == "2") {
        ability_used = cpu.get_Special_Ability().get_name();
        if(ssm_player_winner == "shield") {
            player_curr_hp -= (cpu.get_Special_Ability().get_dmg() * 0.25);
            damage_dealt = cpu.get_Special_Ability().get_dmg() * 0.25;
        }
        else {
            player_curr_hp -= cpu.get_Special_Ability().get_dmg();
            damage_dealt = cpu.get_Special_Ability().get_dmg();
            //ssm sword advantage
            if(ssm_cpu_winner == "sword") {
                player_curr_hp -= cpu.get_Special_Ability().get_dmg() *.2;
                damage_dealt += cpu.get_Special_Ability().get_dmg() * .2;
            }
        }
        cpu_curr_mp--;
    }
    else if(cpu_choice == "3") {
        ability_used = cpu.get_Support_Ability().get_name();
        //does math of applying buff, returns correct value to curr_hp/curr_mp
        if(cpu.get_Support_Ability().get_buff() == "HP") {
            cpu_curr_hp = cpu.get_Support_Ability().apply_buff(cpu_curr_hp, cpu_curr_mp);
        }
        else {
            cpu_curr_mp = int(cpu.get_Support_Ability().apply_buff(cpu_curr_hp, cpu_curr_mp));
        }
    }
    //pause for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "CPU used " << ability_used << "! " << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if(damage_dealt != 0) {
        cout << "CPU dealt " << damage_dealt << " damage! " << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    else {
        cout << "CPU restored " << cpu.get_Support_Ability().get_amount_buff() << " " << cpu.get_Support_Ability().get_buff() << "! " << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "CPU HP: " << cpu_curr_hp << "/" << cpu.get_HP() << endl;
    cout << "Player HP: " << player_curr_hp << "/" << player.get_HP() << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if(player_curr_hp <= 0) {
        game_start = false;
        cout << "Player has fallen! CPU Wins!";
        exit(1);
    }
    cout << "" << endl;
}
    int main() {
        srand(time(0));
        /*
         *CHARACTER SELECT FOR PLAYER AND CPU
         *EVERYTHING HERE MUST BE ADJUSTED IF MORE CHARACTERS ARE ADDED
         */
        string char_selection;
        cout << "Welcome to the Elite Animals RPG Battle Simulator!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Please select a character:" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "----------------------------------------" << endl;
        cout << "(1) " << chuck_ch->get_name() << endl;
        cout << "~" << chuck_ch->get_description() << "~" << endl;
        cout << chuck_ch->get_Melee_Ability().display_string() << "\n" << chuck_ch->get_Special_Ability().display_string() << endl;
        cout << chuck_ch->get_Support_Ability().display_string() << endl;
        cout << "----------------------------------------" << endl;
        cout << "(2) " << odin_ch->get_name() << endl;
        cout << "~" << odin_ch->get_description() << "~" << endl;
        cout << odin_ch->get_Melee_Ability().display_string() << endl;
        cout << odin_ch->get_Special_Ability().display_string() << endl;
        cout << odin_ch->get_Support_Ability().display_string() << endl;
        cout << "----------------------------------------" << endl;
        cout << "(3) " << screech_ch->get_name() << endl;
        cout << "~" << screech_ch->get_description() << "~" << endl;
        cout << screech_ch->get_Melee_Ability().display_string() << endl;
        cout << screech_ch->get_Special_Ability().display_string() << endl;
        cout << screech_ch->get_Support_Ability().display_string() << endl;
        cout << "----------------------------------------" << endl;
        while(true) {
            cin >> char_selection;
            if(char_selection == "1") {
                //do nothing, chuck is default
                break;
            }
            if(char_selection == "2") {
                player = *odin_ch;
                player_curr_mp = odin_special_ab->get_mp();
                player_curr_hp = odin_ch->get_HP();
                break;
            }
            if(char_selection == "3") {
                player = *screech_ch;
                player_curr_mp = screech_special_ab->get_mp();
                player_curr_hp = screech_ch->get_HP();
                break;
            }
            cout << "Invalid Input, Please Try Again" << endl;
            cin.clear();
        }
        int cpu_char_picker = (rand()%3) + 1;
        if(cpu_char_picker == 1) {
            //chuck is default
        }
        else if(cpu_char_picker == 2) {
            cpu = *odin_ch;
            cpu_curr_mp = odin_special_ab->get_mp();
            cpu_curr_hp = odin_ch->get_HP();
        }
        else if(cpu_char_picker == 3) {
            cpu = *screech_ch;
            cpu_curr_mp = screech_special_ab->get_mp();
            cpu_curr_hp = screech_ch->get_HP();
        }
        cout << "You chose: " << player.get_name() << "!" << endl;
        cout << "CPU chose: " << cpu.get_name() << "! \n" << endl;
        int round = 1;
        while (game_start) {
            /*
             *ROUND START
             *Rounds start with rock/paper/scissors. whoever wins attacks first (attacker is revealed after making choice for moves)
             */
            cout << "-----ROUND " << round << "-----" << endl;
            cout << "Choose between sword (Extra Damage), shield (More Defense), or magic (Additional Healing): " << endl;
            while(true) {
                string ssm_player_input;
                cin >> ssm_player_input;
                if (ssm_player_input == "sword" || ssm_player_input == "SWORD") {
                    sword_shield_magic_player_choice = "sword";
                    cin.clear();
                    break;
                }
                if(ssm_player_input == "shield" || ssm_player_input == "SHIELD") {
                    sword_shield_magic_player_choice = "shield";
                    cin.clear();
                    break;
                }
                if(ssm_player_input == "magic" || ssm_player_input == "MAGIC") {
                    sword_shield_magic_player_choice = "magic";
                    cin.clear();
                    break;
                }
                cout << "Invalid input, please try again" << endl;
                cin.clear();
            }
            int random_number = (rand() % 3) + 1;
            if(random_number == 1) {
                sword_shield_magic_cpu_choice = "sword";
            }
            else if(random_number == 2) {
                sword_shield_magic_cpu_choice = "shield";
            }
            else if(random_number == 3) {
                sword_shield_magic_cpu_choice = "magic";
            }
            cout << "Player used " + sword_shield_magic_player_choice << "!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "CPU used " + sword_shield_magic_cpu_choice << "! \n" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));

            if(sword_shield_magic_cpu_choice == sword_shield_magic_player_choice) {
                cout << "Draw! A player will be randomly chosen to go first..."<< endl;
                ssm_player_winner = "null";
                ssm_cpu_winner = "null";
                int random_picker = rand() % (2) + 1;
                if(random_picker == 1) {
                    player_turn();
                    cpu_turn();
                }
                else if(random_picker == 2) {
                    cpu_turn();
                    player_turn();
                }

            }
            if(sword_shield_magic_player_choice == "sword" && sword_shield_magic_cpu_choice == "magic") {
              //sword beats magic
                cout << "Sword beats magic! Player goes first and deals extra damage!" << endl;
                ssm_player_winner = "sword";
                ssm_cpu_winner = "null";
                player_turn();
                cpu_turn();
            }
            if(sword_shield_magic_player_choice == "sword" && sword_shield_magic_cpu_choice == "shield") {
                //shield beats sword
                cout << "Shield beats sword! CPU goes first and resists incoming damage!" << endl;
                ssm_player_winner = "null";
                ssm_cpu_winner = "shield";
                cpu_turn();
                player_turn();
            }
            if(sword_shield_magic_player_choice == "shield" && sword_shield_magic_cpu_choice == "magic") {
                //magic beats shield
                cout << "Magic beats shield! CPU goes first and gains health!" << endl;
                ssm_player_winner = "null";
                ssm_cpu_winner = "magic";
                cpu_turn();
                player_turn();
            }
            if(sword_shield_magic_player_choice == "shield" && sword_shield_magic_cpu_choice == "sword") {
                //shield beats sword
                cout << "Shield beats sword! Player goes first and resists incoming damage!" << endl;
                ssm_player_winner = "shield";
                ssm_cpu_winner = "null";
                player_turn();
                cpu_turn();
            }
            if(sword_shield_magic_player_choice == "magic" && sword_shield_magic_cpu_choice == "shield") {
                //magic beats shield
                cout << "Magic beats sword! Player goes first and gains health!" << endl;
                ssm_player_winner = "magic";
                ssm_cpu_winner = "null";
                player_turn();
                cpu_turn();
            }
            if(sword_shield_magic_player_choice == "magic" && sword_shield_magic_cpu_choice == "sword") {
                cout << "Sword beats magic! CPU goes first and deals extra damage!" << endl;
                //sword beats magic
                ssm_player_winner = "null";
                ssm_cpu_winner = "sword";
                cpu_turn();
                player_turn();
            }
            round++;
        }
    }




