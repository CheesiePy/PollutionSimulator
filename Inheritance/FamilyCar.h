#ifndef POLLUTIONSIMULATOREXTEND_FAMILYCAR_H
#define POLLUTIONSIMULATOREXTEND_FAMILYCAR_H
#include "Car.h"

class FamilyCar : public virtual Car{
public:
    FamilyCar(): Car( 0, 'F'){};

    explicit FamilyCar(int id, char symbol): Car(id, symbol){};

    FamilyCar &operator=(const FamilyCar& car){
        if(this == &car) {
            return *this;
        }
        Car::operator=(car);
    };

    virtual ~FamilyCar(){};

    virtual int getNextLocation(int numOfRoads){
        return Car::getNextLocation(numOfRoads);
    }
    virtual double getPollutionLevel() {return Car::getConstantPollutionLevel()*2;}
};


#endif //POLLUTIONSIMULATOREXTEND_FAMILYCAR_H
