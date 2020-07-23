#pragma once
#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic
{
    public:
        static const uint MAX_HP = 200; 

        ParamedicCommander(uint player_number);
        ~ParamedicCommander() {};
        
        void action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location);
        uint getMaxHP();
        void print();
};