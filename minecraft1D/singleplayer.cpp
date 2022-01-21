#include "..\\includePacks.h"
#include "..\\funcs.cpp"
using namespace std;

#define gameTicks 100
#define borderLimit 5000
string playerName;
int playerHealth = 20;

bool worldData[borderLimit][borderLimit];

void getGameReady();
void createNewWorld(string worldName);
void loadSavedWorld(string worldName);

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
                loadSavedWorld(readedInfo);
            }else{
                createNewWorld(readedInfo);
            }
        }
    }
}

void createNewWorld(string worldName){
    serverReport("Create new world: " + worldName);
    for(int i = 0; i < borderLimit; i++){
        for(int j = 0; j < borderLimit; j++){
            worldData[i][j] = 0;
        }
    }
}

void loadSavedWorld(string worldName){
    serverReport("Load saved world: " + worldName);
    for(int i = 0; i < borderLimit; i++){
        for(int j = 0; j < borderLimit; j++){
            fin >> worldData[i][j];
        }
    }

}