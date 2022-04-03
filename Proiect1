#include <iostream>
#include <cstring>
#include <list>
#include <iterator>

using namespace std;

///--------------------------------------------------CLASA CARD-------------------------------------------------------
class Card
{
private:
    long cod_card;
    float bani_pe_card;
    int nr_plati;
    float* val_plati;
    //marirea nr_tranzactiei+val_tranzactii
public:
    Card();
    Card(int cod_card, float bani_pe_card, int nr_plati, float* val_plati);
    Card(int cod_card);
    Card(const Card& c);

    Card& operator=(const Card& c);
    float operator [](int i);
    ~Card();
    friend istream& operator>>(istream& in, Card& c);
    friend ostream& operator<<(ostream& out, const Card& c);

    const Card& operator--();
    const Card operator--(int);
    const void operator - ( const Card& c)
    {
        this->bani_pe_card = this->bani_pe_card - c.bani_pe_card;
    }

    const void operator += (const Card& c)
    {
        this->bani_pe_card += c.bani_pe_card;
    }

    const void operator + (const Card& c)
    {
        this->nr_plati = this->nr_plati + c.nr_plati;
    }

    ///functionalitatea clasei : media aritmetica a atranzactiilor facute de pe card
    float media_platilor() const {
        float suma = 0;
        for (int i=0; i<nr_plati; i++)
            suma += val_plati[i];
        if(suma > bani_pe_card)
            return -1;
        return suma / nr_plati;
    }

    float total_plata()
    {
        float suma = 0;
        for (int i=0; i<nr_plati; i++)
            suma += val_plati[i];
    }

    ///Supraincarcarea operatorului ==
    bool operator == (const Card& c)
    {
        if(this->nr_plati == c.nr_plati && this->bani_pe_card == c.bani_pe_card && this->cod_card == c.cod_card && this->val_plati == c.val_plati)
            return true;
        return false;
    }

    ///Supraincarcarea operatorului >
    bool operator > (const Card& c)
    {
        if(this->bani_pe_card > c.bani_pe_card)
            return true;
        return false;
    }

    explicit operator int()
    {
        return (int)this->bani_pe_card;
    }

    long get_cod();
    void set_cod(long cod);

    int get_nr_plati();
    void set_nr_plati(int x);

    float get_bani();
    void set_bani(float x);

    float* get_val_plati();
    void set_val_palti(float *val_plati);

};

long Card::get_cod()
{
    return this->cod_card;
}

void Card::set_cod(long cod)
{
    this->cod_card = cod;
}

int Card:: get_nr_plati()  {
    return this->nr_plati;
}

void Card::set_nr_plati(int x)
{
    this->nr_plati = x;
}

float Card:: get_bani()
{
    return this->bani_pe_card;
}
void Card::set_bani(float x)
{
    this->bani_pe_card = x;
}

float* Card::get_val_plati()
{
    return this->val_plati;
}

void Card::set_val_palti(float* val_plati)
{
    int nr = this->get_nr_plati();
    if(this->val_plati != NULL)
        delete [] this->val_plati;
    this->val_plati = new float[nr];
    for(int i = 0; i < nr; i++)
        this->val_plati[i] = val_plati[i];
}

const Card& Card::operator--()
{
    this->bani_pe_card--;
    return *this;
}

const Card Card::operator--(int)
{
    Card aux(*this);
    this->bani_pe_card--;
    return aux;
}

///Constructor fara parametrii
Card::Card()
{
    this->cod_card = -1;
    this->bani_pe_card = 0;
    this->nr_plati = 0;
    this->val_plati = NULL;
}

///Constructor cu toti parametrii
Card::Card(int cod_card,float bani_pe_card, int nr_plati, float* val_plati)
{
    this->cod_card = cod_card;
    this->bani_pe_card = bani_pe_card;
    this->nr_plati = nr_plati;
    this->val_plati = new float[this->nr_plati];
    for(int i=0; i<this->nr_plati; i++)
        this->val_plati[i] = val_plati[i];
}

///Constructor cu mai putini parametrii - consideram ca nu s-au efectuat tranzactii
Card::Card(int cod_card)
{
    this->cod_card = cod_card;
}

