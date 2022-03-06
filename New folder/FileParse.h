//
// Created by Mai on 12/22/2021.
//

#ifndef POLLUTIONSIMULATOR_FILEPARSE_H
#define POLLUTIONSIMULATOR_FILEPARSE_H
#include <iostream>

using namespace std;


class FileParse {
public:
    //
    FileParse();
    // d'tor
    ~FileParse();

    //First File:
    static void load(const string& fileName, double*** graph,unsigned int* size);
    static unsigned int getSize(const string& fileName);
    //Second File:
    static void load(const string& fileName, string carsLocation[], unsigned int size);
private:
    // = operator
    FileParse& operator=(const FileParse& other);

};


#endif //POLLUTIONSIMULATOR_FILEPARSE_H
