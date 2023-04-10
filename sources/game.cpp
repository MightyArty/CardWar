#include "game.hpp"
#include <algorithm>
#include <chrono>
#include <random>

using namespace ariel;

// ----------------- This are colloring functions -----------------
// ----------------- And a Welcome function -----------------------
// ----------------- So your terminal would not look so sad -----------------
void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void blue()
{
    printf("\033[1;34m");
}
void green()
{
    printf("\033[1;32m");
}
void purple()
{
    printf("\033[0;35m");
}
void cyan()
{
    printf("\033[1;36m");
}
void reset()
{
    printf("\033[0m");
}

void welcome()
{
    red();
    printf(" $$$$$$$$   $$         $$  $$       \n");
    blue();
    printf("    $$    $$  $$      $$ $$ $$    \n");
    red();
    printf("    $$   $$    $$    $$  $$  $$   \n");
    blue();
    printf("    $$   $$    $$   $$        $$  \n");
    red();
    printf("    $$    $$  $$   $$          $$ \n");
    blue();
    printf("    $$      $$    $$            $$\n");
    reset();
}
// -------------------------------------------------------------

namespace ariel
{
    /**
     * @brief Create a new game
     * @param p1: first player
     * @param p2: second player
     * @return a new Game
     */
    Game::Game(Player &p1, Player &p2)
    {
        this->p1 = &p1;
        this->p2 = &p2;
        welcome();

        createDeck();
        shuffleDeck();
    }

    /**
     * @brief De-Constructor for the game
     */
    Game::~Game() {}

    /**
     * @brief Play one turn between the two players
     */
    void Game::playTurn()
    {
        if (this->p1->getName() == this->p2->getName())
        {
            throw runtime_error("Players names need to be different!");
            return;
        }

        if (gameOver())
        {
            throw runtime_error("the Game is over!");
            return;
        }

        // Draw one card from each player pile
        Card c1 = this->p1->playCard(0);
        Card c2 = this->p2->playCard(0);
        history.push_back(c1);
        history.push_back(c2);
        log.push_back(p1->getName() + " played: " + c1.toString());
        log.push_back(p2->getName() + " played: " + c2.toString());

        // there is a tie, BEGIN WAR!
        if (c1.getValue() == c2.getValue())
        {
            green();
            cout << "There is a tie, begining WAR " << endl;
            reset();
            if (p1->stacksize() == 0 || p2->stacksize() == 0)
            {
                cout << "Not enough cards for: " << p1->getName() << " or " << p2->getName() << endl;
                return;
            }
            Card c1_hidden = p1->playCard(0);
            Card c2_hidden = p2->playCard(0);
            Card c1_visible = p1->playCard(0);
            Card c2_visible = p2->playCard(0);

            history.push_back(c1_hidden);
            history.push_back(c2_hidden);
            history.push_back(c1_visible);
            history.push_back(c2_visible);

            log.push_back(p1->getName() + " placed: " + c1_hidden.toString() + " face down, and " + c1_visible.toString() + " face up");
            log.push_back(p2->getName() + " placed: " + c2_hidden.toString() + " face down, and " + c2_visible.toString() + " face up");

            // if there is another tie, repeat the proccess
            while (c1_visible.getValue() == c2_visible.getValue())
            {
                green();
                cout << "There is a tie, begining WAR " << endl;
                reset();
                if (p1->stacksize() == 0 || p2->stacksize() == 0)
                {
                    cout << "Not enough cards for: " << p1->getName() << " or " << p2->getName() << endl;
                    return;
                }
                c1_hidden = p1->playCard(0);
                c2_hidden = p2->playCard(0);
                c1_visible = p1->playCard(0);
                c2_visible = p2->playCard(0);

                history.push_back(c1_hidden);
                history.push_back(c2_hidden);
                history.push_back(c1_visible);
                history.push_back(c2_visible);

                log.push_back(p1->getName() + " placed: " + c1_hidden.toString() + " face down, and " + c1_visible.toString() + " face up");
                log.push_back(p2->getName() + " placed: " + c2_hidden.toString() + " face down, and " + c2_visible.toString() + " face up");
            }

            // Determine the winner of the tie
            if (c1_visible > c2_visible)
            {
                log.push_back(p1->getName() + " wins the tie round with: " + c1_visible.toString());
                p1->addWonCard(c1);
                p1->addWonCard(c2);
                p1->addWonCard(c1_hidden);
                p1->addWonCard(c2_hidden);
                p1->addWonCard(c1_visible);
                p1->addWonCard(c2_visible);
                p1->increment_wins();
            }
            else
            {
                log.push_back(p2->getName() + " wins the tie round with: " + c2_visible.toString());
                p2->addWonCard(c1);
                p2->addWonCard(c2);
                p2->addWonCard(c1_hidden);
                p2->addWonCard(c2_hidden);
                p2->addWonCard(c1_visible);
                p2->addWonCard(c2_visible);
                p2->increment_wins();
            }
        }
        else
        {
            // Determine the winner of this turn
            if (c1 > c2)
            {
                log.push_back(p1->getName() + " wins the round with: " + c1.toString());
                p1->addWonCard(c1);
                p1->addWonCard(c2);
                p1->increment_wins();
            }
            else
            {
                log.push_back(p2->getName() + " wins the round with: " + c2.toString());
                p2->addWonCard(c1);
                p2->addWonCard(c2);
                p2->increment_wins();
            }
        }
    }