///CopyConstructor
Card::Card(const Card& c)
{
    this->cod_card = c.cod_card;
    this->bani_pe_card = c.bani_pe_card;
    this->nr_plati = c.nr_plati;
    this->val_plati = new float[this->nr_plati];
    for(int i=0; i<this->nr_plati; i++)
        this->val_plati[i] = c.val_plati[i];
}

///Supraincarcarea operatorului =
Card& Card::operator = (const Card &c)
{
    if (this != &c)
    {
        if(this->val_plati != NULL)
            delete[] this->val_plati;
        this->cod_card = c.cod_card;
        this->bani_pe_card = c.bani_pe_card;
        this->nr_plati = c.nr_plati;
        this->val_plati = new float[this->nr_plati];
        for(int i=0; i<this->nr_plati; i++)
            this->val_plati[i] = c.val_plati[i];
    }
    return *this;
}

float Card :: operator [](int i)
{
    if(0 <= i && i<this->nr_plati)
        return this->val_plati[i];
    cout<<"Index introdus gresit";
}

///Destructor
Card::~Card()
{
    if(this->val_plati != NULL)
        delete[] this->val_plati;
}

///Citire: supraincarcarea operatorului >>
istream& operator>>(istream& in, Card& c)
{
    cout<<"Codul cardului este:";
    in>>c.cod_card;
    cout<<"Valoare de bani de pe card este de: ";
    in>>c.bani_pe_card;
    cout<<"Numarul de tranzactii facute este:";
    in>>c.nr_plati;
    if(c.val_plati != NULL)
        delete[] c.val_plati;
    c.val_plati = new float[c.nr_plati];
    cout<<"Valoarea fiecarei tranzactii este de:"<<endl;
    for(int i=0; i<c.nr_plati; i++)
        in>>c.val_plati[i];

    return in;
}

///Afisare: supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const Card& c)
{
    out<<"Codul cardului este: "<<c.cod_card<<endl;
    out<<"Valoare de bani de pe card este de: "<<c.bani_pe_card<<endl;
    out<<"Numarul de tranzactii facute este: "<<c.nr_plati<<endl;
    out<<"Valoarea fiecarei tranzactii este de:"<<endl;
    for(int i=0; i<c.nr_plati; i++)
        out<<c.val_plati[i]<<" ";
    out<<"\n";
    out<<"Vreti sa stiti suma medie cheltuita cu acest card? Daca da apasati tasta 1, altfel tasta 0 \n";
    int y;
    cin>>y;
    if(y==1)
    {
        float media = c.media_platilor();
        out<<media;
    }
    else
        return out;
}

///--------------------------------------------------CLASA CLIENT---------------------------------------------------------------
class Client
{
private:
    string nume;
    string prenume;
    int cifre_cnp;
    int* cnp;
    static int contor;
    const int IDClient;
    list<Card> lista_carduri;

public:
    Client();
    Client(string nume, string prenume, int cifre_cnp, int* cnp);
    Client(string nume, string prenume); //este un client care urmeaza sa fie inregistrat
    Client(const Client& c);
    Client & operator=(const Client& c);
    ~Client();

    friend istream& operator>>(istream& in, Client& c);
    friend ostream& operator<<(ostream& out, Client& c);
    Client operator + (const Card& c);

    int nr_carduri();

    int get_cifre_cnp();
    void set_cifre_cnp(int cifre_cnp);

    const int* get_cnp();
    void set_cnp(int* cnp, int cifre_cnp);

    string get_nume();
    void set_nume(string nume);

    string get_prenume();
    void set_prenume(string prenume);

    static int get_contor()
    {
        return contor;
    }

    const int get_id()
    {
        return IDClient;
    }

    int operator [](int i);
    bool operator > (Client c);

};

int Client::contor = 0; //numaram clientii de la 0

int Client::get_cifre_cnp()
{
    return this->cifre_cnp;
}
void Client::set_cifre_cnp(int cifre_cnp)
{
    this->cifre_cnp = cifre_cnp;
}

///Getter CNP
const int* Client::get_cnp()
{
    return this->cnp;
}

