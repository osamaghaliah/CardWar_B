/**
 * This namespace represents a cards setup to be played with during the game.
 * @author Osama M. Ghaliah
*/

#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP
#include <vector>
#include "card.hpp"

namespace ariel {
    static Card const two_clubs(Two, Clubs);
    static Card const three_clubs(Three, Clubs);
    static Card const four_clubs(Four, Clubs);
    static Card const five_clubs(Five, Clubs);
    static Card const six_clubs(Six, Clubs);
    static Card const seven_clubs(Seven, Clubs);
    static Card const eight_clubs(Eight, Clubs);
    static Card const nine_clubs(Nine, Clubs);
    static Card const ten_clubs(Ten, Clubs);
    static Card const jack_clubs(Jack, Clubs);
    static Card const queen_clubs(Queen, Clubs);
    static Card const king_clubs(King, Clubs);
    static Card const ace_clubs(Ace, Clubs);

    static Card const two_diamonds(Two, Diamonds);
    static Card const three_diamonds(Three, Diamonds);
    static Card const four_diamonds(Four, Diamonds);
    static Card const five_diamonds(Five, Diamonds);
    static Card const six_diamonds(Six, Diamonds);
    static Card const seven_diamonds(Seven, Diamonds);
    static Card const eight_diamonds(Eight, Diamonds);
    static Card const nine_diamonds(Nine, Diamonds);
    static Card const ten_diamonds(Ten, Diamonds);
    static Card const jack_diamonds(Jack, Diamonds);
    static Card const queen_diamonds(Queen, Diamonds);
    static Card const king_diamonds(King, Diamonds);
    static Card const ace_diamonds(Ace, Diamonds);

    static Card const two_hearts(Two, Hearts);
    static Card const three_hearts(Three, Hearts);
    static Card const four_hearts(Four, Hearts);
    static Card const five_hearts(Five, Hearts);
    static Card const six_hearts(Six, Hearts);
    static Card const seven_hearts(Seven, Hearts);
    static Card const eight_hearts(Eight, Hearts);
    static Card const nine_hearts(Nine, Hearts);
    static Card const ten_hearts(Ten, Hearts);
    static Card const jack_hearts(Jack, Hearts);
    static Card const queen_hearts(Queen, Hearts);
    static Card const king_hearts(King, Hearts);
    static Card const ace_hearts(Ace, Hearts);

    static Card const two_spades(Two, Spades);
    static Card const three_spades(Three, Spades);
    static Card const four_spades(Four, Spades);
    static Card const five_spades(Five, Spades);
    static Card const six_spades(Six, Spades);
    static Card const seven_spades(Seven, Spades);
    static Card const eight_spades(Eight, Spades);
    static Card const nine_spades(Nine, Spades);
    static Card const ten_spades(Ten, Spades);
    static Card const jack_spades(Jack, Spades);
    static Card const queen_spades(Queen, Spades);
    static Card const king_spades(King, Spades);
    static Card const ace_spades(Ace, Spades);

    vector <Card> const DECK {two_clubs, three_clubs, four_clubs, five_clubs, six_clubs, seven_clubs, eight_clubs, nine_clubs, ten_clubs, jack_clubs, queen_clubs, king_clubs, ace_clubs,
    two_diamonds, three_diamonds, four_diamonds, five_diamonds, six_diamonds, seven_diamonds, eight_clubs, nine_diamonds, ten_diamonds, jack_diamonds, queen_diamonds, king_diamonds,
    two_hearts, three_hearts, four_hearts, five_hearts, six_hearts, seven_hearts, eight_hearts, nine_hearts, ten_hearts, jack_hearts, queen_hearts, king_hearts, ace_hearts,
    two_spades, three_spades, four_spades, five_spades, six_spades, seven_spades, eight_spades, nine_spades, ten_spades, jack_spades, queen_spades, king_spades, ace_spades};
};

#endif