/* CSCI Spring 2022
Author: Brendan Nash
Recitation: 102 - Nikhith Sannidhi
Project 3 -  INTERSTELLAR
*/




#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Planet.h"
#include "Map.h"
#include "Player.h"
#include <unistd.h>


using namespace std;



int main()
{
    Player play;
    Map map;
    Planet plan;
    //Character team;
    string playerName;
    int crew1, crew2;

    cout<<"Hello space traveler, what is your name?"<<endl;
    cin>>playerName;


    //PLAYER SELECTION
    //uses vectors to show selection of characters.
    vector<string> num{"1. ","2. ","3. ","4. "};
    vector<string> crew{"Lola", "Nerys", "Millie", "Chuck"};
    vector<string> title{" Doctor", " Fighter", " Tycoon", " Intimidator" };
    vector<string> job{"Ability: Lola is a very successful healer and doctor and will make you gain 5% health each time you lose health after a battle.", "Ability: Nerys is a world-class warrior and weapons operator, increase your odds of winning a battle with hostile aliens by 10%.","Ability: Millie is an fuel tycoon and will allow you to start with double the fuel.","Ability: Chuck was once part of the CIA and is very charismatic and intimidating, the friendly alien will be 10% more likely to tell the truth."};
    vector<string> teamstore{};
    cout<<endl<<"Pick a crewmate to help you with your journey!"<<endl<<endl;
    for (int i=0; i<4; i++)
    {
        cout<<num.at(i);
        cout<<crew.at(i);
        cout<<title.at(i)<<endl;
        cout<<job.at(i)<<endl<<endl;
    }
    cin>>crew1;
    cout<<"Great choice! "<<crew[crew1-1]<<" will bring a lot to your team. Pick your last crewmate."<<endl<<endl;
    
    //erases already chosen character from vector
    teamstore.push_back(crew.at(crew1-1));
    num.erase(num.begin()+crew1-1);
    crew.erase(crew.begin()+crew1-1);
    title.erase(title.begin()+crew1-1);
    job.erase(job.begin()+crew1-1);

    for (int i=0; i<3; i++)
    {
        cout<<num.at(i);
        cout<<crew.at(i);
        cout<<title.at(i)<<endl;
        cout<<job.at(i)<<endl<<endl;
    }

    cin>>crew2;
    while (crew2 == crew1)
    {
        cout<<teamstore[0]<<" is already on your team. Please enter new character."<<endl;
        cin>>crew2;
    }
    if(crew1 == 3 || crew2 == 3)
    {
        play.addFuelGallons(200000);
    
        cout<<"Millie doubled your fuel and now your tank is full with "<<play.getFuelGallons()<<" gallons."<<endl<<endl;
    
    }

    cout<<endl<<"You have a very impressive crew "<<playerName<<". With your leadership, you will be sure to succeed."<<endl<<endl;

    cout<<"WEAPONS. If your weapon breaks or if you lose your weapon during an event, you may need additional weapons to defend yourself!"<<endl;
    cout<<"TRANSLATOR. Allows you to communicate with friendly aliens to get their assessment of the planet and increases odds of winning against a hostile alien."<<endl;
    cout<<"SPACE SUIT. The better the spacesuit, the more durable and protective you will be during the mission and an alien attack."<<endl;
    cout<<"MEDICAL KITS. The more kits you have, the more times you can revive your health by 40%."<<endl;
    cout<<"FUEL. Fuel is an essential element for the spacecraft to travel to more planets."<<endl<<endl;

    cout<<"You can spend all of your money here before you start your journey, or you can save some to spend on different resources along the way. You will also gain money for each turn as you move through the game."<<endl<<endl;

    cout<<"Hit enter when you have understood."<<endl<<endl;
    bool quit=true;
    cin.ignore(2,'\n');
    while(quit )    
    {
        if(cin.get()=='\n')
        {
            quit = false;
    
        }
    }



//FIRST RESOURCE CENTER VISIT
//START WITH STOCK STATS
 {
    
    int resource;
    int quant=0;
    int num = 0;
    string yesno;
    int temp = play.getMoney();
    bool phase1=true;
   
    while (phase1)
    {
    cout<<"Welcome to the Recource Center."<<endl<<"Select number of item you wish to purchase."<<endl;
    cout<<"1. Medical Kits"<<endl<<"2. Fuel"<<endl<<"3. Translators"<<endl<<"4. Space Suits"<<endl<<"5. Weapons"<<endl<<"6. Leave"<<endl;
    cin>>resource;
    switch (resource)
    {
        case 1:
            cout<<"Enter quantity of medkits you'd like."<<endl;
            cin>>quant;
            while(quant>5 || quant<0)
            {
            cout<<"You cannot have more than 5 kits. Please enter new quantity"<<endl;
            cin>>quant;
            }
           
            play.setMedkits(quant);
            play.subtractMoney(quant*2000);
            cout<<"You now have "<<play.getMedkits()<<" medkits"<<endl;
            cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
           
            break;
        case 2:
            cout<<"How many gallons of fuel would you like? (Must be in incriments of 10000)."<<endl;
            cin>>quant;
            if(play.getFuelGallons()+quant>40000)
            {
                cout<<"This is too much fuel for your tank"<<endl<<endl;
            }
            else
            {
                while (quant%10000 != 0)
                {
                cout<<"Must be incriments of 10000 gallons. Please enter new value."<<endl;
                cin>>quant;
                
               
                    play.addFuelGallons(quant);
                    play.subtractMoney(quant/ 10);
                    cout<<"You now have "<<play.getFuelGallons()<<" gallons of fuel."<<endl;
                    cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                
                
            }
            break;
        case 3:
            if (play.getTranslator()==false)
            {
            cout<<"Would you like a translator? (space travelers limited to one at a time)."<<endl;
            cout<<"enter y for yes, or n for no."<<endl;
            cin>>yesno;
                if (yesno != "y" && yesno!= "n")
                {
                cout<<"Please enter valid input."<<endl;
                }
                else if (yesno == "y")
                {
                    
                    play.setTranslator();
                    play.subtractMoney(5000);
                    cout<<"You now have one translator."<<endl;
                    cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                    
                    
                    break;
                }
                else if (yesno == "n")
                {
                    break;
                }
            }
            else 
            {
                cout<<"You already have a translator."<<endl;
                break;
            }
        case 4:
        {
            vector<int> suit{2,3,4,5};
            int suitnum;

            if (play.getSuit()==1)
            {
            cout<<"Which grade spacesuit would you like? ";
                for(int i=0; i<4; i++)
                {
                cout<<suit.at(i)<<" ";
                }
            cout<<endl;
            cin>>suitnum;
             if(suitnum<2 || suitnum >5)
                {
                    cout<<"Please enter a valid suit number"<<endl;
                }
            else
            {
                play.setSuit(suitnum);
                cout<<"You now have suit "<<suitnum<<"."<<endl;
                cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
            }

            }
            else
            {
                suit.erase(suit.begin()+suitnum-2);
                cout<<"Which grade spacesuit would you like? ";
                for(int i=0; i<3; i++)
                {
                cout<<suit.at(i)<<" ";
                }
                cout<<endl;
                cin>>suitnum;
                if(suitnum<2 || suitnum >5)
                {
                    cout<<"Please enter a valid suit number"<<endl;
                }
                else
                {
                play.setSuit(suitnum);
                cout<<"You now have suit "<<play.getSuit()<<"."<<endl;
                cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                }
            }
            break;
        }
        case 5:
        
           // int choice3;
            cout<<"What weapon would you like to buy?"<<endl;
            cout<<"1. Light Saber"<<endl<<"2. Blaster"<<endl<<"3. Beam Gun"<<endl;
            cin>>num;
            cout<<"How many would you like?"<<endl;
            cin>>quant;

            
            while (quant>2 || quant<0)
            {
                cout<<"You can carry up to two weapons, enter valid ammount"<<endl;
                cin>>quant;
            }
            
            
            if(quant == 2)
            {
            
                play.setWeapon1n2(num);
                if(num == 1)
                    play.subtractMoney(2000);
                else if(num == 2)
                    play.subtractMoney(4000);
                else if(num == 3)
                    play.subtractMoney(10000);
            
            }
        
           if (quant == 1)
            {
                if (play.getWeapon2() != "")
                {
                    play.setWeapon1(num);
                    
                    
                }
                else
                    play.setWeapon2(num);
                if(num == 1)
                    play.subtractMoney(1000);
                else if(num == 2)
                    play.subtractMoney(2000);
                else if(num == 3)
                    play.subtractMoney(5000);
            }
        

            cout<<"You are packing the "<<play.getWeapon1()<<" and the "<<play.getWeapon2()<<"."<<endl;
            cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
            break;
        case 6:
            phase1 = false;
            break;
        default:
            cout<<"Enter valid choice."<<endl;
            break;
    }
    }
}





cout<<"Ok, ready to explore your first planet?"<<endl;
bool quit2=true;
cin.ignore(1,'\n');

while(quit2 )
{
    if(cin.get()=='\n')
    {
    quit2 = false;
    
    }
}

//COUNTDOWN
cout<<"T MINUS"<<endl;
for(int i=10; i>0;i--)
{
    cout<<i<<endl;
    usleep(1000000);
}
cout<<"BLAST OFF!!"<<endl;
//initializing phase 2
bool phase2 = true;
int planetsExplored=1;
int planetsHabitable=0;
int inaccurateHabitable=0;
int humansSaved=0;
int humansPerished=0;
vector<string> logvec{};

int vect;

//PHASE 2 OUTER LOOP
//INTERATES WHEN YOU BLAST OFF AND WHEN YOU GO TO A NEW PLANET
//CREATES NEW PLANET
while (phase2)
{   
    
    string logBookEntry = "";
    plan.setSecondName();  plan.setFirstName();
    string planetName = plan.getFirstName()+"-"+plan.getSecondName();
    map.resetMap();
    cout<<"This planet is called: "<<planetName<<endl;
    srand(time(NULL));
    int nummisf = 0;
    int row2 = rand() % 12;
    int col2 = rand() % 12;
    map.spawnNPC(row2, col2);
    //vector<string> logbook{};
    
    
    for(int i=0; i<8; i++)
        {
            int habType =rand() % 6;
            int row1 = rand() % 12;
            int col1 = rand() % 12;
            map.spawnSite(row1, col1, habType);
        }
    
        int misf=rand() %4+4;
    
        for(int i=0; i<misf; i++)
        {
            int misfType =rand() % 4;
            int row3 = rand() % 12;
            int col3 = rand() % 12;
            bool misfmark = map.spawnMisfortune(row3, col3, misfType);
        }
        map.displayMap(); 
  
    //INNER PHASE 2 LOOP
    //ALLOWS PLAYER TO MOVE AND CYCLE THROUGH THE MAIN MENUE
    bool menu = true;
    while (menu)
    { 
        
        
        
                
        
       
        int choice;
        cout<<"Select one"<<endl<<"1. Move"<<endl<<"2. View status"<<endl<<"3. View log book"<<endl<<"4. Resource center"<<endl<<"5. Report planet as habitable"<<endl<<"6. enter wormhole"<<endl <<"7. give up"<<endl;
       cin>>choice; 
        cout<<choice<<endl;
       //MAIN GAME MENUE
        switch (choice)
        { 
          
            case 1:
               { 
                
                char playerMove;
                cout<<"Which way would you like to move?"<<endl;
                cout<<"w up"<<endl;
                cout<<"s down"<<endl;
                cout<<"a left"<<endl;
                cout<<"d right"<<endl;
                cin>>playerMove;
                cout<<playerMove<<endl;

               
                
                
                if(map.executeMove(playerMove) == false)   //tells game which way character will go.
                {
                   cout<<"You have failed to move"<<endl;
                }
               break;
               } 
            
            case 2:
                //cout<<play.getFuelGallons()<<endl;
                cout<<"Health:"<<endl<<endl;
                for(int i=0; i<play.getHealth()/10;i++)
                {
                    cout<<"_";
                }
                cout<<play.getHealth()<<"%"<<endl<<endl;
        
                cout<<"Space Suit Health:"<<endl<<endl;
                for(int i=0; i<play.getSuitHealth()/10;i++)
                {
                    cout<<"_";
                }
                cout<<play.getSuitHealth()<<"%"<<endl<<endl;
        
                cout<<"Fuel tank: "<<play.getFuelGallons()<<"gallons"<<endl<<endl;
        
                for(int i=0; i<(play.getFuelGallons()/40000);i++)
                {
                     cout<<"_";
                }
                cout<<play.getFuelGallons()/4000<<"%"<<endl;
                cout<<endl<<endl;
                cout<<"Planets explored: "<<planetsExplored<<endl;
                cout<<"Planets accurately reported habitable: "<<planetsHabitable<<endl;
                cout<<"Planets inaccurately reported habitable: "<<inaccurateHabitable<<endl<<endl<<endl; 
                cout<<"Humans saved (in millions): "<<humansSaved<<endl;
                cout<<"Humans perised (in millions) "<<humansPerished<<endl<<endl<<endl;
                cout<<"Money - "<<play.getMoney()<<endl;
                cout<<"WEAPONS - "<<endl<<"1. "<<play.getWeapon1()<<endl<<"2. "<<play.getWeapon2()<<endl;
                cout<<"TRANSLATOR - ";
                if (play.getTranslator()==true)
                {
                    cout<<"1"<<endl;
                }
                else
                {
                    cout<<"0"<<endl;
                }
                cout<<"SPACE SUIT GRADE #"<<play.getSuit()<<endl;
                cout<<"MEDICAL KITS - "<<play.getMedkits()<<endl;
                break;
    

            //case 3:
               // for(int i=0; i<logbook.size();i++)
               // {
                //  cout<<logbook.at(i)<<endl;
               // }
               // break;
            case 4:
            {
                        
                        int resource;
                        int quant=0;
                        int num = 0;
                        string yesno;
                        int temp = play.getMoney();
                        bool phase1=true;
                    
                        while (phase1)
                        {
                        cout<<"Welcome to the Recource Center."<<endl<<"Select number of item you wish to purchase."<<endl;
                        cout<<"1. Medical Kits"<<endl<<"2. Fuel"<<endl<<"3. Translators"<<endl<<"4. Space Suits"<<endl<<"5. Weapons"<<endl<<"6. Leave"<<endl;
                        cin>>resource;
                        switch (resource)
                        {
                            case 1:
                                cout<<"Enter quantity of medkits you'd like."<<endl;
                                cin>>quant;
                                while(quant>5 || quant<0)
                                {
                                cout<<"You cannot have more than 5 kits. Please enter new quantity"<<endl;
                                cin>>quant;
                                }
                                if(temp >= quant*2000)
                                {
                                play.setMedkits(quant);
                                play.subtractMoney(quant*2000);
                                cout<<"You now have "<<play.getMedkits()<<" medkits"<<endl;
                                cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                                }
                                else
                                {
                                    cout<<"You are too broke for this."<<endl<<endl;
                                }
                                break;
                            case 2:
                                cout<<"How many gallons of fuel would you like? (Must be in incriments of 10000)."<<endl;
                                cin>>quant;
                                if(play.getFuelGallons()+quant>40000)
                                {
                                    cout<<"This is too much fuel for your tank"<<endl<<endl;
                                }
                                else
                                {
                                    while (quant%10000 != 0)
                                    {
                                    cout<<"Must be incriments of 10000 gallons. Please enter new value."<<endl;
                                    cin>>quant;
                                    }
                                    if(temp >= quant/10)
                                    {
                                        play.addFuelGallons(quant);
                                        play.subtractMoney(quant/ 10);
                                        cout<<"You now have "<<play.getFuelGallons()<<" gallons of fuel."<<endl;
                                        cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                                    }
                                    else
                                    {
                                        cout<<"You are too broke for this."<<endl<<endl;
                                    }
                                }
                                break;
                            case 3:
                                if (play.getTranslator()==false)
                                {
                                cout<<"Would you like a translator? (space travelers limited to one at a time)."<<endl;
                                cout<<"enter y for yes, or n for no."<<endl;
                                cin>>yesno;
                                    if (yesno != "y" && yesno!= "n")
                                    {
                                    cout<<"Please enter valid input."<<endl;
                                    }
                                    else if (yesno == "y")
                                    {
                                        if (temp>5000)
                                        {
                                        play.setTranslator();
                                        play.subtractMoney(5000);
                                        cout<<"You now have one translator."<<endl;
                                        cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                                        }
                                        else
                                        {
                                            cout<<"You are too broke for this."<<endl<<endl;
                                        }
                                        break;
                                    }
                                    else if (yesno == "n")
                                    {
                                        break;
                                    }
                                }
                                else 
                                {
                                    cout<<"You already have a translator."<<endl;
                                    break;
                                }
                            case 4:
                            {
                                vector<int> suit{2,3,4,5};
                                int suitnum;
                                if (play.getSuit()==1)
                                {
                                cout<<"Which grade spacesuit would you like? ";
                                    for(int i=0; i<4; i++)
                                    {
                                    cout<<suit.at(i)<<" ";
                                    }
                                cout<<endl;
                                cin>>suitnum;
                                if(suitnum<2 || suitnum >5)
                                    {
                                        cout<<"Please enter a valid suit number"<<endl;
                                    }
                                else
                                {
                                    play.setSuit(suitnum);
                                    cout<<"You now have suit "<<suitnum<<"."<<endl;
                                    cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                                }

                                }
                                else
                                {
                                    suit.erase(suit.begin()+suitnum-2);
                                    cout<<"Which grade spacesuit would you like? ";
                                    for(int i=0; i<3; i++)
                                    {
                                    cout<<suit.at(i)<<" ";
                                    }
                                    cout<<endl;
                                    cin>>suitnum;
                                    if(suitnum<2 || suitnum >5)
                                    {
                                        cout<<"Please enter a valid suit number"<<endl;
                                    }
                                    else
                                    {
                                    play.setSuit(suitnum);
                                    cout<<"You now have suit "<<play.getSuit()<<"."<<endl;
                                    cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                                    }
                                }
                                break;
                            }
                            case 5:
                            
                            // int choice3;
                                cout<<"What weapon would you like to buy?"<<endl;
                                cout<<"1. Light Saber"<<endl<<"2. Blaster"<<endl<<"3. Beam Gun"<<endl;
                                cin>>num;
                                cout<<"How many would you like?"<<endl;
                                cin>>quant;

                                
                                while (quant>2 || quant<0)
                                {
                                    cout<<"You can carry up to two weapons, enter valid ammount"<<endl;
                                    cin>>quant;
                                }
                                if (num == 1)
                                {
                                    if (temp < quant*1000)
                                    {
                                        cout<<"You are too broke for this."<<endl<<endl;
                                    }
                                }
                                if (num == 2 && temp < quant*2000)
                                {
                                cout<<"You are too broke for this."<<endl<<endl;
                                }
                                if (num == 3 && temp < quant*5000)
                                {
                                    cout<<"You are too broke for this."<<endl<<endl;
                                }

                            if(quant == 2)
                                {
                                
                                    play.setWeapon1n2(num);
                                    if(num == 1)
                                        play.subtractMoney(2000);
                                    else if(num == 2)
                                        play.subtractMoney(4000);
                                    else if(num == 3)
                                        play.subtractMoney(10000);
                                
                                }
                            
                            if (quant == 1)
                                {
                                    if (play.getWeapon2() != "")
                                    {
                                        play.setWeapon1(num);
                                        
                                        
                                    }
                                    else
                                        play.setWeapon2(num);
                                    if(num == 1)
                                        play.subtractMoney(1000);
                                    else if(num == 2)
                                        play.subtractMoney(2000);
                                    else if(num == 3)
                                        play.subtractMoney(5000);
                                }
                            

                                cout<<"You are packing the "<<play.getWeapon1()<<" and the "<<play.getWeapon2()<<"."<<endl;
                                cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                                break;
                            case 6:
                                phase1 = false;
                                break;
                            default:
                                cout<<"Enter valid choice."<<endl;
                                break;
                        }
                        } 
                    break;
                    }
                   


            case 6:
            {
                plan.setFuelForPlanet(planetsExplored);
                cout<<"got here!"<<endl;
                if(play.getFuelGallons() < plan.getFuelForPlanet())
                {
                    cout<<"You do not have enough fuel for the next planet! Hit 7 to give up or 4 get some more gas from the resource center."<<endl;
                    break;
                }
                play.subtractFuelGallons(plan.getFuelForPlanet());
                menu = false;
                break;
            }
            case 7: 
            {
                menu=false;
              phase2 = false;
               break;
            }
            default:
                break;

        
        }//endswitch
     
    map.displayMap();//respawns map with player in new position.
      
      
    //NPC INTERACTION.
    //CHOOSE IF YOU WANT TO GAMPLE OR ASK FOR INFORMATION.
    //MUST HAVE TRANSLATOR TO SPEAK TO ALIEN.
    //IF CHUCK IS CREWMATE, ALIEN HAS LOWER PROBABILITY OF LYING
      if (map.isNPCLocation()==true)
        {
            int truth;
            int achoice;
            cout<<"You've met a friendly alien hit 1 to play rock paper scissors to gamble or 2 to ask if the planet is habitable."<<endl;
            cin>>achoice;
           if (achoice == 1)
           {
                int win = 0;
                //sleep(2000);
                for(int i=0; i<3; i++)
                {
                    int alienHand = rand()%3;
                    int playerHand = rand()%3;
                    if(alienHand==0)
                    cout<<"Alien - R === ";
                    else if(alienHand==1)
                    cout<<"Alien - P === ";
                    else if(alienHand==2)
                    cout<<"Alien - S === ";
                    if(playerHand==0)
                    cout<< playerName<<" - R"<<endl;
                    else if(playerHand==1)
                    cout<<playerName<<" - P"<<endl;
                    else if(playerHand==2)
                    cout<<playerName<<" - S"<<endl;
                    if(alienHand == 0 && playerHand == 1)
                    win++;
                    else if(alienHand == 1 && playerHand == 2)
                    win++;
                    else if(alienHand == 2 && playerHand == 0)
                    win++;
                    usleep(2000000);
                }
                 if(win == 2)
                    {
                        cout<<"Congraduations, you win! Here's 20$"<<endl;
                        play.addMoney(20);
                        cout<<"Remaining Funds: "<<play.getMoney()<<"$"<<endl<<endl;
                    }
                    else
                    cout<<"Sorry, you didnt win :(."<<endl;
            }
            if(achoice == 2)
            {
                if(play.getTranslator() == false)
                {
                    cout<<"This alien speenks Gaelic Chinese. Even if you understand Both, you need a translator."<<endl;
                }
                else
                {
                    int convo = rand() % 10;
                    if(map.isHabitable()==false)
                    {
                        if(convo>=0 && convo<3)
                        {
                        cout<<"This planet be vibin for ya bumbleclot peeps mon. Bringem eer from ya Babylon. (The only translator left was from Jamaica)"<<endl;
                        logBookEntry +="Planet Habitable ";
                        }
                        else if (convo>=3 && convo<=9)
                        {
                            cout<<planetName<<" be a Babylon. No fire for da people eer. (The only translator left was from Jamaica)."<<endl;
                            logBookEntry += "Planet Uninhabitable ";
                        }
                    }
                    else if(map.isHabitable()==false && (crew1 == 4 || crew2 == 4))
                    {
                        cout<<"Chuck crosses his arms stares down the alien"<<endl;
                        if(convo>=0 && convo<2)
                        {
                        cout<<"This planet be vibin for ya bumbleclot peeps mon. Bringem eer from ya Babylon. (The only translator left was from Jamaica)"<<endl;
                        logBookEntry += "Planet Habitable ";
                        }
                        else if (convo>=2 && convo<=9)
                        {
                            cout<<planetName<<" be a Babylon. No fire for da people eer. (The only translator left was from Jamaica)."<<endl;
                            logBookEntry += "Planet Uninhabitable ";
                        }   
                    }
                    else if (map.isHabitable()==true && (crew1 == 4 || crew2 == 4))
                    {
                         cout<<"Chuck crosses his arms stares down the alien"<<endl;
                        if(convo>=0 && convo<2)
                        {
                            cout<<planetName<<" be a Babylon. No fire for da people eer. (The only translator left was from Jamaica)."<<endl;
                            logBookEntry += "Planet Uninhabitable ";
                        }
                        else if (convo>=2 && convo<=9)
                        {
                            cout<<"This planet be vibin for ya bumbleclot peeps mon. Bringem eer from ya Babylon. (The only translator left was from Jamaica)"<<endl;
                            logBookEntry += "Planet Habitable ";
                        }
                    }
                    else
                    {
                        if(convo>=0 && convo<=3)
                        {
                            cout<<planetName<<" be a Babylon. No fire for da people eer. (The only translator left was from Jamaica)."<<endl;
                            logBookEntry +="Planet Uninhabitable ";
                        }
                        else if (convo>3 && convo<=9)
                        {
                            cout<<"This planet be vibin for ya bumbleclot peeps mon. Bringem eer from ya Babylon. (The only translator left was from Jamaica)"<<endl;
                            logBookEntry += "Planet Habitable ";
                        }
                    }
                }

            }
        }
        //SITE EXPLORATION
        //IF SITE IS REACHED, TRIVIA QUESTION MUST BE ANSWERED TO GAIN INFORMATION ON THEIR HABITABILITY.
        else if (map.isSiteLocation()==true)
        {
        int ans=0;
        plan.setTrivia();
        cout<<plan.getTrivia()<<endl;
        cin>>ans;
            if (ans==1)
            {

                if (map.getSiteTrait()==0)
                {
                cout<<"One habitablity trait found - Water"<<endl;
                logBookEntry +="Site Habitable ";
                }
                else if (map.getSiteTrait()==1)
                {
                cout<<"One habitablity trait found - Oxygen"<<endl;
               logBookEntry+= "Site Habitable ";
                }
                else if (map.getSiteTrait()==2)
                {
                cout<<"One habitablity trait found - Fertile Soil"<<endl;
                logBookEntry += "Site Habitable ";
                }
                else if (map.getSiteTrait()==3)
                {
                cout<<"One unininhabitablity trait found - Toxic Gas"<<endl;
                logBookEntry+= "Site Uninabitable ";
                }
                else if (map.getSiteTrait()==4)
                {
                cout<<"One uninhabitablity trait found - Extreme Weather"<<endl;
                logBookEntry += "Site Uninhabitable ";
                }
                else if (map.getSiteTrait()==5)
                {
                cout<<"One uninhabitablity trait found - Bad Atmosphere"<<endl;
                logBookEntry+="Site Uninabitable ";
                }
            }
            else
            {
                while (ans != 1)
                {
                    cout<<"Sorry wrong answer!"<<endl;
                    plan.setTrivia();
                    cout<<plan.getTrivia()<<endl;
                    cin>>ans;
                }
            }
        }
       //MISFORTUNES
       //FALL IN CRATOR AND GETTING SICK HAVE SAME PROBABLITY
       //ALIEN BATTER HAS HIGHEST PROBABLITITY, IF ARYS IS YOUR CREWMATE, PROBABILITY OF WINNING INCREASES.
        else if (map.isMisfortuneLocaton() == true)
        {
            nummisf++;
            //map.setMisfortuneCount(nummisf);
            //map.getMisfortuneType(); 
            int misftype = rand()%11;
            if(misftype >=0 && misftype<=2)
            {
                play.subtractHealth(15);
                cout<<"AW FIDDLESTICKS! You fell into a crater."<<endl;
                if(play.getSuit()==1)
                {
                    play.setSuitHealth(40);
                    
                }
                else if(play.getSuit()==2)
                {
                    play.setSuitHealth(30);
                }
                else if(play.getSuit()==3)
                {
                    play.setSuitHealth(25);
                }
                else if(play.getSuit()==4)
                {
                    play.setSuitHealth(20);
                }
                else if(play.getSuit()==5)
                {
                    play.setSuitHealth(15);
                }
                play.subtractHealth(10);
            }
            else if (misftype >=4 && misftype<=6)
            {
                cout<<"You have come down with galactic plague!"<<endl;
                play.subtractHealth(20);

            }
            else if (misftype >=7 && misftype<=11)
            {
                int attack = 0;
                plan.setAlienName();
                cout<<"You are being attacked by "<<plan.getAlienName()<<"!!!!"<<endl;
                cout<<"Will you fight or run?"<<endl<<"1. fight"<<endl<<"2. run"<<endl;
                cin>>attack;
                if (attack == 1)
                {   
                    int weaponchoice;
                    string weapon;
                    int chance1 = rand()%50;
                    cout<<"Choose your Weapon"<<endl<<"1. "<<play.getWeapon1()<<endl<<"2. "<<play.getWeapon2()<<endl;
                    cin>>weaponchoice;
                    if(weaponchoice == 1)
                    {
                        weapon = play.getWeapon1();
                    }
                    else if (weaponchoice== 2)
                    {
                        weapon = play.getWeapon2();
                    }
                    
                    if (crew1 == 2 || crew2 == 2)
                    {
                        cout<<"Nerys is ready to fight!"<<endl;
                        if(weapon == "Light Saber")
                        {
                            if(chance1 >= 30)
                            {
                                cout<<"Nerys helped you kill "<<plan.getAlienName()<<"! Help yourself to his Beam gun."<<endl;
                                if(play.getWeapon2()=="")
                                {
                                    play.setWeapon2(3);
                                }
                                else
                                {
                                  play.setWeapon1(3);  
                                }
                            }
                            else
                            {
                                if (play.getSuit()==1)
                                {
                                    play.setSuitHealth(50);
                                }
                                else if(play.getSuit()==2)
                                {
                                   play.setSuitHealth(40); 
                                }
                                else if(play.getSuit()==3)
                                {
                                   play.setSuitHealth(30); 
                                }
                                else if(play.getSuit()==4)
                                {
                                   play.setSuitHealth(20); 
                                }
                                else if(play.getSuit()==5)
                                {
                                   play.setSuitHealth(20); 
                                }
                                play.subtractHealth(30);
                                cout<<"You and Nery's have lost! :( say goodbye to your "<<weapon<<endl;
                                if (weaponchoice == 1)
                                {
                                    play.setWeapon1(0);

                                }
                                else if (weaponchoice == 2)
                                {
                                    play.setWeapon2(0);
                                }

                            }
                        }
                        else if(weapon == "Blaster")
                        {
                            if(chance1 >= 20)
                            {
                                cout<<"Nerys helped you kill "<<plan.getAlienName()<<"! Help yourself to his Beam gun."<<endl;
                                if(play.getWeapon2()=="")
                                {
                                    play.setWeapon2(3);
                                }
                                else
                                {
                                  play.setWeapon2(3);  
                                }
                            }
                            else
                            {
                                if (play.getSuit()==1)
                                {
                                    play.setSuitHealth(50);
                                }
                                else if(play.getSuit()==2)
                                {
                                   play.setSuitHealth(40); 
                                }
                                else if(play.getSuit()==3)
                                {
                                   play.setSuitHealth(30); 
                                }
                                else if(play.getSuit()==4)
                                {
                                   play.setSuitHealth(20) ;
                                }
                                else if(play.getSuit()==5)
                                {
                                   play.setSuitHealth(20);
                                }
                                play.subtractHealth(30);
                                cout<<"You and Nery's have lost! :( say goodbye to your "<<weapon<<endl;
                                if (weaponchoice == 1)
                                {
                                    play.setWeapon1(0);

                                }
                                else if (weaponchoice == 2)
                                {
                                    play.setWeapon2(0);
                                }

                            }
                        }
                        else if(weapon == "Beam Gun")
                        {
                            if(chance1 >= 10)
                            {
                                cout<<"Nerys helped you kill "<<plan.getAlienName()<<"! Help yourself to his Beam gun."<<endl;
                                if(play.getWeapon2()=="")
                                {
                                    play.setWeapon2(3);
                                }
                                else
                                {
                                  play.setWeapon1(3);  
                                }
                            }
                            else
                            {
                                if (play.getSuit()==1)
                                {
                                    play.setSuitHealth(50);
                                }
                                else if(play.getSuit()==2)
                                {
                                   play.setSuitHealth(40); 
                                }
                                else if(play.getSuit()==3)
                                {
                                   play.setSuitHealth(30); 
                                }
                                else if(play.getSuit()==4)
                                {
                                   play.setSuitHealth(20); 
                                }
                                else if(play.getSuit()==5)
                                {
                                   play.setSuitHealth(20); 
                                }
                                play.subtractHealth(30);
                                cout<<"You and Nery's have lost! :( say goodbye to your "<<weapon<<endl;
                                if (weaponchoice == 1)
                                {
                                    play.setWeapon1(0);

                                }
                                else if (weaponchoice == 2)
                                {
                                    play.setWeapon2(0);
                                }

                            }
                        }
                    
                    
                    }
                    else
                    {
                        
                        cout<<"Time to Fight!"<<endl;
                        if(weapon == "Light Saber")
                        {
                            if(chance1 >= 40)
                            {
                                cout<<"You have killed "<<plan.getAlienName()<<"! Help yourself to his Beam gun."<<endl;
                                if(play.getWeapon2()=="")
                                {
                                    play.setWeapon2(3);
                                }
                                else
                                {
                                  play.setWeapon1(3);  
                                }
                            }
                            else
                            {
                                if (play.getSuit()==1)
                                {
                                    play.setSuitHealth(50);
                                }
                                else if(play.getSuit()==2)
                                {
                                   play.setSuitHealth(40); 
                                }
                                else if(play.getSuit()==3)
                                {
                                   play.setSuitHealth(30); 
                                }
                                else if(play.getSuit()==4)
                                {
                                   play.setSuitHealth(20);
                                }
                                else if(play.getSuit()==5)
                                {
                                   play.setSuitHealth(20); 
                                }
                                play.subtractHealth(30);
                                cout<<"You have lost! :( say goodbye to your "<<weapon<<endl;
                                if (weaponchoice == 1)
                                {
                                    play.setWeapon1(0);

                                }
                                else if (weaponchoice == 2)
                                {
                                    play.setWeapon2(0);
                                }

                            }
                        }
                        else if(weapon == "Blaster")
                        {
                            if(chance1 >= 30)
                            {
                                cout<<"You have killed "<<plan.getAlienName()<<"! Help yourself to his Beam gun."<<endl;
                                if(play.getWeapon2()=="")
                                {
                                    play.setWeapon2(3);
                                }
                                else
                                {
                                  play.setWeapon1(3);  
                                }
                            }
                            else
                            {
                                if (play.getSuit()==1)
                                {
                                    play.setSuitHealth(50);
                                }
                                else if(play.getSuit()==2)
                                {
                                   play.setSuitHealth(40); 
                                }
                                else if(play.getSuit()==3)
                                {
                                   play.setSuitHealth(30); 
                                }
                                else if(play.getSuit()==4)
                                {
                                   play.setSuitHealth(20) ;
                                }
                                else if(play.getSuit()==5)
                                {
                                   play.setSuitHealth(20);
                                }
                                play.subtractHealth(30);
                                cout<<"You have lost! :( say goodbye to your "<<weapon<<endl;
                                if (weaponchoice == 1)
                                {
                                    play.setWeapon1(0);

                                }
                                else if (weaponchoice == 2)
                                {
                                    play.setWeapon2(0);
                                }

                            }
                        }
                        else if(weapon == "Beam Gun")
                        {
                            if(chance1 >= 20)
                            {
                                cout<<"You have killed "<<plan.getAlienName()<<"! Help yourself to his Beam gun."<<endl;
                                if(play.getWeapon2()=="")
                                {
                                    play.setWeapon2(3);
                                }
                                else
                                {
                                  play.setWeapon1(3);  
                                }
                            }
                            else
                            {
                                if (play.getSuit()==1)
                                {
                                    play.setSuitHealth(50);
                                }
                                else if(play.getSuit()==2)
                                {
                                   play.setSuitHealth(40); 
                                }
                                else if(play.getSuit()==3)
                                {
                                   play.setSuitHealth(30); 
                                }
                                else if(play.getSuit()==4)
                                {
                                   play.setSuitHealth(20) ;
                                }
                                else if(play.getSuit()==5)
                                {
                                   play.setSuitHealth(20);
                                }
                                play.subtractHealth(30);
                                cout<<"You have lost! :( say goodbye to your "<<weapon<<endl;
                                if (weaponchoice == 1)
                                {
                                    play.setWeapon1(0);

                                }
                                else if (weaponchoice == 2)
                                {
                                    play.setWeapon2(0);
                                }

                            }
                        }
                    
                    
                    }
                    
                }
                cout<<"Hit View Status to check inventory"<<endl;
                
            }//endbattle

            

        }  //endmisfurtune
        //IF LOLA IS CREW MEMBER AND HEALTH IS LESS THAN 65%, SHE ADDS HEALTH.
        if(crew1==1 || crew2==1 )
        {
            if(play.getHealth() < 65)
            {
            cout<<"Thank the galactic god's you brought a doctor! Let Lola take a look at your injuries."<<endl;
            play.addHealth(15);
            }
        }
        if(play.getHealth()<=0 || play.getSuitHealth()<=0)
        {
            cout<<"------GAME OVER------"<<endl<<"The great space explorer "<<playerName<<" has died an agonizing death in space!"<<endl;
        }
    }    //end while(menu)   
   //push_back.logvec(logBookEntry);
    vect++;     
    planetsExplored++; 
}  //end while (phase 2)

 }
}//end int main()
