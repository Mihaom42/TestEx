// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here

#endif //PCH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

string EncryptText(const string& Key, const string& Text);
//void SetKeyProperties(const string& Text, int* Key, int* KeyLength);
vector<string> SeparateText(const string& Text);
vector<string> AddNumberToGroups(vector<string> Groups, string Key);
vector<string> RearrangeGroups(vector<string> Groups, string Key);
string ClearText(vector<string> Groups);
bool CompareStrings(const string& A, const string& B);
bool IsKeyValid(const string& Key);
bool IsTextValid(const string& Text);