#include <iostream>
#include <cstdlib>
#include "Simulator/Simulation.h"
using namespace std;

int main(int argc, char ** argv)    {

    if( argc > 3 )  {
        cerr << "ERROR: invalid numbers of arguments to program." << endl;
        exit(1); // TODO : handle correctly according to exercise requirements.
    }
    srand((unsigned) time(NULL));
    int ticks;
    double pLevel;
    cin >> ticks;
    cout << endl;
    cin >> pLevel;
    Simulation simulation;
    simulation.load(string(argv[1]), string(argv[2]), ticks, pLevel);
    simulation.simulate();
    return 0;
}