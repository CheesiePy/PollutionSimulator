#include "FileParse.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

FileParse::FileParse() {}

FileParse::~FileParse() {}

unsigned int FileParse::getSize(const string& fileName){
    unsigned int size;
    fstream file;
    stringstream num_parser; // for parsing numbers (float or integers) and validating them using stringstream.
    file.open(fileName.c_str(), ios::in);
    string buffer;
    getline(file,buffer);

    if(file.eof()){
        cerr << "ERROR: Invalid input." << endl;
        exit(-1);
    }
    num_parser.str(buffer);
    num_parser >> size;
    if(num_parser.fail()){
        cerr << "ERROR: Invalid input." << endl;
        exit(-1);
    }
    file.close();
    return size;
}

void FileParse::load(const string& fileName, double ***graph, unsigned int *size) {
    //cout << fileName << endl;
    fstream file;
    stringstream num_parser; // for parsing numbers (float or integers) and validating them using stringstream.
    file.open(fileName.c_str(), ios::in);

    if( !file ){
        cerr << "ERROR: Invalid input." << endl;
        exit(-1);
    }

    string line;
    getline(file, line);
    if( file.eof() ){
        cerr << "ERROR: Invalid input." << endl;
        exit(-1);
    }
    num_parser.str(line);
    num_parser >> *size;
    if( num_parser.fail() ){
        cerr << "ERROR: Invalid input." << endl;
        exit(-1);
    }

    double temp_val;

    for(int i = 0; i < *size; i++)  {
        num_parser.clear();
        getline(file, line);
        if( file.eof() )    {
            continue;
        }
        num_parser.str(line);
        for(int j = 0; j < *size; j++)  {
            num_parser >> temp_val;
            if( num_parser.fail() ) {
                continue;
            }
            (*graph)[i][j] = temp_val;
        }
    }
    file.close();

}

void FileParse::load(const string &fileName, string* carsLocation, unsigned int size) {
    fstream file;
    file.open(fileName.c_str(), ios::in);
    if (!file) {
        cerr << "ERROR: Invalid input." << endl;
        exit(-1);
    }
    string line;
    for(int i =0 ; i < size ; i++) {
        getline(file, carsLocation[i]);
    }
    file.close();
}
