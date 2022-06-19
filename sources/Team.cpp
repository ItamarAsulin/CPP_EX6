//
// Created by itamarq on 5/29/22.
//

#include "Team.hpp"
using namespace std;




namespace itamar{


    Team::Team(const string &name, const double skillLevel) {
        this->name = name;
        this->skillLevel = skillLevel;
    }

    void Team::setName(const string &nameToSet) {
        this->name = nameToSet;
    }

    string Team::getName() {
        return this->name;
    }

    void Team::setSkillLevel(const double skillLevelToSet) {
        this->skillLevel = skillLevelToSet;
    }

    double Team::getSkillLevel() {
        return this->skillLevel;
    }

    double generateRandomNumber(double lowerBound, double upperBound){
        std::uniform_real_distribution<double> unif(lowerBound,upperBound);
        std::default_random_engine re;
        return unif(re);
    }



}