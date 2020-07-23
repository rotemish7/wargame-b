#pragma once
#include "Soldier.hpp"

class FootSoldier : public Soldier
{
    public:
        static const uint MAX_HP = 100; 
        
        FootSoldier() {};
        virtual ~FootSoldier() {};

        FootSoldier(uint player_number);
        virtual void action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
        virtual uint getMaxHP();
        virtual void print();
};