#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(City c){
    if(loc == c){
        Player::treat(c);
        return *this;
    }
    if(b[c] == 0){
        throw invalid_argument("no disease in this city");
    }
    if(!b.are_neighbors(loc, c)){
        throw invalid_argument("citys are not neighbors");
    }
    if(b.is_cure_found(b.get_color(c))){
            b[c] = 0;
        }
    else{
        b[c]--;
    }
    return *this;
}
