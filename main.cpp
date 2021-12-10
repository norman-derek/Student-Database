/* 
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 6

Using two late days for this assignment!
*/

/*
* Main 
*/

#include "Simulation.h"


int main(int argc, char** argv)
{

    Simulation *sim = new Simulation(); 

    sim->runSimulation(); //runs simulation
    
    delete sim;
    return 0;
}
