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
    Player player("Tom");

    SUBCASE("Player name")
    {
        CHECK(player.getName() == "Tom");
        player.setName("Bar");
        CHECK(player.getName() == "Bar");
    }

    SUBCASE("Add card to hand")
    {
        Card c1("ACE", "HEARTS", true);
        player.addCard(c1);
        CHECK(player.stacksize() == 1);
    }

    SUBCASE("Play card")
    {
        Card c1("TEN", "SPADES", true);
        Card c2("ACE", "CLUBS", true);
        player.addCard(c1);
        Card player_card = player.playCard(c1);
        CHECK(player_card == c1);
    }
}

TEST_CASE("Card")
{
    SUBCASE("Equal")
    {
        Card c1("TEN", "CLUBS", true);
        Card c2("TEN", "CLUBS", true);
        CHECK(c1 == c2);
    }
    SUBCASE("Greater then")
    {
        Card c1("TEN", "CLUBS", true);
        Card c2("KING", "HEARTS", true);
        CHECK(c2 > c1);
    }
    SUBCASE("Smaller then")
    {
        Card c1("TWO", "CLUBS", true);
        Card c2("ACE", "HEARTS", true);
        CHECK(c1 < c2);
    }
    SUBCASE("Greater or equal then")
    {
        Card c1("QUEEN", "CLUBS", true);
        Card c2("QUEEN", "HEARTS", true);
        CHECK(c2 <= c1);
    }
}

TEST_CASE("Game")
{
    Player p1("Tom");
    Player p2("Neta");
    Game game(p1,p2);

    SUBCASE("Shuffle")
    {
        game.shuffleDeck();
    }
}
