#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>

using namespace std;

class Zbor
{
private:
    char plecare[256],destinatie[256];
    int zi,luna,an,ora,durata,pret;
public:
    Zbor()
    {
        for(int i=0;i<strlen(plecare);i++)
            plecare[i]=NULL;
        for(int i=0;i<strlen(destinatie);i++)
            destinatie[i]=NULL;
        zi=luna=an=ora=durata=pret=0;
    }
    ~Zbor(){}
    Zbor(const Zbor& ob)
    {
        strcpy(plecare, ob.plecare);///plecare si destinatie sunt siruri de caractere
        strcpy(destinatie, ob.destinatie);///pt a le copia, folosim functia strcpy
        zi=ob.zi;
        luna=ob.luna;
        an=ob.an;
        ora=ob.ora;
        durata=ob.durata;
        pret=ob.pret;
    }
    Zbor operator = (const Zbor& ob)
    {
        strcpy(plecare, ob.plecare);
        strcpy(destinatie, ob.destinatie);
        zi=ob.zi;
        luna=ob.luna;
        an=ob.an;
        ora=ob.ora;
        durata=ob.durata;
        pret=ob.pret;
        return *this;
    }
    int get_zi()   ///facute ca sa pot folosi valorile variabilelor zi, an, luna in main
    {              ///ptc sunt private
        return zi;
    }
    int get_luna()
    {
        return luna;
    }
    int get_an()
    {
        return an;
    }
    int get_pret()
    {
        return pret;
    }
    char* get_plecare() ///char ptc returnez string, * ptc e vector
    {
        return plecare;
    }
    char* get_dest()
    {
        return destinatie;
    }
    friend istream& operator >>(istream &in, Zbor &ob);
    friend ostream& operator <<(ostream &out, Zbor &ob);
};

istream& operator >>(istream &in, Zbor &ob)
{
        in.getline(ob.plecare,sizeof(ob.plecare)); ///cin.getline(string,dimens_string);
        in.getline(ob.destinatie,sizeof(ob.destinatie));
        in>>ob.zi>>ob.luna>>ob.an;
        in>>ob.ora;
        in>>ob.durata;               ///ii atribui lui >> proprietatea de a citi toate variabilele clasei
        in>>ob.pret;
        in.get();
        return in;
}

ostream& operator <<(ostream &out, Zbor &ob)
{
        out<<"\nPlecare din: ";
        for(int i=0;i<strlen(ob.plecare);i++)
            out<<ob.plecare[i];
        out<<"\n";
        out<<"Sosire la: ";
        for(int i=0;i<strlen(ob.destinatie);i++)
            out<<ob.destinatie[i];
        out<<"\nZbor la data: ";
        out<<ob.zi<<"."<<ob.luna<<"."<<ob.an;
        out<<"\nLa ora: "<<ob.ora;
        out<<"\nDurata zbor: ";
        out<<ob.durata<<" minute";
        out<<"\nPret bilet: ";
        out<<ob.pret<<" lei\n";
        return out;
}

class CompanieAeriana: public Zbor
{
private:
    char denumire_companie[256];
    char denumire_alianta[256];
    Zbor zboruri;
public:
    CompanieAeriana ()    ///constructor de initialiare
    {
        for(int i=0;i<strlen(denumire_companie);i++)
            denumire_companie[i]=NULL;
        for(int i=0;i<strlen(denumire_alianta);i++)
            denumire_alianta[i]=NULL;
    }
    ~CompanieAeriana(){}
    CompanieAeriana (const CompanieAeriana &ob)      ///constructor de copiere
    {
        strcpy(denumire_companie, ob.denumire_companie);
        strcpy(denumire_alianta, ob.denumire_alianta);
        zboruri=ob.zboruri; ///zboruri apeleaza constructorul din clasa Zbor
    }
    CompanieAeriana operator = (const CompanieAeriana &ob)
    {
        strcpy(denumire_companie, ob.denumire_companie);
        strcpy(denumire_alianta, ob.denumire_alianta);
        zboruri=ob.zboruri;
        return *this;
    }
    int get_zi_zbor()
    {
        return zboruri.get_zi();
    }
    int get_luna_zbor()
    {
        return zboruri.get_luna();
    }
    int get_an_zbor()
    {
        return zboruri.get_an();
    }
    int get_pret_zbor()
    {
        return zboruri.get_pret();
    }
    char* get_plecare_zbor()
    {
        return zboruri.get_plecare();
    }
    char* get_dest_zbor()
    {
        return zboruri.get_dest();
    }
    friend istream& operator >> (istream& in, CompanieAeriana& ob);
    friend ostream& operator << (ostream& out, CompanieAeriana& ob);
};

