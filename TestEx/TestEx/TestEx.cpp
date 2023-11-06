#include "pch.h"


int main()
{
    string Key;
    string Text;

    cout << "Enter key-> ";
    getline(cin, Key);
    cout << '\n';

    if (!IsKeyValid(Key))
    {
        return 0;
    }

    cout << "Enter text-> ";
    getline(cin, Text);
    cout << '\n';

    if (!IsTextValid(Text))
    {
        return 0;
    }

    cout << "Cyphered text-> " << EncryptText(Key, Text) << '\n';
    
    return 0;
}
