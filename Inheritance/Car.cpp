#include "Car.h"

double Car::constantPollutionLevel = 0;
uint Car::numOfCars = 0;


Car::Car(): id(0), symbol('\0'){Car::numOfCars++;}


Car::~Car() {

}

Car &Car::operator=(const Car& other) {
    if(this == &other){
        return *this;
    }else{
        Assign(&other);
    }
    return *this;
}

void Car::Assign(const Car *other){
    setId(other->getId());
}

Car::Car(int id, char symbol):id(id), symbol(symbol){Car::numOfCars++;}

// Setters & Getters imp


double Car::getConstantPollutionLevel() {
    return constantPollutionLevel;
}

void Car::setConstantPollutionLevel(double setConstantPollutionLevel) {
    Car::constantPollutionLevel = setConstantPollutionLevel;
}

uint Car::getId() const {
    return id;
}

void Car::setId(uint setId) {
    Car::id = setId;
}

uint Car::getNumOfCars() {
    return numOfCars;
}

void Car::pollute(Road* road){
    road->pollute(getPollutionLevel());

}

int Car::getNextLocation(int numOfRoads) {
    return rand() % numOfRoads;
}


