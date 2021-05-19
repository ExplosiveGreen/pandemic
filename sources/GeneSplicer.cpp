#include "GeneSplicer.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

GeneSplicer& GeneSplicer::discover_cure(Color c){
    if(b.has_station(loc)){
        if(holds.size() >= CURE_COUNT){
            int count = 0;
            for(const auto& card : holds){
                if(count++ < CURE_COUNT){
                    holds.erase(card);
                }
            }
            b.cure_found(c);
        }
        else{
            throw invalid_argument("Player doesn't hold 5 cards or more");
        }
    }
    else{
        throw invalid_argument("A station needed in order to discover cure");
    }
    return *this;
}
