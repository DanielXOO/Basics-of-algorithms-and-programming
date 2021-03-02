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

 vector<string>::iterator shortest(vector <string>& val)
{
    size_t minim = val[0].length();
    vector<string>::iterator itr_min;
    for (auto itr = val.begin(); itr != val.end(); advance(itr,1))
    {
        string tmp = *itr;
        if (minim > tmp.length())
        {
            itr_min = itr;
            minim = tmp.length();
        }
    }
    return itr_min;
}

bool check(vector<string>& res, string& fnd)
{
    bool chk = false;
    for (string tmp : res)
    {
        if (tmp == fnd) chk = true;
    }
    return chk;
}

int main()
{
    string str_a;
    getline(cin, str_a);
    vector <string> val_a = cut(str_a);
    string str_b;
    getline(cin, str_b);
    vector <string> val_b = cut(str_b);
    while (true)
    {
        auto itr = shortest(val_a);
        str_a = *itr;
        if (!check(val_b, str_a))break;
        val_a.erase(itr);
    }
    cout << str_a;
    return 0;
}