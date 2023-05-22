//
// Created by malaklinux on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_A_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_A_SMARTTEAM_HPP

#include "Team.hpp"
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

namespace ariel {

#ifndef SMARTTEAM_H
#define SMARTTEAM_H

#include "Team.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

    using namespace ariel;

    class SmartTeam : public Team {
    private:
        bool setNewLeader() override;

    public:
        SmartTeam(Character *leader);

        void add(Character *character) override;

        void attack(Team *enemyTeam) override;

        void sortArray() override;

        Character *setVictim(Team *enemyTeam) override;


    };

#endif

}
#endif //COWBOY_VS_NINJA_A_SMARTTEAM_HPP
