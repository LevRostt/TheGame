#include <iostream>
#include "gameStart.h"
using namespace std;


int main()
{
    
    setlocale(0, "");
    theGameStart();
    bool outOfGame = false;
    while (!outOfGame) {
        system("cls");
        outOfGame = gotoTheMenu();
    }
}
