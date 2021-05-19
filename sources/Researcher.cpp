#include "Researcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <stdexcept>

using namespace std;
using namespace pandemic;

Researcher& Researcher::discover_cure(Color c){
    
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
    
    return *this;
}
