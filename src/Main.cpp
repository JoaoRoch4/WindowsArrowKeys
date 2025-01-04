/*****************************************************************/ /**
 * @file   Main.cpp
 * @brief  
 * @author João Rocha
 * @date   4 January 2025
 *********************************************************************/

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include "Menu.hpp"
#include "MyTypes.hpp"

void funcMenu();

void clearBuffer() {
	bool bHasBuffer = std::cin.rdbuf()->in_avail() > 0;

	if (bHasBuffer) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void func_vClearScreen() {
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

void whriteToCosole() {
	func_vClearScreen();

	std::string get;
	std::cin >> get;
	const char *str = get.c_str();
	std::system(str);
}

void help() {
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

void About() {
	std::cout << "\nHelp: \n";

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

void funcMenu() {
	clearBuffer();
	Menu home;

	bool bSetted = false;

	if (bSetted == false) {
		home.setTitle(" Option ~~~~~~~~~~ 1 ");
		home.setTitle(" Option ~~~~~~~~~~ 2 ");
		home.setTitle(" Option ~~~~~~~~~~ 3 ");
		home.setTitle(" Option ~~~~~~~~~~ 4 ");
		home.setTitle(" Option ~~~~~~~~~~ 5 ");
		home.setTitle(" Option ~~~~~~~~~~ 6 ");
		home.setTitle(" Option ~~~~~~~~~~ 7 - whrite to console ");
		home.setTitle(" Option ~~~~~~~~~~ 8 - Get help ");
		home.setTitle(" Option ~~~~~~~~~~ 9 - About ");
		bSetted = true;
	}

	//...

	home.setModeToSet(home.getModeToSet());

	std::cout << "Selected Option: " << home.getModeToSet() << '\n';

	clearBuffer();

	auto clearAndReturn = []() {
		clearBuffer();
		funcMenu();
	};

	int mode = home.getModeToSet();

	switch (mode) {
		case 1: std::cout << "Option 1"; return clearAndReturn();
		case 2: std::cout << "Option 2"; return clearAndReturn();
		case 3: std::cout << "Option 3"; return clearAndReturn();
		case 4: std::cout << "Option 4"; return clearAndReturn();
		case 5: std::cout << "Option 5"; return clearAndReturn();
		case 6: std::cout << "Option 6"; return clearAndReturn();

		case 7: {
			std::cout << "Option 7";
			whriteToCosole();
			return clearAndReturn();
		}

		case 8: {
			std::cout << "Option 8";
			help();
			return clearAndReturn();
		}

		case 9: {
			std::cout << "Option 9";
			About();
			return clearAndReturn();
		}

		case 10: [[fallthrough]];

		//...
		default: std::cout << "Option not found"; return clearAndReturn();
	}
}

int main() {
	setUTF8();
	headerShow();
	funcMenu();
	std::cin.get();
	return 0;
}
