# Card War

![](https://upload.wikimedia.org/wikipedia/commons/1/13/Wojna_gra_karciana.jpg)
## Game Overview

In this assigment we will implement the card war game for 2 players.

There is a normal deck of cards with 52 cards, at the beginning of the game the deck is shuffled (randomly) and divided equally between the two players.

On each turn the players draw one card from the top of their pile and the player with the highest card takes both cards to him (2 wins Ace, but Ace wins all other cards).

If the players have drawn two identical cards then they place once card face down and a lesser card on top of it.

The high card player takes all six card. If there is a tie again, continue with a closed card followed by an open card until on of the players wins.

The turn continues intil one of the players takes the pot or runs out of cards. If you run out of cards while breaking a tie, each player takes the cards he threw (divide the pot half and half).

The game continues until the players run out of card and the winner is the player who took the most cards.

## How to run
```bash
# Clone the repository
$ git clone "https://github.com/MightyArty/CardWar.git"
# Open terminal on linux
$ Run "make demo && ./demo"
$ Run "make test && ./test"
$ Run "bash ./grade"