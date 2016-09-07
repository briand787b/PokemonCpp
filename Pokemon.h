#ifndef POKEMON_H
#define POKEMON_H
#include "Attack.h"
#include <string>
using namespace std;

enum Attack::PokeType { null = 0, normal, fire, water, electric, grass, ice, fighting, poison, ground, flying,
                psychic, bug, rock, ghost, dragon, dark, steel };

class Pokemon
{
    public:
        Pokemon();
        virtual ~Pokemon();
        Pokemon(string, double, double, double, double, double, double, PokeType);
        Pokemon(string, double, double, double, double, double, double, PokeType, PokeType);
        void setAllMoves(Attack, Attack, Attack, Attack);
        double getHitpoints() { return hitpoints; }
        void setHitpoints(double val) { hitpoints = val; }
        double getAttack() { return attack; }
        void setAttack(double val) { attack = val; }
        double getDefense() { return defense; }
        void setDefense(double val) { defense = val; }
        void setName(string n){ name = n; }
        string getName(){ return name; }
        void decreaseHP(double dmg);
        void hitOpp(Pokemon&, double);
        void setType1(PokeType type1) { defType1 = type1; }
        PokeType getType1() { return defType1; }
        void setType2(PokeType type2) { defType2 = type2; }
        PokeType getType2() { return defType2; }
        void setSpeed(double spd) { speed = spd; }
        double getSpeed() { return speed; }

        void setMove(Attack, int);

        void setMoveType(PokeType, int);
        PokeType getMoveType(int);

        void setMoveDamg(double, int);
        double getMoveDamg(int);

        void setMoveName(string, int);
        string getMoveName(int);

        double getLowerAtt(int);
        double getRaiseAtt(int);

        double getLowerDef(int);
        double getRaiseDef(int);

        double getLowerSpA(int);
        double getRaiseSpA(int);

        double getLowerSpD(int);
        double getRaiseSpD(int);

        double getLowerSpe(int);
        double getRaiseSpe(int);
        //***************************************************

        //functions for effecting stat-changing moves
            //Physical Attack and Defense
        void decreaseAtt(double);
        void decreaseDef(double);
        void increaseAtt(double);
        void increaseDef(double);
            //Special Attack and Defense
        void decreaseSpA(double);
        void decreaseSpD(double);
        void increaseSpA(double);
        void increaseSpD(double);
            //Speed
        void decreaseSpe(double);
        void increaseSpe(double);

        //****************************************************
        //functions for adjusting statuses
            //setters
        void setFrozen(bool val) { frozen = val; }
        void setParalysis(bool val) { paralyzed = val; }
        void setSleep(bool val) { asleep = val; }
        void setPoison(bool val) { poisoned = val; }
        void setConfusion(bool val) { confused = val; }
            //getters
        bool getFrozen() { return frozen; }
        bool getParalysis() { return paralyzed; }
        bool getSleep() { return asleep; }
        bool getPoison() { return poisoned; }
        bool getConfusion() { return confused; }
            //
    protected:
    private:
        string name;
        PokeType defType1;
        PokeType defType2;
        double hitpoints;
        double attack;
        double defense;
        double speed;
        double spA;
        double spD;
        Attack attArr[4];
        bool frozen;
        bool paralyzed;
        bool asleep;
        bool poisoned;
        bool confused;
};

#endif // POKEMON_H
