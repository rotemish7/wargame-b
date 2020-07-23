#include "Paramedic.hpp"

Paramedic::Paramedic(uint player_number)
{
    m_player_number = player_number;
    m_hp = MAX_HP;
    m_damage = 0;
    m_type = Type::ParamedicType;
}

uint Paramedic::getMaxHP()
{
    return MAX_HP;
}

void Paramedic::action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location)
{
    int x = location.first;
    int y = location.second;

    for(int i = x - 1; i <= x+1 && i <board.size(); i++)
    {

        if(i < 0) continue;
        int size = board[i].size();
        for(int j = (y - 1); j < size && j <= (y+1); j++)
        {
            if(j < 0) continue;
            if(i == location.first && j == location.second) continue;
            Soldier* curr = board[i][j];
            if(curr != nullptr)
            {
                if(curr->getPlayerNumber() == m_player_number)
                {
                    curr->setHP(curr->getMaxHP());
                }
            }
        }
    }

}

void Paramedic::print()
{
    printf("{(%d) Paramedic,hp: %d}",m_player_number,m_hp);
}