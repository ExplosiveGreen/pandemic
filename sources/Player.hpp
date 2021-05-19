#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <vector>
#include <unordered_set>
namespace pandemic{
    class Player{
    protected:
        Board& b;
        City loc;
        std::unordered_set<City> holds;
        std::vector<City> cards_colored(Color);
    public:
        Player(Board&, City);
        Player& take_card(City);
        virtual Player& drive(City);
        virtual Player& fly_direct(City);
        virtual Player& fly_charter(City);
        virtual Player& fly_shuttle(City);
        virtual Player& discover_cure(Color);
        virtual Player& build();
        virtual Player& treat(City);
        virtual std::string role() const = 0;
    };
}