#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <player.hpp>
#include <card.hpp>

namespace ariel
{
    class Game
    {
    private:
        Player player1;
        Player player2;
        vector<Card> deck;
        vector<Card> cardsPlayed;
        vector<string> log;
        int numOfDraws;
        bool gameOver;

    public:
        Game(Player &p1, Player &p2);
        void shuffleDeck();
        void dealCards();
        Card getCard();
        void playTurn();
        void playAll();
        void printLastTurn() const;
        void printWiner() const;
        void printLog() const;
        void printStats() const;
    };
}

#endif