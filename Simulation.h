#ifndef SIMULATION_H
#define SIMULATION_H
#include <iostream>
#include "Database.h"

class Simulation {
    public:
        Simulation(); //constructor
        ~Simulation(); //destructor
        void runSimulation(); //runs the simulations
        bool isInteger(string s); //checks if a string is a integer


    private:
        Database *db;
};

#endif