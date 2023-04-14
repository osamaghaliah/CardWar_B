#include "player.hpp"

using namespace std;

Player::Player(string name): playerDeck{}, playerWinningDeck{} {
    this->name = name; 
    this->cardsWon = 0;
    this->roundsWon = 0;
}

vector <Card> Player::getPlayerDeck() {
    return this->playerDeck;
}

vector <Card> Player::getPlayerWinningDeck() {
    return this->playerWinningDeck;
}

int Player::getRoundsWon() {
    return this->roundsWon;
}

void Player::setRoundsWon(int roundsWon) {
    this->roundsWon = roundsWon;
}

string Player::getName() {
    return this->name;
}

int Player::stacksize() {
    return this->playerDeck.size();
}

int Player::cardesTaken() {
    return this->playerWinningDeck.size();
}

void Player::putOnPlayerDeck(Card card) {
    this->playerDeck.push_back(card);
}

void Player::putOnPlayerWinningDeck(Card card) {
    this->playerWinningDeck.push_back(card);
}

Card Player::pullFromTopOfDeck() {
    if (this->stacksize() == 0) {
        throw logic_error(this->name + " has ran out of cards.");
    }

    else {
        Card top = this->playerDeck[0];
        this->playerDeck.erase(this->playerDeck.begin());
        
        return top;
    }
}


