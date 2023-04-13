#include "game.hpp"
#include <algorithm>
#include <random>
using namespace std;
using namespace ariel;

Game::Game(): first_player(), second_player(), current_winner() {
    this->current_round = 0;
    this->index = 0;
    this->isDone = true;
    
    this->all_cards = {two_clubs, three_clubs, four_clubs, five_clubs, six_clubs, seven_clubs, eight_clubs, nine_clubs, ten_clubs, jack_clubs, queen_clubs, king_clubs, ace_clubs,
    two_diamonds, three_diamonds, four_diamonds, five_diamonds, six_diamonds, seven_diamonds, eight_clubs, nine_diamonds, ten_diamonds, jack_diamonds, queen_diamonds, king_diamonds,
    two_hearts, three_hearts, four_hearts, five_hearts, six_hearts, seven_hearts, eight_hearts, nine_hearts, ten_hearts, jack_hearts, queen_hearts, king_hearts, ace_hearts,
    two_spades, three_spades, four_spades, five_spades, six_spades, seven_spades, eight_spades, nine_spades, ten_spades, jack_spades, queen_spades, king_spades, ace_spades};
    
    shuffle(all_cards.begin(), all_cards.end(), default_random_engine());
    this->first_player.set_cards_stack({all_cards.begin(), all_cards.begin() + 25});
    this->second_player.set_cards_stack({all_cards.begin() + 26, all_cards.end()});
}

Game::Game(Player &first_player, Player &second_player): first_player(first_player), second_player(second_player), current_winner() {
    this->first_player.set_current_stack_size(26);
    this->second_player.set_current_stack_size(26);
    this->current_round = 0;
    this->index = 0;
    this->isDone = true;

    this->all_cards = {two_clubs, three_clubs, four_clubs, five_clubs, six_clubs, seven_clubs, eight_clubs, nine_clubs, ten_clubs, jack_clubs, queen_clubs, king_clubs, ace_clubs,
    two_diamonds, three_diamonds, four_diamonds, five_diamonds, six_diamonds, seven_diamonds, eight_clubs, nine_diamonds, ten_diamonds, jack_diamonds, queen_diamonds, king_diamonds,
    two_hearts, three_hearts, four_hearts, five_hearts, six_hearts, seven_hearts, eight_hearts, nine_hearts, ten_hearts, jack_hearts, queen_hearts, king_hearts, ace_hearts,
    two_spades, three_spades, four_spades, five_spades, six_spades, seven_spades, eight_spades, nine_spades, ten_spades, jack_spades, queen_spades, king_spades, ace_spades};
    
    shuffle(begin(all_cards), end(all_cards), default_random_engine());

    this->first_player.set_cards_stack({all_cards.begin(), all_cards.begin() + 25});
    this->second_player.set_cards_stack({all_cards.begin() + 26, all_cards.end()});
}

Game::Game(Game &game) {
    this->first_player = game.first_player;
    this->second_player = game.second_player;
    this->current_winner = game.current_winner;
    this->current_round = game.current_round;
    this->index = game.index;
    this->isDone = game.isDone;
    this->rounds_details = game.rounds_details;
    this->all_cards = game.all_cards;
}

Player Game::get_first_player() {
    return this->first_player;
}

Player Game::get_second_player() {
    return this->second_player;
}

Player Game::get_current_winner() {
    return this->current_winner;
}

int Game::get_current_round() {
    return this->current_round;
}

size_t Game::getIndex() {
    return this->index;
}

bool Game::get_isDone() {
    return this->isDone;
}

void Game::set_first_player(Player new_player) {
    this->first_player = new_player;
}

void Game::set_second_player(Player new_player) {
    this->second_player = new_player;
}

void Game::set_current_winner(Player current_winner) {
    this->current_winner = current_winner;
}

void Game::set_current_round(int new_round) {
    this->current_round = new_round;
}

void Game::setIndex(size_t index) {
    this->index = index;
}

void Game::set_isDone(bool isDone) {
    this->isDone = isDone;
}

map <int, string> Game::get_rounds_details() {
    return this->rounds_details;
}

