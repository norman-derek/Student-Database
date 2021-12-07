/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 5
*/

/*
* Main 
*/

#include "Simulation.h"


int main(int argc, char** argv)
{

    Simulation *sim = new Simulation();

    sim->runSimulation();
    
    delete sim;
    return 0;
}
