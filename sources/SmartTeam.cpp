//
// Created by malaklinux on 5/16/23.
//

#include "SmartTeam.hpp"
#include <algorithm>

using namespace std;

namespace ariel {

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    void SmartTeam::add(Character *fighter) {
        if (fighter->getJoinedTeam()) {
            throw runtime_error("Error With add(): Fighter Is Already In A Team\n");
        }
        if (getCurrTeamMembers() >= 10) {
            throw runtime_error("Error With add(): Team Is Full\n");
        }
        getFighters().at(getCurrTeamMembers()) = fighter;
        cout << getCurrTeamMembers() << endl;
        setCurrTeamMembers(getCurrTeamMembers() + 1);
        fighter->updateJoinedTeam();
        sortArray();
    }

    void SmartTeam::attack(Team *enemyTeam) {
        if (!enemyTeam) {
            throw invalid_argument("Error With attack(): No enemyTeam Found\n");
        }
        if (this == enemyTeam) {
            throw runtime_error("Error With attack(): Two Teams Are Equal\n");
        }
        if (!this->stillAlive()) {
            throw runtime_error("Error With attack(): Attacking Team Is Dead\n");
        }
        if (!enemyTeam->stillAlive()) {
            throw runtime_error("Error With attack(): EnemyTeam Is Dead\n");
        }

        if (!setNewLeader()) {
            return;
        }

        Character *victim = setVictim(enemyTeam);
        if (!victim) {
            return;
        }
        size_t i;
        for (i = 0; i < getCurrTeamMembers(); i++) {
            if (getFighters().at(i)->isAlive()) {
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(getFighters().at(i))) {
                    if (cowboy->hasBullets()) {
                        cowboy->shoot(victim);
                    } else {
                        cowboy->reload();
                    }
                } else if (Ninja *ninja = dynamic_cast<Ninja *>(getFighters().at(i))) {
                    if (ninja->distance(victim) < 1) {
                        ninja->slash(victim);
                    } else {
                        ninja->move(victim);
                    }
                }
            }

            if (!victim->isAlive()) {
                victim = setVictim(enemyTeam);
                if (!victim) {
                    break;
                }
            }
        }
    }

    void SmartTeam::sortArray() {
        std::sort(getFighters().begin(), getFighters().begin() + getCurrTeamMembers(),
                  [this](Character *a, Character *b) {
                      double distA = this->getLeader()->distance(a);
                      double distB = this->getLeader()->distance(b);
                      return (a->getDamage() / distA > b->getDamage() / distB);
                  });
    }

    Character *SmartTeam::setVictim(Team *enemyTeam) {
        array<Character *, TeamMembers> &enemyFighters = enemyTeam->getFighters();
        size_t enemyCurrTeamMembers = enemyTeam->getCurrTeamMembers();
        Character *closest = nullptr;
        double closestDistance = numeric_limits<double>::max();

        for (size_t i = 0; i < enemyCurrTeamMembers; i++) {
            if (enemyFighters.at(i)->isAlive() && this->getLeader()->distance(enemyFighters.at(i)) < closestDistance) {
                closestDistance = this->getLeader()->distance(enemyFighters.at(i));
                closest = enemyFighters.at(i);
            }
        }
        return closest;
    }

    bool SmartTeam::setNewLeader() {
        if (!this->getLeader()->isAlive()) {
            for (size_t i = 0; i < getCurrTeamMembers(); i++) {
                if (getFighters().at(i)->isAlive()) {
                    setLeader(getFighters().at(i));
                    sortArray();
                    return true;
                }
            }
            return false;
        }
        return true;
    }
}