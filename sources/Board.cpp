#include <iostream>
#include "Board.hpp"
#include "City.hpp"
using namespace std;
using namespace pandemic;

Board::Board():cure{false}{
    for(int c = (int)City::Algiers; c<= (int)City::Washington; c++){
        level[(City)c] = 0;
    }
    for(size_t i = 0; i < 4; i++){
        cure.at(i) = false;
    }
    City city;
    for(size_t i = (int)City::Algiers; i <= (int)City::Washington; i++){
        deck.insert(i);
        stat[(City)i] = false;
    }

    map[City::Algiers].insert({City::Madrid, City::Paris, City::Istanbul, City::Cairo});
    map[City::Atlanta].insert({City::Chicago, City::Miami, City::Washington});
    map[City::Baghdad].insert({City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi});
    map[City::Bangkok].insert({City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong});
    map[City::Beijing].insert({City::Shanghai, City::Seoul});
    map[City::Bogota].insert({City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires});
    map[City::BuenosAires].insert({City::Bogota, City::SaoPaulo});
    map[City::Cairo].insert({City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh});
    map[City::Chennai].insert({City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta});
    map[City::Chicago].insert({City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal});
    map[City::Delhi].insert({City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata});
    map[City::Essen].insert({City::London, City::Paris, City::Milan, City::StPetersburg});
    map[City::HoChiMinhCity].insert({City::Jakarta, City::Bangkok, City::HongKong, City::Manila});
    map[City::HongKong].insert({City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei});
    map[City::Istanbul].insert({City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow});
    map[City::Jakarta].insert({City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney});
    map[City::Johannesburg].insert({City::Kinshasa, City::Khartoum});
    map[City::Karachi].insert({City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi});
    map[City::Khartoum].insert({City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg});
    map[City::Kinshasa].insert({City::Lagos, City::Khartoum, City::Johannesburg});
    map[City::Kolkata].insert({City::Delhi, City::Chennai, City::Bangkok, City::HongKong});
    map[City::Lagos].insert({City::SaoPaulo, City::Khartoum, City::Kinshasa});
    map[City::Lima].insert({City::MexicoCity, City::Bogota, City::Santiago});
    map[City::London].insert({City::NewYork, City::Madrid, City::Essen, City::Paris});
    map[City::LosAngeles].insert({City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney});
    map[City::Madrid].insert({City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers});
    map[City::Manila].insert({City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney});
    map[City::MexicoCity].insert({City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota});
    map[City::Miami].insert({City::Atlanta, City::MexicoCity, City::Washington, City::Bogota});
    map[City::Milan].insert({City::Essen, City::Paris, City::Istanbul});
    map[City::Montreal].insert({City::Chicago, City::Washington, City::NewYork});
    map[City::Moscow].insert({City::StPetersburg, City::Istanbul, City::Tehran});
    map[City::Mumbai].insert({City::Karachi, City::Delhi, City::Chennai});
    map[City::NewYork].insert({City::Montreal, City::Washington, City::London, City::Madrid});
    map[City::Osaka].insert({City::Taipei, City::Tokyo});
    map[City::Paris].insert({City::Algiers, City::Essen, City::Madrid, City::Milan, City::London});
    map[City::Riyadh].insert({City::Baghdad, City::Cairo, City::Karachi});
    map[City::SanFrancisco].insert({City::LosAngeles, City::Chicago, City::Tokyo, City::Manila});
    map[City::Santiago].insert({City::Lima});
    map[City::SaoPaulo].insert({City::Bogota, City::BuenosAires, City::Lagos, City::Madrid});
    map[City::Seoul].insert({City::Beijing, City::Shanghai, City::Tokyo});
    map[City::Shanghai].insert({City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo});
    map[City::StPetersburg].insert({City::Essen, City::Istanbul, City::Moscow});
    map[City::Sydney].insert({City::Jakarta, City::Manila, City::LosAngeles});
    map[City::Taipei].insert({City::Shanghai, City::HongKong, City::Osaka, City::Manila});
    map[City::Tehran].insert({City::Baghdad, City::Moscow, City::Karachi, City::Delhi});
    map[City::Tokyo].insert({City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco});
    map[City::Washington].insert({City::Atlanta, City::NewYork, City::Montreal, City::Miami}); 
    
    colors[City::Algiers] = Color::Black;
    colors[City::Atlanta] = Color::Blue;
    colors[City::Baghdad] = Color::Black;
    colors[City::Bangkok] = Color::Red;
    colors[City::Beijing] = Color::Red;
    colors[City::Bogota] = Color::Yellow;
    colors[City::BuenosAires] = Color::Yellow;
    colors[City::Cairo] = Color::Black;
    colors[City::Chennai] = Color::Black;
    colors[City::Chicago] = Color::Blue;
    colors[City::Delhi] = Color::Black;
    colors[City::Essen] = Color::Blue;
    colors[City::HoChiMinhCity] = Color::Red;
    colors[City::HongKong] = Color::Red;
    colors[City::Istanbul] = Color::Black;
    colors[City::Jakarta] = Color::Red;
    colors[City::Johannesburg] = Color::Yellow;;
    colors[City::Karachi] = Color::Black;
    colors[City::Khartoum] = Color::Yellow;
    colors[City::Kinshasa] = Color::Yellow;
    colors[City::Kolkata] = Color::Black;
    colors[City::Lagos] = Color::Yellow;
    colors[City::Lima] = Color::Yellow;
    colors[City::London] = Color::Blue;
    colors[City::LosAngeles] = Color::Yellow;
    colors[City::Madrid] = Color::Blue;
    colors[City::Manila] = Color::Red;
    colors[City::MexicoCity] = Color::Yellow;
    colors[City::Miami] = Color::Yellow;
    colors[City::Milan] = Color::Blue;
    colors[City::Montreal] = Color::Blue;
    colors[City::Moscow] = Color::Black;
    colors[City::Mumbai] = Color::Black;
    colors[City::NewYork] = Color::Blue;
    colors[City::Osaka] = Color::Red;
    colors[City::Paris] = Color::Blue;
    colors[City::Riyadh] = Color::Black;
    colors[City::SanFrancisco] = Color::Blue;
    colors[City::Santiago] = Color::Yellow;
    colors[City::SaoPaulo] = Color::Yellow;
    colors[City::Seoul] = Color::Red;
    colors[City::Shanghai] = Color::Red;
    colors[City::StPetersburg] = Color::Blue;
    colors[City::Sydney] = Color::Red;
    colors[City::Taipei] = Color::Red;
    colors[City::Tehran] = Color::Black;
    colors[City::Tokyo] = Color::Red;
    colors[City::Washington] = Color::Blue;
        
}
int& Board::operator[](City c){
    return level[c];
}

bool Board::is_clean(){
    for(auto& c: this->level){
        if(c.second > 0){
            return false;
        }
    }
    return true;
}

void Board::remove_cures(){
    for(size_t i = 0; i < 4; i++){
        cure.at(i) = false;
    }
}
ostream& pandemic::operator<<(ostream& output, const Board& b){
    output << "disease levels: " << endl;
    for(const auto& c: b.level){
        output << '(' << (int)c.first << ',' << (int)c.second << ')';
    }
    output<<endl;
    output << "cures found:" << endl;
    for (size_t i = 0; i < 4; i++)
    {
        output << boolalpha << "(" << i << "," << b.is_cure_found((Color)i) << ") ";
    }
    
    return output;
}