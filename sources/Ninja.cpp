//
// Created by malaklinux on 5/16/23.
//

#include "Ninja.hpp"

using namespace std;

namespace ariel {

    Ninja::Ninja(string name, Point location, int hitPoints, int speed) : Character(name, location, hitPoints),
                                                                          speed(speed) {}

    void Ninja::move(Character *enemy) {
        if (!enemy) {
            throw invalid_argument("Error With move(): No Enemy Found\n");
        }
        double distance = min(this->getLocation().distance(enemy->getLocation()), static_cast<double>(this->speed));
        setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), distance));

    }

    void Ninja::slash(Character *enemy) {
        if (!enemy) {
            throw invalid_argument("Error With slash(): No Enemy Found\n");
        }
        if (!isAlive()) {
            throw runtime_error("Error With slash(): Current Character Is Dead\n");
        }
        if (!enemy->isAlive()) {
            throw runtime_error("Error With slash(): Enemy Character Is Dead\n");
        }
        if (enemy == this) {
            throw runtime_error("Error With slash(): Can't Slash Himself\n");
        }
        if (this->isAlive() && distance(enemy) < 1) {
            enemy->hit(Ninja_SlashDamage);
        }
    }

    int Ninja::getSpeed() {
        return this->speed;
    }

    string Ninja::print() {
        if (!this->isAlive()) {
            return "N (" + this->getName() + ")\n";
        }
        return "{ {Name:" + this->getName() +
               "} , {Hit Points:" + to_string(this->getHitPoints()) +
               "} , {Location: (" + to_string(this->getLocation().getX()) + "," +
               to_string(this->getLocation().getY()) +
               ")} }\n";
    }
}
