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
        CHECK(p.cardesTaken() == 0);

        Card c2 = p.playCard(0);
        CHECK(c2.toString() == "Ace of Hearts");
        CHECK(p.stacksize() == 0);
    }

    SUBCASE("Play a card")
    {
        Card c1("Queen", "Hearts", 12);
        Card c2("Five", "Spades", 5);
        p.takeCard(c1);
        p.takeCard(c2);

        Card c3 = p.playCard(1);
        CHECK(c3.toString() == "Five of Spades");
        CHECK(p.stacksize() == 1);

        Card c4 = p.playCard(0);
        CHECK(c4.toString() == "Queen of Hearts");
        CHECK(p.stacksize() == 0);
    }

    SUBCASE("Initialize player with no name")
    {
        CHECK_THROWS(new Player(""));
    }
}

TEST_CASE("Card")
{
    Card c1("Ace", "Hearts", 1);
    Card c2("Two", "Clubs", 2);
    Card c3("Jack", "Diamonds", 11);
    Card c4("King", "Spades", 13);
    Card c5("Ace", "Hearts", 1);

    SUBCASE("Constructor")
    {
        Card c("Ten", "Diamonds", 10);
        CHECK(c.getType() == "Diamonds");
        CHECK(c.getRank() == "Ten");
        CHECK(c.getValue() == 10);
        CHECK(c.toString() == "Ten of Diamonds");
    }

    SUBCASE("getRank")
    {
        CHECK(c1.getRank() == "Ace");
        CHECK(c2.getRank() == "Two");
        CHECK(c3.getRank() == "Jack");
        CHECK(c4.getRank() == "King");
    }

    SUBCASE("getType")
    {
        CHECK(c1.getType() == "Hearts");
        CHECK(c2.getType() == "Clubs");
        CHECK(c3.getType() == "Diamonds");
        CHECK(c4.getType() == "Spades");
    }

    SUBCASE("getValue")
    {
        CHECK(c1.getValue() == 1);
        CHECK(c2.getValue() == 2);
        CHECK(c3.getValue() == 11);
        CHECK(c4.getValue() == 13);
    }

    SUBCASE("toString")
    {
        CHECK(c1.toString() == "Ace of Hearts");
        CHECK(c2.toString() == "Two of Clubs");
        CHECK(c3.toString() == "Jack of Diamonds");
        CHECK(c4.toString() == "King of Spades");
    }

    SUBCASE("Testing comparison operators of two cards")
    {
        CHECK(c1 < c2);
        CHECK(c1 <= c3);
        CHECK(c1 == c5);
        CHECK(c1 != c4);
        CHECK(c4 > c2);
        CHECK(c4 >= c3);
    }
}

TEST_CASE("Game")
{

    SUBCASE("Constructor")
    {
        Player p1("Bar");
        Player p2("Yosi");
        Game game(p1, p2);

        CHECK(game.getDeckSize() == 52);
        CHECK(game.getHistorySize() == 0);
        CHECK(!game.gameOver());
        CHECK(!game.draw());
    }

    SUBCASE("One turn play")
    {
        Player p1("Bar");
        Player p2("Yosi");
        Game game(p1, p2);

        game.playTurn();
        CHECK(game.getDeckSize() == 51);
        CHECK(game.getHistorySize() == 1);
    }

    SUBCASE("stacksize and cardesTaken methods")
    {
        Player p1("Bar");
        Player p2("Yosi");
        Game game(p1, p2);

        for (int i = 0; i < 10; i++)
        {
            game.playTurn();
        }
        CHECK(p1.stacksize() + p2.stacksize() == 42);
        CHECK(p1.cardesTaken() + p2.cardesTaken() == 10);
    }

    SUBCASE("playAll function")
    {
        Player p1("Bar");
        Player p2("Yosi");
        Game game(p1, p2);

        game.playAll();
        CHECK(game.getDeckSize() == 0);
        CHECK(game.getHistorySize() == 52);
    }

    SUBCASE("printWinner function")
    {
        Player p1("Bar");
        Player p2("Yosi");
        Game game(p1, p2);

        game.playAll();
        game.printWiner();
        CHECK(game.draw() == false);
    }

    SUBCASE("Create game with two same players")
    {
        Player p1("Tom");
        Player p2("Tom");
        CHECK_THROWS(new Game(p1, p2));
    }

    SUBCASE("Create game where one player has no name")
    {
        Player p1("Tom");
        Player p2("");
        CHECK_THROWS(new Game(p1, p2));
    }
}
