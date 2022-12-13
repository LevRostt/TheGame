#include "gameStart.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

void theGameStart()
{
	bool stop = false; // Если True - останавливает работу
	string out = "Welcome, to the PockeFightGame";
	string heh = "heh";
	string lets = "Just let's enjoy! :3"; // Задаю переменные строк, чтобы можно было их красиво выводить в консоль используя задерку.
		for (int i = 0; i <= 25; i++) {
			if (!stop)
			for (int j = 0; j < 100; j++) {
				if (!stop) {
					if (_kbhit()) { // Проверяем введено ли что-либо на клавиатуру
						switch (_getch()) 
						{
						case 13: // Если Enter
							stop = true;
							break;
						case 32: // Если Space
							stop = true;
							break;
						case 27: // Если Esc
							stop = true; 
							break;
						} 
					}

					if (i == 15 and j >= 40 and j <= (40 + out.length())) {
						cout << out[j - 40];
						Sleep(100);
					}
					else if (i == 18 and j >= 45 and j <= (45 + lets.length())) {
						cout << lets[j - 45];
						Sleep(300);
					}
					else {
						cout << " ";
					}

					if (i == 16 and j >= 50 and j <= (50 + heh.length())) {
						cout << heh[j - 50];
						Sleep(250);
					}
				}

			} // соответственно вывожу каждую из строк с задержкой
			cout << endl;
		}
}

void drawable(string newGame, string score, string help, string exitFromGame) { //Функцияя рисования консольного меню
	string menu = "<|  PockeFightGame  |>";

	for (int i = 0; i < 18; i++) { // Снова рисуем меню только с изменёнными параметрами. Да, это копипаст. И что?)
		for (int j = 0; j < 100; j++) {

			if (i == 4 and j >= (85 / 2 - menu.length() / 2) and j <= (85 / 2 + menu.length() / 2)) {
				cout << menu[j - (85 / 2 - menu.length() / 2)];
			}


			if (i == 10 and j >= (100 / 2 - newGame.length() / 2) and j <= (100 / 2 + newGame.length() / 2)) { // формула обозначает следующее:
				cout << newGame[j - (100 / 2 - newGame.length() / 2)];									// длина всего вывода/2 - половина слова 
			}																						// Позваляет выводить слова идеально посередине
																								// короче просто визуально красиво.
			else if (i == 12 and j >= (100 / 2 - score.length() / 2) and j <= (100 / 2 + score.length() / 2)) {
				cout << score[j - (100 / 2 - score.length() / 2)];
			}


			//else if (i == 14 and j >= (100 / 2 - help.length() / 2) and j <= (100 / 2 + help.length() / 2)) {
			//	cout << help[j - (100 / 2 - help.length() / 2)];
			//}

			else if (i == 14 and j >= (100 / 2 - exitFromGame.length() / 2) and j <= (100 / 2 + exitFromGame.length() / 2)) {
				cout << exitFromGame[j - (100 / 2 - exitFromGame.length() / 2)];
			}

			else
				cout << " ";
		}
		cout << endl;
	}
}





void gameHelp() {
	bool outOfHelp = false;



	while (!outOfHelp) { // Выход из меню помощи при вводе Esc;
		if (_kbhit()) {
			switch (_getch())
			{
			case 27:
				outOfHelp = true;
				break;
			}
		}
	}

}

void scoreRating() { // Тут будет реализация топа лидеров

	system("cls");

	ifstream data;
	data.open("System/data.txt");
	
	string s;
	int count = 0;

	while (getline(data, s)) {

		count++;

	}

	data.close();
	data.open("System/data.txt"); // Переоткрываю файл, чтобы сдвинуть курсор в начало

	string* listWithNames = new string[count];

	int i = 0;

	int maxLvl = 0;

	while (getline(data, s)) {

		listWithNames[i] = s;
		i++;

		int spaces = 0;
		string localLvl = "";
		for (int j = 0; j < s.length(); j++) { // Получаем уровень персонажа

			if (spaces == 2) {

				if (s[j] != ' ') {
					localLvl += s[j];
				}

			}

			if (s[j] == '-')
				spaces++;

		}

		if (maxLvl < (stoi(localLvl))) {
			maxLvl = stoi(localLvl);
		}

	}

	data.close();

	string outPutText = "Топ игроков продвинувшихся дальше всего";
	for (int outPut = 0; outPut < 80; outPut++) {

		if (outPut >= 100 / 2 - outPutText.length() / 2 and outPut <= 100 / 2 + outPutText.length() / 2) {

			cout << outPutText[outPut - (100 / 2 - outPutText.length()/2)];

		}

		else
			cout << " ";

	}

	cout << endl;

	outPutText = "Класс - Имя - Уровень";
	for (int outPut = 0; outPut < 100; outPut++) {

		if (outPut >= 100 / 2 - outPutText.length() / 2 and outPut <= 100 / 2 + outPutText.length() / 2) {

			cout << outPutText[outPut - (100 / 2 - outPutText.length()/2)];

		}

		else
			cout << " ";

	}

	cout << endl << endl;

	for (i = maxLvl; i >= 0; i--) {

		for (int index = 0; index < count; index++) {

			int spaces = 0;
			string localLvl = "";
			for (int j = 0; j < listWithNames[index].length(); j++) { // Получаем уровень персонажа 
												// Копи - паст примера выше
				if (spaces == 2) {

					if (listWithNames[index][j] != ' ') {
						localLvl += listWithNames[index][j];
					}

				}

				if (listWithNames[index][j] == '-')
					spaces++;

			}

			if (stoi(localLvl) == i) {

				for (int inside = 0; inside < 100; inside++) {

					if (inside >= 100 / 2 - listWithNames[index].length() / 2 and inside <= 100 / 2 + listWithNames[index].length() / 2) {
						cout << listWithNames[index][inside - (100 / 2 - listWithNames[index].length()/2)];
					}
					else
						cout << " ";
				
				}

				cout << endl;

			}

		}

	}




	boolean out = false;
	while (!out) {

		if (_kbhit()) {

			out = true;

		}

	}

}


