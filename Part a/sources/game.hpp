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
        vector<Card> drawPile;
        vector<Card> discardPile;
        vector<string> log;
        int turn;

        void createDeck();
        void shuffleDeck();
        void dealCards();
        void dealOneCard(Player &p);
        void playRound();
        void roundWinner(Card c1, Card c2, Player &p1, Player &p2);

    public:
        Game(Player &p1, Player &p2);
        void playTurn();
        void playAll();
        void printLastTurn() const;
        void printWiner() const;
        void printLog() const;
        void printStats() const;
    };
}

#endif