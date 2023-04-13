#include "player.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace ariel;

namespace ariel
{

    /**
     * @brief Main Constructor
     * @return a new Player
     */
    Player::Player(string name)
    {
        this->name = name;
        this->stack_size = 0;
        this->cards_taken = 0;
        this->wining_rounds = 0;
        this->cards.clear();
    }

    /**
     * @brief Default Constructor
     * @return a new Player
     */
    Player::Player()
    {
        this->name = "";
        this->stack_size = 0;
        this->cards_taken = 0;
        this->wining_rounds = 0;
        this->cards.clear();
    }

    /**
     * @brief De-Constructor
     */
    // Player::~Player() {}

    /**
     * @return the card amount of the player
     */
    int Player::stacksize()
    {
        return this->stack_size;
    }

    /**
     * @return the wins of the particular player
     */
    int Player::getWins()
    {
        return this->wining_rounds;
    }

    /**
     * @brief incrementing the wins for particular player
     */
    void Player::increment_wins()
    {
        this->wining_rounds++;
    }

    /**
     * @return cards that the player took
     */
    int Player::cardesTaken()
    {
        return this->cards_taken;
    }

    /**
     * @return the name of the current player
     */
    string Player::getName()
    {
        return this->name;
    }

    /**
     * @brief plays a signle card
     * @param index of the card at the player stack
     * @return the played card
     */
    Card Player::playCard(int index)
    {
        Card c = cards[static_cast<vector<Card>::size_type>(index)];
        cards.erase(cards.begin() + index);
        this->stack_size--;
        return c;
    }

    /**
     * @brief when dealing the cards, this function is applied
     * @param c  the card you want to take
     */
    void Player::takeCard(Card c)
    {
        cards.push_back(c);
        this->stack_size++;
    }

    /**
     * @brief when winning a round, this function is applied
     * @param c  the card you want to take
     */
    void Player::addWonCard(Card c)
    {
        won_cards.push_back(c);
        this->cards_taken++;
    }
}