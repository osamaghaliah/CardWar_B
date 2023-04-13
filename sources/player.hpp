/**
 * This class represents a card player.
 * 
 * @author Osama M. Ghaliah
*/

#ifndef player_hpp
#define player_hpp

#include <iostream>
#include <vector>
#include "card.hpp"
using namespace std;

class Player {
    private:
        string name;
        int current_stack_size;
        int cards_won;
        Card current_card;
        vector <Card> cards_stack;

    public:
        // No-default contructor.
        Player(string name);
        // Default constructor.
        Player();
        // Copy constructor.
        Player(Player &player);
        // This method returns how many cards this player has won so far.
        int cardesTaken();
        // This method is a setter for the cards that this player has won.
        void set_cards_won(int cards_won);
        // This method returns how mnay cards are left in this player's stack.
        int stacksize();
        // This method updates the amount of cards of this player's stack.
        void set_current_stack_size(int size);
        // This is a getter for this player's name.
        string getName();
        // This is a setter for this player's name.
        void setName(string name);
        // This is a getter for this player's current card that was pulled out from his stack.
        Card get_current_card();
        // This is a setter for this player's current card that was pulled out from his stack.
        void set_current_card(Card new_card);
        // This is a getter for this player's cards stack.
        vector <Card> get_cards_stack();
        // This is a setter for this player's cards stack.
        void set_cards_stack(vector <Card> cards_stack);
        // This is a getter for this player's cards stack.
};

#endif