## M1OEP-mjajkiew
________________________________
# CS 2300 Module 2 Open Project

    
My open project is an RPG battle simulator. The player chooses from one of (currently) two animal characters, using combat similar to Pokemon. 
Each character has two abilities, melee and special, as well as having a pick between three actions: sword, shield, and magic. 
In a rock/paper/scissors type standoff, whoever wins gains a special buff corresponding to what they chose. In battle, sword beats magic, magic beats shield, and shield beats sword.
If the player chose magic, they gain some health back, if they choose sword, they do extra damage, and if they choose shield, incoming damage is divided.

I'm using the code from module 1, and expanding on it. Using inheritance, I'm making the Character_Ability class abstract and creating new 
types of moves (separating abilities into melee / special / support). Before, I just used a general "Character_Ability" class which covered every type of move. 
I'm also making melee combat more complex, having a range of dmg a move is able to deal, along with a mechanic of it skewing higher or lower, as opposed to static amount of damage. 
There is also a character select screen with multiple characters, unlike with module 1 which only had one character. 

I hope you enjoy the Elite Animals RPG Battle Simulator :)

