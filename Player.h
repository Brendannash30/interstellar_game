/* CSCI Spring 2022
Author: Brendan Nash
Recitation: 102 - Nikhith Sannidhi
Project 3 - Player class
*/


#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
 
 
 using namespace std;

 class Player
 {
    private:
    string playerName;
    int money;
    int fuelGallons;
    double health;
    int weapon1;
    int weapon2;
    int suit;
    int medkits;
    int suitHealth;
    bool translator;
    
    


    public: 
    Player();
    Player(string);
    
    
    void subtractMoney(int);
    void addMoney(int);
    void addFuelGallons(int);
    void subtractFuelGallons(int);
    void setWeapon1(int);
    void setWeapon2(int);
    void setSuit(int);
    void setMedkits(int);
    void setTranslator();
    void addHealth(double);
    void subtractHealth(double);
    void setSuitHealth(int);
    void setWeapon1n2(int);
    void subtractSuitHealth(int);
    
    
    
    int getSuitHealth();
    bool getTranslator();
    int getMedkits();
    double useMedkits();
    int getMoney();
    int getFuelGallons();
    string getWeapon1();
    string getWeapon2();
    int getSuit();
    double getHealth();
};
#endif