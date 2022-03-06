#ifndef POLLUTIONSIMULATOR_CROSSSECTION_H
#define POLLUTIONSIMULATOR_CROSSSECTION_H


#include "Road.h"
#include "../Data_Structures/LinkedList.h"

class CrossSection {
public:
    // c'tor
    CrossSection();
    // Big Three
    CrossSection(const CrossSection& other);
    CrossSection& operator=(const CrossSection& other);
    //d'tor
    ~CrossSection();


    // -- Getters & Setters
    int getId() const {return id;}

    int getNumOfRoads() const;

    LinkedList<Road> *getRoadsTo() const;

    void addRoad(Road* newRoad);


private:
    void Assign(const CrossSection& other);
    static int count_id;
    int id; // number 1 -> n (n is the number of crossSections)
    int numOfRoads;
    LinkedList<Road>* roadsTo; // -> all the available roads from this CrossSection
};


#endif //POLLUTIONSIMULATOR_CROSSSECTION_H
