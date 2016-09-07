#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Attack.h"
#include "Trainer.h"
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

void selectPokemon(Trainer&, Pokemon*, int);
//void selectMoves
void displayTypes(Pokemon);
string typeDisplaySwitch(PokeType);
void fightMenu(Trainer&, Trainer&);
void battlePokes(Trainer&, int, Trainer&, int);
int checkHp(Trainer&);
void manualSwitch(Trainer&);

int main()
{
    //CONSIDER MAKING POKEMON AND ATTACKS ARRAYS INSIDE THEIR AGGREGATE CLASSES
    //THIS COULD LESSEN THE AMOUNT OF CODE NECESSARY.

    //NEED TO MAKE A SPEED STAT THAT DETERMINES WHO ATTACKS FIRST

    //GET TRAINER.GETPOKESPEED AND USE THAT IN THE WHILE LOOP TO DETERMINE WHICH
    //POKEMONS BATTLE FUNCTION IS USED FIRST

    unsigned seed = time(0);
    srand(seed);

    const int POKE_TYPES = 18;
    double typeChart [POKE_TYPES] [POKE_TYPES] =
        {//   NUL, NRM, FIR, WAT, ELE, GRS, ICE, FIT, POI, GND, FLY, PSY, BUG, RCK, GHO, DRA, DRK, STE
      /*NUL*/{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0},
      /*NRM*/{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5},
      /*FIR*/{1.0, 1.0, 0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0},
      /*WAT*/{1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0},
      /*ELE*/{1.0, 1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0},
      /*GRS*/{1.0, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5},
      /*ICE*/{1.0, 1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5},
      /*FIT*/{1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 0.5, 2.0, 0.0, 2.0, 2.0, 1.0},
      /*POI*/{1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 0.0},
      /*GND*/{1.0, 1.0, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 2.0},
      /*FLY*/{1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5},
      /*PSY*/{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.0, 0.5},
      /*BUG*/{1.0, 1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5},
      /*RCK*/{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5},
      /*GHO*/{1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5},
      /*DRA*/{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5},
      /*DRK*/{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5},
      /*STE*/{1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5},
        };
    //*****************************************************************************************
    //Establish Pokemon
    const int NUMPOKES = 19;
    Pokemon pokeArr[NUMPOKES] = {   Pokemon("Alakazam", 55, 50, 45, 135, 135, 120, psychic), //00
                                    Pokemon("Articuno", 90, 85, 100, 125, 125, 50, ice, flying), //01
                                    Pokemon("Chansey", 250, 5, 5, 105, 105, 50, normal), //02
                                    Pokemon("Cloyster", 50, 95, 180, 85, 85, 70, water, ice), //03
                                    Pokemon("Dragonite", 91, 134, 95, 100, 100, 80, dragon, flying), //04
                                    Pokemon("Exeggutor", 95, 95, 85, 125, 125, 55, grass, psychic), //05
                                    Pokemon("Gengar", 60, 65, 60, 130, 130, 110, ghost, poison), //06
                                    Pokemon("Golem", 80, 110, 130, 55, 55, 45, rock, ground), //07
                                    Pokemon("Jolteon", 65, 65, 60, 110, 110, 130, electric), //08
                                    Pokemon("Jynx", 65, 50, 35, 95, 95, 95, ice, psychic),  //09
                                    Pokemon("Lapras", 130, 85, 80, 95, 95, 60, ice, water), //10
                                    Pokemon("Persian", 65, 70, 60, 65, 65, 115, normal), //11
                                    Pokemon("Rhydon", 105, 130, 120, 45, 45, 40, ground, rock), //12
                                    Pokemon("Slowbro", 95, 75, 110, 80, 80, 30, psychic, water), //13
                                    Pokemon("Snorlax", 160, 110, 65, 65, 65, 30, normal), //14
                                    Pokemon("Starmie", 60, 75, 85, 100, 100, 115, psychic, water), //15
                                    Pokemon("Tauros", 75, 100, 95, 70, 70, 110, normal), //16
                                    Pokemon("Victreebel", 80, 105, 65, 100, 100, 70, grass, poison), //17
                                    Pokemon("Zapdos", 90, 90, 85, 125, 125, 100, electric, flying) //18
                                };
    //*****************************************************************************************
    //Establish Attacks
        //Initialize attack( names, damage, type, physical?(if special, list 'false')
    const int NUM_MOVES = 36;
    Attack movePool[NUM_MOVES] = {  Attack("Agility", 0, psychic, false, 100), //00
                                    Attack("Amnesia", 0, psychic, false, 100), //01
                                    Attack("Blizzard", 120, ice, false, 90), //02
                                    Attack("Body Slam", 85, normal, true, 100), //03
                                    Attack("Bubble Beam", 65, water, false, 100), //04
                                    Attack("Clamp", 35, water, false, 75), //05
                                    Attack("Confuse Ray", 0, ghost, false, 100), //06
                                    Attack("Counter", 0, fighting, true, 100), //07
                                    Attack("Double Edge", 100, normal, true, 100), //08
                                    Attack("Drill Peck", 80, flying, true, 100), //09
                                    Attack("Earthquake", 100, ground, true, 100), //10
                                    Attack("Explosion", 170, normal, true, 100), //11
                                    Attack("Hyper Beam", 150, normal, true, 90), //12
                                    Attack("Hypnosis", 0, psychic, false, 60), //13
                                    Attack("Ice Beam", 95, ice, false, 100), //14
                                    Attack("Lovely Kiss", 0, psychic, false, 75), //15
                                    Attack("Mega Drain", 40, grass, false, 100), //16
                                    Attack("Mimic", 0, psychic, false, 100), //17
                                    Attack("Pin Missile", 14, bug, true, 85), //18
                                    Attack("Psychic", 90, psychic, false, 100), //19
                                    Attack("Razor Leaf", 55, grass, false, 95), //20
                                    Attack("Recover", 0, normal, false, 100), //21
                                    Attack("Rest", 0, psychic, false, 100), //22
                                    Attack("Rock Slide", 75, rock, true, 90), //23
                                    Attack("Seismic Toss", 0, fighting, true, 100),  //24
                                    Attack("Self-Destruct", 130, normal, true, 100), //26
                                    Attack("Slash", 70, normal, true, 100), //26
                                    Attack("Sleep Powder", 0, grass, false, 75), //27
                                    Attack("Soft Boiled", 0, normal, false, 100), //28
                                    Attack("Stun Spore", 0, grass, false, 75), //29
                                    Attack("Substitute", 0, normal, false, 100), //30
                                    Attack("Surf", 95, water, false, 100), //31
                                    Attack("Swords Dance", 0, normal, false, 100), //32
                                    Attack("Thunderbolt", 95, electric, false, 100), //33
                                    Attack("Thunder Wave", 0, electric, false, 100), //34
                                    Attack("Wrap", 15, normal, true, 85), //35
                                 };
        //Initialize status-changing power of moves
    movePool[0].setRaiseSpe(2); //Agility:  Raises speed by two stages
    //movePool[1] //Amnesia:  Boosts the users special by two stages
    //movePool[2] //Blizzard:  10% chance of freezing opponent
    //movePool[3] //Body Slam:  30% chance to paralyze the target.
    //movePool[4] //Bubble Beam:  10% chance to lower the target's Speed by one stage.
    //movePool[5] //Clamp:  Prevents the opponent from attacking and deals damage to it at the end of every turn for two to five turns
    //movePool[6] //Confuse Ray:  confuses the opponent
    //movePool[7] //Counter:  If hit by a Normal- or Fighting-type attack, deals double the damage taken
    //movePool[8] //Double Edge:  User takes one quarter of damage dealt in recoil.
    //movePool[9] //Drill Peck:  No additional effect
    //movePool[10] //Earthquake:  no additional effect
    //movePool[11] //Explosion:  Faints the user
    //movePool[12] //Hyper Beam:  User cannot move next turn, unless opponent or Substitute was KOed.
    //movePool[13] //Hypnosis:  60% chance of putting target to sleep
    //movePool[14] //Ice Beam:  10% chance to freeze.
    //movePool[15] //Lovely Kiss:  Puts target to sleep 75% of the time
    //movePool[16] //Mega Drain:  leeches 50% of damage dealt to target
    //movePool[17] //Mimic:  Copies a random move the opponent knows
    //movePool[18] //Pin Missile:  Hits two to five times.
        //Checkpoint:  After move is chosen, before move is effected
        //If-Do:  1b) Calls function with move's unique id as an argument.  If it matches, the function returns

        //          a random number between 2 and 5.  If it does not match pin missile (or any other multiple attack
        //          move), then it returns 1.  The return number is stored in a variable.  A for-loop then executes
        //          with the variable holding the returned value as the limiter.  Inside the for-loop is the move effector
        //          for ALL moves.
    //movePool[19] //Psychic:  30% chance of lowering target's special by one stage
    //movePool[20] //Razor Leaf:  High critical hit rate
    //movePool[21] //Recover:  Heals 50% of user's max hp
    //movePool[22] //Rest:  The user goes to sleep for two turns, restoring all HP
        //Checkpoint:   While move is being effected, just before damage-dealing aspect is effected
        //If-Do:        NOTE:  Rest's damage should be 0
        //              NOTE:  Order of Effect for all moves:  [start]damage->status->stat[end] (status vs. stat priority is arbitrary as of me writing this)
        //              1.  Before the damage->status->stat cascade starts, the checkpoint in main should detect Rest
        //              2.  The code triggered by this checkpoint detecting Rest should set the using pokemons hp to 'maxHP'
        //              3.  The normal damage->status->stat cascade should begin executing
        //              4.  When the program gets to the status section, the pokemon will be put to sleep
        //              5.  A counter will be established either in the pokemon's class or in main that keeps the user asleep for 2 turns
        //              6.  Upon waking, the pokemon cannot attack
    //movePool[23] //Rock Slide:  No additional effect
    //movePool[24] //Seismic Toss:  Does damage equal to the opponent's level
        //Checkpoint:   None
        //Note:         Since all pokemon are the same level, this number will just be converted to a fixed base power (50 in this case)
    //movePool[25] //Self-Destruct:  Faints user
        //Checkpoint:   After user's move is effected, before opp.'s move is effected (if user attacks first)
        //If-Do:        Calls function with move's unique id as the argument.  If it matches, the user's pokemon's
        //                hp is set to zero.  Function ends with void return.
        //Note:  I might need to use the whole class object as the argument in order to do the above action.
    //movePool[26] //Slash:  High critical hit rate
    //movePool[27] //Sleep Powder:  75% chance of putting target to sleep
    //movePool[28] //Soft Boiled:  Heals 50% of user's max hp
    //movePool[29] //Stun Spore:  75% chance of paralyzing target
    //movePool[30] //Substitute:  Takes 1/4 the user's max HP to create a Substitute that takes damage for the user.
        //Checkpoint:  (While Being Effected)
        //If-Do:       If (User has more than 25% max health) {[in class] set bool substitute to true;  [in class]set int subHealth to (25% max health);
        //               decrease user's current hp by 25% max health;}
        //Checkpoint:  (While Being Affected)
        //If-Do:       If (Opp.'s bool substitute is true) {redirect damage to substitute; if (damage >= subHealth) {set bool substitute to false;}}
    //movePool[31] //Surf:  No additional effect
    //movePool[32] //Swords Dance:  Boosts user's attack by two stages
    //movePool[33] //Thunderbolt:  10% chance to paralyze
        //Checkpoint:   After user's (damage-dealing) move is effected, before opp.'s move is effected (if user attacks first)
        //If-Do:        Calls function with either (Trainer object & moveIndex) or (move's unique id) as the argument.
        //
    //movePool[34] //Thunder Wave:  100% chance of paralyzing target
    //movePool[35] //Wrap:  Prevents the opponent from attacking and deals damage to it at the end of every turn for two to five turns.
        //Checkpoint:
        //If-Do:    partial trapping moves inflict damage for 2-5 turns. There is a 37.5% chance that they will last 2 turns,
        //            a 37.5% chance that they will last 3 turns, a 12.5% chance that they will last 4 turns, and a 12.5%
        //            chance that they will last 5 turns.
        //Note:     Look up "partial-trapping" for more info on what to do about this move

    //*****************************************************************************************
    //Flesh out Pokemon with moves (according to OU list on smogon)
        pokeArr[0].setAllMoves(movePool[19], movePool[21], movePool[34], movePool[24]); //Alakazam
        pokeArr[1].setAllMoves(movePool[2], movePool[0], movePool[8], movePool[12]); //Articuno
        pokeArr[2].setAllMoves(movePool[14], movePool[28], movePool[34], movePool[33]); //Chansey
        pokeArr[3].setAllMoves(movePool[5], movePool[2], movePool[12], movePool[11]); //Cloyster
        pokeArr[4].setAllMoves(movePool[0], movePool[35], movePool[12], movePool[31]); //Dragonite
        pokeArr[5].setAllMoves(movePool[27], movePool[19], movePool[29], movePool[11]); //Exeggutor
        pokeArr[6].setAllMoves(movePool[13], movePool[11], movePool[33], movePool[16]); //Gengar
        pokeArr[7].setAllMoves(movePool[3], movePool[10], movePool[23], movePool[11]); //Golem
        pokeArr[8].setAllMoves(movePool[33], movePool[34], movePool[18], movePool[3]); //Jolteon
        pokeArr[9].setAllMoves(movePool[15], movePool[2], movePool[19], movePool[17]); //Jynx
        pokeArr[10].setAllMoves(movePool[2], movePool[33], movePool[3], movePool[6]); //Lapras
        pokeArr[11].setAllMoves(movePool[26], movePool[4], movePool[12], movePool[33]); //Persian
        pokeArr[12].setAllMoves(movePool[10], movePool[23], movePool[30], movePool[3]); //Rhydon
        pokeArr[13].setAllMoves(movePool[1], movePool[31], movePool[34], movePool[22]); //Slowbro
        pokeArr[14].setAllMoves(movePool[3], movePool[12], movePool[10], movePool[25]); //Snorlax
        pokeArr[15].setAllMoves(movePool[2], movePool[33], movePool[21], movePool[34]); //Starmie
        pokeArr[16].setAllMoves(movePool[3], movePool[12], movePool[10], movePool[2]); //Tauros
        pokeArr[17].setAllMoves(movePool[20], movePool[32], movePool[27], movePool[12]); //Victreebel
        pokeArr[18].setAllMoves(movePool[33], movePool[9], movePool[34], movePool[0]); //Zapdos

    //*****************************************************************************************
    //Run program
    cout << "Details for Alakazam\n";
    for (int count = 0; count < 4; count++)
    {
        cout << "Attack Increase(" << (count+1) << "):  "
            << pokeArr[0].getRaiseAtt(count) << endl;
        cout << "Attack Decrease(" << (count+1) << "):  "
            << pokeArr[0].getLowerAtt(count) << endl;
        cout << "Defense Increase(" << (count+1) << "):  "
            << pokeArr[0].getRaiseDef(count) << endl;
        cout << "Defense Decrease(" << (count+1) << "):  "
            << pokeArr[0].getLowerDef(count) << endl;
        cout << endl;
    }

    //Delete this after debugging is complete!!!
    Trainer ash;
    Trainer gary;
    selectPokemon(ash, pokeArr, NUMPOKES);
    selectPokemon(gary, pokeArr, NUMPOKES);
    fightMenu(ash, gary);

    return 0;
}