///Setter CNP
void Client ::set_cnp(int *cnp, int cifre_cnp)
{
    if(this->cnp != NULL)
        delete [] this->cnp;
    this->cifre_cnp = cifre_cnp;
    this->cnp = new int[this->cifre_cnp];
    for(int i = 0; i<this->cifre_cnp; i++)
        this->cnp[i] = cnp[i];
}

string Client ::get_nume()
{
    return this->nume;
}
void Client ::set_nume(string nume)
{
    this->nume = nume;
}

string Client ::get_prenume()
{
    return this->prenume;
}
void Client::set_prenume(string prenume)
{
    this->prenume = prenume;
}


int Client :: nr_carduri()
{
    int l = this->lista_carduri.size();
    return l;
}

bool Client::operator>(Client c)
{
    int nr1 = this->nr_carduri();
    int nr2 = c.nr_carduri();
    if(nr1>nr2)
        return true;
    return false;
}

int Client ::operator[](int i)
{
    if(0 <= i && i < this->cifre_cnp)
        return this->cnp[i];
    cout<<"Index introdus gresit";
}

///constructor fara parametrii
Client::Client():IDClient(contor++)
{
    this->nume = "Anonim";
    this->prenume = "Anonim";
    cifre_cnp = 0;
    this->cnp = NULL;
}

///Constructor cu toti parametrii
Client::Client(string nume, string prenume, int cifre_cnp, int* cnp):IDClient(contor++)
{
    this->nume = nume;
    this->prenume = prenume;
    this->cifre_cnp = cifre_cnp;
    this->cnp = new int[this->cifre_cnp];
    for(int i=0; i<this->cifre_cnp; i++)
        this->cnp[i] = cnp[i];
}

///Constructor fara toti parametrii
Client::Client(string nume, string prenume):IDClient(contor++)
{
    this->nume = nume;
    this->prenume = prenume;
}

///CopyConstructor
Client::Client(const Client& c):IDClient(contor++)
{
    this->nume = c.nume;
    this->prenume = c.prenume;
    this->cifre_cnp = c.cifre_cnp;
    this->cnp = new int[c.cifre_cnp];
    for(int i=0; i<c.cifre_cnp; i++)
        this->cnp[i] = c.cnp[i];
    this->lista_carduri = c.lista_carduri;
}

///Supraincarcarea operatorului =
Client& Client::operator=(const Client &c)
{
    if(this != &c)
    {
        this->nume = c.nume;
        this->prenume = c.prenume;
        this->cifre_cnp = c.cifre_cnp;
        if(this->cnp != NULL)
            delete[] this->cnp;
        this->cnp=new int[c.cifre_cnp];
        for(int i=0; i<c.cifre_cnp; i++)
            this->cnp[i] = c.cnp[i];
        this->lista_carduri = c.lista_carduri;
    }
    return *this;
}

///Supraincarcarea operatorului +
Client Client:: operator +(const Card& c)
{
    this->lista_carduri.push_back(c);
    return *this;
}

/*Client& operator +(const Card& card, Client& c)
{
    c.set_card(card);
}*/

///Citire - supraincarcarea operatorului >>
istream& operator>>(istream& in, Client& c)
{
    cout<<"Numele clientului este:";
    in>>c.nume;
    cout<<"Prenumele clientului este:";
    in>>c.prenume;
    cout<<"Numarul de cifre din cnp este de:";
    in>>c.cifre_cnp;
    cout<<"Cnp-ul este(cifrele trebuie date cu spatiu intre ele):";
    if(c.cnp!=NULL)
        delete [] c.cnp;
    c.cnp = new int[c.cifre_cnp];
    for(int i=0; i<c.cifre_cnp; i++)
        in>>c.cnp[i];
    cout<<"Ati introdus corect cnp-ul? Daca da apasati tasta 1, daca nu tasta 0.\n";
    int y;
    cin>>y;
    if(y==0)
    {
        cout<<"Reintroduceti cnp-ul(fiecare cifra cu spatiu intre ele): ";
        if(c.cnp!=NULL)
            delete [] c.cnp;
        c.cnp = new int[c.cifre_cnp];
        for(int i=0; i<c.cifre_cnp; i++)
            in>>c.cnp[i];
    }
    Card card;
    in>>card;
    c = c + card;
    while(true)
    {
        cout<<"Mai vreti sa ii adaugati un card clientului? \n"
              "0 - nu\n "
              "1 - da\n ";
        int x;
        in>>x;
        if(x == 1)
        {
            Card card;
            in>>card;
            c = c + card;

        }
        else
            break;
    }
    return in;

}