istream& operator >> (istream& in, CompanieAeriana& ob)
{

//        cout<<"Nume companie: ";
//        in.getline(ob.denumire_companie,sizeof(ob.denumire_companie));
//        cout<<"\nNume alianta: ";
//        in.getline(ob.denumire_alianta,sizeof(ob.denumire_alianta));
        in>>ob.zboruri; ///variabila zboruri care e de tip Zbor(clasa) isi apeleaza singura operatorul >>
                        ///care este supraincarcat anterior
        return in;  ///
}

ostream& operator << (ostream& out, CompanieAeriana& ob)
{
        out<<ob.zboruri; ///variabila zboruri care e de tip Zbor(clasa) isi apeleaza singura operatorul <<
                        ///care este supraincarcat anterior
//        cout<<"\nNume companie: ";
//        out<<ob.denumire_companie;
//        cout<<"\nNume alianta: ";
//        out<<ob.denumire_alianta;
        return out;
}
int main()
{
    CompanieAeriana zboruri_1[11], zboruri_2[11]; /// vector de zbouri 1 pt airfrance si 2 pt blueair
    ifstream fin1("airfrance.in");
    ofstream fout1("airfrance.out");
    ifstream fin2("blueair.in");
    ofstream fout2("blueair.out");
    int n=0, m=0;
    for(int i=0;i<10;i++) ///10 zboruri
    {
        CompanieAeriana z;
        fin1>>z;
        zboruri_1[n++]=z;   ///z e un zbor si il bag in vectorul de zboruri
    }
    for(int i=0;i<10;i++)
    {
        CompanieAeriana z2;
        fin2>>z2;
        zboruri_2[m++]=z2;
    }


//    ce vrea cumparatorul de bilet:
    int zi,luna,an;
    char plecare[256],destinatie[256];
    cin>>zi>>luna>>an;
    cin.get();
    cin.getline(plecare,sizeof(plecare));
    cin.getline(destinatie,sizeof(destinatie));
    CompanieAeriana zboruri_valide[10];/// in asta intra zborurile potrivite cerintelor
    int k=0;
    for(int i=0;i<10;i++)
    {
        if(zboruri_1[i].get_an_zbor()==an && zboruri_1[i].get_luna_zbor()==luna && zboruri_1[i].get_zi_zbor()==zi)
            if(strcmp(plecare,zboruri_1[i].get_plecare_zbor())==0 && strcmp(destinatie,zboruri_1[i].get_dest_zbor())==0) ///0 ins sunt la fel
                zboruri_valide[k++]=zboruri_1[i];  /// bag in vectorul cu zboruri valide
        if(zboruri_2[i].get_an_zbor()==an && zboruri_2[i].get_luna_zbor()==luna && zboruri_2[i].get_zi_zbor()==zi)
            if(strcmp(plecare,zboruri_2[i].get_plecare_zbor())==0 && strcmp(destinatie,zboruri_2[i].get_dest_zbor())==0)
                zboruri_valide[k++]=zboruri_2[i];
    }
    for(int i=0;i<k;i++)
        for(int j=i+1;j<=k;j++)
            if(zboruri_valide[i].get_pret_zbor()>zboruri_valide[j].get_pret_zbor())
                swap(zboruri_valide[i],zboruri_valide[j]);
    cout<<"\n\n Iata biletul cautat:";
    cout<<zboruri_valide[1];
    for(int i=0;i<n;i++)
        fout1<<zboruri_1[i];
    for(int i=0;i<m;i++)
        fout2<<zboruri_2[i];
    return 0;
}
