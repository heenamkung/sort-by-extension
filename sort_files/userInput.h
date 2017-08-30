#pragma once
using namespace std;

#include <iostream>
#include <Windows.h>
#include <string>
#include <direct.h>


/**
*Asks user the path (where mp3 files are stored) and how to sort the mp3 files.
*/

inline string get_directory() {
	cout << "Enter directory where files are stored: (e.g: C://Users/Bob/Documents) " << endl;
	static string dir; // Get directory where mp3 files are stored
	cin >> dir;
	//mp3_dir = "C://Users/Hee/Documents/hey";

	_chdir(dir.c_str()); //change current dir to mp3_dir
	return dir;
}
