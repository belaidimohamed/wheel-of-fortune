#include <iostream>
#include <cstdlib> //pour rand et srand
#include <ctime> // pour time
#include <cstring> // pour strlen
#include <string>
#include <iostream>
#include <unistd.h> // for sleep()
#include <Windows.h> // this  is used to color the texts

using  namespace std ;
class Wheel{
   private :
        int wheel_prizes[10] = { 50, 100, 150, 200, 250, 300, 350, 400, 450, 500}; //prizes's array

   public:
        int spinWheel() {

                srand(time(NULL));; //call it once to generate random number
                int nbgen=rand()%10;    // get a random number between 0-9 (index of array)
                cout<<" Spining wheel ..  " ;
                std::cout << '-' << std::flush;
                for (int i=0 ;i<7 ; i++) {
                    usleep(85000);
                    std::cout << "\b\\" << std::flush;
                    usleep(85000);
                    std::cout << "\b|" << std::flush;
                    usleep(85000);
                    std::cout << "\b/" << std::flush;
                    usleep(85000);
                    std::cout << "\b-" << std::flush;
                }
                cout<<"\n The wheel has chosen the score of : " ;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
                cout <<  wheel_prizes[nbgen] ;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                cout<<"\n \n         -------------------------------- \n";
                return wheel_prizes[nbgen];
		}

        int getOccurence(char c ,string str ) {
            int compteur = 0;
            int len=str.length();
            for (int i =0; i<len; i++) {
                if (str[i] == c)
                    compteur+=1;
            }

            return compteur ;
        }
        int calculatePointsLetter(int a ,char c , string str) {
            int b;

            b=getOccurence(c,str);
            if(b==0)
                return 0;
            else
                return a/b ;
        }
};

