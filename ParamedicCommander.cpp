#include "ParamedicCommander.hpp"

ParamedicCommander::ParamedicCommander(uint player_number)
{
    m_player_number = player_number;
    m_hp = MAX_HP;
    m_damage = 0;
    m_type = Type::ParamedicCommanderType;
}

uint ParamedicCommander::getMaxHP()
{
    return MAX_HP;
}

void ParamedicCommander::action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location)
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

    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0 ; j <board[i].size(); j++)
        {
            Soldier* curr = board[i][j];
            if (curr != nullptr) 
            {
                if(curr->getPlayerNumber() == m_player_number)
                {
                    if(curr->getType() == Type::ParamedicType)
                    {

                        std::pair<int,int> loc = {i,j};
                        curr->action(board,loc);
                    }
                }
            }
        }
    }

}

// For Debugging use:
void ParamedicCommander::print()
{
    printf("{(%d) ParamedicCommander,hp: %d}",m_player_number,m_hp);
}