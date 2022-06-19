//
// Created by itamarq on 5/29/22.
//

#include "League.hpp"

namespace itamar{
    double skillLevelLowerBound = 0.0;
    double skillLevelUpperBound = 1.0;
    uint numberOfTeamsInLeague = 20;

    League::League() {
        for (int i = 0; i < numberOfTeamsInLeague; ++i) {
            Team *teamToAdd = generateNewTeam();
            teamNumber++;
            participatingTeams.push_back(teamToAdd);
        }
    }

    League::League(vector<Team *> &teamsVector) {
        validateInputTeams(teamsVector);
        vector<string> teamsNames;
        uint numberOfTeamsToGenerate = numberOfTeamsInLeague - teamsVector.size();
        for (Team* currentTeam : teamsVector) {
            string teamName = currentTeam->getName();
            validateNameIsUnique(this->participatingTeams, teamName);
            participatingTeams.push_back(currentTeam);
            teamNumber++;
        }

        for (int i = 0; i < numberOfTeamsToGenerate; ++i) {
            Team *teamToAdd = generateNewTeam();
            teamNumber++;
            participatingTeams.push_back(teamToAdd);
        }


    }

    League::~League() {
        for ( Team* currentTeam : participatingTeams){
            delete currentTeam;
        }
        participatingTeams.clear();
    }

    vector<Team *> League::getParticipatingTeams() {
        return this->participatingTeams;
    }

    Team *League::generateNewTeam() {
        string teamName = "Team " + to_string(teamNumber);
        double teamSkillLevel = generateRandomNumber(skillLevelLowerBound, skillLevelUpperBound);
        Team *newTeam = new Team(teamName, teamSkillLevel);
        return newTeam;
    }

    void validateInputTeams(const vector<Team *> &teamsVector) {
        if(teamsVector.size() > numberOfTeamsInLeague){
            throw invalid_argument("Max Number Of Participating Teams Is 20!\n");
        }

    }

    void validateNameIsUnique(const vector<Team *> &teamsVector, const string& teamName){
        for (Team* currentTeam : teamsVector) {
            if(currentTeam->getName() == teamName){
                throw invalid_argument("Teams Names Must Be Unique!\n");
            }
        }
    }

}