#pragma once


#include "FileScanner.h"

using namespace std;



int main() {

	FileScanner fileScanner;
	if (!fileScanner.scanFirstFile()) {
		cout << "File not found" << endl;
	}

	while (fileScanner.nextFileExists()) {
		fileScanner.scanNextFile();
	}

	cout << "Sorting Finished" << endl;
		

	system("pause");
}