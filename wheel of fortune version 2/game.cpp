#include <stdio.h>
#include <iostream>
#include <Windows.h> // this  is used to color the texts
#include <stdlib.h> // this used for cin.getline() function
#include <cstdlib> // this  is used fr time sleeping
#include "welcoming.h"
#include "play.h"

using namespace std;
/*--------------------------------------------------------- Declarations ---------------------------------------------------------------------*/

int main() {
   decorating color ;
   welcoming wel ;

   int x = 0 ;
   string language = "English" ;// id of the choosed lang
   int k = 0; // variable to altern between players (p1 then p2 , p1 then p2 ...)
   char guess[200];  // guess for the phrase by the players
   bool gameover = false; // check if the game over or not (the game is over if the phrase is completely exposed , and still no one figure it out)
   string ch ="hello world"; // example of the phrase ( we will remplace that later by the function that return a random phrase from the text file)
   string ch1 = "" ; // variable in which will store the hidden phrase

   for (int i = 0; i < ch.length(); i++) {ch1+='#'; } /* hidding the line (prize) by # */


/*----------------------------------------------------------- réglages and signing up ----------------------------------------------------*/
   wel.welcome();
   while(x!=1 && x!=2 && x!=3){
      color.title("--");
      cout<<" select a language : \n  1) arabic (not ready yet) \n  2) french (not ready yet)  \n  3) english  \n";
      cin>>x;
   }

   if(x==3){
      language = "English";
      system ("CLS"); /* clear screen */
      color.title(language);
   }
   // adding players
   Player* p1 = new Player  ;
   Player* p2 = new Player ;
   char y[50];
   color.print_With_Color(" Player 1 please enter your name : ",11);
   cin.ignore();
   cin.getline(y,50);
   p1->setName(y);
   color.print_With_Color(" Player 2 please enter your name : ",11);
   cin.getline(y,50);
   p2->setName(y);

   play playy(language , ch) ;
   system ("CLS");

/*-------------------------------------------------------- main game code ---------------------------------------------------------------*/

    while(!gameover && ch1!="end"){
      if(k%2==0){
         ch1 = playy.playing(p1,p2,ch1);
      }
      else{
         ch1 = playy.playing(p2,p1,ch1);
      }
      k++;
   }
   return 0;
/*-------------------------------------------------------- End of game --------------------------------------------------------*/
}
