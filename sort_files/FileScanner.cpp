#include "FileScanner.h"

using namespace std;

FileScanner::FileScanner() {
	currentDirectory = get_directory();
	allFiles = conv(currentDirectory) + L"/*"; // used to select all file in current directory directory eg. C:/users/.* 
}

bool FileScanner::scanFirstFile() {
	hFind = FindFirstFile(allFiles.c_str(), &findFileData);
	GetLastErrorAsString();
	if (hFind != INVALID_HANDLE_VALUE) {
		_tprintf(TEXT("The first file found is %s\n"),
			findFileData.cFileName); // prints cFileName string

									 //HERE. need name of file

		sort_file(findFileData, conv(currentDirectory));
	}
	else {
		cout << "file not found" << endl;
		return 0;
	}
}

void FileScanner::scanNextFile() {
	if (hFind != INVALID_HANDLE_VALUE) {
		_tprintf(TEXT("The second file found is %s\n"),
			findFileData.cFileName); // prints cFileName string
									 //strcpy(artist, return_tag(FindFileData.cFileName, 1));
		sort_file(findFileData, conv(currentDirectory));
	}
}

bool FileScanner::nextFileExists() {
	return FindNextFile(hFind, &findFileData);
}