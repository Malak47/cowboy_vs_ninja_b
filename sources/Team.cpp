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
        while (stillAlive() > 0 && enemyTeam->stillAlive() > 0) {
            double closest = INT32_MAX;

            //new Leader if necessary
            setNewLeader();

            //select a victim from the enemy team
            closest = INT32_MAX;
            size_t i = 0;
            size_t at = 0;

            while (i < enemyTeam->currTeamMembers) {
                if (enemyTeam->fighters.at(i)->isAlive()) {
                    double temp = leader->distance(enemyTeam->fighters.at(i));
                    if (temp < closest) {
                        closest = temp;
                        at = i;
                    }
                }
                i++;
            }

            //attack the victim
            while (i < currTeamMembers) {
                if (fighters.at(i)->isAlive()) {
                    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighters.at(i))) {
                        if (!cowboy->hasBullets()) {
                            cowboy->reload();
                            continue;
                        }
                        cowboy->shoot(enemyTeam->fighters.at(at));
                    } else if (Ninja *ninja = dynamic_cast<Ninja *>(fighters.at(i))) {
                        if (ninja->distance(enemyTeam->fighters.at(at)) >= 1) {
                            ninja->move(enemyTeam->fighters.at(at));
                            continue;
                        }
                        ninja->slash(enemyTeam->fighters.at(at));
                    }
                }
                i++;
            }
            if (enemyTeam->stillAlive() == 0) {
                cout << "All EnemyTeam Are Dead!" << endl;
                return;
            }

            if (stillAlive() == 0) {
                cout << "All CurrentTeam Are Dead!" << endl;
                return;
            }
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

    void Team::setNewLeader() {
        //choose a new leader
        size_t i = 0;
        double closest = 0;
        size_t at = 0;
        if (!this->leader->isAlive()) {
            while (i < currTeamMembers) {
                if (fighters.at(i)->isAlive()) {
                    double temp = this->leader->distance(fighters.at(i));
                    if (temp < closest) {
                        closest = temp;
                        at = i;
                    }
                }
                i++;
            }
            this->leader = fighters.at(at);
        }
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
}