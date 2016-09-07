#ifndef ATTACK_H
#define ATTACK_H
#include <string>
using namespace std;

enum PokeType { null = -1, normal, fire, water, electric, grass, ice, fighting, poison, ground, flying,
                psychic, bug, rock, ghost, dragon, dark, steel };
class Attack
{
    public:
        Attack();
        virtual ~Attack();
        Attack(string, int, PokeType, bool, int);

        double Getdamage() { return damage; }
        void Setdamage(double val) { damage = val; }

        bool getPhysical() { return physical; }
        void setPhysical(bool val) { physical = val; }

        string getMoveName() { return moveName; }
        void setMoveName(string val) { moveName = val; }

        PokeType getType() { return attackType; }
        void setType(PokeType type) { attackType = type; }

        int getAcc() { return accuracy; }
        void setAcc(int val) { accuracy = val; }
            //Priority:  Some moves have higher priority than others, so some attacks will need to be effected
            //before others purely based on their priority, rather than their speed
        int getPriority() { return priority; }
        void setPriority(int val) { priority = val; }
            //For Physical Att and Def
        void setLowerDef(double val) { lowerDef = val; }
        double getLowerDef() { return lowerDef; }
        void setRaiseDef(double val) { raiseDef = val; }
        double getRaiseDef() { return raiseDef; }
        void setLowerAtt(double val) { lowerAtt = val; }
        double getLowerAtt() { return lowerAtt; }
        void setRaiseAtt(double val) { raiseAtt = val; }
        double getRaiseAtt() { return raiseAtt; }
            //For Special Att and Def
        void setLowerSpD(double val) { lowerSpD = val; }
        double getLowerSpD() { return lowerSpD; }
        void setRaiseSpD(double val) { raiseSpA = val; }
        double getRaiseSpD() { return raiseSpD; }
        void setLowerSpA(double val) { lowerSpA = val; }
        double getLowerSpA() { return lowerSpA; }
        void setRaiseSpA(double val) { raiseSpA = val; }
        double getRaiseSpA() { return raiseSpA; }
            //For Speed
        void setLowerSpe(double val) { lowerSpe = val; }
        double getLowerSpe() { return lowerSpe; }
        void setRaiseSpe(double val) { raiseSpe = val; }
        double getRaiseSpe() { return raiseSpe; }

    protected:
    private:
        string moveName;
        PokeType attackType;
        double damage;
        int accuracy;
        bool physical;
        int priority;
        double lowerDef;
        double raiseDef;
        double lowerAtt;
        double raiseAtt;
        double lowerSpA;
        double raiseSpA;
        double lowerSpD;
        double raiseSpD;
        double lowerSpe;
        double raiseSpe;
};

#endif // ATTACK_H
