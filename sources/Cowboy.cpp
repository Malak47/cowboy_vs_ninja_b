//
// Created by malaklinux on 5/5/23.
//

#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy(string name, Point location) : Character(name, location, Cowboy_HitPoints),
                                                  bullets(Cowboy_Bullets) {}

    void Cowboy::shoot(Character *enemy) {
        if (!enemy) {
            throw invalid_argument("Error With shoot(): No Enemy Found\n");
        }
        if (!isAlive()) {
            throw runtime_error("Error With shoot(): Current Character Is Dead\n");
        }
        if (!enemy->isAlive()) {
            throw runtime_error("Error With shoot(): Enemy Character Is Dead\n");
        }
        if(enemy == this){
            throw runtime_error("Error With shoot(): Can't Shoot Himself\n");
        }
        if (this->isAlive() && hasBullets()) {
            enemy->hit(Cowboy_shotDamage);
            bullets--;
        }
    }

    bool Cowboy::hasBullets() {
        return bullets > 0;
    }

    void Cowboy::reload() {
        if(!isAlive()){
            throw runtime_error("Error With reload(): Current Character Is Dead\n");
        }
        bullets = Cowboy_Bullets;
    }

    bool Cowboy::hasboolets() {
        return hasBullets();
    }

    string Cowboy::print() {
        if (!this->isAlive()) {
            return "C (" + this->getName() + ")\n";
        }
        return "{ {Name:" + this->getName() +
               "} , {Hit Points:" + to_string(this->getHitPoints()) +
               "} , {Location: (" + to_string(this->getLocation().getX()) + "," +
               to_string(this->getLocation().getY()) +
               ")} }\n";
    }

    int Cowboy::getBulletsLeft() {
        return bullets;
    }


}