#include ".\\includePacks.h"
#include ".\\funcs.cpp"
using namespace std;

// ofstream fout;
// ifstream fin;

string userInput;

void getLaucherReady();

void errorsCheck();
void showInstructions();
void getStarted();
void getUserModPack();
void enterGame();

int main(){

    getLaucherReady();

    showInstructions();
    getStarted();
    getUserModPack();
    enterGame();
}


void showInstructions(){
    startReadFile(".\\instructions\\getStarted.txt");
}

void getLaucherReady(){
    serverConsole("Loading laucher...");
    errorsCheck();
    serverConsole("Finished!");
}   

void errorsCheck(){
    serverConsole("Checking for errors...");
}

void getStarted(){

}

void getUserModPack(){

}

void enterGame(){

}

