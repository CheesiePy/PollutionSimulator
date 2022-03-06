//
// Created by May Lindenberg on 12/18/2021.
//

#ifndef POLLUTIONSIMULATOR_ROAD_H
#define POLLUTIONSIMULATOR_ROAD_H

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;
class CrossSection;

class Road {
public:

    //** no empty constructor -> no need for an uninitialized road

    //c'tor
    Road(CrossSection* from, CrossSection* to, double roadLen):
    pollutionLevel(0.0) ,roadLen(roadLen){this->from = from; this->to = to;}
    //--Big Three--

    //copy c'tor
    Road(const Road& other);
    // = operator
    Road& operator=(const Road& rhs);
    //d'tor
    ~Road(){};

    //--Getters & Setters--
    CrossSection* getFrom() const{return from;}
    CrossSection* getTo() const{return to;}
    double getPollutionLevel() const {return pollutionLevel;}
    double getRoadLen() const {return roadLen;}

    void setPollutionLevel(float pLevel) {Road::pollutionLevel = pLevel;}
    void pollute(double pLevel) {Road::pollutionLevel += pLevel/roadLen;}
    void setTo(CrossSection* setTo) {Road::to = setTo;}
    void setFrom(CrossSection* setFrom) {Road::from = setFrom;}

    friend ostream& operator<<(ostream& out, const Road& road);
private:
    //Private Class Methods
    void Assign(const Road& road);

    //Class Fields
    double const roadLen;
    double pollutionLevel;
    CrossSection* from;
    CrossSection* to;
};

ostream& operator<<(ostream& out, const Road& road);


#endif //POLLUTIONSIMULATOR_ROAD_H
