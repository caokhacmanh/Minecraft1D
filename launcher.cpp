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
    setReportFile(".\\reports.txt");
    refreshFile(reportFile);
    serverConsole("Loading laucher...");
    errorsCheck();
    serverConsole("Finished!");
}   


void getStarted(){
    cout << "\n";
    selectAccountAgain:
    serverConsole("Your account?");
    getUserReply(&userAccount);
    serverConsole("Checking for your account...");
    if(isFileExist(".\\minecraft1D\\userConfig\\" + userAccount)){
        serverConsole("You already logged in with your account!");
    }else{
        serverConsole("You have not logged in with your account, do you want to create a new account? (y/n)");
        if(getch() == 'y'){
            createFile(".\\minecraft1D\\userConfig\\" + userAccount);
        }else{
            goto selectAccountAgain;
        }
    }
    startWriteFile(".\\minecraft1D\\properties.txt");
    fout << "User: " << userAccount << "\n";
}

void getUserModPack(){
    cout << "\n";
    serverConsole("Do you want to use your own modpack? (y/n)");
    if(getch() == 'y'){
        keyPressReport('y');
        serverConsole("Which modpack do you want to use?");
        getUserReply(&userInput);
        startWriteFile(".\\minecraft1D\\properties.txt");
        fout << "Modpack: " + userInput << "\n";
    }else{
        keyPressReport('n');
        serverConsole("Using default modpack");
        startWriteFile(".\\minecraft1D\\properties.txt");
        fout << "Modpack: default" << "\n";
    }
}

void enterGame(){
    cout << "\n";
    serverConsole("Launching Minecraft1D ver.Beta...");
    system(".\\minecraft1D\\minecraft1D.exe");
    startWriteFile(".\\minecraft1D\\properties.txt");
    fout << "#000#\n";
    closeWriteFile();
}