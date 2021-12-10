/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 6

Using two late days for this assignment!
*/

/*
* Simulation class, simple class representing a simple simulation 
*/
#ifndef SIMULATION_H
#define SIMULATION_H
#include <iostream>
#include <fstream>
#include "Database.h"

class Simulation {
    public:
        Simulation(); //constructor
        ~Simulation(); //destructor
        void runSimulation(); //runs the simulations
        bool isInteger(string s); //checks if a string is a integer
        void fileProcessor(string studentFile, string facultyFile); //processes file if a file is provided


    private:
        Database *db;
};

#endif