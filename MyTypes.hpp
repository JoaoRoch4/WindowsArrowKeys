#pragma once

#define NOMINMAX

#include <iostream>
#include <string>

#include <Windows.h>
#include <vector>

#define out  std::cout
#define wout std::wcout
#define in   std::cin
#define win  std::wcin
#define setUTF8()                                                                                  \
    setlocale(LC_ALL, "");                                                                         \
    SetConsoleOutputCP(CP_UTF8)

typedef std::string               str;
typedef std::wstring              wstr;
typedef std::vector<int>          vec;
typedef std::vector<std::string>  vecStr;
typedef std::vector<std::wstring> vecWstr;

void headerShow() noexcept;
void headerShow(const bool &show) noexcept;

   