///Afisare - supraincarcarea operatorului <<
ostream& operator<<(ostream& out, Client& c)
{
    out<<"ID-ul Clientului este: "<<c.IDClient<<endl;
    out<<"Numele este: "<<c.nume<<endl;
    out<<"Prenumele este: "<<c.prenume<<endl;
    out<<"Numarul de cifre din cnp este: "<<c.cifre_cnp<<endl;
    out<<"Cnp-ul este: ";
    for(int i=0; i<c.cifre_cnp; i++)
        out<<c.cnp[i];
    out<<endl;
    out<<"-------------Card--------------\n";
    list<Card>::iterator it;
    for (it = c.lista_carduri.begin(); it!=c.lista_carduri.end(); it++)
    {
        out<<"---------------------------------------------------------------------------------------\n";
        out<<*it<<endl;
    }
    return out;
}

///Destructor
Client::~Client()
{
    if(this->cnp!=NULL)
        delete [] this->cnp;
}

///------------------------------------------------CLASA TRANZACTIE---------------------------------------------------------
class Tranzactie
{
private:
    int numar;
    string dep_ex;
    float valoare;
    bool reusita;
public:
    Tranzactie();
    Tranzactie(int numar, string dep_ex, float valoare, bool reusita);
    Tranzactie(const Tranzactie& t);

    Tranzactie & operator=(const Tranzactie& t);
    float operator +(const Tranzactie& t);
    const void operator * (int x);
    const Tranzactie& operator++();
    const Tranzactie& operator++(int);

    friend istream& operator>>(istream& in, Tranzactie& t);
    friend ostream& operator<<(ostream &out, const Tranzactie& t);


    explicit operator int()
    {
        return (int)this->reusita;
    }

    bool operator<(const Tranzactie& t)
    {
        if(this->valoare<t.valoare)
            return true;
        return false;
    }

    bool operator ==(const Tranzactie& t)
    {
        if(this->reusita == t.reusita && this->valoare == t.valoare)
            return true;
        return false;
    }

    int get_numar()
    {
        return this->numar;
    }
    void set_numar(int x)
    {
        this->numar = x;
    }

    float get_valoare()
    {
        return valoare;
    }
    void set_valoare(float x)
    {
        this->valoare = x;
    }

    int get_dep_ex()
    {
        if(dep_ex == "depunere")
            return 1;
        else if(dep_ex == "retragere")
            return 0;
        else
            return -1;
    }
    void set_dep_ex(string ce)
    {
        this->dep_ex = ce;
    }

    bool get_reusita()
    {
        return reusita;
    }
    void set_reusita(bool x)
    {
        this->reusita = x;
    }
};

const Tranzactie& Tranzactie ::operator++()
{
    this->valoare++;
    return *this;
}

const Tranzactie& Tranzactie::operator++(int)
{
    Tranzactie aux(*this);
    this->valoare++;
    return aux;
}

float Tranzactie:: operator +(const Tranzactie& t)
{
    float total =  this->valoare + t.valoare;
    return total;
}

const void Tranzactie::operator*(int x)
{
    float v = this->get_valoare();
    this->set_valoare(v*x);
}

///Cosntrcutor fara parametrii
Tranzactie::Tranzactie()
{
    numar = -1;
    dep_ex = "Necunoscut";
    valoare = 0;
    reusita = false;
}

///Constructor cu toti parametrii
Tranzactie::Tranzactie(int numar, string dep_ex, float valoare, bool reusita)
{
    this->numar = numar;
    this->dep_ex = dep_ex;
    this->valoare = valoare;
    this->reusita = reusita;
}

///CopyConstructor
Tranzactie::Tranzactie(const Tranzactie& t)
{
    this->numar = t.numar;
    this->dep_ex = t.dep_ex;
    this->valoare = t.valoare;
    this->reusita = t.reusita;
}

