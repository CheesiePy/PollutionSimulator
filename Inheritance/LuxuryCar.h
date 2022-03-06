#ifndef POLLUTIONSIMULATOREXTEND_LUXURYCAR_H
#define POLLUTIONSIMULATOREXTEND_LUXURYCAR_H
#include "Car.h"

class LuxuryCar : public virtual Car{
public:
    LuxuryCar(): Car(0,'L'){};

    explicit LuxuryCar(int id, char symbol='L'): Car( id, symbol){};

    LuxuryCar &operator=(const LuxuryCar& car){
        if(this == &car) {
            return *this;
        }
        Car::operator=(car);
    };

    virtual ~LuxuryCar(){};

    virtual int getNextLocation(int numOfRoads){
        int x = rand() + 1 % 2;
        if(x == 0)
            return 0;
        return (rand() % numOfRoads - 1) + 1;

    };

    virtual double getPollutionLevel() {return Car::getConstantPollutionLevel()*3;}
};


#endif //POLLUTIONSIMULATOREXTEND_LUXURYCAR_H
