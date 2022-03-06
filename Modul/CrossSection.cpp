#include "CrossSection.h"
int CrossSection::count_id = 0;

CrossSection &CrossSection::operator =(const CrossSection &other) {
    if(this == &other)
        return *this;
    else
        Assign(other);
    return *this;
}

int CrossSection::getNumOfRoads() const {return numOfRoads;}

LinkedList<Road>* CrossSection::getRoadsTo() const {return roadsTo;}

CrossSection::~CrossSection(){}

CrossSection::CrossSection(const CrossSection &other):id(other.id){
    roadsTo = other.getRoadsTo();
    numOfRoads = other.getNumOfRoads();
}

CrossSection::CrossSection():id(++count_id), numOfRoads(0), roadsTo(new LinkedList<Road>()) {}

void CrossSection::addRoad(Road *newRoad) {
    roadsTo->insert(*newRoad);
    this->numOfRoads++;
}

void CrossSection::Assign(const CrossSection &other)
{
    //id = other.id;
    numOfRoads = other.getNumOfRoads();
    roadsTo = other.getRoadsTo();
}
