/*
 *
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
 *
 */

/******************************************************************************
 *
 *  @file      Menu.cpp
 *  @brief     Menu.hpp implementation file
 *  @author    João Rocha
 *  @date      4 January 2025 / 6 January 2025
 *  @copyright João Rocha 2025
 *
 *****************************************************************************/

#include "Menu.hpp"

#define NOMINMAX
#define GetAsync(key) GetAsyncKeyState(key) & 0x8000

#include <consoleapi2.h>
#include <processenv.h>
#include <synchapi.h>
#include <windows.h>

#include <cstdlib>
#include <functional>
#include <initializer_list>
#include <iosfwd>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "MyTypes.hpp"

Menu::Menu()
    : bNumKey(false),
      bRun(true),
      hConsole(),
      iNumKeyNumber(-1),
      iModeToSet(0),
      iTitlecounter(0),
      str_Header(),
      strvec_TitleVector() {
  bool bHasBuffer = std::cin.rdbuf()->in_avail() > 0;

  if (bHasBuffer) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  func_vRideCursor();
}

int Menu::chooseTitle() { return func_iRun(); }

void Menu::func_vShowTitle() {
  HANDLE
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hConsole, 112);

  /*if (bNumKey) std::cout << '>' << titleVector[iNumKeyNumber];

  if (!bNumKey) std::cout << '>' << titleVector[0];*/

  std::cout << "\n >" << strvec_TitleVector[0];

  SetConsoleTextAttribute(hConsole, 7);

  for (int i = 1; i <= strvec_TitleVector.size() - 1; i++)
    std::cout << "\n " << strvec_TitleVector[i];
}

int Menu::getModeToSet() { return iModeToSet; }

void Menu::setModeToSet(int const iModeToSet) { this->iModeToSet = iModeToSet; }

