/*****************************************************************/ /**
 * @file Menu.hpp
 *
 * @brief A class that creates a menu with a list of options,
 * and the user can choose one of them using the arrow keys with
 * enter key. Also, number keys and numpad keys work aswell.
 *
 * @author João Rocha
 * @date 4 January 2025
 *********************************************************************/

#pragma once

#ifndef _MENUCLASS_XEDT_V1
#define _MENUCLASS_XEDT_V1

#include <string>
#include <vector>

typedef void *HANDLE;

class Menu {
private:

    bool bNumKey;
    bool bRun;
    HANDLE hConsole;
    int iNumKeyNumber;
    int iModeToSet;
    int Titlecounter;
    std::string header;
    std::vector<std::string> titleVector;

protected:

    /**
    * @brief This function processes the number key input.
    * @param uiNumKey The number key that was pressed.
    * @return uiNumKey itself the processed number key.
    */
    int func_iNumKey(const unsigned int uiNumKey);

    /**
     * @brief This function processes the key input.
     * @return Titlecounter + 1 where is the cursor.
     */
    int func_iRun();

    /**
     * @brief When the enter-key is pressed.
     * @return Titlecounter + 1 where is the cursor.
     */
    int func_vEnterKey();

    /**
     * @brief Clears the screen.
     */
    void func_vClearScreen();

    /**
     * @brief Moves the cursor down with the down arrow key.
     */
    void func_vDownArrow();

    /**
     * @brief Erases the lines.
     * @param uiCount The number of lines to erase.
     */
    void func_vEraseLines(const unsigned int uiCount);

    /**
     * @brief Prints the header.
     */
    void func_vPrintHeader();

    /**
     * @brief Prints the message.
     */
    void func_vPrintMsg();

    /**
     * @brief hides the cursor.
     */
    void func_vRideCursor();

    /**
     * @brief Moves the cursor up with the up arrow key.
     */
    void func_vUpArrow();

    /**
     * @brief Shows the title.
     */
    void func_vShowTitle();

public:

    /**
     * @brief Default contructor.
     */
    Menu();

    /**
     * Prints the title.
     *
     * \return go to func_iRun() initializing the program;
     */
    int PrintTitle();

    // Getters

    /**
     * @brief iModeToSet getter
     * @return iModeToSet
     */
    int getModeToSet() const;

    // Setters

    /**
     * @brief header setter
     * @param headerRec The header to set.
     */
    void setHeader(const std::string &headerRec);

    /**
     * @brief iModeToSet setter
     * @param iModeToSet The mode to set.
     */
    void setModeToSet(const int iModeToSet);

    /**
     * @brief setTitle setter
     * @param Title1 The title to set.
     */
    void setTitle(const std::string &Title1);

    /**
     * @brief Default destructor.
     */
    ~Menu();
};

#endif