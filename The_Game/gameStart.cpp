#include "gameStart.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

void theGameStart()
{
	bool stop = false; // ���� True - ������������� ������
	string out = "Welcome, to the PockeFightGame";
	string heh = "heh";
	string lets = "Just let's enjoy! :3"; // ����� ���������� �����, ����� ����� ���� �� ������� �������� � ������� ��������� �������.
		for (int i = 0; i <= 25; i++) {
			if (!stop)
			for (int j = 0; j < 100; j++) {
				if (!stop) {
					if (_kbhit()) { // ��������� ������� �� ���-���� �� ����������
						switch (_getch()) 
						{
						case 13: // ���� Enter
							stop = true;
							break;
						case 32: // ���� Space
							stop = true;
							break;
						case 27: // ���� Esc
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

			} // �������������� ������ ������ �� ����� � ���������
			cout << endl;
		}
}

bool gotoTheMenu() // ������ ���� � �������� ��� ��� ������ ������
{
	bool insideMenu = true;
	string newGame = "<newGame>";
	string score = "scoreRating";
	string help = "help";
	string exitFromGame = "exit";
	int posChose = 0; //������� ������� ������ < >
	while (insideMenu) {
		system("cls");


		if (_kbhit) {
			switch (_getch())
			{
			case 72: // ���� ������� ����� - ���������
				posChose--;
				if (posChose < 0) {
					posChose = 3;
				}
				break;
			case 80: // ���� ������� ���� - �����������
				posChose++;
				if (posChose > 3) {
					posChose = 0;
				}
				break;
			}
		}

		for (int i = 0; i < 20; i++) { // ������ ���� "�� ���������"
			for (int j = 0; j < 100; j++) {
				
				if (i == 10 and j >= (100 / 2 - newGame.length() / 2) and j <= (100 / 2 + newGame.length() / 2)) { // ������� ���������� ���������:
					cout << newGame[j - (100 / 2 - newGame.length() / 2)];									// ����� ����� ������/2 - �������� ����� 
				}																						// ��������� �������� ����� �������� ����������
																									// ������ ������ ��������� �������.
				else if (i == 12 and j >= (100 / 2 - score.length() / 2) and j <= (100 / 2 + score.length() / 2)) {
					cout << score[j - (100 / 2 - score.length() / 2)];
				}


				else if (i == 14 and j >= (100 / 2 - help.length() / 2) and j <= (100 / 2 + help.length() / 2)) {
					cout << help[j - (100 / 2 - help.length() / 2)];
				}

				else if (i == 16 and j >= (100 / 2 - exitFromGame.length() / 2) and j <= (100 / 2 + exitFromGame.length() / 2)) {
					cout << exitFromGame[j - (100 / 2 - exitFromGame.length() / 2)];
				}

				else
					cout << " ";
			}
			cout << endl;
		}

		Sleep(10000);


		// ������ � ����������� �� ����������. ����� ������� ���������� ����� ������� ����������� ������� ��������� ������.
		switch (posChose)
		{
		default:
			break;
		}
	}
	return false;
}
