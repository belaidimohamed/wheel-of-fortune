#include <stdio.h>
#include <iostream>
#include <Windows.h> // this  is used to color the texts
#include <stdlib.h> // this used for cin.getline() function
#include <cstdlib> // this  is used fr time sleeping
using namespace std;

/*------------------------------------------------------------- functions ----------------------------------------------------------------------*/

void title(string lang){
   const string start="\n ----------------------------------------------- Welcome to Wheel Of Fortune -------------------------------------------";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),46); /* set color to green for title */
   cout<<start;
   cout<<"\n";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
   cout<<" \n Language selected : "+ lang +"\n \n";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); /* get back to normal color */
   } // print le title(welcome .. ) and the language selected

void print_With_Color(string argg, int i){
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
   cout<<argg;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); /* get back to normal color */
} 

/*--------------------------------------------------------- Declarations ---------------------------------------------------------------------*/

int main() {
   int m = 0;
   int x = 0; // id of the choosed lang
   int k = 0; // variable to altern between players (p1 then p2 , p1 then p2 ...)
   char guess[200];  // guess for the phrase by the players
   char l ;   // lettre choosed by the player
   bool gameover = false; // check if the game over or not (the game is over if the phrase is completely exposed , and still no one figure it out)
   string ch ="hello world"; // example of the phrase ( we will remplace that later by the function that return a random phrase from the text file)
   string ch1 = "" ; // variable in which will store the hidden phrase
   string p1 , p2 ; // players ( we will remplace that later by a class of players )
   for (int i = 0; i < ch.length(); i++) {ch1+='#'; } /* hidding the line (prize) by # */

/*----------------------------------------------------------- réglages and signing up ----------------------------------------------------*/

   while(x!=1 && x!=2 && x!=3){
      title("--");
      cout<<" select a language : \n  1) arabic (not ready yet) \n  2) french (not ready yet)  \n  3) english  \n";
      cin>>x;
   }

   if(x==3){
        system ("CLS"); /* clear screen */
        title("English");
        }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout << " Player 1 please enter your name : ";
    cin>>p1;
    cout << " Player 2 please enter your name : ";
    cin>>p2;
    system ("CLS");

/*-------------------------------------------------------- main game code ---------------------------------------------------------------*/

    while(!gameover){
      if(k%2==0){
         title("English");
         print_With_Color("\n"+p1,11);
         cout<<" >> please select an option : \n \n  1) Select a letter \n  2) guess the phrase  \n  3) pass the turn  \n";
         cin>>x;
         system ("CLS");

         
         if(x==1){
            title("English");
            print_With_Color("\n"+p1,11);
            cout<<" >> Select a letter :";
            cin>>l;
            for(int i=0 ;i<ch.length();i++) { // if the selected lettre is in the phrase , it will unhidden in the hidden phrase
               if(ch[i]==l){
                  if(ch1[i] == '#'){
                     ch1[i]=l;
                     cout<<"\n The phrase become : ";
                     print_With_Color(ch1+"\n",95); //print the new unhidden phrase with color
                     x=2;
                     m =1 ; 
                     break;
                  }
               }
            }
            
            if(m==0){
               print_With_Color("\n The letter is not in the phrase !  ",12);
               Sleep(2000);
               system ("CLS");
            }     
         }


         if(x==2){
            if(m==0){title("English");}
            print_With_Color("\n"+p1,11); // print the name of player
            cout<<" >> try to guess the phrase : ";
            cin.ignore();
            cin.getline(guess,200); // read the phrase (we can't use cin>> because it will only read the first word)
            if(guess==ch){ // if the guess is true the player will win and the program quit the loop , else it will continue to the next player
               print_With_Color("Congruatulation "+p1+", you win !!! ",14);
               break;
            }else{print_With_Color("\n Naah , that's wrong . ",12);Sleep(2000);}
            system ("CLS");
            m=0;
         }
         if(x==3){k++;system ("CLS");continue;}
         
      }
       // ------------------------------------------- player 2 -------------------------------------------------------------------
      else{ 
         title("English");
         print_With_Color("\n"+p2,9);
         cout<<" >> please select an option : \n \n  1) Select a letter \n  2) guess the phrase  \n  3) pass the turn  \n";
         cin>>x;
         system ("CLS");

         
         if(x==1){
            title("English");
            print_With_Color("\n"+p2,9);
            cout<<" >> Select a letter :";
            cin>>l;
            for(int i=0 ;i<ch.length();i++) { // if the selected lettre is in the phrase , it will unhidden in the hidden phrase
               if(ch[i]==l){
                  if(ch1[i] == '#'){
                     ch1[i]=l;
                     cout<<"\n The phrase become : ";
                     print_With_Color(ch1+"\n",95); //print the new unhidden phrase with color
                     x=2;
                     m =1 ; 
                     break;
                  }}
            }  
            if(m==0){
               print_With_Color("\n The letter is not in the phrase !  ",12);
               Sleep(2000);
               system ("CLS");
               }
         }

         if(x==2){
            if(m==0){title("English");}
            print_With_Color("\n"+p2,9); // print the name of player
            cout<<" >> try to guess the phrase : ";
            cin.ignore();
            cin.getline(guess,200); // read the phrase (we can't use cin>> because it will only read the first word)
            if(guess==ch){ // if the guess is true the player will win and the program quit the loop , else it will continue to the next player
               print_With_Color("Congruatulation "+p2+", you win !!! ",14);
               break;
            }else{print_With_Color("\n Naah , that's wrong . ",12);Sleep(2000);}
            system ("CLS");
            m=0;
         }
         if(x==3){k++;system ("CLS");continue;}
      }
      k++;
   }
   return 0;
/*-------------------------------------------------------- End of game --------------------------------------------------------*/
}
