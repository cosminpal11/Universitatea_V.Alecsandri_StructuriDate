#include <iostream>

using namespace std;

int a[20][20],sol[20],viz[20];
int n,m, i,j,e1,e2,x,k;

void afisare()
{
    unsigned int x;
    for (x=1;x<=n;x++)
        cout<<sol[x]<<endl;
}

void back(unsigned int nodCurent)
{
    unsigned int x;
    if (k==n)
        afisare();
        else for(x=1;x<=n;x++)
            if ((!viz[x])&&(a[x][sol[nodCurent]]))
            {
                viz[x]=1;
                k++;
                sol[k]=x;
                back(k);
            }
}
int main()
{
    cout<<"Numarul de noduri: ";
    cin>>n;
    cout<<"Numarul de muchii: ";
    cin>>m;
    cout<<"Dati graful prin muchii e1 si e2: ";
    for (i=1;i<=n;i++)
    {
        cout<<"muchia:"<<i<<endl;
        cout<<"e1=";
        cin>>e1;
        cout<<"e2=";
        cin>>e2;
        a[e1][e2]=a[e2][e1]=1;
    }
    for (i=1;i<=n;i++)
        viz[i]=0;
    cout<<"Nodul de plecare:";
    cin>>x;
    sol[1]=x;
    viz[x]=1;
    k=1;
    back(1);
    return 0;
}
