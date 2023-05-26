#include <iostream>

using namespace std;

int main()
{
    int n,o=0,c;
    cin>>n;
    c=n;
    while(n!=0)
    {
        o=o*10+n%10;
        n/=10;
    }
    if(o==c)
       cout<<"este palindrom"<<endl;
    else cout<<"nu este palindrom"<<endl;
}
