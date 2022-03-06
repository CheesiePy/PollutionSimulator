#ifndef POLLUTIONSIMULATOREXTEND_CAR_H
#define POLLUTIONSIMULATOREXTEND_CAR_H


#include <cstdio>
#include <iostream>
#include "../Modul/Road.h"

class Car {
public:
//---Setters & Getters---
    Car& operator=(const Car& car);

    static double getConstantPollutionLevel();
    uint getId() const;
    char getSymbol() const {return symbol;};

    static uint getNumOfCars();

    virtual void pollute(Road* road);

    friend ostream& operator<<(ostream& out, const Car& car){
        out  << car.getSymbol() << car.getId();
        return out;
    }

    virtual int getNextLocation(int numOfRoads);

    static void setConstantPollutionLevel(double setConstantPollutionLevel);

protected:
    Car();
    // --THE BIG THREE--
    explicit Car(int id, char symbol);

    virtual ~Car();

    void setId(uint setId);



    virtual double getPollutionLevel(){return Car::getConstantPollutionLevel();}

    void setSymbol(char setSymbol){
        symbol = setSymbol;
    }

private:

    void Assign(const Car *other);
    char symbol;
    uint id;
    static uint numOfCars;
    static double constantPollutionLevel;
};





#endif //POLLUTIONSIMULATOREXTEND_CAR_H
