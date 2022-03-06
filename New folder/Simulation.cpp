//
// Created by Mai on 12/22/2021.
//

#include <sstream>
#include "Simulation.h"
#include "../Modul/Metropolis.h"



Simulation::Simulation(): cp(), clockTick(), world(0), fp(FileParse()), numberOfVehicles(0), CarMap(new LinkedList<SortedPair<Car, CrossSection> >()) , SortedCarMap(new LinkedList<SortedPair<Car, CrossSection> >()){}

Simulation::~Simulation() {
    delete world->getGraph();
    delete world;

}

void Simulation::load(const string& firstFile, const string& secondFile, int ticks, double pLevel) {

    unsigned int size = FileParse::getSize(firstFile);

    double **graph = new double *[size];
    valMap = new double *[size];
    string *vehiclePos = new string[size];
    int carCount = 0;
    setSimulationValues(pLevel, ticks);
    Car::setConstantPollutionLevel(pLevel);

    for (int i = 0; i < size; i++) {
        graph[i] = new double[size];
        valMap[i] = new double[size];
    }

    FileParse::load(firstFile, &graph, &size);
    world = new Metropolis(graph, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            valMap[i][j] = graph[i][j];
        }
    }

    FileParse::load(secondFile, vehiclePos, size);
    stringstream ss;
    string strline;
    for (int line = 0; line < size; line++) {
        ss.clear();
        ss.str(vehiclePos[line]); // stream -> " 1: F4 F7
        ss >> strline; // ss -> " F4 F7, strline -> "1:"
        if (ss.fail()) {
            // error
        }
        CrossSection* cross = world->getGraph()[line];
        while (!ss.eof()) {
            ss >> strline; // ss -> "F7" strline -> "F4"
            if (ss.fail()) {
                // error
            }
            int id = strline[1] - '0';
            if( strline.size() > 2 )    {
                id *= 10;
                id += strline[2] - '0';
            }
            char symbol = strline[0];

            Car* car;

            switch (symbol) { // letter
                case 'F':
                    car = new FamilyCar(id,'F');
                    CarMap->insert(SortedPair<Car, CrossSection>(*car, cross));

                    break;
                case 'S':
                    strline.at(1) >> id;// car id;
                    car = new SportsCar(id,'S');
                    CarMap->insert(SortedPair<Car, CrossSection>(*car, cross));
                    break;
                case 'L':
                    strline.at(1) >> id;// car id;
                    car = new LuxuryCar(id,'L');
                    CarMap->insert(SortedPair<Car, CrossSection>(*car, cross));
                    break;
                case 'M':
                    strline.at(1) >> id;// car id;
                    car = new Maserati(id,'M');
                    CarMap->insert(SortedPair<Car, CrossSection>(*car, cross));
                    break;
                default:
                    numberOfVehicles--;
                    //error
                    break;
            }
            numberOfVehicles++;
        }
    }
}

void Simulation::simulate() {
    sortLL();

    for (int i = 0; i < clockTick; i++)
    {
        moveAll();
        printCarLocation();
        cout << endl;
        printWorld();
    }



}

void Simulation::sortLL() {

    int j;

    for (int i = 1  ; i < numberOfVehicles+1; i++)
    {
        j = 0;
        while (j < numberOfVehicles && (*CarMap)[j]->getKey().getId() != i){j++;}
        SortedCarMap->insert(*((*CarMap)[j]));
    }

}

void Simulation::moveAll() {

    for (int i = 0; i < numberOfVehicles; i++)
    {
        CrossSection* currLocation = (*SortedCarMap)[i]->getVal();
        LinkedList<Road>* availableRoads = currLocation->getRoadsTo();
        int numOfRoads = currLocation->getNumOfRoads();
        Car* p = &(*SortedCarMap)[i]->getKey();
        int destIndex = p->getNextLocation(numOfRoads);
        if(destIndex == numOfRoads)
            continue;
        Road* destRoad = (*availableRoads)[destIndex];
        p->pollute(destRoad);
        (*SortedCarMap)[i]->setVal(destRoad->getTo());
    }
}


void Simulation::printWorld()
{
    unsigned int size = world->getSize();
    //cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        CrossSection *cross = world->getGraph()[i];
        LinkedList<Road> *list = cross->getRoadsTo();
        int numOfRoads = cross->getNumOfRoads();
        int k = 0; //hold the position of the first road in the list;
        for(int j = 0; j < size; j++)
        {
            if(valMap[i][j] != 0 && k < numOfRoads){
                Road* currRoad = (*list)[k];
                double plevel = currRoad->getPollutionLevel();
                valMap[i][j] = round(plevel * 100.0) / 100.0;
               // cout << valMap[i][j] << " ";
                cout << valMap[i][j] << " ";
                k++;
            }else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

void Simulation::printCarLocation() {
    int counter = numberOfVehicles+1;
    for (int i = 0; i < world->getSize(); i++) {
        CrossSection *cross = world->getGraph()[i];
        cout << cross->getId() << ": ";
        for(int j = 1; j < counter; j++){
            if (cross->getId() == (*SortedCarMap)[j]->getVal()->getId()) {
                Car *c = &(*SortedCarMap)[j]->getKey();
                cout << *c << " ";
            }
        }
        cout << endl;
    }
}