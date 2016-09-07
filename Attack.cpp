#include "Attack.h"

Attack::Attack()
{
    Setdamage(0);
    setMoveName("");
    setLowerDef(0);
    setLowerAtt(0);
    setRaiseAtt(0);
    setRaiseDef(0);
    setType(normal);
    priority = 0;
}

Attack::~Attack()
{
    //dtor
}

Attack::Attack(string n, int val, PokeType type, bool phys, int acc)
{
    Setdamage(val);
    setMoveName(n);
    setLowerAtt(0);
    setLowerDef(0);
    setRaiseAtt(0);
    setRaiseDef(0);
    setType(type);
    setPhysical(phys);
    setAcc(acc);
    priority = 0;
}

