## By Michael Jajkiewicz
________________________________
# Elite Animals RPG Simulator

    
An RPG simulator based in the console with multiple animal characters, with common RPG mechanics such as multiple types of moves and MP. 
Each character has three abilities, melee, special, and support, as well as having a pick between three actions: sword, shield, and magic. 
In a rock/paper/scissors type standoff, whoever wins gains a special buff corresponding to what they chose. In battle, sword beats magic, magic beats shield, and shield beats sword.
If the player chose magic, they gain some health back, if they choose sword, they do extra damage, and if they choose shield, incoming damage is divided.
The winner of the rock/paper/scissors standoff also takes their turn first.
Melee attacks cover a range of attack damage that can skew up or down randomly throughout the match.
Special attacks work like they do in many other RPGs, with a limited amount of uses, with each use draining MP.
Support moves increase HP or Special MP, with its uses also limited by its own MP.

I utilized C++ within the CLion IDE, creating multiple classes to initialize the animal characters themselves, as well as using inheritance
in order to create the different types of moves that a player/cpu could use. The code is brought together with
a main file which initializes all variables needed to make a character with multiple moves, executes the rock/paper/scissors
standoff that kicks off each round, and constructs how a turn would look like for both a player and cpu.

I hope you enjoy the Elite Animals RPG Battle Simulator :)

