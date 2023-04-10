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
        Player *p1;
        Player *p2;
        vector<Card> deck;
        vector<Card> history;
        vector<string> log;

    public:
        Game(Player &p1, Player &p2);
        ~Game();
        void playTurn();
        void playAll();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();

        int getDeckSize();
        int getHistorySize();

        bool gameOver();

        void createDeck();
        void shuffleDeck();
    };
}

#endif