void Game::playTurn() {
    this->first_player.set_current_stack_size(this->first_player.stacksize() - 1);
    this->first_player.set_current_card(this->first_player.get_cards_stack().at(this->index));

    this->second_player.set_current_stack_size(this->second_player.stacksize() - 1);
    this->second_player.set_current_card(this->second_player.get_cards_stack().at(this->index));

    this->index++;

    string incident;

    if (this->first_player.get_current_card().getRank() == this->second_player.get_current_card().getRank()) {
        while (this->first_player.get_current_card().getRank() == this->second_player.get_current_card().getRank()) {
            incident = this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";
            
            // The two players pulling a card from their stacks and facing it down.
            this->first_player.set_current_stack_size(this->first_player.stacksize() - 1);
            this->first_player.set_current_card(this->first_player.get_cards_stack().at(this->index));
            this->first_player.get_current_card().setRevealed(false);
            this->second_player.set_current_stack_size(this->second_player.stacksize() - 1);
            this->second_player.set_current_card(this->second_player.get_cards_stack().at(this->index));
            this->second_player.get_current_card().setRevealed(false);
            this->index++;

            // Then, both of them pull another one by facing it up for comparison.
            this->first_player.set_current_stack_size(this->first_player.stacksize() - 1);
            this->first_player.set_current_card(this->first_player.get_cards_stack().at(this->index));
            this->first_player.get_current_card().setRevealed(true);
            this->second_player.set_current_stack_size(this->second_player.stacksize() - 1);
            this->second_player.set_current_card(this->second_player.get_cards_stack().at(this->index));
            this->second_player.get_current_card().setRevealed(true);
            this->index++;

            // Handling rank results contradictions based on ASCI table and the game's rules.
            if (this->first_player.get_current_card().getRank() > this->second_player.get_current_card().getRank()) {
                if (this->first_player.get_current_card().getRank() == "Ace" && this->second_player.get_current_card().getRank() == "Two") {
                    this->second_player.set_cards_won(this->second_player.cardesTaken() + 1);
                    this->set_current_winner(this->second_player);
                    
                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }
                
                else if (this->first_player.get_current_card().getRank() == "Queen" && this->second_player.get_current_card().getRank() == "King") {
                    this->second_player.set_cards_won(this->second_player.cardesTaken() + 1);
                    this->set_current_winner(this->second_player);
                    
                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else if (this->first_player.get_current_card().getRank() == "Queen" && this->second_player.get_current_card().getRank() == "Ace") {
                    this->second_player.set_cards_won(this->second_player.cardesTaken() + 1);
                    this->set_current_winner(this->second_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else if (this->first_player.get_current_card().getRank() == "Jack" && this->second_player.get_current_card().getRank() == "Ace") {
                    this->second_player.set_cards_won(this->second_player.cardesTaken() + 1);
                    this->set_current_winner(this->second_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else if (this->first_player.get_current_card().getRank() == "King" && this->second_player.get_current_card().getRank() == "Ace") {
                    this->second_player.set_cards_won(this->second_player.cardesTaken() + 1);
                    this->set_current_winner(this->second_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else {
                    this->first_player.set_cards_won(this->first_player.cardesTaken() + 1);
                    this->set_current_winner(this->first_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }
            }

            else if (this->first_player.get_current_card().getRank() < this->second_player.get_current_card().getRank()) {
                if (this->first_player.get_current_card().getRank() == "Ace" && this->second_player.get_current_card().getRank() == "Jack") {
                    this->first_player.set_cards_won(this->first_player.cardesTaken() + 1);
                    this->set_current_winner(this->first_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else if (this->first_player.get_current_card().getRank() == "Ace" && this->second_player.get_current_card().getRank() == "Queen") {
                    this->first_player.set_cards_won(this->first_player.cardesTaken() + 1);
                    this->set_current_winner(this->first_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else if (this->first_player.get_current_card().getRank() == "Ace" && this->second_player.get_current_card().getRank() == "King") {
                    this->first_player.set_cards_won(this->first_player.cardesTaken() + 1);
                    this->set_current_winner(this->first_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else if (this->first_player.get_current_card().getRank() == "Ace" && this->second_player.get_current_card().getRank() == "Two") {
                    this->second_player.set_cards_won(this->second_player.cardesTaken() + 1);
                    this->set_current_winner(this->second_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else if (this->first_player.get_current_card().getRank() == "King" && this->second_player.get_current_card().getRank() == "Queen") {
                    this->first_player.set_cards_won(this->first_player.cardesTaken() + 1);
                    this->set_current_winner(this->first_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }

                else {
                    this->second_player.set_cards_won(this->second_player.cardesTaken() + 1);
                    this->set_current_winner(this->second_player);

                    incident += this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";

                    break;
                }
            }
        }
    }

    else if (this->first_player.get_current_card().getRank() > this->second_player.get_current_card().getRank()) {
        this->first_player.set_cards_won(this->first_player.cardesTaken() + 1);
        this->set_current_winner(first_player);

        incident = this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";
    }
    
    else {
        this->second_player.set_cards_won(this->second_player.cardesTaken() + 1);
        this->set_current_winner(second_player);
        incident = this->first_player.getName() + " pulled " + this->first_player.get_current_card().description()
                        + " and " + this->second_player.getName() + " pulled " + this->second_player.get_current_card().description() + ". DRAW!";
    }
    
    this->current_round++;
    this->rounds_details.insert({this->current_round, incident});
}

void Game::printLastTurn() {
    cout << this->rounds_details.at(rounds_details.size() - 1);
}

void Game::playAll() {
    while (this->first_player.stacksize() != 0 || this->second_player.stacksize() != 0) {
        playTurn();
    }

    this->isDone = true;
}

void Game::printWiner() {
    if (this->first_player.cardesTaken() > this->second_player.cardesTaken()) {
        cout << "The winner is " << this->first_player.getName() << ".";
    }
    else if (this->first_player.cardesTaken() < this->second_player.cardesTaken()) {
        cout << "The winner is " << this->second_player.getName() << ".";
    }
    else {
        cout << "IT IS A DRAW!";
    }
}

void Game::printLog() {
    for (auto pair : this->rounds_details) {
        cout << pair.second << endl;
    }
}

void Game::printStats() {
    /* To be continued in part B... */
}