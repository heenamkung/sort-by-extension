#pragma once
using namespace std;

#include <iostream>
#include <Windows.h>
#include <string>
#include "stringHandling.h"

/**
*Creates an empty folder and names it "sort_by". Then moves the mp3 file to the folder.
*/

inline void sort_file( WIN32_FIND_DATA FindFileData, wstring folder) {
	
	_mkdir(convWS(fileExtension(FindFileData.cFileName)).c_str()); //create folder named sort_by
	wstring loc = conv("C:\\Users\\Hee\\Documents\\temp\\");
	loc = folder + L"/";
	wstring src = loc + FindFileData.cFileName;
	wstring dst = loc + fileExtension(FindFileData.cFileName) + L"\\" + FindFileData.cFileName;


	if (MoveFile(src.c_str(), dst.c_str()) == 0) {
		cout << GetLastErrorAsString() << endl;
		cout << "error moving files" << endl;
	}

}