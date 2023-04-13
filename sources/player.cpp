#include "player.hpp"

Player::Player() {
    this->name = "";
    this->current_stack_size = 0;
    this->cards_won = 0;
}

Player::Player(string name) {
    this->name = name;
    this->current_stack_size = 0;
    this->cards_won = 0;
}

Player::Player(Player &player) {
    this->name = player.name;
    this->current_stack_size = player.stacksize();
    this->cards_won = player.cards_won;
    this->cards_stack = player.cards_stack;
}

Player::~Player() {
    
}

int Player::stacksize() {
    return this->current_stack_size;
}

void Player::set_current_stack_size(int size) {
    this->current_stack_size = size;
}

int Player::cardesTaken() {
    return this->cards_won;
}

void Player::set_cards_won(int cards_won) {
    this->cards_won = cards_won;
}

string Player::getName() {
    return this->name;
}

void Player::setName(string name) {
    this->name = name;
}

Card Player::get_current_card() {
    return this->current_card;
}

void Player::set_current_card(Card new_card) {
    this->current_card = new_card;
}

array <Card, player_deck_size> Player::get_cards_stack() {
    return this->cards_stack;
}

void Player::set_cards_stack(array <Card, player_deck_size> cards_stack) {
    this->cards_stack = cards_stack;
}