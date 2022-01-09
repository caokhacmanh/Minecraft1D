#include "..\\includePacks.h"
#include "..\\funcs.cpp"
using namespace std;

string readedInfo = "";
string modpack = "";

void mainBoard();
void getMainBoardReady();
void loadProperties();
void loadLibraries();

int main(){
    getMainBoardReady();
    mainBoard();
    loadProperties();
    loadLibraries();
}

void getMainBoardReady(){
    cls();
    serverConsole("Loading files...");
    setReportFile("..\\ reports.txt");
}

void loadLibraries(){

}

void loadProperties(){
    startReadFile(".\\propeties.txt");
    while(readedInfo == "#000#"){
        fin >> readedInfo;
        if(readedInfo == "modpack:"){
            fead(&readedInfo);
            modpack = readedInfo;
        }
    }
    closeReadFile();
}