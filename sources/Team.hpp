//
// Created by itamarq on 5/29/22.
//

#ifndef BASKETBALLLEAGUE_TEAM_HPP
#define BASKETBALLLEAGUE_TEAM_HPP
#include <string>
#include <iostream>
#include <random>


using namespace std;
namespace itamar {

    class Team {
    private:
        string name;
        double skillLevel;
    public:
        Team(const string &name, const double skillLevel);
        void setName(const string &nameToSet);
        string getName();
        void setSkillLevel(const double skillLevelToSet);
        double getSkillLevel();
    };

    double generateRandomNumber(double lowerBound, double upperBound);
}



#endif //BASKETBALLLEAGUE_TEAM_HPP
