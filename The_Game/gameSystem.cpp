#include "gameSystem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

void LoreOfGame() {
	setlocale(LC_ALL, "RUS");
	system("cls");
	ifstream lore;
	lore.open("System/Lore.txt"); // обращение к файлу с лором
	
	string loreText;
	bool outOf = false;
	while (getline(lore, loreText) and !outOf) {
		for (int i = 0; i < loreText.length(); i++) {
			if (_kbhit()) {
				if (_getch() == 13 or _getch() == 27) { // Если Esc или Enter - скипаем титры
					outOf = true;
					break;
				}
			}
			if (loreText[i] != ' ') {
				Sleep(50);
			}
			cout << loreText[i];
		}
		cout << endl;
	}


}


void menuOfChoise(string warrior, string witcher) {// Рисуему меню выбора полностью
	
	system("cls");

	string choose = "Выберите своего бойца";

	for (int i = 0; i < 6; i++) {  
		for (int j = 0; j < 100; j++) {


			if (i == 2 and j > 40 and j <= 40 + choose.length()) {
				cout << choose[j - 41];
			}

			else if ((i == 5) and j >= (50 / 2 - warrior.length() / 2) and (j <= (50 / 2 + warrior.length() / 2))) {
				cout << warrior[j - (50 / 2 - warrior.length() / 2)];
			}

			else if ((i == 5) and j >= (50 + (50 / 2 - witcher.length() / 2)) and (j <= (50 + (50 / 2 + witcher.length() / 2)))) {
				cout << witcher[j - (50 + (50 / 2 - witcher.length() / 2))];
			}

			else {
				cout << " ";
			}

		}

		cout << endl;

	}

	ifstream choiseText;
	choiseText.open("System/classes.txt"); // Обращение к файлу с описанием классов.

	string thisStrok;
	while (getline(choiseText, thisStrok)) {
		cout << thisStrok;
		cout << endl;
	}
	
}


int setPersonClassMenu() { // Логика в меню выбора персонажа
	
	bool out = false;

	system("cls");

	string warrior = "<- Воин ->";
	string witcher = "Маг";
	menuOfChoise(warrior, witcher);
	int pos = 0;

	while (!out) {

		if (_kbhit()) { // Если нажали клавишу
			switch (_getch())
			{
			case 77:
				pos++;
				break;
			case 75:
				pos--;
				break;
			case 13:
				out = true;
				break;
			}

			if (pos > 1)
				pos = 0;
			
			if (pos < 0)
				pos = 1;
			


			if (pos == 0) {
				warrior = "<- Воин ->";
				witcher = "Маг";
			}
			else {
				warrior = "Воин";
				witcher = "<- Маг ->";
			}

			menuOfChoise(warrior, witcher); 

		}

	}

	return pos; // Возвращаем соответственно класс
}


bool gameSystem()
{
	setlocale(0, "");

	LoreOfGame(); //Показ вступительного Лора игры

	int personClass = setPersonClassMenu(); // Получаем класс персонажа 0 - Воин. 1 - волшебник
	
	bool alive = true;

	while (alive) { // Пока персонаж жив повторять эти действия

		checkInventory(); // Смотрим инвентарь и что-либо делаем

		// Рандомить действие или в данж или гибкий многоходовочный файт с мобами.

	}
	

	return false;
}
