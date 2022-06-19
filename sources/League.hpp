//
// Created by itamarq on 5/29/22.
//

#ifndef BASKETBALLLEAGUE_LEAGUE_HPP
#define BASKETBALLLEAGUE_LEAGUE_HPP

#include "Game.hpp"
#include <vector>
#include <unordered_set>
namespace itamar {


    class League {
    private:
        vector<Team *> participatingTeams;
        int teamNumber = 1;

        Team *generateNewTeam();
        bool contains(const string& teamName);

    public:
        League();

        League(vector<Team *> &teamsVector);

        ~League();

        vector<Team *> getParticipatingTeams();
    };

    void validateInputTeams(const vector<Team *> &teamsVector);
    void validateNameIsUnique(const vector<Team *> &teamsVector, const string& teamName);
}


#endif //BASKETBALLLEAGUE_LEAGUE_HPP
