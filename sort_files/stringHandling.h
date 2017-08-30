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

//https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring?page=1&tab=votes#tab-top trim string function
inline string &rtrim(string &s) { //function to trim string
	s.erase(find_if(s.rbegin(), s.rend(),
		not1(std::ptr_fun<int, int>(isspace))).base(), s.end());
	return s;
}





inline string GetLastErrorAsString() //https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror answer by jamin grey
{
	//Get the error message, if any.
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0)
		return string(); //No error message has been recorded

	LPSTR messageBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	string message(messageBuffer, size);

	//Free the buffer.
	LocalFree(messageBuffer);

	return message;
}


inline wstring conv(string str) {
	wstring str2(str.length(), L' '); // Make room for characters
									  // Copy string to wstring.
	copy(str.begin(), str.end(), str2.begin());
	return str2;
}

inline wstring fileExtension(wstring fileName){
	return fileName.substr(fileName.find_last_of(L".") + 1); 
}

inline string convWS(const wstring& s)
{
	string temp(s.length(), ' ');
	copy(s.begin(), s.end(), temp.begin());
	return temp;
}

