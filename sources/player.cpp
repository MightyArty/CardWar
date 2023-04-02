#include "player.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace ariel;

namespace ariel{

    Player::Player(string name): name(name), cards_taken(0) {};


    int Player::stacksize(){
        return cards.size();
    }

    int Player::cardesTaken(){
        return this->cards_taken;
    }

    string Player::getName(){
        return name;
    }

    Card Player::playCard(int index){
        Card c = cards[static_cast<vector<Card>::size_type>(index)];
        return c;
    }

    void Player::takeCard(Card c){
        cards.push_back(c);
    }
}