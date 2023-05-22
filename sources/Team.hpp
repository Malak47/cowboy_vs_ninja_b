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
#include <algorithm>

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
        virtual ~Team();

        virtual void add(Character *fighter);
        virtual void attack(Team *enemyTeam);
        int stillAlive();
        void print();

        virtual void sortArray();

        Character *getLeader() const;
        array<Character *, TeamMembers> &getFighters();
        size_t getCurrTeamMembers();

        virtual bool setNewLeader();
        void setLeader(Character *newLeader);
        virtual Character *setVictim(Team *enemyTeam);

        void updateCurrTeamMembers();
        void setCurrTeamMembers(size_t newSize);

        Team(Team &) = delete; // Copy Constructor.
        Team(Team &&) noexcept = delete; // Move Constructor.
        Team &operator=(const Team &) = delete; // Copy assignment operator.
        Team &operator=(Team &&) noexcept = delete;

    };
}

#endif //COWBOY_VS_NINJA_A_TEAM_HPP
