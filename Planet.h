/* CSCI Spring 2022
Author: Brendan Nash
Recitation: 102 - Nikhith Sannidhi
Project 3 - Planet class
*/



#ifndef PLANET_H
#define PLANET_H
#include <iostream>
 
 
 using namespace std;

 class Planet
 {
    private:
    string firstName;
    string secondName;
    string triviaQ;
    string arr[5];
    string answers[4];
    string rightAns;
    string alienName;
    double diameter;
    double capacity;
    int fuelForPlanet;


    public: 
    Planet();
    Planet(string firstName, string secondName, double diameter);
    
    void setFirstName();
    void setSecondName();
    void setDiameter();
    void setCapacity();
    void setFuelForPlanet(int);
    void setTrivia();
    void setAlienName();

    string getAlienName();
    string getTrivia();
    string getFirstName();
    string getSecondName();
    double getDiameter();
    int getCapacity();
    int getFuelForPlanet();
};
#endif