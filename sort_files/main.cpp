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
#include "stringHandling.h"
#include "scanFile.h"

using namespace std;



int main() {
	string mp3_folder;
	mp3_folder = get_directory();

	//file handlers 
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	wstring all_mp3 = conv(mp3_folder) + L"/*"; // adds "/*.mp3" to the end of path. Used to search all mp3 files in dir.  e.g C:\\Users\\Hee\\Documents\\*.mp3
	

	if (scanFirstFile(hFind, FindFileData, all_mp3, conv(mp3_folder))==0) {
		cout << "mp3 file not found" << endl;
		return 0;
	}

	while (FindNextFile(hFind, &FindFileData)) {
		scanNextFile(hFind, FindFileData, conv(mp3_folder));
	}
	cout << "Sorting finished" << endl;

	
		

	system("pause");
}