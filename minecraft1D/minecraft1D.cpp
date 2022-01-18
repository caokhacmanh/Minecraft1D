#include "..\\includePacks.h"
#include "..\\funcs.cpp"
using namespace std;

string readedInfo = "";
string modpack = "";

void enterSingleplayer();
void getMainBoardReady();
void loadProperties();
void loadLibraries();

int main(){
    getMainBoardReady();
    enterSingleplayer();
}

//////////////////////////////
void enterSingleplayer(){
    serverConsole("Your world?");
    getUserReply(&readedInfo);
    startWriteFile(".\\minecraft1D\\properties.txt");
    fout << "World: " << readedInfo << "\n";
    fout << "#000#" << "\n";
    closeWriteFile();
    serverConsole("Entering SinglePlayer...");
    wait(3000);
    system(".\\minecraft1D\\singleplayer.exe");
}

void getMainBoardReady(){
    cls();
    setReportFile(".\\reports.txt");
    serverConsole("Loading files...");
}