void Menu::func_vRideCursor() {
  HANDLE
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO
  cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void Menu::func_vPrintHeader() {
  headerShow();
  std::cout << str_Header;  // header
}

void Menu::func_vPrintMsg() {
  // MODIFY for custom
  std::cout << "Choose Mode (Arrowkeys, Enter with ->):\n";
}

void Menu::func_vClearScreen() { std::cout << "\033[2J\033[1;1H"; }

void Menu::setTitle(std::string const& Title1) {
  strvec_TitleVector.push_back(Title1);
}

void Menu::setTitle(std::initializer_list<std::string> list) {
  for (auto& Title : list) strvec_TitleVector.push_back(Title);
}

void Menu::setHeader(std::string const& headerRec) { str_Header = headerRec; }

int Menu::PrintTitle() {
  // header
  std::cout << str_Header;

  // MODIFY for custom // select-text
  std::cout << "\nChoose Mode (Arrowkey+s, Enter with ->):\n";

  func_vShowTitle();

  return func_iRun();
}

#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
#define VK_6 0x36
#define VK_7 0x37
#define VK_8 0x38
#define VK_9 0x39

int Menu::func_iRun() {
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  iTitlecounter = 0;

  // header
  std::cout << str_Header;

  // MODIFY for custom select-text
  std::cout << "\nChoose Mode (Arrowkeys, Enter with ->):\n";

  func_vShowTitle();
  bRun = true;
  while (bRun) {
    if (GetAsync(VK_UP)) func_vUpArrow();
    if (GetAsync(VK_DOWN)) func_vDownArrow();
    if (GetAsync(VK_RETURN)) func_iEnterKey();
    if (GetAsync(VK_ESCAPE)) func_iEscapeKey();

    // TODO: Finish
  }
  return iTitlecounter + 1;
}

// while (bRun) {
//     for (int i = 0; i < 256; i++) {
//         if (GetAsyncKeyState(i) & 0b1) {
//             if (i == VK_DOWN) {
//                 system("cls");
//                 std::cout << header;
//                 std::cout << "\nChoose Mode (Arrowkeys, Enter with ->):\n";
//                 // MODIFY for custom select-text if (Titlecounter <
//                 titleVector.size() - 1) {
//                     Titlecounter++;
//                 }
//                 for (int i = 0; i < Titlecounter; i++) {
//                     std::cout << "\n" << titleVector[i];
//                 }
//                 SetConsoleTextAttribute(hConsole, 112); // MODIFY for custom
//                 text color std::cout << "\n" << titleVector[Titlecounter];
//                 SetConsoleTextAttribute(hConsole, 07); // MODIFY for custom
//                 text color for (int i = Titlecounter + 1; i <=
//                 titleVector.size() - 1; i++) {
//                     std::cout << "\n" << titleVector[i];
//                 }
//             }
//             else if (i == VK_UP) {
//                 func_vClearScreen();
//                 std::cout << header;
//                 std::cout << "\nChoose Mode (Arrowkeys, Enter with ->):\n";
//                 // MODIFY for custom select-text if (Titlecounter > 0) {
//                     Titlecounter--;
//                 }
//                 for (int i = 0; i < Titlecounter; i++) {
//                     std::cout << "\n" << titleVector[i];
//                 }
//                 SetConsoleTextAttribute(hConsole, 112); // MODIFY for custom
//                 text color std::cout << "\n" << titleVector[Titlecounter];
//                 SetConsoleTextAttribute(hConsole, 07); // MODIFY for custom
//                 text color for (int i = Titlecounter + 1; i <=
//                 titleVector.size() - 1; i++) {
//                     std::cout << "\n" << titleVector[i];
//                 }
//             }
//             else if (i == VK_RIGHT) { // MODIFY for custom 'select'-key
//                 system("cls");
//                 bRun = false;
//                 return Titlecounter;
//             }
//             else {
//                 Sleep(500);
//             }
//         }
//     }
// }

/* while (bRun) {
     for (int i = 0; i < 256; i++) {
         if (GetAsyncKeyState(i) & 0b1) {
             if (i == VK_DOWN) func_vDownArrow();
             else if (i == VK_UP)
                 func_vUpArrow();
             else if (i == VK_RETURN)
                 return func_iEnterKey();
             else if (i == VK_ESCAPE)
                 return func_iEnterKey();
             else if (i == VK_0 || i == VK_NUMPAD0) return func_iNumKey(0);
             else if (i == VK_1 || i == VK_NUMPAD1)
                 return func_iNumKey(1);
             else if (i == VK_2 || i == VK_NUMPAD2)
                 return func_iNumKey(2);
             else if (i == VK_3 || i == VK_NUMPAD3)
                 return func_iNumKey(3);
             else if (i == VK_4 || i == VK_NUMPAD4)
                 return func_iNumKey(4);
             else if (i == VK_5 || i == VK_NUMPAD5)
                 return func_iNumKey(5);
             else if (i == VK_6 || i == VK_NUMPAD6)
                 return func_iNumKey(6);
             else if (i == VK_7 || i == VK_NUMPAD7)
                 return func_iNumKey(7);
             else if (i == VK_8 || i == VK_NUMPAD8)
                 return func_iNumKey(8);
             else if (i == VK_9 || i == VK_NUMPAD9)
                 return func_iNumKey(9);
         }
         else
             Sleep(500);
     }
 }*/

void Menu::func_vUpArrow() {
  Sleep(50);
  func_vClearScreen();

  std::cout << str_Header;

  // MODIFY for custom select-text
  std::cout << "\nChoose Mode (Arrowkeys, Enter with ->):\n";

  if (iTitlecounter > 0) iTitlecounter--;

  for (int i = 0; i < iTitlecounter; i++)
    std::cout << "\n" << strvec_TitleVector[i];

  // MODIFY for custom text color
  SetConsoleTextAttribute(hConsole, 112);
  std::cout << "\n" << strvec_TitleVector[iTitlecounter];

  // MODIFY for custom text color
  SetConsoleTextAttribute(hConsole, 07);
  for (int i = iTitlecounter + 1; i <= strvec_TitleVector.size() - 1; i++)
    std::cout << "\n" << strvec_TitleVector[i];

  // Delay for the key press
  Sleep(150);
}

void Menu::func_vDownArrow() {
  Sleep(50);
  func_vClearScreen();

  std::cout << str_Header;

  // MODIFY for custom select-text
  std::cout << "\nChoose Mode (Arrowkeys, Enter with ->):\n";

  if (iTitlecounter < strvec_TitleVector.size() - 1) iTitlecounter++;

  for (int i = 0; i < iTitlecounter; i++)
    std::cout << "\n" << strvec_TitleVector[i];

  // MODIFY for custom text color
  SetConsoleTextAttribute(hConsole, 112);

  std::cout << "\n" << strvec_TitleVector[iTitlecounter];

  // MODIFY for custom text color
  SetConsoleTextAttribute(hConsole, 07);
  for (int i = iTitlecounter + 1; i <= strvec_TitleVector.size() - 1; i++)
    std::cout << "\n" << strvec_TitleVector[i];

  Sleep(150);
}

int Menu::func_iEnterKey() {
  Sleep(20);
  func_vClearScreen();

  bRun = false;
  Sleep(300);
  return iTitlecounter + 1;
}

int Menu::func_iEscapeKey() {
  func_vClearScreen();
  bRun = false;
  std::cout << "Exiting...";
  Sleep(500);
  std::exit(0);
}

int Menu::func_iNumberKeys(int iPosition) {
  int i = iPosition;

  if (i == VK_0 || i == VK_NUMPAD0)
    return func_iNumKey(0);
  else if (i == VK_1 || i == VK_NUMPAD1)
    return func_iNumKey(1);
  else if (i == VK_2 || i == VK_NUMPAD2)
    return func_iNumKey(2);
  else if (i == VK_3 || i == VK_NUMPAD3)
    return func_iNumKey(3);
  else if (i == VK_4 || i == VK_NUMPAD4)
    return func_iNumKey(4);
  else if (i == VK_5 || i == VK_NUMPAD5)
    return func_iNumKey(5);
  else if (i == VK_6 || i == VK_NUMPAD6)
    return func_iNumKey(6);
  else if (i == VK_7 || i == VK_NUMPAD7)
    return func_iNumKey(7);
  else if (i == VK_8 || i == VK_NUMPAD8)
    return func_iNumKey(8);
  else if (i == VK_9 || i == VK_NUMPAD9)
    return func_iNumKey(9);
}

int Menu::func_iNumKey(unsigned int const uiNumKey) {
  func_vClearScreen();

  bNumKey = true;
  iNumKeyNumber = uiNumKey;

  Sleep(100);
  bRun = false;
  return uiNumKey;
}

void Menu::func_vEraseLines(unsigned int const uiCount) {
  if (uiCount <= 0) return;

  if (uiCount >= 1) {
    // Delete current line
    std::cout << "\x1b[2K";

    // i=1 because we included the first line
    for (unsigned int i = 1; i < uiCount; i++) {
      // Move cursor up one
      std::cout << "\x1b[1A";

      // Delete the entire line
      std::cout << "\x1b[2K";
    }

    // Resume the cursor at beginning of line
    std::cout << "\r";
  }
}

Menu ::~Menu() {
  bool bHasBuffer = std::cin.rdbuf()->in_avail() > 0;

  if (bHasBuffer) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

Menu::Menu(bool bNumKey, bool bRun, const HANDLE& hConsole, int iNumKeyNumber,
           int iModeToSet, int iTitlecounter, const std::string& str_Header,
           const std::vector<std::string>& strvec_TitleVector)
    : bNumKey(bNumKey),
      bRun(bRun),
      hConsole(hConsole),
      iNumKeyNumber(iNumKeyNumber),
      iModeToSet(iModeToSet),
      iTitlecounter(iTitlecounter),
      str_Header(str_Header),
      strvec_TitleVector(strvec_TitleVector) {}
