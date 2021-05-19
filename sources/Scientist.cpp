#include "Scientist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <vector>

using namespace std;
using namespace pandemic;

Scientist& Scientist::discover_cure(Color c){
    if(b.has_station(loc)){
        vector<City> tmp = Player::cards_colored(c);
        if(tmp.size() >= cure_count){
            for(size_t i = 0; i < cure_count; i++){
                holds.erase(tmp.at(i));
            }
            b.cure_found(c);
        }
        else{
            cout << tmp.size() << " , " << cure_count << endl;
            throw invalid_argument("scientist doesn't hold enough cards from this color");
        }
    }
    else{
        throw invalid_argument("A station needed in order to discover cure");
    }
    return *this;
}
