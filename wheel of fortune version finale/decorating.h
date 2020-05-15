#include <stdio.h>
#include <iostream>
#include <Windows.h> // this  is used to color the texts 

using namespace std;


class decorating {
    public :
        void title(string lang,int round,string hint) {
            const string start="\n ----------------------------------------------- Welcome to Wheel Of Fortune -------------------------------------------";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),46); /* set color to green for title */
            cout<<start;
            cout<<"\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
            cout<<" \n Language selected : "+ lang +"  -- round : "<<round<<"\n \n ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); /* get back to normal color */
            if (hint!=""){
                print_With_Color(" Hint : "+hint,3);cout<<"\n \n";}
    } // print le title(welcome .. ) and the language selected

        void print_With_Color(string argg, int i) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
            cout<<argg;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); /* get back to normal color */
        } 
        void welcome() {
        
            cout<<"\n \n \n -----------------------------------------------";
            print_With_Color(" Welcome ",12);
            cout<< "----------------------------------------------------";
            cout<<"\n -----------------------------------------";
            print_With_Color(" To Wheel Of Fortune ",12);
            cout<<" ---------------------------------------------------- ";
            Sleep(4000);
            system ("CLS");
            cout<<"\n \n \n \n --------------------------------------------------";
            print_With_Color("  Made By  ",78);
            cout<< "--------------------------------------------------------";
            Sleep(2000);
            system ("CLS");
            cout<<"\n \n \n \n --------------------------------------------------";
            print_With_Color(" Mohamed ",9);  
            cout<< " --------------------------------------------------------";
            Sleep(4000);
            system ("CLS");


        } 
};