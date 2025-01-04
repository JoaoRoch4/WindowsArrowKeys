#pragma once
#ifndef _MENUCLASS_XEDT_V1
#define _MENUCLASS_XEDT_V1

#include <iostream>
#include <string>
#include <vector>


typedef void *HANDLE;

class Menu {

private:

    bool bNumKey;
    bool bRun;
    HANDLE hConsole;
    int iNumKeyNumber;
    int ModeToSet;
    int Titlecounter;
    std::string header;
    std::vector<std::string> titleVector;


protected:

    int  func_iNumKey(const unsigned int uiNumKey);
    int  func_iRun();
    int  func_vEnterKey();

    void func_vClearScreen();
    void func_vDownArrow();
    void func_vEraseLines(const unsigned int uiCount);
    void func_vPrintHeader();
    void func_vPrintMsg();
    void func_vRideCursor();
    void func_vUpArrow();

public:

    Menu();

    int chooseTitle();
    int getModeToSet() const;
    void getTitle();
    void setHeader(const std::string &headerRec);
    void setModeToSet(const int ModeToSet);
    void setTitle(const std::string &Title1);

    ~Menu();
};

#endif