#ifndef MAN_H
#define MAN_H
#include "purchase.h"
#include "talk.h"
#include "fight.h"
#include "map.h"
#include "display.h"
void AddAglity(int Increment);
void AddAttack(int Increment);
void AddDefense(int Increment);
void AddExperience(int Increment);
void AddAgility(float Increment);
void AddHealth(int Increment);
void AddMoney(int Increment);
void SetMap(int z,int x,int y,int ID);
void move();
#endif