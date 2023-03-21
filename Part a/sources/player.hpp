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
        vector<Card> hand;

    public:
        Player(const string name);
        string getName() const;
        Player setName(const string name);
        void addCard(const Card& card);
        Card playCard(const Card&);
        int stacksize() const;
        int cardesTaken() const;
    };
}

#endif