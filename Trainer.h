#ifndef TRAINER_H
#define TRAINER_H
#include "Pokemon.h"
#include <string>

class Trainer
{

    public:
        Trainer();
        virtual ~Trainer();
        void setPoke(Pokemon);
        void setPoke(Pokemon, int);
        Pokemon getPoke(int);
        string getPokeName(int);
        void takePokeDmgArr(double, double, double, double, int);
            //User and Computer Move Selection
        void battleArr(Trainer&, int, int);
        void generateMoveArr(Trainer&, int, int);
            //Accessors for pokemon data (for main function)
        double getPokeSpeed(int);
        double getPokeHealthArr(int);
            //Functions dealing with ordering pokemon in battle
        void setCurrentPoke(int poke) { currentPoke = poke; }
        int getCurrentPoke() { return currentPoke; }
        void incrmntCurrPoke();
        //NEW FUNCTION(s) TO DEAL WITH PREMATURE DISPLAY OF GARY'S MOVE
        //STRATEGY:  MAKE TWO SEPARATE FUNCTIONS, ONE FOR CHOOSING
        //THE USERS MOVE, A SECOND FOR EFFECTING IT
        void moveSelector(int);

    protected:
    private:
        //Compiler won't let me make a const int equal to 6
        // and use that as array size const variable
        Pokemon trainerPokes[6];
        int currentPoke;
        char moveSelection;
};

#endif // TRAINER_H
