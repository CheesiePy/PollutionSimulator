#ifndef POLLUTIONSIMULATOREXTEND_SPORTSCAR_H
#define POLLUTIONSIMULATOREXTEND_SPORTSCAR_H
#include "Car.h"

class SportsCar :  public virtual Car{
    public:
    SportsCar():Car( 0, 'S'){};

    explicit SportsCar( int id, char symbol = 'S'): Car( id, symbol){};

    SportsCar &operator=(const SportsCar& car){
            if(this == &car) {
                return *this;
            }
            Car::operator=(car);
        };

        virtual ~SportsCar(){};

        virtual int getNextLocation(int numOfRoads){
            int random = 0;
            while(random == 0){
                random = Car::getNextLocation(numOfRoads+1);
            }
            return random;
        };

        virtual double getPollutionLevel() {return Car::getConstantPollutionLevel()*4;}
    };



#endif //POLLUTIONSIMULATOREXTEND_SPORTSCAR_H
