/**
 * This class represents a cards game that will be played between two rivals.
 * 
 * @author Osama M. Ghaliah
*/

#ifndef game_hpp
#define game_hpp

#include "Deck.hpp"
#include "player.hpp"
#include "card.hpp"
#include "namespace.hpp"
#include <map>

using namespace std;

class Game {
    private:
        Player &first_player;
        Player &second_player;
        Player current_winner;
        Deck deck;
        int current_round;
        size_t index;
        bool isDone;
        map <int, string> rounds_details;

    public:
        // Non-default constructor.
        Game(Player &first_player, Player &second_player);
        ~Game();
        // Getters for this game's attributes.
        Player get_first_player();
        Player get_second_player();
        Player get_current_winner();
        int get_current_round();
        size_t getIndex();
        bool get_isDone();
        map <int, string> get_rounds_details();
        // Setters for this game's attributes.
        void set_first_player(Player &new_player);
        void set_second_player(Player &new_player);
        void set_current_winner(Player &current_winner);
        void set_current_round(int new_round);
        void setIndex(size_t index);
        void set_isDone(bool isDone);
        // This method let the two players play a one single round.
        void playTurn();
        // This method prints what has happened in the latest round that was played.
        void printLastTurn();
        // This method plays the rounds left so the game ends.
        void playAll();
        // This method prints the name of the winner.
        void printWiner();
        // This method prints whatever happened in each round that was played.
        void printLog();
        // This method prints final summarized-statistics of each player once the game ends.
        void printStats();
};

#endif