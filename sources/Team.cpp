//
// Created by malaklinux on 5/5/23.
//
#include "Team.hpp"
#include <algorithm>

using namespace std;

namespace ariel {
    Team::Team(Character *leader) : leader(leader), currTeamMembers(0) {
        if (!leader) {
            throw invalid_argument("Error With TeamConstructor(): No Leader Found\n");
        }
        if (leader->getJoinedTeam()) {
            throw runtime_error("Error With TeamConstructor(): Leader Is Already In A Team\n");
        }
        fighters.at(currTeamMembers++) = leader;
        leader->updateJoinedTeam();
    }


    Team::~Team() {
        size_t i = 0;
        while (i < currTeamMembers) {
            delete fighters.at(i++);
        }
    }

    void Team::add(Character *fighter) {
        if (!fighter) {
            throw invalid_argument("Error With add(): No Fighter Found\n");
        }
        if (fighter->getJoinedTeam()) {
            throw runtime_error("Error With add(): Fighter Is Already In A Team\n");
        }
        if (currTeamMembers >= 10) {
            throw runtime_error("Error With add(): Team Is Full\n");
        }
        fighters.at(currTeamMembers++) = fighter;
        fighter->updateJoinedTeam();
        sortArray();

    }

    void Team::attack(Team *enemyTeam) {
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
        //new Leader if necessary
        if (!this->leader->isAlive()) {
            setNewLeader();
            if (!leader) {
                return;
            }
        }
        //select a victim from the enemy team
        Character *victim = setVictim(enemyTeam);
        if (!victim) {
            return;
        }
        //attack the victim
        size_t i = 0;
        while (i < currTeamMembers) {
            if (fighters.at(i)->isAlive() && victim->isAlive()) {
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighters.at(i))) {
                    if (cowboy->hasBullets()) {
                        cowboy->shoot(victim);
                    } else {
                        cowboy->reload();
                    }
                } else if (Ninja *ninja = dynamic_cast<Ninja *>(fighters.at(i))) {
                    if (ninja->distance(victim) < 1) {
                        ninja->slash(victim);
                    } else {
                        ninja->move(victim);
                    }
                }
            }
            if (!victim->isAlive()) {
                victim = setVictim(enemyTeam);
            }
            i++;
        }

    }


    int Team::stillAlive() {
        size_t i = 0;
        int alive = 0;
        while (i < currTeamMembers) {
            if (fighters.at(i++)->isAlive()) {
                alive++;
            }
        }
        return alive;
    }

    void Team::print() {
        size_t i = 0;
        while (i < currTeamMembers) {
            fighters[i++]->print();
        }
    }

    size_t Team::getCurrTeamMembers() {
        return currTeamMembers;
    }


    void Team::sortArray() {
        //https://en.cppreference.com/w/cpp/algorithm/stable_partition
        //https://www.geeksforgeeks.org/sort-c-stl/
        std::stable_partition(fighters.begin(), fighters.begin() + currTeamMembers, [](const Character *c) {
            return dynamic_cast<const Cowboy *>(c) != nullptr;
        });
    }

    array<Character *, TeamMembers> &Team::getFighters() {
        return fighters;
    }

    void Team::setFighters(array<Character *, TeamMembers> &fighters) {
        this->fighters = fighters;
    }

    void Team::updateCurrTeamMembers() {
        currTeamMembers++;
    }

    Character *Team::setVictim(Team *enemyTeam) {
        //select a victim from the enemy team
        double closest = INT32_MAX;
        size_t i = 0;
        size_t at = 0;
        bool flag = false;
        while (i < enemyTeam->currTeamMembers) {
            if (enemyTeam->fighters.at(i)->isAlive()) {
                flag = true;
                double temp = leader->distance(enemyTeam->fighters.at(i));
                if (temp < closest) {
                    closest = temp;
                    at = i;
                }
            }
            i++;
        }
        if (!flag) {
            return nullptr;
        }
        return enemyTeam->fighters.at(at);
    }

    void Team::setNewLeader() {
        //choose a new leader
        size_t i = 0;
        double closest = 0;
        size_t at = 0;
        bool flag = false;
        if (!this->leader->isAlive()) {
            while (i < currTeamMembers) {
                if (fighters.at(i)->isAlive()) {
                    flag = true;
                    double temp = this->leader->distance(fighters.at(i));
                    if (temp < closest) {
                        closest = temp;
                        at = i;
                    }
                }
                i++;
            }
            if (!flag) {
                this->leader = nullptr;
            }
            this->leader = fighters.at(at);
        }
    }


}