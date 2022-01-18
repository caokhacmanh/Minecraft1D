#include ".\includePacks.h"
using namespace std;

int main(){
    system("g++ -std=c++11 .\\launcher.cpp -o .\\launcher");
    system("g++ -std=c++11 .\\minecraft1D\\minecraft1D.cpp -o .\\minecraft1D\\minecraft1D");
    system("g++ -std=c++11 .\\minecraft1D\\singleplayer.cpp -o .\\minecraft1D\\singleplayer");
}