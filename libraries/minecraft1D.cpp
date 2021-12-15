#include "..\\includePacks.h"
#include "..\\funcs.cpp"
using namespace std;

void mainBoard();
void getMainBoardReady();

int main(){
    getMainBoardReady();
    mainBoard();
}

void getMainBoardReady(){
    setReportFile("..\\ reports.txt");
}