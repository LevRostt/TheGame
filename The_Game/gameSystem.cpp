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

	lore.close();
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
	
	choiseText.close();
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


string PersonName() {// Ввод имени игрока. По хорошему необходимо реализовать отхватку ошибок и смотреть, когда игрок ввёл хреновое имя.

	system("cls");
	
	string toOut = "Введите имя"; 

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 100; j++) {

			if (i == 3 and j >= (100 / 2 - toOut.length()/2) and j <= (100 / 2 + toOut.length()/2)) {
				cout << toOut[j - (100 / 2 - toOut.length()/2)];
				Sleep(50);
			} 
			
			else if (i == 4 and j == 50) {
				break;
			}

			else {
				cout << " ";
			}

		}

		if (i != 4) 
			cout << endl;
	}

	string namePerson;

	cin >> namePerson;

	return namePerson;
}


void drawInventory(int select, int inventory[]) { // Прорисовка меню инвенторя. На вход выбранный элемент инвенторя и сам список инвенторя

	system("cls");

	//string items[] = { "Пусто", "Малый пузырёк для Hp (+5%)", "Большой пузырёк для Hp(+15%)", "Свиток опыт (+1 lvl)", "Огненный шар (Убивает противника)" };

	//string choose = "Выбирете предмет, который хотите использовать или пустую ячейку, если хотите выйти";

	//for (int i = 0; i < 15; i++) {
	//	for (int j = 0; j < 100; j++) {

	//		if (i == 2) {

	//		}

	//		if (select == 0) {
	//			
	//		}

	//	}

	//	cout << endl;
	//}

	cout << "<Меню в данный момент не работает>";

}


void checkInventory(int inventory[], int* hp, int* lvl) { // Реализация инвенторя. На данный момент отключена, будет реализована позже
	
	bool out = false;

	int select = 0;

	drawInventory(select, inventory);

	Sleep(3000);
	//while (!out) {
	//	

	//}
}



// Реализация боёвки

void drawFight() { // Отрисовка экрана перехода между врагами. Возможно тут позже будет спрайт, а может не спрайт, а что-то круче. Или нет)

	system("cls");

	string fight = "NEXT EMENY";

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 100; j++) {

			if (i == 6 and j >= (100 / 2 - fight.length()/2) and (j <= (100 / 2 + fight.length()/2))) {

					cout << fight[j - (100 / 2 - fight.length()/2)];

			}

			else {
				cout << " ";
			}

		}

		cout << endl;
	}
}




void drawFightScene(int hp, int lvl, int hpEnemy, int choose) { // Отрисовка самого главного меню боёвки. Передаём здоровье, уровень и выбранную ячейку

	system("cls");
	 
	for (int i = 0; i < 90; i++) { // Вывод первой строки 

		if (i == 8) {
			cout << "Hp: " << hp;
		}

		else if (i == 80) {
			cout << "Lvl: " << lvl;
		}

		else {
			cout << " ";
		}

	}



	ifstream fight;
	fight.open("System/FightSprite.txt"); // Вывод спрайта битвы

	string line;

	cout << endl;
	while (getline(fight, line)) {

		cout << line;
		cout << endl;
	}

	fight.close();



	string attack, block, spell, items;

	switch (choose) 
	{
	case 0:
		attack = "<- Attack ->"; block = "Block"; spell = "Spell"; items = "Items";
		break;
	case 1:
		attack = "Attack"; block = "<- Block ->"; spell = "Spell"; items = "Items";
		break;
	case 2:
		attack = "Attack"; block = "Block"; spell = "<- Spell ->"; items = "Items";
		break;
	case 3:
		attack = "Attack"; block = "Block"; spell = "Spell"; items = "<- Items ->";
		break;
	}

	for (int i = 0; i < 7; i++) { // Вывод меню выбора действия
		for (int j = 0; j < 100; j++) {
			if (i == 3) {
				if (j >= (100 / 4 - attack.length()/2) and j <= (100/4 + attack.length()/2)) {

					cout << attack[j - (100 / 4 - attack.length()/2)];

				}

				else if (j >= (100 / 4 - block.length()/2 + 50) and j <= (100 / 4 + block.length()/2 + 50)) {

					cout << block[j - (100 / 4 - block.length()/2 + 50)];

				}

				else {
					cout << " ";
				}
			}

			else if (i == 6) {
				if (j >= (100 / 4 - spell.length()/2) and j <= (100 / 4 + spell.length()/2)) {

					cout << spell[j - (100 / 4 - spell.length()/2)];

				}

				else if (j >= (100 / 4 - items.length()/2 + 50 ) and j <= (100 / 4 + items.length()/2 + 50 )) {

					cout << items[j - (100 / 4 - items.length()/2 + 50)];

				}

				else {
					cout << " ";
				}
			}

			else {
				cout << " ";
			}

		}

		cout << endl;

	}


}
	

int FightScene(int& hp, int& lvl) { // Основная логика меню сражения 

	drawFight(); // Вывод экрана перед боем

	Sleep(1000);

	int choose = 0;

	int hpEnemy = hp;

	drawFightScene(hp, lvl, hpEnemy, choose); // Вывод самого интерфейса

	while (hpEnemy != 0 or hp != 0) {
		
		if (_kbhit()) { // действия в зависимости от нажатого элемента
			
			switch (_getch())
			{
			case 72: // Стрелка вверх 
				if (choose == 0) {
					choose = 2;
				}
				else if (choose == 1) {
					choose = 3;
				}
				else {
					choose -= 2;
				}
				break;

			case 75: // Стрелка влево
				choose--;
				break;
			
			case 77: // Вправо
				choose++;
				break;

			case 80: // Вниз
				if (choose == 3) {
					choose = 1;
				}
				else if (choose == 2) {
					choose = 0;
				}
				else {
					choose += 2;
				}
				break;
			}

			if (choose > 3) {
				choose = 0;
			}
			if (choose < 0) {
				choose = 3;
			}

			drawFightScene(hp, lvl, hpEnemy , choose); // Обновление экрана на следующий вариант в зависимости от действия игрока.

		}
		
	}

	return true;
}

bool gameSystem() // Логика меню "Новая игра"
{
	setlocale(0, "");

	string name = PersonName();

	int personClass = setPersonClassMenu(); // Получаем класс персонажа 0 - Воин. 1 - волшебник

	LoreOfGame(); //Показ вступительного Лора игры
	
	bool alive = true;

	int inventory[] = {1, 1, 0};

	int hp = 100;

	int lvl = 0;

	while (alive) { // Пока персонаж жив повторять эти действия



		//checkInventory(inventory, &hp, &lvl); // Смотрим инвентарь и что-либо делаем
		
		alive = FightScene(hp, lvl);



		// Рандомить действие или в данж или гибкий многоходовочный файт с мобами.


	}
	

	return false;
}
