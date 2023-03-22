/**
 * @file Test.cpp
 * @author Tom Shabalin
 * @date 2023-03-20
 */

#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
using namespace ariel;

#include <iostream>
#include <sstream>
#include <fstream>

TEST_CASE("Player")
{
    Player p("Tom");

    SUBCASE("Constructor")
    {
        CHECK(p.getName() == "Tom");
        CHECK(p.stacksize() == 0);
        CHECK(p.cardesTaken() == 0);
    }

    SUBCASE("Taking a card")
    {
        Card c1("Ace", "Hearts", 1);
        p.takeCard(c1);
        CHECK(p.stacksize() == 1);
        CHECK(p.cardesTaken() == 1);

        Card c2 = p.playCard(0);
        CHECK(c2.toString() == "Ace of Hearts");
        CHECK(p.stacksize() == 0);
    }

    SUBCASE("Play a card")
    {
        Card c1("Queen", "Hearts", 12);
        Card c2("5", "Spades", 5);
        p.takeCard(c1);
        p.takeCard(c2);

        Card c3 = p.playCard(1);
        CHECK(c3.toString() == "5 of Spades");
        CHECK(p.stacksize() == 1);

        Card c4 = p.playCard(0);
        CHECK(c4.toString() == "Queen of Hearts");
        CHECK(p.stacksize() == 0);
    }
}

TEST_CASE("Card")
{
    SUBCASE("Constructor")
    {
        Card c("10", "Diamonds", 10);
        CHECK(c.getType() == "Diamonds");
        CHECK(c.getType() == "10");
        CHECK(c.getValue() == 10);
        CHECK(c.toString() == "10 of Diamonds");
    }

    SUBCASE("Equal")
    {
        Card c1("10", "Clubs", 10);
        Card c2("10", "Diamonds", 10);
        CHECK(c1 == c2);
    }
    SUBCASE("Greater then")
    {
        Card c1("10", "Clubs", 10);
        Card c2("King", "Hearts", 13);
        CHECK(c2 > c1);
    }
    SUBCASE("Greater or equal then")
    {
        Card c1("Queen", "Clubs", 12);
        Card c2("Queen", "Hearts", 12);
        CHECK(c2 <= c1);
    }
    SUBCASE("Not equal")
    {
        Card c1("5", "Diamonds", 5);
        Card c2("Jack", "Spades", 11);
        CHECK(c1 != c2);
    }
}

TEST_CASE("Game")
{
    Player p1("Bar");
    Player p2("Yosi");
    Game game(p1, p2);

    SUBCASE("Constructor")
    {
        CHECK(game.getDeckSize() == 52);
        CHECK(game.getHistorySize() == 0);
        CHECK(!game.gameOver());
        CHECK(!game.draw());
    }

    SUBCASE("Shuffle deck")
    {
        game.shuffleDeck();
        }
}
