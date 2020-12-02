#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


vector<string> cut(string& str)
{
    istringstream iss(str);
    vector <string> res;
    string w;
    while (iss >> w) res.push_back(w);
    return res;
}

vector<string>::iterator longest(vector <string>& val)
{
    size_t longst = val[0].length();
    vector<string>::iterator itr_max;
    for (auto itr = val.begin(); itr != val.end(); advance(itr, 1))
    {
        string tmp = *itr;
        if (longst < tmp.length())
        {
            itr_max = itr;
            longst = tmp.length();
        }
    }
    return itr_max;
}

bool palindrome(string& word)
{
    int len = word.length();
    for (int i = 0; i < len / 2; ++i)
    {
        if (word[i] != word[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str_a;
    getline(cin, str_a);
    vector <string> val_a = cut(str_a);
    vector<string>::iterator itr;
    while (true)
    {
        itr = longest(val_a);
        str_a = *itr;
        if (palindrome(str_a)) break;
        val_a.erase(itr);
    }
    cout << str_a;
    return 0;
}