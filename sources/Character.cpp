//
// Created by malaklinux on 5/16/23.
//

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

namespace ariel {
    Character::Character(string name, Point location, int hitPoints) : name(name), location(location),
                                                                       hitPoints(hitPoints), joinedTeam(false) {}

    bool Character::isAlive() {
        return hitPoints > 0;
    }

    double Character::distance(Character *other) {
        if (!other) {
            throw invalid_argument("Error With distance(): No Other Character Found\n");
        }
        return sqrt((pow((this->location.getX() - other->getLocation().getX()), 2)) +
                    (pow((this->location.getY() - other->getLocation().getY()), 2)));
    }

    void Character::hit(int hit) {
        if (hit < 0) {
            throw invalid_argument("Error With hit(): Negative Hit Value\n");
        }
        hitPoints = hitPoints - hit;
    }

    string Character::getName() {
        return name;
    }

    Point Character::getLocation() {
        return location;
    }

    void Character::print() {
        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(this)) {
            std::cout << cowboy->print();
        } else if (Ninja *ninja = dynamic_cast<Ninja *>(this)) {
            std::cout << ninja->print();
        }
    }

    int Character::getHitPoints() {
        return hitPoints;
    }

    void Character::updateJoinedTeam() {
        joinedTeam = true;
    }
    bool Character::getJoinedTeam(){
        return joinedTeam;
    }

}