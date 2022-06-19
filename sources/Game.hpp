//
// Created by itamarq on 5/29/22.
//

#ifndef BASKETBALLLEAGUE_GAME_HPP
#define BASKETBALLLEAGUE_GAME_HPP

#include "Team.hpp"
#include <iostream>
#include "../GlobalVariablesAndMethods.hpp"

using namespace std;


namespace itamar {

    class Game {
    private:
        Team *homeTeam;
        Team *awayTeam;
        int homeTeamScore = 0;
        int awayTeamScore = 0;
        Team *winner;

        void runGame();
        void generateHomeTeamScore();
        void generateAwayTeamScore();
    public:
        Game(Team &homeTeam, Team &awayTeam);

        int getHomeTeamScore();
        int getAwayTeamScore();

        Team *getWinner();
    };
}


#endif //BASKETBALLLEAGUE_GAME_HPP
