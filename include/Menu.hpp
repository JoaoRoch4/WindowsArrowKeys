/******************************************************************************
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
 *****************************************************************************/

/******************************************************************************
  * @file Menu.hpp
  *
  * @brief A class that creates a menu with a list of options,
  * and the user can choose one of them using the arrow keys with
  * enter key. Also, number keys and numpad keys work aswell.
  *
  * @author João Rocha
  * @date 4 January 2025
  * 
******************************************************************************/

/*
  |–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––|
  |                                                                           |
  |     To work and create "for nothing," to sculpture in clay, to know one's |
  |  creation has no future, to see one's work destroyed in a day while being |
  |  aware that fundamentally this has no more importance than building for   |
  |  centuries — this is the difficult wisdom that absurd thought sanctions.  |
  |  Performing these two tasks simultaneously, negating on the one hand and  |
  |  magnifying on the other, it the way open to the absurd creator.          |
  |     He must give the void its colors.                                     |
  |                                                                           |
  |     – Albert Camus                                                        |
  |                                                                           |
  |–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––|
*/

#pragma once

#include <string>
#include <vector>

/**
  *
  *  @typedef HANDLE
  *  @brief   HANDLE type from windows.h.
  *  @date    7.01.2025
  *
*/
typedef void* HANDLE;

/**
 *
 *  @class Menu Menu.hpp "include/Menu.hpp"
 *  @brief The Menu class provides a console-based interactive menu system.
 *  @details It allows users to navigate through a list of options using the
 *      arrow keys and select an option with the enter key. It also supports
 *      selection via number keys and numpad keys.
 *
 */
class Menu {
private:
	/**
	*
	* @privatesection
	* @brief if a number key was pressed.
	* @date     2.01.2025
	*
	*/
	bool bNumKey;

	/**
  *
  * @privatesection
  * @brief if the program is running or not.
  * @date     2.01.2025
  *
  */
	bool bRun;
	/**
  *
  * @privatesection
  * @brief The console handle.
  * @date     2.01.2025
  *
  */
	HANDLE hConsole;

	/**
   *
   * @privatesection
   * @brief The number key that was pressed.
   * @date     2.01.2025
   *
   */
	int iNumKeyNumber;

	/**
   *
   * @privatesection
   * @brief The mode to set.
   * @date     2.01.2025
   *
   */
	int iModeToSet;

	/**
	*
	* @privatesection
	* @brief The cursor position.
	* @date     2.01.2025
	*
	*/
	int iTitlecounter;

	/**
	*
	* @privatesection
	* @brief The header.
	* @date     2.01.2025
	*
	*/
	std::string str_Header;

	/**
   *
   * @privatesection
   * @brief The title.
   * @date     2.01.2025
   *
   */
	std::vector<std::string> strvec_TitleVector;

protected:
	/**
	  *
	  * @protectedsection
	  * @brief This function processes the number key input.
	  * @param[in] uiNumKey The number key that was pressed.
	  * @return uiNumKey; itself the processed number key.
	  * @date     2.01.2025
	  *
	  */
	int func_iNumKey(const unsigned int uiNumKey);

	/**
  *
  *  @brief   
  *  @details  
  *  @param   uiNumKey   
  *  @param   DebugBreak 
  *  @returns            
  *  @date    7.01.2025
  *		
  //TODO: Finish the documentation int func_iNumKey(DebugBreak const bool DebugBreak);

  */
	int func_iNumKey(const unsigned int uiNumKey, const bool DebugBreak);

	/**
  *
  *  @brief   
  *  @details  
  *  @param   uiNumKey   
  *  @param   DebugBreak 
  *  @returns            
  *  @date    7.01.2025
  *
  */

	/**
	 *
	 * @protectedsection
	 * @brief This function processes the key input.
	 * @return iTitlecounter + 1; where is the cursor.
	 * @date     2.01.2025
	 *
	 */
	int func_iRun();

	/**
	*
	* @protectedsection
	* @brief When the enter-key is pressed.
	* @return iTitlecounter + 1 where is the cursor.
	* @date     2.01.2025
	*
	*/
	int func_iEnterKey();

	/**
  *
  *  @brief   
  *  @details  
  *  @param   DebugBreak 
  *  @returns            
  *  @date    7.01.2025
  *
  */

	//TODO: Finish the documentation int func_iEnterKey(const bool DebugBreak);

	int func_iEnterKey(const bool DebugBreak);

	/**
   *
   *  @protectedsection
   *  @brief   Closses the program when the escape key is pressed.
   *  @details call func_vClearScreen(); set bRun to false;
   *           print "Exiting..."; call Sleep(500); call std::exit(0);
   *           ending the program.
   *  @returns  Nothing.
   *  @date    6.01.2025
   *
   */
	int func_iEscapeKey();

	/**
   *
   *  @protectedsection
   *  @brief   Clears the screen.
   *  @details
   *  @date    2.01.2025
   *
   */
	void func_vClearScreen();

