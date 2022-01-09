#include "..\\includePacks.h"
#include "..\\funcs.cpp"
using namespace std;

string readedInfo = "";

void mainBoard();
void getMainBoardReady();
void loadMods();
void loadLibraries();

int main(){
    getMainBoardReady();
    mainBoard();
}

void getMainBoardReady(){
    cls();
    setReportFile("..\\ reports.txt");
}

void loadLibraries(){

}

void loadMods(){
    startReadFile(".\\propeties.txt");
    while(readedInfo == "#000#"){
        
    }
    closeReadFile();
}