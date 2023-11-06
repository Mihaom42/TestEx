// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// Функция для шифрования текста
string EncryptText(const string& Key, const string& Text)
{
    vector<string> NewText = RearrangeGroups(AddNumberToGroups(SeparateText(Text), Key), Key);

    return ClearText(NewText);
}

vector<string> SeparateText(const string& Text)
{
    vector<string> Groups;
    string Group;

    bool Flag = false;

    for (int i = 0; i < Text.length(); i+=3)
    {
        Flag = false;
        for (int j = i; ; j+=2)
        {
            Group = ' ';

            Group = Text[j];

            if (j + 1 < Text.length() && Flag == false)
            {
                Group += Text[j + 1];
                Flag = true;
            }
            else
            {
                break;
            }

            Groups.push_back(Group);
        }

        Groups.push_back(Group);
    }

    return Groups;
}

vector<string> AddNumberToGroups(vector<string> Groups, string Key)
{
    int Counter = 0;
    for (int i = 0; i < Groups.size(); i++) {
        Groups[i] = Key[Counter] + Groups[i];
        Counter = (Counter + 1) % Key.length();
    }

    return Groups;
}

bool CompareStrings(const string& A, const string& B)
{
    int aNum = std::stoi(A.substr(0, 1));
    int bNum = std::stoi(B.substr(0, 1));

    return aNum < bNum;
}

vector<string> RearrangeGroups(vector<string> Groups, string Key)
{
    sort(Groups.begin(), Groups.end(), CompareStrings);

    return Groups;
}

string ClearText(vector<string> Groups)
{
    string FinalString;

    for (int i = 0; i < Groups.size(); i++)
    {
        Groups[i].erase(Groups[i].begin());

        FinalString += Groups[i];
    }

    return FinalString;
}

bool IsKeyValid(const string& Key)
{
    regex R("^[0-9]*$");

    if (Key.length() > 9)
    {
        cout << "The key length must be less or equal 9!\n";
        return false;
    }

    if (!regex_match(Key, R))
    {
        cout << "Key must contain only numbers! Please, try one more time.\n";
        return false;
    }
    
    return true;
}

bool IsTextValid(const string& Text)
{
    regex R("^[A-Za-z]+$");
    
    if (Text.length() > 250)
    {
        cout << "The Text length must be less or equal 250!\n";
        return false;
    }

    if (!regex_match(Text, R))
    {
        cout << "Text must contain only letters! Please, try one more time.\n";
        return false;
    }

    return true;
}