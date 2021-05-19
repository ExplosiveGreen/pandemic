#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace pandemic;

Player::Player(Board& b, City c):b(b), loc(c){}
Player& Player::take_card(City c){
    holds.insert(c);
    return *this;
}
Player& Player::drive(City c){
    if(b.are_neighbors(loc, c)){
        loc = c;
    }
    else{
        throw invalid_argument("illegal action: city isn't connected");
    }
    return *this;
}
Player& Player::fly_direct(City c){
    if(loc == c){
        throw invalid_argument("can't fly from city to itself");

    }
    if(holds.contains(c)){
        holds.erase(c);
        loc = c;
    }
    else{
        throw invalid_argument("Player doesn't hold this card");
    }
    return *this;
}
Player& Player::fly_charter(City c){
    if(loc == c){
        throw invalid_argument("can't fly from city to itself");

    }
    if(holds.contains(loc)){
        holds.erase(loc);
        loc = c;
    }
    else{
        throw invalid_argument("Player doesn't hold his location card");
    }
    return *this;
}
Player& Player::fly_shuttle(City c){
    if(loc == c){
        throw invalid_argument("can't fly from city to itself");

    }
    if(b.has_station(loc) && b.has_station(c)){
        loc = c;
    }
    else{
        throw invalid_argument("In order to complete this action please build stations in the src and the dst citys");
    }
    return *this;
}
Player& Player::discover_cure(Color c){
    if(b.is_cure_found(c)){
        return *this;
    }
    if(b.has_station(loc)){
        vector<City> tmp = cards_colored(c);
        if(tmp.size() >= CURE_COUNT){
            for(size_t i = 0; i < CURE_COUNT; i++){
                holds.erase(tmp.at(i));
            }
            b.cure_found(c);
        }
        else{
            throw invalid_argument("Player doesn't hold 5 cards from this color");
        }
    }
    else{
        throw invalid_argument("A station needed in order to discover cure");
    }
    return *this;
}
Player& Player::build(){
    if(holds.contains(loc)){
        holds.erase(loc);
        b.add_station(loc);
    }
    else{
        throw invalid_argument("Player doesn't hold his location city card");
    }
    return *this;
}
Player& Player::treat(City c){
    if(loc == c && b[c] > 0){
        if(b.is_cure_found(b.get_color(c))){
            b[c] = 0;
        }
        else{
            b[c]--;
        }
    }
    else if(b[c] <= 0){
        throw invalid_argument("no disease in this city");
    }
    else{
        throw invalid_argument("can't treat remote city");
    }
    return *this;
}

vector<City> Player::cards_colored(Color c){
    vector<City> res;
    for(const auto& card: holds){
        if(b.get_color(card) == c){
            res.push_back(card);
        }
    }
    return res;
}


