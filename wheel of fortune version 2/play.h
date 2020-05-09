#include <stdio.h>
#include <iostream>
#include <Windows.h> // this  is used to color the texts
#include <stdlib.h> // this used for cin.getline() function
#include <cstdlib> // this  is used fr time sleeping
#include "player.h"
#include "wheel.h"
using namespace std;

class play { 
    private :
        string lang ;
        string ch; 
    public : 
        play(string language , string phrase){
            lang = language;
            ch = phrase ;
        }
        string playing(Player* p ,Player* p2 ,  string ch1  ){
            Wheel w;
            decorating color  ;
           
            int m = 0;
            int x = 0; // id of the choosed lang
            int k = 0; // variable to altern between players (p1 then p2 , p1 then p2 ...)
            char guess[200];  // guess for the phrase by the players
            char l ;   // lettre choosed by the player
           
           /* this block allways handle score and  title */
            color.title(lang); 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<" "<<p->getName()<<" : "<<p->getScore()<<" ||| "<<p2->getName()<<" : "<<p2->getScore()<<" \n \n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

            int a=w.spinWheel(); /* spin the wheel and get the value */
            
            color.print_With_Color("\n"+p->getName(),11);
            cout<<" >> please select an option : \n \n  1) Select a letter \n  2) guess the phrase  \n  3) pass the turn  \n";
            cin>>x;
            system("CLS");


            if(x==1){
            color.title(lang);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<" "<<p->getName()<<" : "<<p->getScore()<<" ||| "<<p2->getName()<<" : "<<p2->getScore()<<" \n \n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

            color.print_With_Color("\n"+p->getName(),11);
            cout<<" >> Select a letter :";
            cin>>l;
            p->updateScore(w.calculatePointsLetter(a,l,ch));

            for(int i=0 ;i<ch.length();i++) { // if the selected lettre is in the phrase , it will unhidden in the hidden phrase
                if(ch[i]==l){
                    if(ch1[i] == '#'){
                        ch1[i]=l;
                        cout<<"\n The phrase become : ";
                        color.print_With_Color(ch1+"\n",95); //print the new unhidden phrase with color
                        x=2;
                        m =1 ; 
                        break;
                    }
                }
            }
            
            
            

        if(m==0){
            color.print_With_Color("\n The letter is not in the phrase !  ",12);
            Sleep(2000);
            system ("CLS");}     
        }


        if(x==2){
            if(m==0){
                color.title(lang);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<" "<<p->getName()<<" : "<<p->getScore()<<" ||| "<<p2->getName()<<" : "<<p2->getScore()<<" \n \n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                }
            color.print_With_Color("\n"+p->getName(),11); // print the name of player
            cout<<" >> try to guess the phrase : ";
            cin.ignore();
            cin.getline(guess,200); // read the phrase (we can't use cin>> because it will only read the first word)
           
            if(guess==ch){
                system ("CLS");
                color.title(lang);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<" "<<p->getName()<<" : "<<p->getScore()<<" ||| "<<p2->getName()<<" : "<<p2->getScore()<<" \n \n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

                 // if the guess is true the player will win and the program quit the loop , else it will continue to the next player
                p->updateScore(600);
                if (p->getScore() > p2->getScore()){
                    color.print_With_Color("Congruatulation "+p->getName()+", you win !!! \n ",14);
                }
                else{
                    color.print_With_Color("Congruatulation "+p2->getName()+", you win !!! \n ",14);                
                }
            
                return "end";

            }
            else{
                color.print_With_Color("\n Naah , that's wrong . ",12);Sleep(2000);
            }
            system ("CLS");
            m=0;
        };

        if(x==3){system ("CLS");}

        return ch1;
    };

};
