#ifndef POLLUTIONSIMULATOR_METROPOLIS_H
#define POLLUTIONSIMULATOR_METROPOLIS_H
#include "CrossSection.h"

class Metropolis {
public:
    Metropolis();
    Metropolis(double ** graph, unsigned int size);
    ~Metropolis();

    CrossSection **getGraph() const;
    unsigned int getSize() const;



private:
    void setGraph(CrossSection **graph);
    void setSize(unsigned int size);
    CrossSection** Graph;
    unsigned int size;
};


#endif //POLLUTIONSIMULATOR_METROPOLIS_H
