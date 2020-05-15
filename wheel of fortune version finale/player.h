#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> //to use NULL and clear the screen

using namespace std;
class Player{
    private:
        string name;
        int score = 0 ;
    public :
        void setName(string n){this->name=n;}
        string getName() { return name; }
        int getScore(){ return score ; }
        void updateScore(int x) { score+=x; }
    };



