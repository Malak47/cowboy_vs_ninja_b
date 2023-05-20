//
// Created by malaklinux on 5/16/23.
//

#include "Team2.hpp"

namespace ariel {
    Team2::Team2(Character *leader) : Team(leader) {
    }

    void Team2::attack(Team *enemyTeam) {
        Team::attack(enemyTeam);
    }

    void Team2::print() {
        Team::print();
    }

    void Team2::add(Character *fighter) {
        if (!fighter) {
            throw invalid_argument("Error With add(): No Fighter Found\n");
        }
        if (fighter->getJoinedTeam()) {
            throw runtime_error("Error With add(): Fighter Is Already In A Team\n");
        }
        if (getCurrTeamMembers() >= 10) {
            throw runtime_error("Error With add(): Team Is Full\n");
        }
        getFighters().at(getCurrTeamMembers()) = fighter;
        fighter->updateJoinedTeam();
        updateCurrTeamMembers();
    }


}