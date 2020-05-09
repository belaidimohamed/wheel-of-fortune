#include <stdio.h>
#include <iostream>
#include <Windows.h> // this  is used to color the texts

using namespace std;


class decorating {
    public :
        void title(string lang) {
            const string start="\n ----------------------------------------------- Welcome to Wheel Of Fortune -------------------------------------------";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),46); /* set color to green for title */
            cout<<start;
            cout<<"\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
            cout<<" \n Language selected : "+ lang +"\n \n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); /* get back to normal color */
    } // print le title(welcome .. ) and the language selected

        void print_With_Color(string argg, int i) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
            cout<<argg;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); /* get back to normal color */
        } 
};