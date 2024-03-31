/* CSCI Spring 2022
Author: Brendan Nash
Recitation: 102 - Nikhith Sannidhi
Project 3 - Player class member functions
*/


#include "Player.h"
#include "Map.h"
#include <random>
#include <time.h>
#include <fstream>


//CONSTRUCTORS, SET DEFAULT VALUES FOR PLAYER CLASS, PARAMATERIZED ONE TAKES PLAYER NAME.

Player::Player()
{
   string playerName = "";
    money = 100000;
    fuelGallons = 200000;
    health = 100;
    weapon1 = 1;
    suit = 1;
    suitHealth = 100;
    medkits = 0;
    translator = false;
}


Player::Player(string playerName_)
{
    playerName = playerName_;
    money = 100000;
    fuelGallons = 200000;
    health = 100;
    weapon1 = 1;
    suit = 1;
    medkits = 0;
    translator = false;
   
}
//SUBTRACTS MONEY
void Player::subtractMoney(int cost_)
{
    int temp = getMoney();
    temp -=cost_;
    if (temp<=0)
    {
        cout<<"You are too broke for this."<<endl;
    }
    else
    money-= cost_;
}
//ADDS MONEY
void Player::addMoney(int cost_)
{
    money += cost_;
}



//ADDS GALLONS OF FUEL TO TANK
void Player::addFuelGallons(int gallons_)
{
    fuelGallons += gallons_;
}
//SUBTRACTS FUEL GALLONS FROM TANK
void Player::subtractFuelGallons(int subGallons)
{
    fuelGallons -= subGallons;
}

//SETS WEAPON 1
void Player::setWeapon1(int weapon_)
{
    weapon1 = weapon_;
    
    
    
}  
//SETS WEAPON 2 
void Player::setWeapon2(int weapon_)
{
    weapon2 = weapon_;
} 

//SETS WEAPON 1 AND 2
void Player::setWeapon1n2(int weapon_)
{
    weapon1 = weapon_;  
    weapon2 = weapon_;
}


//SETS SPACE SUIT GRADE
void Player::setSuit(int suit_)
{
    int temp = getMoney();
    
    suitHealth = 100;
    if(suit_==2 && temp>5000)
    {
        money-=5000;
        suit = 2;
    }
    else if(suit_==3 && temp > 10000)
    {
        money-=10000;
        suit = 3;
    }
    else if(suit_==4 && temp > 15000)
    {
        money-=15000;
        suit = 4;
    }
    else if(suit_==5 && temp > 20000)
    {
        money-=20000;
        suit = 5;
    }
    else
    {
        cout<<"You are too broke for this."<<endl;
    }
}


//SETS WHETHER OF NOT YOU GET A TRANSLATOR
void Player::setTranslator()
{
    translator = true;
}

//SETS NUMBER OF MEDKITS
void Player::setMedkits(int numMedkits_)
{
    medkits += numMedkits_;
    
}
//SETS SUIT HEALTH
void Player::setSuitHealth(int suitDownBy)
{
    suitHealth -= suitDownBy;
}

//ADDS HEALTH
void Player::addHealth(double healthUpBy_)
{
    health += healthUpBy_;
}
//SUBTRACTS HEALTH
//USES MEDKITS WHEN HEALTH DROPS BELOW 60
void Player::subtractHealth(double healthDownBy_)
{
    health-= healthDownBy_;
    if(health <= 60 && medkits > 1)
    {
        useMedkits();
    }
}

//USES MEDKIDS 
double Player::useMedkits()
{
    health += .4*health;
    medkits--;
    return health;
}

//GETTERS FOR ALL VARIABLES FOLLOWING.
//WEAPONS RETURN STRINGS BASED ON WHAT NUMBER IS CHOS


bool Player::getTranslator()
{
    return translator;
}

int Player::getMedkits()
{
    return medkits;
}



int Player::getMoney()
{
    return money;
}

int Player::getFuelGallons()
{
    return fuelGallons;
}

string Player::getWeapon1()
{
    if (weapon1 == 1)
    {
        return "Light Saber";
    }
     else if (weapon1 == 2)
    {
        return "Blaster";
    }
     else if (weapon1 == 3)
    {
        return "Beam Gun";
    }
    return "";
}
string Player::getWeapon2()
{
    if (weapon2 == 1)
    {
        return "Light Saber";
    }
     else if (weapon2 == 2)
    {
        return "Blaster";
    }
     else if (weapon2 == 3)
    {
        return "Beam Gun";
    }
    return "";
}
int Player::getSuitHealth()
{
    return suitHealth;
}
double Player::getHealth()
{
    return health;
}
int Player::getSuit()
{
    return suit;
}