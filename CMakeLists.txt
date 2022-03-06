cmake_minimum_required(VERSION 3.19)
project(PollutionSimulatorExtend)

set(CMAKE_CXX_STANDARD 98)

add_executable(PollutionSimulatorExtend main.cpp
        Data_Structures/SortedPair.h Data_Structures/LinkedList.h
        Data_Structures/LinkedList_imp.h
        Inheritance/Car.cpp Inheritance/Car.h
        Simulator/FileParse.h
        Simulator/FileParse.cpp
        Simulator/Simulation.cpp
        Simulator/Simulation.h
        Modul/Metropolis.h
        Modul/Metropolis.cpp
        Modul/CrossSection.h
        Modul/CrossSection.cpp
        Modul/Road.h
        Modul/Road.cpp
        Inheritance/FamilyCar.h Inheritance/SportsCar.h Inheritance/LuxuryCar.h Inheritance/Maserati.h)