#include "card.hpp"
#include "game.hpp"
using namespace std;

Card::Card() {
    this->rank = "";
    this->symbol = "";
    this->revealed = false;
}

Card::Card(Card &card) {
    this->rank = card.rank;
    this->symbol = card.symbol;
    this->revealed = false;
}

Card::Card(string rank, string symbol) {
    this->rank = rank;
    this->symbol = symbol;
    this->revealed = false;
}

Card::~Card() {

}

string Card::getRank() {
    return this->rank;
}

string Card::getSymbol() {
    return this->symbol;
}

bool Card::getRevealed() {
    return this->revealed;
}

void Card::setRank(string new_rank) {
    this->rank = new_rank;
}

void Card::setSymbol(string new_symbol) {
    this->symbol = new_symbol;
}

void Card::setRevealed(bool revealed) {
    this->revealed = revealed;
}

string Card::description() {
    return "'Rank: " + this->rank + " | Symbol:" + this->symbol + "'";
}