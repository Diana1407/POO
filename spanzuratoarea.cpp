///Am realizat o clasa numita Spanzuratoare care are doi constructori cel implicit si cel in car initializam datele pt startul jocului
///Jocul se initializeaza folosind un un auxiliar in care puenm literele de inceput si sfarsit precum si altele in cazul
///in care acestea se repata iar in rest punem liniuta _
///Dupa care jucatorul trebuie sa citeasca o litera iar apoi se verifica daca litera apare in cuvant daca da o pune si trece mai departe
///daca nu iti zice cate incercari mai ai si iti arata desenul
///Clasa prezinta pe langa constructori metoda pt lungime, initializare, joc si afisare
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

ifstream f("cuvant.in");

class Spanzuratoare
{
private:
    char c[256],vec[256];
public:
    Spanzuratoare() {};
    Spanzuratoare(char x[], char z[])
    {
        strcpy(c,x);
        strcpy(vec,z);
    }

    int lungime()
    {
        return strlen(c);
    }

    void initializare()
    {
        int l=lungime();
        vec[0]=c[0];
        vec[l-1]=c[l-1];
        for(int i=0; i<l; i++)
        {
            if(c[i]==vec[0])
                vec[i]=c[i];
            if(c[i]==vec[l-1])
                vec[i]=c[i];
        }
        for(int i=0; i<strlen(c); i++)
            cout<<vec[i];
        cout<<endl;
        cout<<"Sa inceapa jocul \n";
    }

    void afis_desen(int nr)
    {
        if(nr==7)
        {
            cout<<"__________\n";
            cout<<"|        |\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"_\n";
        }
        if(nr==6)
        {
            cout<<"__________\n";
            cout<<"|        |\n";
            cout<<"|        0\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"_\n";
        }
        if(nr==5)
        {
            cout<<"__________\n";
            cout<<"|        |\n";
            cout<<"|        0\n";
            cout<<"|        |\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"_\n";
        }
        if(nr==4)
        {
            cout<<"__________\n";
            cout<<"|        |\n";
            cout<<"|        0\n";
            cout<<"|        |\n";
            cout<<"|       ( \n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"_\n";
        }
        if(nr==3)
        {
            cout<<"__________\n";
            cout<<"|        |\n";
            cout<<"|        0\n";
            cout<<"|        |\n";
            cout<<"|       ( ) \n";
            cout<<"|\n";
            cout<<"|\n";
            cout<<"_\n";
        }
        if(nr==2)
        {
            cout<<"__________\n";
            cout<<"|        |\n";
            cout<<"|        0\n";
            cout<<"|        |\n";
            cout<<"|       ( ) \n";
            cout<<"|        |\n";
            cout<<"|\n";
            cout<<"_\n";
        }
        if(nr==1)
        {
            cout<<"__________\n";
            cout<<"|        |\n";
            cout<<"|        0\n";
            cout<<"|        |\n";
            cout<<"|       ( ) \n";
            cout<<"|        |\n";
            cout<<"|       ( \n";
            cout<<"_\n";
        }
        if(nr==0)
        {
            cout<<"__________\n";
            cout<<"|        |\n";
            cout<<"|        0\n";
            cout<<"|        |\n";
            cout<<"|       ( ) \n";
            cout<<"|        |\n";
            cout<<"|       ( ) \n";
            cout<<"_\n";
        }
    }
    void joc()
    {
        int l=lungime();
        int incercari=7;
        char lit;
        const char ch = '_';
        afis_desen(incercari);
        while(incercari>=0)
        {
            if(incercari==0)
            {
                cout<<"Ai pierdut :( \n";
                break;
            }
            cout<<"Alege o litera: ";
            cin>>lit;

            int ok=0;
            for(int i=0; i<l; i++)
                if(lit==c[i] && (lit!=c[0] || lit!=c[l-1]))
                {
                    vec[i]=lit;
                    ok=1;
                }
            if(ok==0)
            {
                incercari--;
                //cout<<"Mai ai: "<<incercari<<" incercari. \n";
                afis_desen(incercari);
                cout<<endl;

            }
            for(int i=0; i<l; i++)
                cout<<vec[i];
            cout<<endl;
            if(strchr(vec,ch)==0)
            {
                cout<<"Felicitari ai castigat!! :) \n";
                break;
            }
            cout<<"\n\n";


        }


    }

};

int main()
{
    char s[256],v[256];
    int jocuri=1,nr;
    ///citim din fisier pt ca jucatorul sa nu il vada
    cout<<" Se citeste cuvantul din fisier \n";
    while(jocuri==1)
    {
        f.getline(s,256);

        for(int i=0; i<strlen(s); i++)
            v[i]='_';
        Spanzuratoare cuv(s,v);
        cuv.initializare();
        cuv.joc();
        cout<<"Mai vrei sa joci? Daca da apasa tasta 1 daca nu 0. \n";
        cin>>nr;
        if(nr==1)
            jocuri=1;
        else
            jocuri=0;
    }


    return 0;
}
