/*
 * Project Name: Windows Arrow Keys
 * Author: João Rocha
 * Year: 2025
 * License: GNU Affero General Public License v3 (AGPLv3)
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 * Commercial Use Restriction:
 * Commercial use of this software is strictly prohibited without prior
 * written permission from the author, João Rocha.
 */

#ifndef _MENUCLASS_XEDT_V1
#define _MENUCLASS_XEDT_V1

#include "cstdio"
#include "iostream"
#include "string"
#include "vector"
#include "windows.h"

using std::cin;
using std::cout;
using std::ios;
using std::string;
using std::vector;

class old_menu {

private:
	// to saves the set titles in vector
	vector<string> strvec_TitleVector;
	string		   str_Header = "";
	bool		   run		  = true;

public:
	// to get return-value
	int ModeToSet;

	// output function for all set titles
	void getTitle() {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, 112);

		cout << strvec_TitleVector[0];

		SetConsoleTextAttribute(hConsole, 7);

		for (int i = 1; i <= strvec_TitleVector.size() - 1; i++)
			cout << "\n" << strvec_TitleVector[i];
	}

	// function stores string values in vector
	void setTitle(const string &Title1) {
		strvec_TitleVector.push_back(Title1);
	}

	void setHeader(const string &headerRec) { str_Header = headerRec; }

	// selection algorithm...only modify what is marked with
	int chooseTitle() {

		// MODIFY
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		int Titlecounter = 0;

		// str_Header
		cout << str_Header;

		// MODIFY for custom select-text
		cout << "\nChoose Mode (Arrowkeys, Enter with ->):\n";

		getTitle();

		while (run) {

			for (int i = 0; i < 256; i++) {

				if (GetAsyncKeyState(i) & 0b1) {

					if (i == VK_DOWN) {

						system("cls");

						cout << str_Header;

						// MODIFY for custom select-text
						cout << "\nChoose Mode (Arrowkeys, Enter with ->):\n";

						if (Titlecounter < strvec_TitleVector.size() - 1) {

							Titlecounter++;

							for (int i = 0; i < Titlecounter; i++)
								cout << "\n" << strvec_TitleVector[i];

							// MODIFY for custom text color
							SetConsoleTextAttribute(hConsole, 112);

							cout << "\n" << strvec_TitleVector[Titlecounter];

							// MODIFY for custom text color
							SetConsoleTextAttribute(hConsole, 07);

							for (int i = Titlecounter + 1;
								i <= strvec_TitleVector.size() - 1; i++)
								cout << "\n" << strvec_TitleVector[i];

						} else if (i == VK_UP) {

							system("cls");
							cout << str_Header;

							// MODIFY
							cout << "\nChoose Mode (Arrowkeys,Enter with "
									"->):\n";

							// for custom select-text
							if (Titlecounter > 0) { Titlecounter--; }

							for (int i = 0; i < Titlecounter; i++)
								cout << "\n" << strvec_TitleVector[i];

							// MODIFY for custom text color
							SetConsoleTextAttribute(hConsole, 112);

							cout << "\n" << strvec_TitleVector[Titlecounter];

							// MODIFY for custom text color
							SetConsoleTextAttribute(hConsole, 07);

							for (int i = Titlecounter + 1;
								i <= strvec_TitleVector.size() - 1; i++) {
								cout << "\n" << strvec_TitleVector[i];
							}

							// MODIFY for custom 'select'-key
						} else if (i == VK_RIGHT) {

							system("cls");
							run = false;
							return Titlecounter;

						} else
							Sleep(500);
					}
				}
			}
		}
	}
};
#endif
