#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "card.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    class Player
    {
    private:
        vector<Card> cards;     // the cards at the begining
        vector<Card> won_cards; // the cards after winning/losing each round
        string name;
        int cards_taken;   // amount of cards the player took
        int stack_size;    // the size of the player stack
        int wining_rounds; // how much rounds the player won

    public:
        Player(string name);
        Player();

        string getName();

        Card playCard(int index);

        void takeCard(Card card);

        void addWonCard(Card card);

        int stacksize();

        int cardesTaken();

        int getWins();

        void increment_wins();
    };
}

#endif