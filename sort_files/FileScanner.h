#pragma once


#include <iostream>
#include <Windows.h>
#include <string>
#include <direct.h>
#include <fstream>
#include <algorithm>
#include <tchar.h> 
#include <functional> 
#include <cctype>
#include <locale>
#include "userInput.h"
#include "sortFile.h"

class FileScanner {

public:
	FileScanner();
	bool scanFirstFile();
	void scanNextFile();
	bool nextFileExists();

private:
	std::string currentDirectory;
	WIN32_FIND_DATA findFileData;
	HANDLE hFind; // file handlers
	std::wstring allFiles; 

};