#include ".\\includePacks.h"
using namespace std;

ofstream fout;
ifstream fin;

void serverConsole(string output);
void serverReport(string output);
void startWriteFile(string fileName);
void startReadFile(string fileName);
void closeWriteFile();
void closeReadFile();

void serverConsole(string output){
    cout << "[" << output << "]" << "\n";
    serverReport(output);
}

void serverReport(string output){
    fout << "[" << output << "]" << "\n";
}

void startWriteFile(string fileName){
    fout.open(fileName);
    // serverReport("Write in file " + "\"" + fileName + "\"");
}

void closeWriteFile(){
    fout.close();
    serverReport("Close writing file");
}

void startReadFile(string fileName){
    fin.open(fileName);
    serverReport("Read file " + fileName);
}

void closeReadFile(){
    fin.close();
    serverReport("Close reading file");
}