	/**
   *
   *  @protectedsection
   *  @brief   Moves the cursor down with the down arrow key.
   *  @details
   *  @date    7.01.2025
   *
   */
	void func_vDownArrow();

	/**
  *
  *  @brief   
  *  @details  
  *  @param   DebugBreak 
  *  @date    7.01.2025
  *
  */
	//TODO: Finish the documentation func_vDownArrow(const bool DebugBreak);

	void func_vDownArrow(const bool DebugBreak);

	/**
   *
   * @protectedsection
   * @brief Erases the lines.
   * @param uiCount The number of lines to erase.
   *
   */
	void func_vEraseLines(const unsigned int uiCount);

	/**
   *
   * @protectedsection
   * @brief Prints the header.
   */
	void func_vPrintHeader();

	/**
   *
   * @protectedsection
   * @brief Prints the message.
   */
	void func_vPrintMsg();

	/**
   *
   * @protectedsection
   * @brief hides the cursor.
   */
	void func_vRideCursor();

	/**
   * @protectedsection
   * @brief Moves the cursor up with the up arrow key.
   */
	void func_vUpArrow();
	/**
  *
  *  @brief   
  *  @details  
  *  @param   DebugBreak 
  *  @date    7.01.2025
  *
  */
	void func_vUpArrow(const bool DebugBreak);

	/**
   * @protectedsection
   * @brief Shows the title.
   */
	void func_vShowTitle();

	/**
   *
   *  @brief   Menu object constructor with parameters.
   *  @details Default itialization of the Menu object.
   *  @see     bNumKey
   *  @see     bRun
   *  @see     hConsole
   *  @see     iNumKeyNumber
   *  @see     iModeToSet
   *  @see     iTitlecounter
   *  @see     str_Header
   *  @see     strvec_TitleVector
   *  @date    7.01.2025
   *
   */
	Menu(bool bNumKey, bool bRun, const HANDLE& hConsole, int iNumKeyNumber,
		int iModeToSet, int iTitlecounter, const std::string& str_Header,
		const std::vector<std::string>& strvec_TitleVector);

public:
	/**
   *
   *  @publicsection
   *  @brief   Menu object constructor
   *  @details
   *  @date    2.01.2025
   *
 */
	Menu();
	/**
   *
   *  @publicsection
   *  @brief   go to func_iRun();.
   *  @details
   *  @returns func_iRun();.
   *  @date    4.01.2025
   *
   */
	int chooseTitle();

	/**
  *
  * @publicsection
  * @brief   Prints the title.
  * @details
  * @returns Return go to func_iRun() initializing the program.
  * @date    4.01.2025
  *
  */
	int PrintTitle();

	/*Getters*/

	/**
   *
   *  @publicsection
   *  @brief    Getter. Get iModeToSet.
   *  @details
   *  @returns  iModeToSet.
   *  @date     4.01.2025
   *
   */
	int getModeToSet();

	/*Setters*/

	/**
   *
   *  @publicsection
   *  @brief     Setter. Set header
   *  @details   pass the header to str_Header
   *  @param[in] headerRec the string to be passed to str_Header
   *  @date      4.01.2025
   *
   */
	void setHeader(const std::string& headerRec);

	/**
	  *
	  *  @publicsection
	  *  @brief   Setter. iModeToSet setter
	  *  @details
	  *  @param   iModeToSet mode to set
	  *  @date    4.01.2025
	  *
	*/
	void setModeToSet(const int iModeToSet);

	/* !Setters */

	/**
	  *
	  *  @publicsection
	  *  @brief     Set title
	  *  @details
	  *  @param[in] Title1 title
	  *  @date         6.01.2025
	  *  @code
	  *  Menu home;
	  *  home.setTitle(" Option ~~~~~~~~~~ 1 ");
	  *  home.setTitle(" Option ~~~~~~~~~~ 2 ");
	  *  home.setTitle(" Option ~~~~~~~~~~ 7 - whrite to console ");
	  *  home.setTitle(" Option ~~~~~~~~~~ 8 - Get help ");
	  *  home.setTitle(" Option ~~~~~~~~~~ 9 - About ");
	  *  @endcode
	  *
	  */
	void setTitle(const std::string& Title1);

	/**
   *
   *  @publicsection
   *  @brief Setter. Sets the title.
   *  @details uses a for each loop to get the title to titleVector.push_back
   *  @param[in] list The list of titles.
   * set an std::initializer_list<std::string> that will be pushed
   * to titleVector
   *  @date    5.01.2025
   *  @details Exemple:
   *  @code
   *  Menu home;
   *  home.setTitle({" Option ~~~~~~~~~~ 1 ",
   *   " Option ~~~~~~~~~~ 2 ",
   *   " Option ~~~~~~~~~~ 3 ", });
   *  @endcode
   *
   */
	void setTitle(std::initializer_list<std::string> list);

	/**
   *
   *  @publicsection
   *  @brief   Menu object destructor
   *  @details
   *  @date    2.01.2025
   *
   */
	~Menu();

	bool operator==(const Menu& other) const = default;
};