///Supraincarcarea operatorului =
Tranzactie& Tranzactie::operator=(const Tranzactie &t)
{
    if(this != &t)
    {
        this->numar = t.numar;
        this->dep_ex = t.dep_ex;
        this->valoare = t.valoare;
        this->reusita = t.reusita;
    }
    return *this;

}

///Citire - supraincarcarea operatorului >>
istream& operator>>(istream& in, Tranzactie& t)
{
    cout<<"Numarul tranzactiei este: ";
    in>>t.numar;
    cout<<"Este depunere sau retragere? ";
    in>>t.dep_ex;
    cout<<"Valoarea tranzactiei: ";
    in>>t.valoare;
    cout<<"A fost reusita? ";
    in>>t.reusita;

    return in;
}
///Afisare - supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const Tranzactie& t)
{
    out<<"Numarul tranzactiei este: "<<t.numar<<endl;
    out<<"Este depunere sau retragere: "<<t.dep_ex<<endl;
    out<<"Valoarea tranzactiei este de: "<<t.valoare<<endl;
    out<<"A fost reusita? "<<t.reusita;

    return out;
}
/*
///Supraincarcarea operatorului +
Tranzactie Tranzactie :: operator +(const Tranzactie& t)
{
    Tranzactie* aux = nullptr;
    if(this->lista_)
}
*/

///----------------------------------------------------CLASA BANCA-----------------------------------------------------------------
class Banca
{
private:

    char* nume;
    double bani_in_banca;
    list<Tranzactie> lista_tranzactii;
    list<Client> lista_clienti;
public:
    Banca();
    Banca(char* nume);
    Banca(char* nume, double bani_in_banca);
    Banca(const Banca& b);

    Banca & operator = (const Banca& b);
    Banca operator + (const Tranzactie& t);
    Banca operator + (const Client& b);
    Banca operator - (const Tranzactie&t);

    ~Banca();

    friend istream& operator>>(istream& in, Banca& b);
    friend ostream& operator<<(ostream& out, Banca& b);

    ///Supraincarcarea operatorului ==
    bool operator == (const Banca& b)
    {
        if(this->nume==b.nume && this->bani_in_banca==b.bani_in_banca)
            return true;
        return false;
    }
    ///Supraincarcarea operatorului >
    bool operator > (const Banca& b)
    {
        if(this->bani_in_banca>b.bani_in_banca)
            return true;
        return false;
    }
    Banca& operator ++();
    Banca operator ++(int);

    Banca operator --();
    Banca operator --(int);

    Banca operator +=(double x);
    Banca operator -=(double x);


    explicit operator int()
    {
        return (int)this->bani_in_banca;
    }
    /*float get_retragere_maxima()
    {
        return retragre_maxima;
    }*/
    char* get_nume()
    {
        return nume;
    }
    void set_nume(char* nume)
    {
        strcpy(this->nume, nume);
    }

    double get_bani_in_banca()
    {
        return bani_in_banca;
    }

    void set_bani_in_banca(double bani_in_banca)
    {
        this->bani_in_banca = bani_in_banca;
    }

    ///functionalitate pe banca: modificarea sumei din banca
    void bani_dupa_retragere(double suma)
    {
        bani_in_banca -= suma;
    }
    void bani_dupa_depunere(double suma)
    {
        bani_in_banca += suma;
    }

};

///Constructor fara parametrii
Banca::Banca()
{
    nume=new char[strlen("Anonim")+1];
    strcpy( this->nume,"Anonim");
    bani_in_banca = 0;
    lista_tranzactii = {};

}

///Constructor cu toti parametrii
Banca::Banca(char* nume, double bani_in_banca)
{
    this->nume=new char[strlen(nume)+1];
    strcpy( this->nume, nume);
    this->bani_in_banca = bani_in_banca;
}

///Constructor cu mai putini parametrii - consideram ca nu stim cti bani se afla in banca
Banca::Banca(char* nume)
{
    this->nume=new char[strlen(nume)+1];
    strcpy( this->nume, nume);
}

