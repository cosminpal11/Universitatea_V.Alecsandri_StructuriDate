#include <iostream>

using namespace std;

int main()
{
    int n, v[100],cerinta,x=0;
    cout<<"Numarul de elemente din vector: "; cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Elementul de pe pozitia "<<i<<": ";
        cin>>v[i];
    }
    while(x==0)
    {
        cout<<"Pentru inserare in vector introduceti un numar par. Pentru stergere introduceti un numar impar."<<endl;
        cin>>cerinta;
        if(cerinta%2==0)
        {
            cout<<"Ati ales inserare!"<<endl;
            int c,ins;
            cout<<"Adauga un numar pe pozitia: "; cin>>c;
            cout<<"Adauga numarul: "; cin>>ins;
            if(c<n)
            {
                n++;
                for(int i=n-1;i>=c;i--)
                    v[i]=v[i-1];
                v[c]=ins;
                for(int i=0;i<n;i++)
                    cout<<v[i]<<" ";
            }
            else if(c==n)
            {
                v[n]=ins;
                n++;
                for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
            }
            else
            {
                for(int i=n;i<c;i++)
                    v[i]=0;
                v[c]=ins;
                n=c+1;
                for(int i=0;i<n;i++)
                    cout<<v[i]<<" ";
            }
        }
        else
        {
            cout<<"Ati ales stergere!"<<endl;
            int delpoz;
            cout<<"Alegeti pozitia pe care vreti sa o eliminati: "; cin>>delpoz;
            for(int i=delpoz;i<n;i++)
                v[i]=v[i+1];
            n--;
            for(int i=0;i<n;i++)
                cout<<v[i]<<" ";
        }
        cout<<endl<<"Doriti sa continuati? Daca da, introduceti 0, altfel 1"<<endl;
        cin>>x;
    }
}
