//
// Created by malaklinux on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_A_TEAM2_HPP
#define COWBOY_VS_NINJA_A_TEAM2_HPP

#include "Team.hpp"

using namespace std;

namespace ariel {
    class Team2 : public Team {
    private:

    public:
        Team2(Character *leader);

        void add(Character *fighter) override;

    };
}
#endif //COWBOY_VS_NINJA_A_TEAM2_HPP
