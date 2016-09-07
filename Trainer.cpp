#include "Trainer.h"
#include <string>
#include <iostream>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include "Pokemon.h"
using namespace std;

Trainer::Trainer()
{
    currentPoke = 0;
}

Trainer::~Trainer()
{
    //dtor
}

//*******************************************
//Functions for Trainer-held Pokemon array
void Trainer::setPoke(Pokemon poke)
{
    //This function should function as an
    //auto filler for pokemon array
    //DON'T WORRY ABOUT MAKING THIS FUNCTIONAL UNTIL VERY END, IF EVER
}

void Trainer::setPoke(Pokemon poke, int index)
{
    trainerPokes[index] = poke;
}

Pokemon Trainer::getPoke(int index)
{
    return trainerPokes[index];
}

string Trainer::getPokeName(int index)
{
    return trainerPokes[index].getName();
}

double Trainer::getPokeSpeed(int index)
{
    return trainerPokes[index].getSpeed();
}

double Trainer::getPokeHealthArr(int index)
{
    return trainerPokes[index].getHitpoints();
}

void Trainer::incrmntCurrPoke()
{
    currentPoke++;
}

//The attack argument that is passed to it is the opponents attack
//as are all the other arguments, which means defense doesn't need to
//be passed as an argument
void Trainer::takePokeDmgArr(double damg, double lowerDef, double lowerAtt,
                                double att, int index)
{
    trainerPokes[index].decreaseHP((.44 * (att/trainerPokes[index].getDefense()) * damg) + 2);
    trainerPokes[index].decreaseDef(lowerDef);
    trainerPokes[index].decreaseAtt(lowerAtt);
}

void Trainer::battleArr(Trainer& opponent, int indexUser, int indexComp)
{
    switch(moveSelection)
    {
    case 'A':   opponent.takePokeDmgArr(trainerPokes[indexUser].getMoveDamg(1), trainerPokes[indexUser].getLowerDef(1),
                                         trainerPokes[indexUser].getLowerAtt(1), trainerPokes[indexUser].getAttack(),
                                         indexComp);
                trainerPokes[indexUser].increaseAtt(trainerPokes[indexUser].getRaiseAtt(1));
                trainerPokes[indexUser].increaseDef(trainerPokes[indexUser].getRaiseDef(1));
                break;
    case 'B':   opponent.takePokeDmgArr(trainerPokes[indexUser].getMoveDamg(2), trainerPokes[indexUser].getLowerDef(2),
                                         trainerPokes[indexUser].getLowerAtt(2), trainerPokes[indexUser].getAttack(),
                                         indexComp);
                trainerPokes[indexUser].increaseAtt(trainerPokes[indexUser].getRaiseAtt(2));
                trainerPokes[indexUser].increaseDef(trainerPokes[indexUser].getRaiseDef(2));
                break;
    case 'C':   opponent.takePokeDmgArr(trainerPokes[indexUser].getMoveDamg(3), trainerPokes[indexUser].getLowerDef(3),
                                         trainerPokes[indexUser].getLowerAtt(3), trainerPokes[indexUser].getAttack(),
                                         indexComp);
                trainerPokes[indexUser].increaseAtt(trainerPokes[indexUser].getRaiseAtt(3));
                trainerPokes[indexUser].increaseDef(trainerPokes[indexUser].getRaiseDef(3));
                break;
    case 'D':   opponent.takePokeDmgArr(trainerPokes[indexUser].getMoveDamg(4), trainerPokes[indexUser].getLowerDef(4),
                                         trainerPokes[indexUser].getLowerAtt(4), trainerPokes[indexUser].getAttack(),
                                         indexComp);
                trainerPokes[indexUser].increaseAtt(trainerPokes[indexUser].getRaiseAtt(4));
                trainerPokes[indexUser].increaseDef(trainerPokes[indexUser].getRaiseDef(4));
                break;
    }
}

void Trainer::generateMoveArr(Trainer& opp, int indexUser, int indexComp)
{
    const int NUM_MOVES = 4;

    int moveChoice = (rand()%NUM_MOVES) + 1;

    if (moveChoice > NUM_MOVES || moveChoice < 1)
        cout << "Need to fix random number generator.\n";

    switch(moveChoice)
    {
        case 1: opp.takePokeDmgArr(trainerPokes[indexComp].getMoveDamg(1), trainerPokes[indexComp].getLowerDef(1),
                                    trainerPokes[indexComp].getLowerAtt(1), trainerPokes[indexComp].getAttack(),
                                    indexUser);
                trainerPokes[indexComp].increaseAtt(trainerPokes[indexComp].getRaiseAtt(1));
                trainerPokes[indexComp].increaseDef(trainerPokes[indexComp].getRaiseDef(1));
                cout << "Gary used " << trainerPokes[indexComp].getMoveName(1) << ".\n";
                break;
        case 2: opp.takePokeDmgArr(trainerPokes[indexComp].getMoveDamg(2), trainerPokes[indexComp].getLowerDef(2),
                                    trainerPokes[indexComp].getLowerAtt(2), trainerPokes[indexComp].getAttack(),
                                    indexUser);
                trainerPokes[indexComp].increaseAtt(trainerPokes[indexComp].getRaiseAtt(2));
                trainerPokes[indexComp].increaseDef(trainerPokes[indexComp].getRaiseDef(2));
                cout << "Gary used " << trainerPokes[indexComp].getMoveName(2) << ".\n";
                break;
        case 3: opp.takePokeDmgArr(trainerPokes[indexComp].getMoveDamg(3), trainerPokes[indexComp].getLowerDef(3),
                                    trainerPokes[indexComp].getLowerAtt(3), trainerPokes[indexComp].getAttack(),
                                    indexUser);
                trainerPokes[indexComp].increaseAtt(trainerPokes[indexComp].getRaiseAtt(3));
                trainerPokes[indexComp].increaseDef(trainerPokes[indexComp].getRaiseDef(3));
                cout << "Gary used " << trainerPokes[indexComp].getMoveName(3) << ".\n";
                break;
        case 4: opp.takePokeDmgArr(trainerPokes[indexComp].getMoveDamg(4), trainerPokes[indexComp].getLowerDef(4),
                                    trainerPokes[indexComp].getLowerAtt(4), trainerPokes[indexComp].getAttack(),
                                    indexUser);
                trainerPokes[indexComp].increaseAtt(trainerPokes[indexComp].getRaiseAtt(4));
                trainerPokes[indexComp].increaseDef(trainerPokes[indexComp].getRaiseDef(4));
                cout << "Gary used " << trainerPokes[indexComp].getMoveName(4) << ".\n";
                break;
    }
}

void Trainer::moveSelector(int indexUser)
{
    //NEED TO SWITCH THE .getMoveName1() FUNCTIONS TO .getMoveName(int) FUNCTIONS
    cout << "a.  " << trainerPokes[indexUser].getMoveName(0) << endl;
    cout << "b.  " << trainerPokes[indexUser].getMoveName(1) << endl;
    cout << "c.  " << trainerPokes[indexUser].getMoveName(2) << endl;
    cout << "d.  " << trainerPokes[indexUser].getMoveName(3) << endl;
    cout << ":  ";
    char choice = '\0';
    cin.get(choice);
    cin.ignore();
    choice = toupper(choice);
    while (choice < 'A' || choice > 'D')
    {
        cout << "Please enter a valid letter.\n:  ";
        cin.get(choice);
        choice = toupper(choice);
    }
    moveSelection = choice;
}
