#include <iostream>
#include "gameStart.h"
#include "gameSystem.h"
using namespace std;


int main()
{
    setlocale(0, "");
    theGameStart();
    bool outOfGame = false;
    while (!outOfGame) {
        //system("cls");
        outOfGame = gotoTheMenu(); // Реализация выхода с помощью такой идеи полное говно, но лучше, пока, я придумать не могу
        if(!outOfGame)
            outOfGame = gameSystem();
        
    }
    system("cls");
    cout << "End of Game! Thanks for playing!";
    return 0;
}
