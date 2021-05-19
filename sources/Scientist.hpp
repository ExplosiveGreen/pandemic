#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Scientist: public Player{
    private:
        int cure_count;
    public:
        Scientist(Board& b, City c, int cards):Player(b,c), cure_count(cards){}  
        Scientist& discover_cure(Color);
        std::string role() const{
            return "Scientist";
        }
    };
}