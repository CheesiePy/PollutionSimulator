//
// Created by Mai on 12/18/2021.
//

#include "Metropolis.h"

Metropolis::Metropolis(double **graph, unsigned int Size):Graph(new CrossSection*[Size]), size(Size)    {

    for(int i = 0; i < size; i++){
        Graph[i] = new CrossSection();
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if( graph[i][j] != 0)  {
                Graph[i]->addRoad(new Road(Graph[i],Graph[j],graph[i][j]));
            }
        }
    }
}

Metropolis::Metropolis() {

}

Metropolis::~Metropolis() {}
// Getters & Setters
CrossSection **Metropolis::getGraph() const {return Graph;}

void Metropolis::setGraph(CrossSection **graph) {Graph = graph;}

unsigned int Metropolis::getSize() const {return size;}

void Metropolis::setSize(unsigned int size) {Metropolis::size = size;}
