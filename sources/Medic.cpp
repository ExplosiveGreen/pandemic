#include "Medic.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Medic& Medic::drive(City c){
    Player::drive(c);
    if(b.is_cure_found(b.get_color(loc))){
        b[loc] = 0;
    }
    return *this;
}

Medic& Medic::fly_direct(City c){
    Player::fly_direct(c);
    if(b.is_cure_found(b.get_color(loc))){
        b[loc] = 0;
    }
    return *this;
}

Medic& Medic::fly_charter(City c){
    Player::fly_charter(c);
    if(b.is_cure_found(b.get_color(loc))){
        b[loc] = 0;
    }
    return *this;
}

Medic& Medic::fly_shuttle(City c){
    Player::fly_shuttle(c);
    if(b.is_cure_found(b.get_color(loc))){
        b[loc] = 0;
    }
    return *this;
}

Medic& Medic::treat(City c){
    if(b[c] > 0){
        b[c] = 0;
    }
    else{
        throw invalid_argument("no disease in this city");
    }
    return *this;
}