bool gotoTheMenu() // Рисуем меню и выбираем что нам делать дальше
{
	bool outOfMenu = false;
	string newGame = "<- New Game ->";
	string score = "Score Rating";
	string help = "Help";
	string exitFromGame = "exit";
	int posChose = 0; //Позиция курсора выбора < >

	system("cls");
	drawable(newGame, score, help, exitFromGame);

	while (!outOfMenu) {


		if (_kbhit()) {
			switch (_getch())
			{
			case 72: // Если стрелка вверх - уменьшаем
				posChose--;
				if (posChose < 0) {
					posChose = 2;
				}
				break;
			case 80: // Если стрелка вниз - увеличиваем
				posChose++;
				if (posChose > 2) {
					posChose = 0;
				}
				break;
			case 13:
				switch (posChose)
				{
				case 0:
					return false; // Стартует игру 
					break;
				case 1:
					scoreRating(); // Вызывает таблицу лидеров
					break;
				//case 2:
				//	gameHelp(); // Вызывает меню помощи
				//	break;
				case 2:
					return true; // Возвращает true и заканчивает игру
					break;
				}
				break;
			}


			// рисуем в зависимости от выбранного. 

			switch (posChose)
			{
			case 0:
				newGame = "<- New Game ->";
				exitFromGame = "exit";
				score = "Score Rating";
//				help = "Help";
				break;
			case 1:
				newGame = "New Game";
				score = "<- Score Rating ->";
//				help = "Help";
				exitFromGame = "exit";
				break;
//			case 2:
//				newGame = "New Game";
//				score = "Score Rating";
//				help = "<- Help ->";
//				exitFromGame = "exit";
//				break;
			case 2:
				newGame = "New Game";
				score = "Score Rating";
//				help = "Help";
				exitFromGame = "<- exit ->";
				break;
			}

			system("cls");

			drawable(newGame, score, help, exitFromGame);
			
		}
		
		// Это должна была быть красивая реализация кнопок, но из-за ограниченности системы от этого лучше, да и вообщем пришлось отказаться.
		// Слишком частое обновление вывода в консоли не позволяет адекватно воспринимать происходящее.
		//
		//newGame = "New Game";
		//score = "Score Rating";
		//help = "Help";
		//exitFromGame = "exit";
		//
		//for (int i = 0; i < 20; i++) { // Рисуем меню "по умолчанию"
		//	for (int j = 0; j < 100; j++) {
		//		
		//		if (i == 10 and j >= (100 / 2 - newGame.length() / 2) and j <= (100 / 2 + newGame.length() / 2)) { // формула обозначает следующее:
		//			cout << newGame[j - (100 / 2 - newGame.length() / 2)];									// длина всего вывода/2 - половина слова 
		//		}																						// Позваляет выводить слова идеально посередине
		//																							// короче просто визуально красиво.
		//		else if (i == 12 and j >= (100 / 2 - score.length() / 2) and j <= (100 / 2 + score.length() / 2)) {
		//			cout << score[j - (100 / 2 - score.length() / 2)];
		//		}
		//
		//
		//		else if (i == 14 and j >= (100 / 2 - help.length() / 2) and j <= (100 / 2 + help.length() / 2)) {
		//			cout << help[j - (100 / 2 - help.length() / 2)];
		//		}
		//
		//		else if (i == 16 and j >= (100 / 2 - exitFromGame.length() / 2) and j <= (100 / 2 + exitFromGame.length() / 2)) {
		//			cout << exitFromGame[j - (100 / 2 - exitFromGame.length() / 2)];
		//		}
		//
		//		else
		//			cout << " ";
		//	}
		//	cout << endl;
		//}
		//
		//system("cls");
		//
		//string newGame = "New Game";
		//string score = "Score Rating";
		//string help = "Help";
		//string exitFromGame = "exit";
		
		
	}

	return false;
}