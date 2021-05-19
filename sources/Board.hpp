#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <unordered_set>
#include <array>

namespace pandemic{
    const int CURE_COUNT = 5;
    
    class Board{
    private:
        std::unordered_map<City,int> level;
        std::unordered_map<City,Color> colors;
        std::unordered_map<City,bool> stat;
        std::unordered_map<City,std::unordered_set<City>> map;
        std::unordered_set<int> deck;
        std::array<bool, 4> cure;

    public:
        Board();
        const std::unordered_set<int>& cards() const{
            return deck;
        }
        bool are_neighbors(City src, City dst) {
            return map[src].contains(dst);
        }
        bool has_station(City c){
            return stat[c];
        }

        bool add_station(City c){
            if(stat[c]){
                return false;
            }
            stat[c] = true;
            return true;
        }

        Color get_color(City c){
            return colors[c];
        }

        bool is_cure_found(Color c) const{
            return cure.at((uint)c);
        }
        void cure_found(Color c){
            cure.at((uint)c) = true;
        }

        int& operator[](City c);
        bool is_clean();
        void remove_cures();
        friend std::ostream& operator<<(std::ostream&, const Board&);
    };
}