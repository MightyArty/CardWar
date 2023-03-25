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
        vector<Card> cards;
        string name;
        int cards_taken;
        int stack_size;
        

    public:
        Player(string name);
        Player();
        string getName();
        Card playCard(int index);
        void takeCard(Card c);
        int stacksize();
        int cardesTaken();
    };
}

#endif