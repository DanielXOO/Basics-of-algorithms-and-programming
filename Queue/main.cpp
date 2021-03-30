
#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue test;
    test.push(100);
    test.push(101);
    test.push(102);
    test.push(103);
    test.front();
    std::cout << test.front();
    test.pop();
    std::cout << test.front();

    return 0;
}