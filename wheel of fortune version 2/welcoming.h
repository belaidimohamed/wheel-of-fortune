#include <stdio.h>
#include <iostream>
#include <Windows.h> // this  is used to color the texts
#include <cstdlib> // this  is used fr time sleeping

#include "decorating.h"
using namespace std;


class welcoming {
    public :
        void welcome() {
            decorating color;
        
            cout<<"\n \n \n -----------------------------------------------";
            color.print_With_Color(" Welcome ",12);
            cout<< "----------------------------------------------------";
            cout<<"\n -----------------------------------------";
            color.print_With_Color(" To Wheel Of Fortune ",12);
            cout<<" ---------------------------------------------------- ";
            Sleep(4000);
            system ("CLS");
            cout<<"\n \n \n \n --------------------------------------------------";
            color.print_With_Color("  Made By  ",78);
            cout<< "--------------------------------------------------------";
            Sleep(2000);
            system ("CLS");
            cout<<"\n \n \n \n ----------------------------------------";
            color.print_With_Color(" Mohamed",9); 
            color.print_With_Color(" -- Rayen ",11); 
            color.print_With_Color(" -- Nadine ",12); 
            color.print_With_Color(" -- Ameni ",14); 
            cout<< " ------------------------------------";
            Sleep(4000);
            system ("CLS");


        } 
};
