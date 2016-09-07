#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
{
    name = "";
    hitpoints = 0;
    attack = 0;
    defense = 0;
    spA = 0;
    spD = 0;
}

Pokemon::~Pokemon()
{
    //dtor
}

Pokemon::Pokemon(string n, double hp, double att, double def, double spAt, double spDe, double spd, PokeType type1)
{
    name = n;
    hitpoints = hp;
    attack = att;
    defense = def;
    spA = spAt;
    spD = spDe;
    speed = spd;
    defType1 = type1;
    defType2 = null;
}

Pokemon::Pokemon(string n, double hp, double att, double def, double spAt, double spDe, double spd, PokeType type1, PokeType type2)
{
    name = n;
    hitpoints = hp;
    attack = att;
    defense = def;
    spA = spAt;
    spD = spDe;
    speed = spd;
    defType1 = type1;
    defType2 = type2;
}

void Pokemon::setAllMoves(Attack a1, Attack a2, Attack a3, Attack a4)
{
    attArr[0] = a1;
    attArr[1] = a2;
    attArr[2] = a3;
    attArr[3] = a4;
}

void Pokemon::decreaseHP(double dmg)
{
    if (dmg < 0)
    {
        cout << "damage went negative.\n";
    }
    else
        hitpoints -= dmg;
}

void Pokemon::hitOpp(Pokemon& opponent, double dmg)
{
    opponent.decreaseHP((opponent.getDefense()/attack) * dmg);
}

//************************************************
//Effector Functions for stat-changing moves
void Pokemon::decreaseAtt(double val)
{
    double temp = attack;
    temp -= val;
    if (temp > 0)
    {
        std::cout << getName() << " has " << temp << " attack.\n";
        attack = temp;
    }
    else
    {
        std::cout << getName() << " has " << temp <<
        std::cout << "Attack could not be lowered any further.\n";
    }

}

void Pokemon::increaseAtt(double val)
{
    attack += val;
}

void Pokemon::decreaseDef(double val)
{
    double temp = defense;
    temp -= val;
    if (temp > 0)
        defense = temp;
    else
        std::cout << "Defense could not be decreased anymore.\n";
}

void Pokemon::increaseDef(double val)
{
    defense += val;
}

void Pokemon::decreaseSpA(double val)
{
    double temp = spA;
    temp -= val;
    if (temp > 0)
        spA = temp;
    else
        std::cout << "Special Attack could not be decreased anymore.\n";
}

void Pokemon::increaseSpA(double val)
{
    spA += val;
}

void Pokemon::decreaseSpD(double val)
{
    double temp = spD;
    temp -= val;
    if (temp > 0)
        spD = temp;
    else
        std::cout << "Special Defense could not be decreased anymore.\n";
}

void Pokemon::increaseSpD(double val)
{
    spD += val;
}

void Pokemon::decreaseSpe(double val)
{
    double temp = speed;
    temp -= val;
    if (temp > 0)
        speed = temp;
    else
        std::cout << "Speed could not be decreased anymore.\n";
}

void Pokemon::increaseSpe(double val)
{
    speed += val;
}
//**************************************************
void Pokemon::setMove(Attack att, int index)
{
    attArr[index] = att;
}

void Pokemon::setMoveType(PokeType val, int index)
{
    attArr[index].setType(val);
}

PokeType Pokemon::getMoveType(int index)
{
    return attArr[index].getType();
}

void Pokemon::setMoveDamg(double dmg, int index)
{
    attArr[index].Setdamage(dmg);
}

double Pokemon::getMoveDamg(int index)
{
    return attArr[index].Getdamage();
}

void Pokemon::setMoveName(string n, int index)
{
     attArr[index].setMoveName(n);
}

string Pokemon::getMoveName(int index)
{
    return attArr[index].getMoveName();
}

double Pokemon::getLowerAtt(int index)
{
    return attArr[index].getLowerAtt();
}

double Pokemon::getRaiseAtt(int index)
{
    return attArr[index].getRaiseAtt();
}

double Pokemon::getLowerDef(int index)
{
    return attArr[index].getLowerDef();
}

double Pokemon::getRaiseDef(int index)
{
    return attArr[index].getRaiseDef();
}

double Pokemon::getLowerSpA(int index)
{
    return attArr[index].getLowerSpA();
}

double Pokemon::getRaiseSpA(int index)
{
    return attArr[index].getRaiseSpA();
}

double Pokemon::getLowerSpD(int index)
{
    return attArr[index].getLowerSpD();
}

double Pokemon::getRaiseSpD(int index)
{
    return attArr[index].getRaiseSpD();
}

double Pokemon::getLowerSpe(int index)
{
    return attArr[index].getLowerSpe();
}

double Pokemon::getRaiseSpe(int index)
{
    return attArr[index].getRaiseSpe();
}
//**************************************************
//Everything below will be code going toward consolidating
//the massive waste of code space previously encountered
//by making each function deal with only a certain move
//number



