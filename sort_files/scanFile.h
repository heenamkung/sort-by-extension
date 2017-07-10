#pragma once
using namespace std;

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
#include "sortFile.h"


bool scanFirstFile(HANDLE& hFind, WIN32_FIND_DATAW FindFileData, wstring all_mp3, wstring mp3_folder) {
	hFind = FindFirstFile(all_mp3.c_str(), &FindFileData);
	GetLastErrorAsString();
	if (hFind != INVALID_HANDLE_VALUE) {
		_tprintf(TEXT("The first file found is %s\n"),
		FindFileData.cFileName); // prints cFileName string

		//HERE. need name of file
	
		sort_file( FindFileData, mp3_folder);
	}
	else {
		cout << "Mp3 file not found" << endl;
		return 0;
	}
}

void scanNextFile(HANDLE& hFind, WIN32_FIND_DATAW FindFileData, wstring mp3_folder) {
	if (hFind != INVALID_HANDLE_VALUE) {
		_tprintf(TEXT("The second file found is %s\n"),
			FindFileData.cFileName); // prints cFileName string
		//strcpy(artist, return_tag(FindFileData.cFileName, 1));
		sort_file( FindFileData, mp3_folder);
	}
}