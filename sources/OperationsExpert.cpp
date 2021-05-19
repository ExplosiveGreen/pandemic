#include "OperationsExpert.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

OperationsExpert& OperationsExpert::build(){
    b.add_station(loc);
    return *this;
}

