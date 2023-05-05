#include <iostream>
#include <string>

using namespace std;

struct melodii
{
    string titlu;
    string artist;
    string album;
    string gen;
    int an_lansare;
    float pret;
};

void afisare_lista(melodii lista[],int nr)
{
    for(int i=0;i<nr;i++)
    {
        cout<<"Melodia #"<<i+1<<":"<<endl;
        cout<<"Titlu: "<<lista[i].titlu<<endl;
        cout<<"Artist: "<<lista[i].artist<<endl;
        cout<<"Album: "<<lista[i].album<<endl;
        cout<<"Gen: "<<lista[i].gen<<endl;
        cout<<"Pret: "<<lista[i].pret<<endl;
        cout<<endl;
    }
}

void afisare_an(melodii lista[], int nr, int an)
{
    cout<<"Piese muzicale lansate in anul "<<an<<":"<<endl<<endl;
    int x=0;
    for(int i=0;i<nr;i++)
        if (lista[i].an_lansare==an)
        {
            x=1;
            cout<<"Titlu: "<<lista[i].titlu<<endl;
            cout<<"Artist: "<<lista[i].artist<<endl;
            cout<<"Album: "<<lista[i].album<<endl;
            cout<<"Gen: "<<lista[i].gen<<endl;
            cout<<"Pret: "<<lista[i].pret<<endl;
            cout<<endl;
        }
    if (x==0)
        cout<<"Nu exista piese muzicale lansate in anul "<<an<<endl;
}

void sortare(melodii lista[], int n, int x)
{
    for(int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
        {
            if ((x==1)&&(lista[i].pret>lista[j].pret))
                swap(lista[i], lista[j]);
            else if((x==2)&&(lista[i].pret<lista[j].pret))
                swap(lista[i], lista[j]);
        }
}

void eliminare(melodii lista[], int& nr, string el_titlu)
{
    int index=-1;
    for (int i=0;i<nr;i++)
        if (lista[i].titlu==el_titlu)
        {
            index = i;
            break;
        }
    if (index==-1)
    {
        cout<<"Melodia nu a fost gasita in lista."<<endl;
        return;
    }
    for(int i=index;i<nr-1;i++)
        lista[i]=lista[i+1];
    nr--;
    cout << "Melodia a fost stearsa cu succes." << endl;
}

int main()
{
    system("COLOR 4F");
    int an,x;
    int nr,ex;
    cout<<"Introduceti numarul de melodii: ";
    cin>>nr;
    cin.get();
    melodii lista[nr];
    for(int i=0;i<nr;i++)
    {
        cout << "Introduceti informatii despre melodia #" << i + 1 << endl;
        cout << "Titlu: ";
        getline(cin, lista[i].titlu);
        cout << "Artist: ";
        getline(cin, lista[i].artist);
        cout<<"Album: ";
        getline(cin, lista[i].album);
        cout<<"Gen: ";
        getline(cin, lista[i].gen);
        cout<<"Anul lansarii: ";
        cin>>lista[i].an_lansare;
        cout<<"Pret: ";
        cin>>lista[i].pret;
        cin.get();
        cout<<endl;
    }
    int z=0;
    while(z==0)
    {
        cout<<"1) Afisare lista"<<endl;
        cout<<"2) Afisare melodii lansate intr-un anumit an"<<endl;
        cout<<"3) Sortare melodii"<<endl;
        cout<<"4) Eliminare melodie"<<endl;
        cout<<"9) Exit"<<endl;
        cin>>ex;
        if(ex==1)
        {
            afisare_lista(lista,nr);
            cout<<endl;
        }
        if(ex==2)
        {
            cout<<"Introduceti anul: ";
            cin>>an;
            afisare_an(lista, nr, an);
            cout<<endl;
        }
        else if(ex==3)
        {
            int lol=0;
            while(lol==0)
            {
                cout<<"   3.1) Ordine crescatoare"<<endl;
                cout<<"   3.2) Ordine descrescatoare"<<endl;
                cout<<"   ";
                cin>>x;
                if((x==1)||(x==2))
                    lol=1;
            }
            sortare(lista, nr, x);
            cout<<"Melodiile au fost sortate!"<<endl;
        }
        else if(ex==4)
        {
            cin.get();
            string el_titlu;
            cout<<"Introduceti titlul pe care vreti sa-l eliminati:"<<endl;
            getline(cin, el_titlu);
            eliminare(lista, nr, el_titlu);
        }
        else if(ex==9)
            z=1;
    }
    return 0;
}
