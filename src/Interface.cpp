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
 * written permission from the author, João Rocha.		   ,
 * 
 *****************************************************************************/

/******************************************************************************
 *					// TODO: Finish the documentation  Interface.hpp
 *  @file      Interface.cpp
 *  @brief     
 *  @author    João Rocha
 *  @date      7.01.2025
 *  @copyright João Rocha 2025
 *
 *****************************************************************************/

#include "Interface.hpp"
#include "Menu.hpp"

// TODO: Implement the Interface constructor
Interface::Interface() {}

// TODO: Implement the Interface constructor
Interface::Interface() {}

// TODO: Implement CreateMenu
void Interface::CreateMenu() {

	clearBuffer();
	Menu home;

	home.setTitle({" Option ~~~~~~~~~~ 1 ", " Option ~~~~~~~~~~ 2 ",
		" Option ~~~~~~~~~~ 3 ", " Option ~~~~~~~~~~ 4 ",
		" Option ~~~~~~~~~~ 5 ", " Option ~~~~~~~~~~ 6 ",
		" Option ~~~~~~~~~~ 7 - whrite to console ",
		" Option ~~~~~~~~~~ 8 - Get help ", " Option ~~~~~~~~~~ 9 - About "});

	home.setModeToSet(home.chooseTitle());

	std::cout << "Selected Option: " << home.getModeToSet() << '\n';

	clearBuffer();

	auto clearAndReturn = [&]() {
		clearBuffer();
		CreateMenu();
	};

	int mode = home.getModeToSet();

	switch (mode) {

		case 1 : std::cout << "Option 1"; return clearAndReturn();
		case 2 : std::cout << "Option 2"; return clearAndReturn();
		case 3 : std::cout << "Option 3"; return clearAndReturn();
		case 4 : std::cout << "Option 4"; return clearAndReturn();
		case 5 : std::cout << "Option 5"; return clearAndReturn();
		case 6 : std::cout << "Option 6"; return clearAndReturn();

		case 7 : {

			std::cout << "Option 7";
			whriteToCosole();
			return clearAndReturn();
		}

		case 8 : {

			std::cout << "Option 8";
			help();
			return clearAndReturn();
		}

		case 9 : {

			std::cout << "Option 9";
			About();
			return clearAndReturn();
		}

		case 10 : [[fallthrough]];

		default : std::cout << "Option not found"; return clearAndReturn();
	}
}

