#pragma once
#include "FootSoldier.hpp"

class FootCommander : public FootSoldier
{
    public:
        static const uint MAX_HP = 150; 

        FootCommander(uint player_number);
        void action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
        uint getMaxHP();

        void print();
};