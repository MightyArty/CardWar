#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <card.hpp>
#include <vector>
using namespace std;

namespace ariel
{
    class Player
    {
    private:
        string name;
        vector<Card> Cards;

    public:
        Player(string name);
        ~Player();
        string getName() const;
        Card playCard(int index);
        void takeCard(Card c);
        int stacksize() const;
        int cardesTaken() const;
    };
}

#endif