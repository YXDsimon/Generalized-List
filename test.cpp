#include <iostream>
#include <queue>
#define ELEM char
using namespace std;
void foo(int a)
{
    cout << a << endl;
}
int main()
{
    int a = 5;
    int *i = &a;
    foo(*i); 
    return 0;
}