//*********************************************
//Name:  displayTypes
//Purpose:  convert the numerical output of the
//  "type" enumerated data type to a string
//  explicitly stating the type
//Arguments: Pokemon
//Returns:  nothing, but does make cout output.
//*NOTE:  This will be used for the phase when
//  you choose the pokemon and wish to see its
//  type.
//*********************************************
void displayTypes(Pokemon poke)
{
    if (poke.getType1() != null)
    {
        cout << poke.getName() << "'s first type is ";
        cout << typeDisplaySwitch(poke.getType1()) << endl;
    }
    if (poke.getType2() != null)
    {
        cout << poke.getName() << "'s second type is ";
        cout << typeDisplaySwitch(poke.getType2()) << endl;
    }
    cout << endl;
}

string typeDisplaySwitch(PokeType choice)
{
    switch(choice){
    case normal:    return "Normal";
                    break;
    case fire:      return "Fire";
                    break;
    case water:     return "Water";
                    break;
    case electric:  return "Electric";
                    break;
    case grass:     return "Grass";
                    break;
    case ice:       return "Ice";
                    break;
    case fighting:  return "Fighting";
                    break;
    case poison:    return "Poison";
                    break;
    case ground:    return "Ground";
                    break;
    case flying:    return "Flying";
                    break;
    case psychic:   return "Psychic";
                    break;
    case bug:       return "Bug";
                    break;
    case rock:      return "Rock";
                    break;
    case ghost:     return "Ghost";
                    break;
    case dragon:    return "Dragon";
                    break;
    case dark:      return "Dark";
                    break;
    case steel:     return "Steel";
                    break;

    }
}

