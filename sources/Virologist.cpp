#include "Virologist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Virologist& Virologist::treat(City c){
    if(b[c] == 0){
        throw invalid_argument("no disease in this city");
    }
    if(loc == c){
        Player::treat(c);
        return *this;
    }
    if(holds.contains(c)){
        holds.erase(c);
        b[c]--;
    }
    else{
        throw invalid_argument("Virologist can't treat from distance without city card");
    }
    return *this;
}
string Virologist::role() const{
    return "Virologist";
}