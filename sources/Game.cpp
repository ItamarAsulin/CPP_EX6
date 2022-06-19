//
// Created by itamarq on 5/29/22.
//

#include "Game.hpp"

using namespace std;

namespace itamar {
    int homeTeamScoreLowerBound = 55;
    int awayTeamScoreLowerBound = 50;
    int bothTeamsScoreUpperBound = 100;

    Game::Game(Team &homeTeam, Team &awayTeam) {
        this->homeTeam = &homeTeam;
        this->awayTeam = &awayTeam;
        this->winner = nullptr;
        runGame();
    }

    int Game::getHomeTeamScore() {
        return homeTeamScore;
    }

    int Game::getAwayTeamScore() {
        return awayTeamScore;
    }

    Team *Game::getWinner() {
        if (winner == nullptr) {
            throw logic_error("The Winner Has Not Been Decided Yet!\n");
        }
        return this->winner;
    }

    void Game::runGame() {
        generateHomeTeamScore();
        generateAwayTeamScore();
        if(homeTeamScore > awayTeamScore){
            winner = homeTeam;
        }else{
            winner = awayTeam;
        }
    }

    void Game::generateHomeTeamScore() {
        homeTeamScore = round(generateRandomNumber(homeTeamScoreLowerBound, bothTeamsScoreUpperBound));
        double homeTeamSkillLevel = homeTeam->getSkillLevel();
        int scoreAdditionBySkillLevel = round(100 * homeTeamSkillLevel);
        homeTeamScore += scoreAdditionBySkillLevel;
    }

    void Game::generateAwayTeamScore() {
        awayTeamScore = round(generateRandomNumber(awayTeamScoreLowerBound, bothTeamsScoreUpperBound));
        double awayTeamSkillLevel = awayTeam->getSkillLevel();
        int scoreAdditionBySkillLevel = round(100 * awayTeamSkillLevel);
        awayTeamScore += scoreAdditionBySkillLevel;
    }

}
