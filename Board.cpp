#include "Board.hpp"
using namespace WarGame;

double Utils::distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

Soldier*& Board::operator[](std::pair<int,int> location)
{
    return board[location.first][location.second];   
}

Soldier* Board::operator[](std::pair<int,int> location) const
{
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
{
    if(source.first < 0 || source.second < 0 || source.first >= board.size() || source.second >= board.size())
    {
        throw std::invalid_argument("Invalid source location!");
    }

    Soldier* soldier_chose = board[source.first][source.second];
    if(soldier_chose == nullptr)
    {
        throw std::invalid_argument("There is no Soldier on source location!");
    }

    if(soldier_chose->getPlayerNumber() != player_number)
    {
        throw std::invalid_argument("This is not your Soldier!");
    }

    std::pair<int,int> target = source;
    switch (direction)
    {
    case MoveDIR::Up:
        target.first = source.first+1;
        break;
    case MoveDIR::Down:
        target.first = source.first-1;
        break;
    case MoveDIR::Left:
        target.second = source.second-1;
        break;
    case MoveDIR::Right:
        target.second = source.second+1;
        break;

    default:
        break;
    }

    if(target.first < 0 || target.second < 0 || target.first >= board.size() || target.second >= board[target.first].size())
    {
        throw std::invalid_argument("Invalid Move!");
    }

    if(board[target.first][target.second] != nullptr)
    {
        throw std::invalid_argument("There is already a Soldier in target location!");
    }

    board[target.first][target.second] = soldier_chose;
    board[source.first][source.second] = nullptr;
    
    soldier_chose->action(board,target);

}

bool Board::has_soldiers(uint player_number) const
{
    for(int i = 0; i<board.size(); i++)
    {
        for(int j = 0 ; j < board[i].size() ; j++)
        {
            if(board[i][j] != nullptr)
            {
                if(board[i][j]->getPlayerNumber() == player_number)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Board::print()
{
    for(int i = 0; i<board.size(); i++)
    {
        for(int j = 0 ; j < board[i].size() ; j++)
        {
            printf("[(%d,%d)",i,j);
            if(board[i][j] != nullptr)
            {
                board[i][j]->print();
            } else {
                printf("EMPTY SPOT");
            }
            printf("]");
        }
        printf("\n");
    } 
}