///CopyConstructor
Banca::Banca(const Banca& b)
{
    this->nume=new char[strlen(b.nume)+1];
    strcpy( this->nume, b.nume);
    this->bani_in_banca = b.bani_in_banca;
    this->lista_tranzactii = b.lista_tranzactii;
}

///Supraincarcarea operatorului =
Banca& Banca::operator=(const Banca& b)
{
    if(this != &b)
    {
        if(this->nume != NULL)
            delete[] this->nume;
        this->nume=new char[strlen(b.nume)+1];
        strcpy( this->nume, b.nume);
        this->bani_in_banca = b.bani_in_banca;
        this->lista_tranzactii = b.lista_tranzactii;
    }
    return *this;
}

///Destructor
Banca::~Banca()
{
    if(this->nume != NULL)
        delete[] this->nume;
}

///Supraincarcarea operatorului +
Banca Banca:: operator +(const Tranzactie& t)
{
    this->lista_tranzactii.push_back(t);
    return *this;
}


Banca Banca ::operator+(const Client& c)
{
    this->lista_clienti.push_back(c);
    return *this;
}

Banca Banca ::operator -(const Tranzactie& t)
{
    this->lista_tranzactii.pop_back();
    return *this;
}

Banca Banca ::operator +=(double x)
{
    this->bani_in_banca += x;
}

Banca Banca::operator -=(double x)
{
    this->bani_in_banca -= x;
}

/*void Banca::stergereTranzactie(const Tranzactie &t)
{
    Tranzactie *listaTranzactieAux;
    int nr = 0;
    int lungime = lista_tranzactii.size();
    listaTranzactieAux = new Tranzactie[lungime];
    for(int i = 0; i < lungime; i++)
    {
        if(lista_tranzactii[i] == t)
            nr++;
        listaTranzactieAux[i] = lista_tranzactii[i];
    }
    cout<<nr;
    if(lista_tranzactii != NULL)
        delete [] lista_tranzactii;
}*/

///Supraincarcarea operatorului ++
Banca& Banca::operator++()
{
    this->bani_in_banca++;
    return *this;
}

Banca Banca::operator++(int)
{
    Banca aux(*this);
    this->bani_in_banca++;
    return aux;
}

Banca Banca::operator--()
{
    this->bani_in_banca--;
    return * this;
}
Banca Banca::operator--(int)
{
    Banca aux(*this);
    this->bani_in_banca--;
    return aux;
}

///Citire: supraincarcarea operatorului >>
istream& operator>>(istream& in, Banca& b)
{
    cout<<"Numele bancii este:";
    char n[51];
    in>>n;
    if(b.nume!=NULL)
        delete[] b.nume;
    b.nume=new char[strlen(n)+1];
    strcpy(b.nume,n);
    in>>b.nume;
    cout<<"Suma de bani din banca este de:";
    in>>b.bani_in_banca;
    while(true)
    {
        while (true)
        {
            cout<<"Vreti sa cresteti sau sa micsorati valoarea banilor din banca?\n"
                  "Apasati 1 pentru crestere cu 1\n"
                  "        2 pentru micsorare cu 1\n"
                  "        3 pentru a creste cu o valoarea data\n"
                  "        4 pentru a micsora cu o valoare data\n"
                  "        5 pentru a merge mai departe fara a face modificari\n";
            int ok;
            cin>>ok;
            if(ok == 1)
                b++;
            else if(ok == 2)
                b--;
            else if(ok == 3)
            {
                int k;
                cout<<"Cititi cu cat vreti sa mariti valoarea banilor din banca.\n";
                cin>>k;
                b += k;
            }
            else if(ok == 4)
            {
                int k;
                cout<<"Cititi cu cat vreti sa micsorati valoarea banilor din banca.\n";
                cin>>k;
                double bani = b.get_bani_in_banca();
                if(k > bani)
                    cout<<"Operatia nu poate avea loc\n";
                else
                    b -= k;
            }
                break;
        }
        cout<<"Doriti sa facem o aproximare a banilor din banca? Daca da apassati 1, altfel apasati 0. \n";
        int ok;
        cin>>ok;
        if(ok == 1)
            cout<<b.operator int();
        else {}
        cout<<"\n";

        cout<<"-----------------------MENIUL BANCII------------------------\n"
              "1 - adaugare tranzactie \n"
              "2 - adaugare client \n"
              "3 - exit \n";
        int x;
        cin>>x;
        if(x==1)
        {
            Tranzactie t;
            cin>>t;
            cout<<"Daca este o tranzactie lunara puteti sa o faceti tranzactie pe un numar x luni,"
                  " apasand tasta 1, altfel apaasati 0\n";
            int y;
            in>>y;
            if(y == 1)
            {
                int luni;
                cout<<"Introduceti numarul de luni pe care vreti sa faceti tranzactia: ";
                cin>>luni;
                t * luni;
            }
            else{}

            //b.lista_tranzactii.push_back(t);
            b = b + t;
            int c = t.get_dep_ex();
            if (c == 1)
                if(t.get_reusita() == true)
                {
                    b.bani_dupa_depunere(t.get_valoare());
                    cout<<"Noua suma din banca este de: "<<b.bani_in_banca<<endl;
                }

            if(c == 0)
                if(t.get_reusita() == true)
                {
                    if(b.bani_in_banca > t.get_valoare())
                    {
                        b.bani_dupa_retragere(t.get_valoare());
                        cout<<"Noua suma din banca este de: "<<b.bani_in_banca<<endl;
                    }

                    else
                        cout<<"Nu exista suficienti bani in banca pentru a se realiza retragerea\n";
                }
                if (c == -1)
                    cout<<"Operatie invalida\n";
        }

        else if(x==2)
        {
            Client c;
            in>>c;
            b = b + c;
        }

        else
            break;
    }

    return in;
}

