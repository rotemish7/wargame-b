#include "Sniper.hpp"

Sniper::Sniper(uint player_number)
{
    m_player_number = player_number;
    m_hp = MAX_HP;
    m_damage = 50;
    m_type = Type::SniperType;
}

uint Sniper::getMaxHP()
{
    return MAX_HP;
}


void Sniper::action(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location)
{
    int x1 = location.first;
    int x2 = location.second;

    Soldier* strongest_enemy = nullptr;
    uint strongest_enemy_hp = 0;
    std::pair<int,int> strongest_enemy_location;

    for(int i = 0 ; i < board.size() ; i ++)
    {
        for(int j = 0 ; j < board[i].size(); j++)
        {
            Soldier* curr = board[i][j];
            if(curr != nullptr)
            {
                if(curr->getPlayerNumber() != m_player_number)
                {
                    Soldier* curr = board[i][j];
                    uint curr_hp = curr->getHP();
                    if(curr_hp > strongest_enemy_hp)
                    {
                        strongest_enemy_hp = curr_hp;
                        strongest_enemy = curr;
                        strongest_enemy_location = {i,j};
                    }
                }
            }
        }
    }

    if(strongest_enemy != nullptr)
    {
        int new_hp = strongest_enemy->getHP() - m_damage;
        strongest_enemy->setHP(new_hp);
        if(new_hp <= 0)
        {
            board[strongest_enemy_location.first][strongest_enemy_location.second] = nullptr;
        }
    }
}

void Sniper::print()
{
    printf("{(%d) Sniper,hp: %d}",m_player_number,m_hp);
}