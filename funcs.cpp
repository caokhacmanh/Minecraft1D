#include ".\\includePacks.h"
using namespace std;

string reportFile;

ofstream fout;
ifstream fin;

////////////////////////////////////////////////////

//
void wait(int milliseconds);
int random(int a, int b);

// check
bool isFileExist(string fileName);

// console working
void cls();
void gotoxy(int posX, int posY);
void serverConsole(string output);
void serverReport(string output);
void userReport(string output);
void getUserReply(string *userReply);
void keyPressReport(char key);

// file working
void startWriteFile(string fileName);
void setReportFile(string fileName);
void startReadFile(string fileName);
void fead(string *variable);
void createFile(string fileName);
void closeWriteFile();
void closeReadFile();
void refreshFile(string fileName);

///////////////////////////////////////////////////////

// wait for some milliseconds
void wait(int milliseconds){
    Sleep(milliseconds);
}

// set report file to <fileName>
void setReportFile(string fileName){ 
    reportFile = fileName;
}

// report the key pressed (without refresh the file)
void keyPressReport(char key){ 
    fout.close();
    fout.open(reportFile, ios::app);
    fout << "\'" << key << "\'\n";
    cout << "\'" << key << "\'\n";
    fout.close();
}

// create a new file 
void createFile(string fileName){ 
    fout.open(fileName);
    fout.close();
    serverReport("Create file " + fileName);
}

// check if file <fileName> exist
bool isFileExist(string fileName){ 
    std::ifstream infile(fileName);
    return infile.good();
}

// report user's reply without refresh the file
void userReport(string output){ 
    fout.close();
    fout.open(reportFile, ios::app);
    fout << "> " << output << "\n";
    fout.close();
}

// get user reply in whole line (include spaces)
void getUserReply(string *userReply){ 
    cout << "> ";
    getline(cin, *userReply);
    userReport(*userReply);
}

// refresh the file <fileName>
void refreshFile(string fileName){ 
    serverReport("Refresh file " + fileName);
    fout.open(fileName);
    fout.close();
}

// read in the choosen file (the whole line in clude spaces)
void fead(string *variable){
    getline(fin, *variable);
}

// print to the server console and report to the report file
void serverConsole(string output){
    cout << "[" << output << "]" << "\n";
    serverReport(output);
}

// report to the report file without refresh the file
void serverReport(string output){ 
    fout.close();
    fout.open(reportFile, ios::app);
    fout << "[" << output << "]" << "\n";
    fout.close();
}

// start writing to file <fileName> (without refresh file's contents)
void startWriteFile(string fileName){ 
    serverReport("Write in file " + fileName);
    fout.open(fileName, ios::app);
}

// close the recent writing file
void closeWriteFile(){ 
    fout.close();
    serverReport("Close writing file");
}

// start read file <fileName>
void startReadFile(string fileName){ 
    serverReport("Read file " + fileName);
    fin.open(fileName);
}

// close recently reading file
void closeReadFile(){ 
    fin.close();
    serverReport("Close reading file");
}

// clear serverConsole
void cls(){system("cls");} 

// goto x, y
void gotoxy(int posX, int posY)
{
posX *= 2;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

//gain random number from a to b
int random(int a, int b){
    srand((int) time(0));
    int c = a + rand() % (b + 1 - a);
    return c;
}