///Afisare: supraincarcarea operatorului <<
ostream& operator<<(ostream& out, Banca& b)
{
    out<<"Numele este: "<<b.nume<<endl;
    out<<"Suma de bani care se afla in banca este de: "<<b.bani_in_banca<<endl;
    if(b.lista_tranzactii.size() > 0)
    {
        list<Tranzactie>::iterator it;
        out<<"-------------------Tranzactii pe banca----------------------";
        for (it = b.lista_tranzactii.begin(); it!=b.lista_tranzactii.end(); it++)
        {
            out<<"---------------------------------------------------------------------------------------\n";
            out<<*it<<endl;
        }
    }

    if(b.lista_clienti.size() > 0)
    {
        list<Client>::iterator i;
        out<<"---------------------------Clienti-----------------------------";
        for(i = b.lista_clienti.begin(); i!=b.lista_clienti.end();i++)
        {
            out<<"---------------------------------------------------------------------------------------\n";
            out<<*i<<endl;
        }
    }

    return out;
}

int main()
{
    /*Card c1,c2;
    cin>>c1;
    cin>>c2;
    c1-c2;
    cout<<c1.get_bani();*/


    /*cin>>c2;
    cout<<c1.get_nr_plati()<<endl;
    cout<<c2.get_nr_plati()<<endl;
    Card c3 = c1 + c2;
    cout<<c3.get_nr_plati();*/


    //Banca b;
    //cin>>b;
    //cout<<b;
    //Client c1,c2;
    //cin>>c1>>c2;
    //cout<<(c1>c2);

    /*Card c;
    cin>>c;
    if(c.media_platilor() == -1)
        cout<<"Platile nu se pot realiza deoarece nu exista suficienti bani pe card\n";
    else
    {
        cout<<c.media_platilor()<<endl;
        float bani = c.get_bani();
        float total = c.total_plata();
        bani -= total;
        c.set_bani(bani);
    }
    cout<<c.get_bani();*/

    /*Client c1,c2;
    cin>>c1>>c2;
    if(c1>c2)
        cout<<"Primul client are mai multe carduri decat al doilea";
    else
        cout<<"Al doilea client are mai multe carduri decat primul";*/


    while(true)
    {
        cout<<"Apasati: 1 pentru adaugarea unei banci\n"
              "         2 pentru exit\n";
        int x;
        cin>>x;
        if(x == 1)
        {
            Banca b;
            cin>>b;
            cout<<b;
        }
        else
            break;
    }
    return 0;
}
