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

#include "MyTypes.hpp"

// clang-format off

void headerShow() noexcept {
    const char* Msg{
      "——————————————————————————————————————————————————————————————————————————————————————————"
      "——————————————————————————|\n|"
      "\t\t\t\t"
      "Made by: —— João André Rocha de Almeida —— "
      "\t\t\t\t\t    "
      "|\n| "
      "\t\t\t\t"
      "Now:"
      "\t    " __DATE__ "  --  " __TIME__ "Hs"
      "\t\t\t\t\t\t    "
      "|\n|\t\t\t\t"
      "———————————————————————————————————————"
      "\t\t\t\t\t            "
      "|\n|\t"
      "File path: "
      "\t\t\t\t\t\t\t\t\t\t\t\t    "
      "|\n|" __FILE__ "    |"
      "\n|—————————————————————————————————————————————————————————————————————————————————"
      "——————————————————————————————————|\n\n"
    };
    std::cout << Msg;
}

void headerShow(const bool& show) noexcept {
    if (!show) return;

    const char* Msg{
      "——————————————————————————————————————————————————————————————————————————————————————————"
      "——————————————————————————|\n|"
      "\t\t\t\t"
      "Made by: —— João André Rocha de Almeida —— "
      "\t\t\t\t\t    "
      "|\n| "
      "\t\t\t\t"
      "Now:"
      "\t    " __DATE__ "  --  " __TIME__ "Hs"
      "\t\t\t\t\t\t    "
      "|\n|\t\t\t\t"
      "———————————————————————————————————————"
      "\t\t\t\t\t            "
      "|\n|\t"
      "File path: "
      "\t\t\t\t\t\t\t\t\t\t\t\t    "
      "|\n|" __FILE__ "    |"
      "\n|—————————————————————————————————————————————————————————————————————————————————"
      "——————————————————————————————————|\n\n" };

    std::cout << Msg;
}

// clang-format on