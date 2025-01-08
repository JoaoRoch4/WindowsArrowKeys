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

#pragma once

#define NOMINMAX

#include <consoleapi2.h>

#include <iostream>
#include <string>
#include <vector>

// #define out	 std::cout
// #define wout std::wcout
// #define in	 std::cin
// #define win	 std::wcin
// #define setUTF8()          \
//	setlocale(LC_ALL, ""); \
//	SetConsoleOutputCP(65'001)

typedef std::string				  str;
typedef std::wstring			  wstr;
typedef std::vector<int>		  vec;
typedef std::vector<std::string>  vecStr;
typedef std::vector<std::wstring> vecWstr;

void headerShow() noexcept;
void headerShow(const bool& show) noexcept;
