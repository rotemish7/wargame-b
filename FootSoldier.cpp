#include "FootSoldier.hpp"

FootSoldier::FootSoldier(uint player_number)
{
    m_player_number = player_number;
    m_hp = MAX_HP;
    m_damage = 10;
    m_type = Type::FootSoldierType;
}

uint FootSoldier::getMaxHP()
{
    return MAX_HP;
}

void FootSoldier::action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location)
{
    int x1 = location.first;
    int x2 = location.second;

    Soldier* closest_enemy = nullptr;
    std::pair<int,int> closest_enemy_location;
    double min_dist = board.size()*board.size();

    for(int i = 0 ; i < board.size() ; i ++)
    {
        for(int j = 0 ; j < board[i].size(); j++)
        {
            Soldier * curr = board[i][j];
            if(curr != nullptr)
            {
                if(curr->getPlayerNumber() != m_player_number)
                {
                    double dist = Utils::distance(x1,x2,i,j);
                    if(dist < min_dist)
                    {
                        min_dist = dist;
                        closest_enemy = curr;
                        closest_enemy_location = {i,j};
                    }
                }
            }
        }
    }

    if(closest_enemy != nullptr)
    {
        int new_hp = closest_enemy->getHP() - m_damage;
        closest_enemy->setHP(new_hp);
        if(new_hp <= 0)
        {
            board[closest_enemy_location.first][closest_enemy_location.second] = nullptr;
        }
    }

}

void FootSoldier::print()
{
    printf("{(%d) FootSoldier,hp: %d}",m_player_number,m_hp);
}

