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
        vector<Card> stack;

    public:
        Player(string name);
        void addCard(Card c);
        void removeCard(Card c);
        string getName() const;
        int stacksize() const;
        int cardesTaken() const;
        bool operator==(const Player &other) const;
        bool operator!=(const Player &other) const;
    };
}

#endif