//Debugged and verified to produce correct output
int checkHp(Trainer& train)
{
    for (int count = 0; count < 6; count++)
    {
        if (train.getPokeHealthArr(count) > 0)
            return 1;
    }
    return 0;
}

void fightMenu(Trainer& user, Trainer& comp)
{
    do
    {
        int userCurrent = user.getCurrentPoke();
        cout << "Ash's current pokemon index is:  ";
        cout << userCurrent << endl;
        int compCurrent = comp.getCurrentPoke();
        cout << "\tBattle Menu\n";
        cout << "a.  Fight\nb.  Item\nc.  Pokemon\n";
        char choice;
        cin.get(choice);
        cin.ignore();
        choice = toupper(choice);
        switch(choice)
        {
        case 'A':
            battlePokes(user, userCurrent, comp, compCurrent);
            break;
        case 'B':
            //function to use item
            break;
        case 'C':
            //function to switch pokemon
            manualSwitch(user);
            break;
        }
        cout << checkHp(user) << " " << checkHp(comp) << endl;
    } while((checkHp(user) != 0) && (checkHp(comp) != 0));
}

void battlePokes(Trainer& user, int userCurr, Trainer& comp, int compCurr)
{
    cout << "user's current pokemon index is " << userCurr << endl;
    //MAKE THE MOVE SELECTION FUNCTION WORK HERE, BEFORE THE MOVE EFFECTORS BELOW
    user.moveSelector(userCurr);

    if (user.getPokeSpeed(userCurr) > comp.getPokeSpeed(compCurr))
    {
        user.battleArr(comp, userCurr, compCurr);
        comp.generateMoveArr(user, userCurr, compCurr);
    }
    else if (user.getPokeSpeed(userCurr) < comp.getPokeSpeed(compCurr))
    {
        comp.generateMoveArr(user, userCurr, compCurr);
        user.battleArr(comp, userCurr, compCurr);
    }
    else if (user.getPokeSpeed(userCurr) == comp.getPokeSpeed(compCurr))
    {
        int movePriority = (rand()%2) + 1;
        if (movePriority == 1)
        {
            user.battleArr(comp, userCurr, compCurr);
            comp.generateMoveArr(user, userCurr, compCurr);
        }
        else if (movePriority == 2)
        {
            comp.generateMoveArr(user, userCurr, compCurr);
            user.battleArr(comp, userCurr, compCurr);
        }
        else if (movePriority > 2 || movePriority < 1)
            cout << "Something is wrong!!!!!\n";
    }
    cout << "Ash's " << user.getPokeName(userCurr) << " has "
            << user.getPokeHealthArr(userCurr) << " hitpoints.\n";
        cout << "Gary's " << comp.getPokeName(compCurr) << " has "
            << comp.getPokeHealthArr(compCurr) << " hitpoints.\n";

    //Display output if pokemon faints
    if (user.getPokeHealthArr(userCurr) <= 0)
    {
        cout << "Ash's pokemon fainted.\n";
        manualSwitch(user);
    }
    if (comp.getPokeHealthArr(compCurr) <= 0)
    {
        cout << "Gary's pokemon fainted.\n";
        if (compCurr < 6)
        {   comp.incrmntCurrPoke();
            cout << "Gary switched in " << comp.getPokeName(compCurr + 1) << endl;
        }
    }
}

