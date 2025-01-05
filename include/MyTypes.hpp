#pragma once

#define NOMINMAX

#include <consoleapi2.h>

#include <iostream>
#include <string>
#include <vector>

//#define out	 std::cout
//#define wout std::wcout
//#define in	 std::cin
//#define win	 std::wcin
//#define setUTF8()          \
//	setlocale(LC_ALL, ""); \
//	SetConsoleOutputCP(65'001)

typedef std::string				  str;
typedef std::wstring			  wstr;
typedef std::vector<int>		  vec;
typedef std::vector<std::string>  vecStr;
typedef std::vector<std::wstring> vecWstr;

void							  headerShow() noexcept;
void							  headerShow(const bool& show) noexcept;