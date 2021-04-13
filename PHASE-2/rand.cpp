#include <iostream>

using namespace std;


class A
{
    public:
    int a;
    int c;
    
};
int main()
{
    int a=5;
    int b=a*5;
    if(a<24)
    {
        b=(3+5) + (3+5);
        if(b>10)
        {
            b=5;
        }
        else
        {
            b=8;
        }
    }
    else
    {
        b=(4+8) + (4+8);
    }
}