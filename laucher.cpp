#include ".\\includePacks.h"
#include ".\\funcs.cpp"
using namespace std;

string userInput;
string userAccount;

void getLaucherReady();

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
    cout << "\n";
    startReadFile(".\\instructions\\getStarted.txt");
    string readInfo = "";
    
    while(readInfo != "#000#"){
        fead(&readInfo);
        if(readInfo != "#000#") cout << readInfo << "\n";
    }

}

void errorsCheck(){
    cout << "\n";
    serverConsole("Checking for errors...");
}

void getLaucherReady(){
    cout << "\n";
    refreshFile(".\\reports.txt");
    serverConsole("Loading laucher...");
    errorsCheck();
    serverConsole("Finished!");
}   


void getStarted(){
    cout << "\n";
    serverConsole("Your account?");
    getUserReply(&userAccount);
    
}

void getUserModPack(){
    cout << "\n";

}

void enterGame(){
    cout << "\n";

}

