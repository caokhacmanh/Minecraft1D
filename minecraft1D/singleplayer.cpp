#include "..\\includePacks.h"
#include "..\\funcs.cpp"
using namespace std;

#define gameTicks 100
#define borderLimit 5000
string playerName;
int playerHealth = 20;

bool world[borderLimit][borderLimit];

void getGameReady();
void createNewWorld();
void loadSavedWorld();

int main(){
    getGameReady();
}

void getGameReady(){
    string readedInfo;
    startReadFile(".\\properties.txt");
    while(readedInfo == "#000#"){
        fin >> readedInfo;
        if(readedInfo == "World:"){
            fin >> readedInfo;
            if(isFileExist(".\\worlds\\" + readedInfo + ".txt")){
                loadSavedWorld();
            }else{

            }
        }
    }
}

void createNewWorld(){

}