void manualSwitch(Trainer& user)
{
    cout << "Which pokemon would you like to switch to?\n";
    for (int count = 0; count < 6; count++)
    {
        //If statement to check if pokemon has health
            cout << count << "  " << user.getPokeName(count) << endl;
    }
    cout << "selection: ";
    int selection;
    cin >> selection;
    cin.ignore();
    user.setCurrentPoke(selection);

}

void selectPokemon(Trainer& user, Pokemon* arr, int numPokes)
{
    //for six times
    //{
        //Select a Pokemon from array
        //Select Attacks from array
        //Add the Attacks to the chosen Pokemon
        //Add chosen pokemon to user's array
    //}

    for (int count = 0; count < 6; count++)
    {
        cout << "Please select your " << (count + 1);
        if (count == 0)
            cout << "st";
        else if (count == 1)
            cout << "nd";
        else if (count == 2)
            cout << "rd";
        else if (count < 6)
            cout << "th";
        cout << " pokemon from the list below:\n";
        for (int count = 0; count < numPokes; count++)
        {
            cout << "No. " << (count + 1) << ":  " <<
                arr[count].getName() << endl;
        }
        cout << "Enter pokemon's number to select it:  ";
        int choice;
        cin >> choice;
        choice -= 1;
        //Make a validation loop here when i finish normal debugging
        user.setPoke(arr[choice], count);
        cout << user.getPokeName(count) << endl;
    }
    cin.ignore();
}
