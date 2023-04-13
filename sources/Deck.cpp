#include "Deck.hpp"

Deck::Deck() {
    Card two_clubs("Two", "Clubs");
    Card three_clubs("Three", "Clubs");
    Card four_clubs("Four", "Clubs");
    Card five_clubs("Five", "Clubs");
    Card six_clubs("Six", "Clubs");
    Card seven_clubs("Seven", "Clubs");
    Card eight_clubs("Eight", "Clubs");
    Card nine_clubs("Nine", "Clubs");
    Card ten_clubs("Ten", "Clubs");
    Card jack_clubs("Jack", "Clubs");
    Card queen_clubs("Queen", "Clubs");
    Card king_clubs("King", "Clubs");
    Card ace_clubs("Ace", "Clubs");

    Card two_diamonds("Two", "Diamonds");
    Card three_diamonds("Three", "Diamonds");
    Card four_diamonds("Four", "Diamonds");
    Card five_diamonds("Five", "Diamonds");
    Card six_diamonds("Six", "Diamonds");
    Card seven_diamonds("Seven", "Diamonds");
    Card eight_diamonds("Eight", "Diamonds");
    Card nine_diamonds("Nine", "Diamonds");
    Card ten_diamonds("Ten", "Diamonds");
    Card jack_diamonds("Jack", "Diamonds");
    Card queen_diamonds("Queen", "Diamonds");
    Card king_diamonds("King", "Diamonds");
    Card ace_diamonds("Ace", "Diamonds");

    Card two_hearts("Two", "Hearts");
    Card three_hearts("Three", "Hearts");
    Card four_hearts("Four", "Hearts");
    Card five_hearts("Five", "Hearts");
    Card six_hearts("Six", "Hearts");
    Card seven_hearts("Seven", "Hearts");
    Card eight_hearts("Eight", "Hearts");
    Card nine_hearts("Nine", "Hearts");
    Card ten_hearts("Ten", "Hearts");
    Card jack_hearts("Jack", "Hearts");
    Card queen_hearts("Queen", "Hearts");
    Card king_hearts("King", "Hearts");
    Card ace_hearts("Ace", "Hearts");

    Card two_spades("Two", "Spades");
    Card three_spades("Three", "Spades");
    Card four_spades("Four", "Spades");
    Card five_spades("Five", "Spades");
    Card six_spades("Six", "Spades");
    Card seven_spades("Seven", "Spades");
    Card eight_spades("Eight", "Spades");
    Card nine_spades("Nine", "Spades");
    Card ten_spades("Ten", "Spades");
    Card jack_spades("Jack", "Spades");
    Card queen_spades("Queen", "Spades");
    Card king_spades("King", "Spades");
    Card ace_spades("Ace", "Spades");

    this->deck = {two_clubs, three_clubs, four_clubs, five_clubs, six_clubs, seven_clubs, eight_clubs, nine_clubs, ten_clubs, jack_clubs, queen_clubs, king_clubs, ace_clubs,
    two_diamonds, three_diamonds, four_diamonds, five_diamonds, six_diamonds, seven_diamonds, eight_clubs, nine_diamonds, ten_diamonds, jack_diamonds, queen_diamonds, king_diamonds,
    two_hearts, three_hearts, four_hearts, five_hearts, six_hearts, seven_hearts, eight_hearts, nine_hearts, ten_hearts, jack_hearts, queen_hearts, king_hearts, ace_hearts,
    two_spades, three_spades, four_spades, five_spades, six_spades, seven_spades, eight_spades, nine_spades, ten_spades, jack_spades, queen_spades, king_spades, ace_spades};
}

Deck::Deck(array <Card, game_deck_size> deck) {
    this->deck = deck;
}

Deck::Deck(Deck &deck) {
    this->deck = deck.getDeck();
}

Deck::~Deck() {

}

array <Card, game_deck_size> Deck::getDeck() {
    return this->deck;
}

void Deck::setDeck(array <Card, game_deck_size> deck) {
    this->deck = deck;
}

void Deck::shuffle() {
    Card temp_card;
    size_t rnd_index, rnd = (size_t) rand();

    for (size_t i = 0; i < this->deck.size(); i++) {
        rnd_index = rnd % (sizeof(this->deck) / sizeof(Card));
        temp_card = this->deck.at(i);
        this->deck.at(i) = this->deck.at(rnd_index);
        this->deck.at(rnd_index) = temp_card;
    }
}