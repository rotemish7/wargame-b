#pragma once
#include "Sniper.hpp"

class SniperCommander : public Sniper
{
    public:
        static const uint MAX_HP = 120; 

        SniperCommander(uint player_number);
        ~SniperCommander() {};

        void action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
        uint getMaxHP();
        void print();
};