// TODO: Implement clearBuffer
void Interface::clearBuffer() {

	bool bHasBuffer = std::cin.rdbuf()->in_avail() > 0;

	if (bHasBuffer) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// TODO: Implement func_vClearScreen
void Interface::func_vClearScreen() {

	int count = 100;
	// Delete current line
	std::cout << "\x1b[2K";

	// i=1 because we included the first line
	for (int i = 1; i < count; i++) {
		// Move cursor up one
		std::cout << "\x1b[1A"

				  // Delete the entire line
				  << "\x1b[2K";
	}
	// Resume the cursor at beginning of line
	std::cout << "\r";
}

// TODO: Implement whriteToCosole
void Interface::whriteToCosole() {

	func_vClearScreen();

	std::string get;
	std::cin >> get;
	char const *str = get.c_str();
	std::system(str);
}

// TODO: Implement help
void Interface::help() {

	std::cout << "\nHelp: \n";

	std::cout << (R"(
	   Heard dirges word i raven this nights more its i much gaunt
	   what word the master there more entreating broken a scarce at out in one
 this or syllable dared eyes that more heaven again swung upon gently soul said
 was to grim theeby whose your as fact this is my bird thrilled his sad from
 its did tapping for sitting this beast by beguiling the hope agreeing dreams
 bird is is bends stock placid before thing beguiling my fowl while in flirt
 \n)");
}

// TODO: Implement About
void Interface::About() {

	std::cout << "\nAbout: \n";

	std::cout << (
		R"( Aliquyam labore te voluptua dolor diam diam lorem nonumy nonumy,
 consequat justo takimata consetetur tempor sadipscing erat accusam accusam
 sit at  sadipscing aliquyam nonumy sadipscing nonummy ipsum erat dolor no
 illum nulla accusam consequat sed lorem et enim delenit sanctus eos sed
 dolor aliquyam eos sit ut amet accumsan et placerat dolore illum in ipsum
 tempor lorem et dolores liber eirmod nulla ipsum aliquyam diam qui lorem
 lorem dolor tation gubergren imperdiet voluptua rebum enim labore volutpat
 sit lorem feugait dolore molestie velit amet consequat sit gubergren lorem
 ut est sit sed et no justo dolore eirmod veniam et est velit rebum diam
 dolores nulla amet at duo at ea labore dolore vero sea gubergren justo diam
 eros clita tempor accusam dolore nonumy dolor sit lorem nonummy dolores id
 ipsum erat gubergren diam consetetur elitr et sanctus ut veniam in autem lorem
 eos eirmod facer no sanctus sea ipsum justo dignissim magna lorem takimata ea
 blandit sed amet lorem lorem eirmod sea dolor eos justo sed sed stet lorem
 clita minim velit kasd odio sed et erat labore at dolore elitr tempor ut
 voluptua sit ipsum kasd sit eros tincidunt voluptua takimata wisi amet elitr
 tempor takimata sit aliquam amet.
\n)");
}

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
 * written permission from the author, João Rocha.		   ,
 * 
 *****************************************************************************/

/******************************************************************************
 *					// TODO: Finish the documentation  Interface.hpp
 *  @file      Interface.cpp
 *  @brief     
 *  @author    João Rocha
 *  @date      7.01.2025
 *  @copyright João Rocha 2025
 *
 *****************************************************************************/

#include "Interface.hpp"
#include "Menu.hpp"

// TODO: Implement the Interface constructor
Interface::Interface() {}

// TODO: Implement CreateMenu
void Interface::CreateMenu() {

	clearBuffer();
	Menu home;

	home.setTitle({" Option ~~~~~~~~~~ 1 ", " Option ~~~~~~~~~~ 2 ",
		" Option ~~~~~~~~~~ 3 ", " Option ~~~~~~~~~~ 4 ",
		" Option ~~~~~~~~~~ 5 ", " Option ~~~~~~~~~~ 6 ",
		" Option ~~~~~~~~~~ 7 - write to console ",
		" Option ~~~~~~~~~~ 8 - Get help ", " Option ~~~~~~~~~~ 9 - About "});

	home.setModeToSet(home.chooseTitle());

	std::cout << "Selected Option: " << home.getModeToSet() << '\n';

	clearBuffer();

	auto clearAndReturn = [&]() {
		clearBuffer();
		CreateMenu();
	};

	int mode = home.getModeToSet();

	switch (mode) {

		case 1 : std::cout << "Option 1"; return clearAndReturn();
		case 2 : std::cout << "Option 2"; return clearAndReturn();
		case 3 : std::cout << "Option 3"; return clearAndReturn();
		case 4 : std::cout << "Option 4"; return clearAndReturn();
		case 5 : std::cout << "Option 5"; return clearAndReturn();
		case 6 : std::cout << "Option 6"; return clearAndReturn();

		case 7 : {

			std::cout << "Option 7";
			writeToConsole();
			return clearAndReturn();
		}

		case 8 : {

			std::cout << "Option 8";
			help();
			return clearAndReturn();
		}

		case 9 : {

			std::cout << "Option 9";
			About();
			return clearAndReturn();
		}

		case 10 : [[fallthrough]];

		default : std::cout << "Option not found"; return clearAndReturn();
	}
}

// TODO: Implement clearBuffer
void Interface::clearBuffer() {

	bool bHasBuffer = std::cin.rdbuf()->in_avail() > 0;

	if (bHasBuffer) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// TODO: Implement func_vClearScreen
void Interface::func_vClearScreen() {

	int count = 100;
	// Delete current line
	std::cout << "\x1b[2K";

	// i=1 because we included the first line
	for (int i = 1; i < count; i++) {
		// Move cursor up one
		std::cout << "\x1b[1A"

				  // Delete the entire line
				  << "\x1b[2K";
	}
	// Resume the cursor at beginning of line
	std::cout << "\r";
}

// TODO: Implement writeToConsole
void Interface::writeToConsole() {

	func_vClearScreen();

	std::string get;
	std::cin >> get;
	char const *str = get.c_str();
	std::system(str);
}

// TODO: Implement help
void Interface::help() {

	std::cout << "\nHelp: \n";

	std::cout << (R"(
	   Heard dirges word i raven this nights more its i much gaunt
	   what word the master there more entreating broken a scarce at out in one
 this or syllable dared eyes that more heaven again swung upon gently soul said
 was to grim theeby whose your as fact this is my bird thrilled his sad from
 its did tapping for sitting this beast by beguiling the hope agreeing dreams
 bird is is bends stock placid before thing beguiling my fowl while in flirt
 \n)");
}

// TODO: Implement About
void Interface::About() {

	std::cout << "\nAbout: \n";

	std::cout << (
		R"( Aliquyam labore te voluptua dolor diam diam lorem nonumy nonumy,
 consequat justo takimata consetetur tempor sadipscing erat accusam accusam
 sit at  sadipscing aliquyam nonumy sadipscing nonummy ipsum erat dolor no
 illum nulla accusam consequat sed lorem et enim delenit sanctus eos sed
 dolor aliquyam eos sit ut amet accumsan et placerat dolore illum in ipsum
 tempor lorem et dolores liber eirmod nulla ipsum aliquyam diam qui lorem
 lorem dolor tation gubergren imperdiet voluptua rebum enim labore volutpat
 sit lorem feugait dolore molestie velit amet consequat sit gubergren lorem
 ut est sit sed et no justo dolore eirmod veniam et est velit rebum diam
 dolores nulla amet at duo at ea labore dolore vero sea gubergren justo diam
 eros clita tempor accusam dolore nonumy dolor sit lorem nonummy dolores id
 ipsum erat gubergren diam consetetur elitr et sanctus ut veniam in autem lorem
 eos eirmod facer no sanctus sea ipsum justo dignissim magna lorem takimata ea
 blandit sed amet lorem lorem eirmod sea dolor eos justo sed sed stet lorem
 clita minim velit kasd odio sed et erat labore at dolore elitr tempor ut
 voluptua sit ipsum kasd sit eros tincidunt voluptua takimata wisi amet elitr
 tempor takimata sit aliquam amet.
\n)");
}

// TODO: implement func_vClearScreen
void Interface::func_vClearScreen() {

	int count = 100;
	// Delete current line
	std::cout << "\x1b[2K";

	// i=1 because we included the first line
	for (int i = 1; i < count; i++) {
		// Move cursor up one
		std::cout << "\x1b[1A"

				  // Delete the entire line
				  << "\x1b[2K";
	}
	// Resume the cursor at beginning of line
	std::cout << "\r";
}

// TODO: implement whriteToCosole()
void Interface::whriteToCosole() {

	func_vClearScreen();

	std::string get;
	std::cin >> get;
	char const *str = get.c_str();
	std::system(str);
}

// TODO: implement help()
void Interface::help() {

	std::cout << "\nHelp: \n";

	std::cout << (R"(
	   Heard dirges word i raven this nights more its i much gaunt
	   what word the master there more entreating broken a scarce at out in one
 this or syllable dared eyes that more heaven again swung upon gently soul said
 was to grim theeby whose your as fact this is my bird thrilled his sad from
 its did tapping for sitting this beast by beguiling the hope agreeing dreams
 bird is is bends stock placid before thing beguiling my fowl while in flirt
 \n)");
}

// TODO: implement About()
void Interface::About() {

	std::cout << "\nAbout: \n";

	std::cout << (
		R"( Aliquyam labore te voluptua dolor diam diam lorem nonumy nonumy,
 consequat justo takimata consetetur tempor sadipscing erat accusam accusam
 sit at  sadipscing aliquyam nonumy sadipscing nonummy ipsum erat dolor no
 illum nulla accusam consequat sed lorem et enim delenit sanctus eos sed
 dolor aliquyam eos sit ut amet accumsan et placerat dolore illum in ipsum
 tempor lorem et dolores liber eirmod nulla ipsum aliquyam diam qui lorem
 lorem dolor tation gubergren imperdiet voluptua rebum enim labore volutpat
 sit lorem feugait dolore molestie velit amet consequat sit gubergren lorem
 ut est sit sed et no justo dolore eirmod veniam et est velit rebum diam
 dolores nulla amet at duo at ea labore dolore vero sea gubergren justo diam
 eros clita tempor accusam dolore nonumy dolor sit lorem nonummy dolores id
 ipsum erat gubergren diam consetetur elitr et sanctus ut veniam in autem lorem
 eos eirmod facer no sanctus sea ipsum justo dignissim magna lorem takimata ea
 blandit sed amet lorem lorem eirmod sea dolor eos justo sed sed stet lorem
 clita minim velit kasd odio sed et erat labore at dolore elitr tempor ut
 voluptua sit ipsum kasd sit eros tincidunt voluptua takimata wisi amet elitr
 tempor takimata sit aliquam amet.
\n)");
}
