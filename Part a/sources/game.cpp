#include "game.hpp"
#include <algorithm>
#include <chrono>
#include <random>

using namespace ariel;

namespace ariel
{
    Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2){

                                                 };

    Game::~Game(){

    };

    void Game::playTurn()
    {
    }

    void Game::playAll()
    {
    }

    void Game::printLastTurn()
    {
    }

    void Game::printWiner()
    {
    }

    void Game::printLog()
    {
    }

    void Game::printStats()
    {
    }

    int Game::getDeckSize()
    {
        return 0;
    };
    int Game::getHistorySize()
    {
        return 0;
    };

    bool Game::gameOver()
    {
        return false;
    }

    bool Game::draw()
    {
        return false;
    }
}