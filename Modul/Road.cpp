//
// Created by Mai on 12/18/2021.
//

#include "Road.h"

Road &Road::operator =(const Road& rhs) {
    if(this == &rhs)
        return *this;
    else
        Assign(rhs);
    return *this;

}

Road::Road(const Road &other) : roadLen(other.roadLen){
    pollutionLevel = other.getPollutionLevel();
    from = other.getFrom();
    to = other.getTo();

}
void Road::Assign(const Road &road) {
    pollutionLevel = road.getPollutionLevel();
    from = road.getFrom();
    to = road.getTo();
}

ostream &operator<<(ostream &out, const Road &road) {
    out << setprecision(2) << road.getPollutionLevel();
    return out;
}


