#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector <string> cut(string str)
{
    istringstream iss(str); //Convert string to stream
    vector <string> res;
    string w;
    while (iss >> w) res.push_back(w);
    return res;
}

int main()
{
    string str;
    getline(cin, str);
    vector <string> val = cut(str);
    for (size_t idx = 0; idx < val.size(); idx++)
    {
        if ((idx + 1) % 2 == 0) reverse(val[idx].begin(), val[idx].end());
        cout << val[idx] << ' ';
    }
    return 0;
}
