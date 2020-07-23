#pragma once
#include <iostream>
#include <vector>
#include <cmath>


typedef enum Type {
    FootSoldierType,
    FootCommanderType,
    SniperType,
    SniperCommanderType,
    ParamedicType,
    ParamedicCommanderType
} Type;

class Soldier 
{
    protected:
        uint m_player_number;
        Type m_type;
        uint m_hp;
        uint m_damage;
        //std::pair<int,int> m_location;

    public:

        Soldier() {};
        virtual ~Soldier() {};

        virtual void action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) = 0;
        virtual uint getMaxHP() = 0;
        virtual void print() = 0;


       // void setLocation(std::pair<int,int> &location) { m_location = location; }
        Type getType() { return m_type; } 
        uint getPlayerNumber() { return m_player_number; }
        uint getHP() { return m_hp; }
        void setHP(uint hp) { m_hp = hp; }

};

namespace Utils {
    double distance(double x1,double y1,double x2,double y2);
};