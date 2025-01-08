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
 *				// TODO: Finish the documentation  Interface.hpp
 *  @file      Interface.hpp
 *  @brief     
 *  @details    
 *  @author    João Rocha
 *  @date      7.01.2025
 *  @copyright João Rocha 2025
 *
 *****************************************************************************/

/*	
|–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––|
|																			  |
|					“I am not upset that you lied to me,					  |
|				I am upset that from now on I cannot believe you.”			  |
|							― Fredrich Nietzche								  |
|																			  |
|–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––|
*/

#pragma once

#include "Menu.hpp"
#include "MyTypes.hpp"

//TODO: Finish the documentation class Interface

/**
 *
 *  @class   Interface
 *  @brief   
 *  @details  
 *  @date    7.01.2025
 *
 */
class Interface : virtual public Menu {

public:
	//TODO: Finish the documentation Interface();
	/**
  *
  *  @brief   Interface object constructor
  *  @details  
  *  @date    7.01.2025
  *
  */

	Interface();
	//TODO: Finish the documentation void CreateMenu();

	/**
  *
  *  @brief   
  *  @details  
  *  @date    7.01.2025
  *
  */
	void CreateMenu();

	//TODO: Finish the documentation void clearBuffer();

	/**
  *
  *  @brief   
  *  @details  
  *  @date    7.01.2025
  *
  */
	void clearBuffer();

	//TODO: Finish the documentation void whriteToCosole();

	/**
  *
  *  @brief   
  *  @details  
  *  @date    7.01.2025
  *
  */
	void whriteToCosole();

	//TODO: Finish the documentation void help();

	/**
  *
  *  @brief   
  *  @details  
  *  @date    7.01.2025
  *
  */
	void help();

	//TODO: Finish the documentation void About();

	/**
  *
  *  @brief   
  *  @details  
  *  @date    7.01.2025
  *
  */
	void About();

protected:
	//TODO: Finish the documentation void func_vClearScreen();
	/**
  *
  *  @brief   
  *  @details  
  *  @date    7.01.2025
  *
  */
	void func_vClearScreen();
};