    /**
     * @brief play the game until in ends
     */
    void Game::playAll()
    {
        while (!gameOver())
        {
            playTurn();
        }
    }

    /**
     * @brief Prints the last turn that played
     */
    void Game::printLastTurn()
    {
        if (this->log.empty())
        {
            cout << "No turns played yet. " << endl;
        }
        yellow();
        cout << this->log.back() << endl;
        reset();
    }

    /**
     * @brief Prints the winner
     */
    void Game::printWiner()
    {
        int p1_cards = p1->cardesTaken();
        int p2_cards = p2->cardesTaken();
        if (p1_cards > p2_cards)
        {
            log.push_back(p1->getName() + " is the winner");
        }
        else if (p1_cards < p2_cards)
        {
            log.push_back(p2->getName() + " is the winner");
        }
        else
        {
            log.push_back("The game ends with a tie!");
        }
    }

    /**
     * @brief Prints the log of the game
     */
    void Game::printLog()
    {
        if (log.empty())
        {
            cout << "No moves made yet. " << endl;
        }
        cout << "-----------------------------------------------" << endl;
        red();
        cout << "Game log: " << endl;
        reset();
        purple();
        for (string curr : log)
        {
            cout << curr << endl;
        }
        reset();
    }

    /**
     * @brief Prints the statistics of the game
     */
    void Game::printStats()
    {
        int total = getHistorySize() / 2;

        int p1_wins = p1->getWins();
        int p2_wins = p2->getWins();

        double p1_rate = (double)p1_wins / (double)total;
        double p2_rate = (double)p2_wins / (double)total;

        // int ties = total - abs(p1_wins - p2_wins);
        int ties = 0;
        for (size_t i = 0; i < getHistorySize() - 1; i += 2)
        {
            if (history[i].getValue() == history[i + 1].getValue())
            {
                ties++;
            }
        }
        cout << "-----------------------------------------------" << endl;
        cyan();
        cout << "The game statistics is right here" << endl;
        red();
        cout << "Total turns played: " << total - ties << endl;
        green();
        cout << p1->getName() << " wins: " << p1_wins << " times, and the win rate is: " << p1_rate << "%" << endl;
        yellow();
        cout << p2->getName() << " wins: " << p2_wins << " times, and the win rate is: " << p2_rate << "%" << endl;
        blue();
        cout << "Number of ties: " << ties << endl;
        reset();
    }

    /**
     * @brief get the size of the deck
     * @return the size
     */
    int Game::getDeckSize()
    {
        return this->deck.size();
    }

    /**
     * @brief get the size of history
     * @return size
     */
    int Game::getHistorySize()
    {
        return this->history.size();
    }

    /**
     * @return true/false if the game over or not
     */
    bool Game::gameOver()
    {
        return (p1->stacksize() == 0 || p2->stacksize() == 0);
    }

    /**
     * @brief Creating a new deck with all the types of cards
     */
    void Game::createDeck()
    {
        string types[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string ranks[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        deck.clear();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                Card c(ranks[j], types[i], j + 1);
                deck.push_back(c);
            }
        }
    }

    /**
     * @brief Shuffling the cards and dealing them to the 2 players.
     * Using the Mersenne Twister random number generator (found on the Internet)
     */
    void Game::shuffleDeck()
    {
        mt19937 rng(random_device{}());
        shuffle(deck.begin(), deck.end(), rng);
        for (size_t i = 0; i < 52; i++)
        {
            if (i % 2 == 0)
                p1->takeCard(deck[i]);
            else
                p2->takeCard(deck[i]);
        }
    }
}