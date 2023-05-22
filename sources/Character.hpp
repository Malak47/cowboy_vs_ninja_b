//
// Created by malaklinux on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_A_CHARACTER_HPP
#define COWBOY_VS_NINJA_A_CHARACTER_HPP

#include "Point.hpp"
#include <cmath>

using namespace std;
namespace ariel {
    class Character {
    private:
        Point location;
        int hitPoints;
        string name;
        bool joinedTeam;

    public:
        Character(string name, Point location, int hitPoints);

        virtual ~Character() = default;

        bool isAlive();

        double distance(Character *other);

        void hit(int hit);

        string getName();

        Point getLocation();

        void print();

        int getHitPoints();

        int getDamage();

        bool getJoinedTeam();

        void setLocation(Point location);

        void updateJoinedTeam();

        Character(Character &); // Copy Constructor.
        Character(Character &&) noexcept; // Move Constructor.
        Character &operator=(const Character &); // Copy assignment operator.
        Character &operator=(Character &&) noexcept; // Move assignment operator.


    };
}
#endif //COWBOY_VS_NINJA_A_CHARACTER_HPP
