#include "Menu.hpp"

#define NOMINMAX

#include "MyTypes.hpp"

#include <consoleapi2.h>
#include <processenv.h>
#include <synchapi.h>
#include <windows.h>

#include <iosfwd>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

Menu::Menu()
    : bNumKey(false)
    , bRun(true)
    , hConsole()
    , iNumKeyNumber(-1)
    , iModeToSet(0)
    , Titlecounter(0)
    , header()
    , titleVector() {
    bool bHasBuffer = std::cin.rdbuf()->in_avail() > 0;

    if (bHasBuffer) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    func_vRideCursor();
}

void Menu::func_vShowTitle() {
    HANDLE
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 112);

    /*if (bNumKey) std::cout << '>' << titleVector[iNumKeyNumber];

    if (!bNumKey) std::cout << '>' << titleVector[0];*/

    std::cout << "\n >" << titleVector[0];

    SetConsoleTextAttribute(hConsole, 7);

    for (int i = 1; i <= titleVector.size() - 1; i++)
        std::cout << "\n " << titleVector[i];
}

int Menu::getModeToSet() const { return iModeToSet; }

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
    std::cout << header; // header
}

void Menu::func_vPrintMsg() {
    // MODIFY for custom
    std::cout << "Choose Mode (Arrowkeys, Enter with ->):\n";
}

void Menu::func_vClearScreen() { std::cout << "\033[2J\033[1;1H"; }

void Menu::setTitle(std::string const& Title1) {
    titleVector.push_back(Title1);
}

void Menu::setHeader(std::string const& headerRec) { header = headerRec; }

int Menu::PrintTitle() {
    // header
    std::cout << header;

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
    Titlecounter = 0;

    while (bRun) {
        for (int i = 0; i < 256; i++) {
            if (GetAsyncKeyState(i) & 0b1) {
                if (i == VK_DOWN) func_vUpArrow();
                else if (i == VK_UP)
                    func_vDownArrow();
                else if (i == VK_RETURN)
                    return func_vEnterKey();
                else if (i == VK_ESCAPE)
                    return 0;
                else if (!(i == VK_DOWN, i == VK_UP, i == VK_RETURN,
                    i == VK_RETURN))
                    func_iNumberKeys(i);
            }
            else
                Sleep(500);
        }
    }
}

void Menu::func_vUpArrow() {
    size_t vecSize = titleVector.size();
    size_t lines = vecSize + 1;
    func_vEraseLines(lines);

    if (Titlecounter < titleVector.size() - 1) { Titlecounter++; }

    for (size_t i = 0; i < Titlecounter; i++)
        std::cout << "\n" << titleVector[i];

    // MODIFY for custom text color
    SetConsoleTextAttribute(hConsole, 112);

    std::cout << "\n >" << titleVector[Titlecounter];

    // MODIFY for custom text color
    SetConsoleTextAttribute(hConsole, 07);

    for (int i = Titlecounter + 1; i <= titleVector.size() - 1; i++)
        std::cout << "\n" << titleVector[i];

    Sleep(100);
}

void Menu::func_vDownArrow() {
    int vecSize = titleVector.size();
    int lines = vecSize + 1;
    func_vEraseLines(lines);

    if (Titlecounter > 0) Titlecounter--;

    for (int i = 0; i < Titlecounter; i++) {
        std::cout << "\n" << titleVector[i];
    }

// MODIFY for custom text color
    SetConsoleTextAttribute(hConsole, 112);

    std::cout << "\n >" << titleVector[Titlecounter];
    // MODIFY for custom text color
    SetConsoleTextAttribute(hConsole, 07);

    for (int i = Titlecounter + 1; i <= titleVector.size() - 1; i++)
        std::cout << "\n" << titleVector[i];

    Sleep(100);
}

int Menu::func_vEnterKey() {
    func_vClearScreen();

    Sleep(100);
    bRun = false;

    return Titlecounter + 1;
}

int Menu::func_iNumberKeys(int iPosition) {
    int i = iPosition;

    if (i == VK_0 || i == VK_NUMPAD0) return func_iNumKey(0);
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