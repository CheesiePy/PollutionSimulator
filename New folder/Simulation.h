//
// Created by Mai on 12/22/2021.
//

#ifndef POLLUTIONSIMULATOR_SIMULATION_H
#define POLLUTIONSIMULATOR_SIMULATION_H

#include <string>
#include "../Modul/Metropolis.h"
#include "FileParse.h"
#include "../Inheritance/Maserati.h"
#include"../Data_Structures/SortedPair.h"



class Simulation {
public:
    Simulation();
    //d'tor
    ~Simulation();
    // load -> use fileparse to load the data to world
    void load(const string& fileName,const string& secondFile, int ticks = 1000, double pLevel = 1.2);
    //
    void sortLL();
    // move all cars
    void moveAll();
    // run..
    void simulate();

private:
    Simulation(const Simulation& other); // disabled only one allowed
    Simulation& operator=(const Simulation& other); // disabled only one allowed
    // setSimulationValues
    void setSimulationValues(double setCp, int setClockTicks)
    {
        cp = setCp;
        clockTick = setClockTicks;
    }
    //print world
    void printWorld();
    //print car Location;
    void printCarLocation();
    //Class Fields
    LinkedList<SortedPair<Car, CrossSection> >* CarMap;
    LinkedList<SortedPair<Car, CrossSection> >* SortedCarMap;
    int numberOfVehicles;
    double cp; // constant pollution level;
    int clockTick;
    Metropolis *world;
    double **valMap;
    FileParse fp;
};


#endif //POLLUTIONSIMULATOR_SIMULATION_H
