#ifndef POLLUTIONSIMULATOREXTEND_MASERATI_H
#define POLLUTIONSIMULATOREXTEND_MASERATI_H
#include "SportsCar.h"
#include "LuxuryCar.h"
#include "FamilyCar.h"

class Maserati :public LuxuryCar, public SportsCar{
public:
    Maserati():Car(0,'M'), LuxuryCar( 0, 'M'),SportsCar( 0, 'M'){};
    explicit Maserati( int id, char symbol='M') : Car(id,'M'), LuxuryCar( id, 'M'), SportsCar( id, 'M'){}

    Maserati &operator=(const Maserati& car){
        if(this == &car) {
            return *this;
        }
        Car::operator=(car);
    };

    virtual double getPollutionLevel() {
        return LuxuryCar::getPollutionLevel();
    };

    virtual int getNextLocation(int numOfRoads) {
        return SportsCar::getNextLocation(numOfRoads);
    }
};


#endif //POLLUTIONSIMULATOREXTEND_MASERATI_H
