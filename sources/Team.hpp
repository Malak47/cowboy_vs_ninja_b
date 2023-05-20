//
// Created by malaklinux on 5/5/23.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_HPP
#define COWBOY_VS_NINJA_A_TEAM_HPP

#include <array>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

constexpr int TeamMembers = 10;

using namespace std;
namespace ariel {
    class Team {
    private:
        Character *leader;
        array<Character *, TeamMembers> fighters;
        size_t currTeamMembers;
    public:
        Team(Character *leader);

        void add(Character *fighter);

        void attack(Team *enemyTeam);

        int stillAlive();

        size_t getCurrTeamMembers();

        void setNewLeader();

        void print();

        void sortArray();

        array<Character *, TeamMembers> &getFighters();
        void setFighters(array<Character *, TeamMembers> &fighters);
        void updateCurrTeamMembers();
        Character* setVictim(Team *enemyTeam);

        ~Team();
        Team(Team &) = delete; // Copy Constructor.
        Team(Team &&) noexcept = delete; // Move Constructor.
        Team &operator=(const Team &) = delete; // Copy assignment operator.

        Team &operator=(Team &&) noexcept = delete;
    };
}

#endif //COWBOY_VS_NINJA_A_TEAM_HPP
