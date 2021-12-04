#include ".\\includePacks.h"
using namespace std;

ofstream fout;
ifstream fin;

////////////////////////////////////////////////////

bool isFileExist(string fileName);

void cls();
void serverConsole(string output);
void serverReport(string output);
void userReport(string output);
void getUserReply(string *userReply);
void keyPressReport(char key);

void startWriteFile(string fileName);
void startReadFile(string fileName);
void fead(string *variable);
void createFile(string fileName);
void closeWriteFile();
void closeReadFile();
void refreshFile(string fileName);

///////////////////////////////////////////////////////

void keyPressReport(char key){
    fout.close();
    fout.open(".\\reports.txt", ios::app);
    fout << "\'" << key << "\'\n";
    cout << "\'" << key << "\'\n";
    fout.close();
}

void createFile(string fileName){
    fout.open(fileName);
    fout.close();
    serverReport("Create file " + fileName);
}

bool isFileExist(string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

void userReport(string output){
    fout.close();
    fout.open(".\\reports.txt", ios::app);
    fout << "> " << output << "\n";
    fout.close();
}

void getUserReply(string *userReply){
    cout << "> ";
    getline(cin, *userReply);
    userReport(*userReply);
}

void refreshFile(string fileName){
    serverReport("Refresh file " + fileName);
    fout.open(fileName);
    fout.close();
}

void fead(string *variable){
    getline(fin, *variable);
}

void serverConsole(string output){
    cout << "[" << output << "]" << "\n";
    serverReport(output);
}

void serverReport(string output){
    fout.close();
    fout.open(".\\reports.txt", ios::app);
    fout << "[" << output << "]" << "\n";
    fout.close();
}

void startWriteFile(string fileName){
    serverReport("Write in file " + fileName);
    fout.open(fileName);
}

void closeWriteFile(){
    fout.close();
    serverReport("Close writing file");
}

void startReadFile(string fileName){
    serverReport("Read file " + fileName);
    fin.open(fileName);
}

void closeReadFile(){
    fin.close();
    serverReport("Close reading file");
}

void cls(){system("cls");}