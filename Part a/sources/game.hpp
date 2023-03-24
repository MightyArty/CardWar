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
        vector<Card> history;
        vector<string> log;
        int turnCounter;
        string winner;

    public:
        Game(Player &p1, Player &p2);
        ~Game();
        void shuffleDeck();
        void dealCards();
        int getDeckSize();
        int getHistorySize();
        void playTurn();
        void playAll();
        string printLastTurn() const;
        string printWiner() const;
        string printLog() const;
        string printStats() const;
        bool gameOver() const;
        bool draw() const;
    };
}

#endif