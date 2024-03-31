/* CSCI Spring 2022
Author: Brendan Nash
Recitation: 102 - Nikhith Sannidhi
Project 3 - Planet class member functions
*/


#include "Planet.h"
#include <random>
#include <time.h>
#include <fstream>
#include <algorithm> 


//CONSTRUCTORS SET DEFAULT VALUES
//PARAMETERIZED CONSTRUCTOR NOT NEEDED
Planet::Planet()
    {
        firstName = "";
        secondName = "";
        diameter = 0;
        capacity = 0;
        fuelForPlanet = 0;

    } 
    
    
Planet::Planet(string firstName_, string secondName_, double diameter_)
    {
        firstName = firstName_;
        secondName = secondName_;
        diameter = diameter_;
    }


//RANDOMLY GENERATES 6 DIGITS FROM 0-9 AND A-Z (CAPS)
//FIRST NAME OF PLANET
void Planet::setFirstName()
    {
        int random;
        firstName="";
        srand(time(NULL));
        for (int i=0; i <6; i++)
        {
            random = rand()%37;
            if (random >= 0 && random <= 9)
            {
                random += 48;
                firstName += random;
            }
            else if (random >= 10 && random <= 36)
            {
                random += 55;
                firstName += random;
            }

        }
        
    }
//RANDOMLY PULLS NAMES FROM 4let.txt FILE
//SECOND PART OF PLANET NAME
void Planet::setSecondName()
    {   int random = 0;
        int numOfLines = 0;

        
        ifstream fin;  
        fin.open("4let.txt");   
        string line;
        

        srand(time(NULL));
        random = rand() % 3124;

    while(getline(fin, line))
    {
        ++numOfLines;

        if(numOfLines == random)
        {
            secondName = line;
            break;
        }
    }
}

//READS RANDOM LINE FROM alienName.txt FILE
//AISIGNS TO ALIEN IN BATTLE
void Planet::setAlienName()
    {   int random = 0;
        int numOfLines = 0;

        
        ifstream fin;  
        fin.open("alienName.txt");   
        string line;
        

        srand(time(NULL));
        random = rand() % 20;

    while(getline(fin, line))
    {
        ++numOfLines;

        if(numOfLines == random)
        {
           alienName = line;
            break;
        }
    }
}
//SETS DIAMETER OF PLANET
//RANDOMLY GENTERATES # BETWEEN 1 AND 16  AND DIVIDES THEM BY 2.
//SETS NUMBER FROM 1 - 8. INTERVALS OF .5 INCLUDED
void Planet::setDiameter()
    {
        srand(time(NULL));
        diameter = ((rand()%15)+2)/2.0;           //generates random # between 0 and 14, ads 2 and divides by 2 to get incriments of .5
        
    }
//USES DIAMETER OF PLANET TO SET CAPACITY
void Planet::setCapacity()
    {
        capacity =  diameter * 615;
        
    }

//RECURSIVE HELPER THAT SETS FUEL NEEDED TO TRAVEL TO NEXT PLANET.
int setFuelForPlanetHelper(int i)
    {
        if(i==1)
        {
           return 50000;
        }
        else
        {
            return setFuelForPlanetHelper(i-1) * setFuelForPlanetHelper(i-1)/1000000 + setFuelForPlanetHelper(i-1);
        }

    }
//FUNCTION CALLING FUEL FOR PLANET HELPER. RECURSIVE.
void Planet::setFuelForPlanet(int i)
    {
        fuelForPlanet = setFuelForPlanetHelper(i);
    }
//READS RANDOM LINE FROM questions.txt FILE
//WHEN ANSWERED IN GAME, DATA ON HABITABILITY OF A SITE IS ACCESSED
void Planet::setTrivia()
{
    {   
        int random = 0;
        int numOfLines = 0;

        
        ifstream fin;  
        fin.open("questions.txt");   
        string line;
        

        srand(time(NULL));
        random = rand() % 86;

    while(getline(fin, line))
    {
        ++numOfLines;

        if(numOfLines == random)
        {
            triviaQ = line;
            break;
        }
    }
    }
}


//GETTERS FOR ALL PRIVATE DATA MEMBERS.

string Planet::getAlienName()
{
    return alienName;
}
string Planet::getTrivia()
{
    return triviaQ;
}

string Planet::getFirstName()
    {
        return firstName;
    }
string Planet::getSecondName()
    {
        return secondName;
    }
double Planet::getDiameter()
    {
        return diameter;
    }
int Planet::getCapacity()
    {
        return capacity;
    }
    
int Planet::getFuelForPlanet()
    {
        return fuelForPlanet;
    }
    
