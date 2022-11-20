#include <iostream>
#include <cstring>
#include <list>
#include <iterator>

using namespace std;

class CitireAfisare
{
public:
    virtual istream& cit(istream&)=0;
    virtual ostream& afis(ostream&);//const=0;
};

class Cantina:public CitireAfisare
{
protected:
    string dataExp;
    int nrTotal;

public:
    Cantina()
    {
        dataExp = "necunoscuta";
        nrTotal = 0;
    }
    Cantina(string dataExp, int nrTotal)
    {
        this->dataExp = dataExp;
        this->nrTotal = nrTotal;
    }
    Cantina(const Cantina &c)
    {
        this->dataExp = c.dataExp;
        this->nrTotal = c.nrTotal;
    }
    Cantina& operator=(const Cantina &c)
    {
        if(this != &c)
        {
            this->dataExp = c.dataExp;
            this->nrTotal = c.nrTotal;
        }
        return *this;
    }

    virtual ostream& afis(ostream&);//const;
    virtual istream& cit(istream&);
    friend istream& operator>>(istream& in, Cantina& c);
    friend ostream& operator<<(ostream& out, /*const*/ Cantina &c);

    /*void afis()
    {
        cout<<"Data exp: "<<dataExp<<", Nr. total de produse disponibile: "<<nrTotal<<endl;
    }*/

    ~Cantina(){
        cout<<"\n Destructor Cantina\n";
    }

    /*virtual Cantina& operator +=(double gr) = 0;*/

    virtual void costTotal() = 0;

    virtual void cost_gram() = 0;
};

ostream& Cantina :: afis(ostream& out)//const
{
    out<<"Data expirarii: "<<this->dataExp<<endl;
    out<<"Nr. total de produse cumparate este: "<<this->nrTotal<<endl;
    return out;
}

istream &Cantina :: cit(istream& in)
{
    cout<<"Data expirarii: ";
    in>>this->dataExp;
    cout<<"Nr. total de produse cumparate este: ";
    in>>this->nrTotal;

    return in;
}

istream &operator>>(istream &in, Cantina &c)
{
    return c.cit(in);
}

ostream &operator<<(ostream &out, /*const*/ Cantina &c)
{
    return c.afis(out);
}

class Mancare : public virtual Cantina
{
protected:
    char *numeM;
    double gramaj;
    float pretM;

public:
    Mancare() : Cantina(){
        numeM=new char[strlen("necunoscuta")+1];
        strcpy( this->numeM,"necunoscuta");
        gramaj = 0;
        pretM = 0;
    }

    Mancare(string dataExp, int nrTotal, char*numeM, double gramaj, float pretM) : Cantina(dataExp, nrTotal){
        this->numeM=new char[strlen(numeM)+1];
        strcpy( this->numeM, numeM);
        this->gramaj = gramaj;
        this->pretM = pretM;
    }

    Mancare(const Mancare&m) : Cantina(m){
        this->numeM = new char[strlen(numeM)+1];
        strcpy(this->numeM, m.numeM);
        this->gramaj = m.gramaj;
        this->pretM = m.pretM;
    }

    Mancare &operator = (const Mancare &m){
        if(this != &m){
            Cantina::operator=(m);
            if(this->numeM != NULL)
                delete [] this->numeM;
            this->numeM = new char[strlen(numeM)+1];
            strcpy(this->numeM, m.numeM);
            this->gramaj = m.gramaj;
            this->pretM = m.pretM;
        }
        return *this;
    }

    Mancare &operator +=(double gr);

    ~Mancare()
    {
        if(this->numeM != NULL)
            delete [] this->numeM;
    }

    double getGramaj() const;
    float getPret() const;

    ostream& afis(ostream&);//const;
    istream& cit(istream&);

    /*void afis()
    {
        Cantina::afis();
        cout<<"Numele mancarii este:"<<numeM<<", Gramajul: "<<gramaj<<", Felul: "<<felMancare;
    }*/

    void costTotal(){
        int z;
        cout<<"Clientul este student? Daca da apasati 1, daca nu 0.\n";
        cin>>z;
        if(z == 0)
            cout<<"Costul total pe mancarea cumparata este: "<<this->pretM * (float)nrTotal<<endl;
        else
        {
            cout<<"Costul pe mancarea cumparate este: "<<this->pretM * (float)nrTotal<<endl;
            cout<<"Aplicam reducerea de stundent de 10%, costul total fiind de: "<< (float)nrTotal*(this->pretM - this->pretM * 0.1 )<<endl;
        }
    }

    void cost_gram()
    {
        cout<<"Costul pe 100 de grame este: "<< this->pretM * 100 / this->gramaj << endl;
    }
};

ostream &Mancare :: afis(ostream& out)//const
{
    Cantina :: afis(out);
    out<<"Numele mancarii este: "<<this->numeM<<endl;
    out << "Gramajul este: " << this->gramaj << endl;
    out<<"Pretul macarii este: "<<this->pretM<<endl;

    return out;
}

istream &Mancare :: cit(istream &in)
{
    Cantina :: cit(in);
    cout << "Numele mancarii este: ";
    in.get();
    in.getline(this->numeM,100);
    cout << "Gramajul este: ";
    in>>this->gramaj;
    cout<<"Pretul mancarii este: ";
    in>>this->pretM;

    return in;
}

Mancare &Mancare ::operator+=(double gr){
        this->gramaj = this->gramaj + gr;
        return *this;
}

double Mancare::getGramaj() const{
    return gramaj;
}

float Mancare::getPret() const{
    return pretM;
}

class Bautura : public virtual Cantina
{
protected:
    char *numeB;
    double ml;
    float pretB;

public:
    Bautura() : Cantina(){
        numeB=new char[strlen("necunoscuta")+1];
        strcpy( this->numeB,"necunoscuta");
        ml = 0;
        pretB = 0;
    }

    Bautura(string dataExp, int nrTotal, char* numeB, double ml, float pretB) : Cantina(dataExp, nrTotal){
        this->numeB=new char[strlen(numeB)+1];
        strcpy( this->numeB, numeB);
        this->ml = ml;
        this->pretB = pretB;
    }

    Bautura(const Bautura &b) : Cantina(b){
        this->numeB = new char[strlen(numeB)+1];
        strcpy(this->numeB, b.numeB);
        this->ml = b.ml;
        this->pretB = b.pretB;
    }
    Bautura &operator = (const Bautura &b){
        if(this != &b){
            Cantina::operator=(b);
            if(this->numeB != NULL)
                delete [] this->numeB;
            this->numeB = new char[strlen(numeB)+1];
            strcpy(this->numeB, b.numeB);
            this->ml = b.ml;
            this->pretB = b.pretB;
        }
        return *this;
    }
    ~Bautura()
    {
        if(this->numeB != NULL)
            delete [] this->numeB;
    }

    ostream &afis(ostream&);//const;
    istream &cit(istream&);

    /*void afis()
    {
        Cantina :: afis();
        cout<<"Numele bauturii este:"<<numeB<<", Ml: "<<ml<<", Acidulat? "<<acidulat;
    }*/

    void costTotal(){
        int z;
        cout<<"Clientul este student? Daca da apasati 1, daca nu 0.\n";
        cin>>z;
        if(z == 0)
            cout<<"Costul total pe bauturile cumparate este: "<<this->pretB * (float)nrTotal<<endl;
        else
        {
            cout<<"Costul pe bauturile cumparate este: "<<this->pretB * (float)nrTotal<<endl;
            cout<<"Aplicam reducerea de stundent de 10%, costul total fiind de: "<< (float)nrTotal * (this->pretB - this->pretB * 0.1 )<<endl;
        }
    }

    void cost_gram()
    {
        cout<<"Costul pe 100 de ml este: "<< this->pretB * 100 / this->ml << endl;
    }
};

ostream &Bautura :: afis(ostream& out)//const
{
    Cantina :: afis(out);
    out<<"Numele bauturii este: "<<this->numeB<<endl;
    out << "Ml: " << this->ml << endl;
    out << "Pretul bauturii este: "<<this->pretB<<endl;

    return out;
}

istream &Bautura :: cit(istream& in)
{
    Cantina :: cit(in);
    cout << "Numele bauturii este: ";
    in.get();
    in.getline(this->numeB,100);
    cout << "Ml: ";
    in>>this->ml;
    cout<<"Pretul bauturii este: ";
    in>>this->pretB;

    return in;
}

class Meniu: public virtual Mancare,
             public virtual Bautura
{
protected:
    float pret_meniu;
    string desert;

public:
    Meniu(): Bautura(),Mancare(),Cantina(){
        pret_meniu = 0;
        desert = "necunoscut";
    }

    Meniu(string dataExp, int nrTotal, char* numeM, double gramaj, float pretM, char* numeB, double ml, float pretB, float pret_meniu, string desert):Bautura(dataExp, nrTotal, numeB, ml, pretB),Mancare(dataExp, nrTotal, numeM, gramaj, pretM),Cantina(dataExp, nrTotal)
    {
        this->pret_meniu = pret_meniu;
        this->desert = desert;
    }

    ~Meniu()
    {
        cout<<"\n Destructor Meniu\n";
    }

    Meniu &operator=(const Meniu& m)
    {
        if(this != &m)
        {
            Cantina::operator=(m);
            if(this->numeM != NULL)
                delete [] this->numeM;
            this->numeM = new char[strlen(numeM)+1];
            strcpy(this->numeM, m.numeM);
            this->gramaj = m.gramaj;
            this->pretM = m.pretM;

            if(this->numeB != NULL)
                delete [] this->numeB;
            this->numeB = new char[strlen(numeB)+1];
            strcpy(this->numeB, m.numeB);
            this->ml = m.ml;
            this->pretB = m.pretB;

            this->pret_meniu = m.pret_meniu;
            this->desert = m.desert;
        }
        return *this;
    }

    ostream &afis(ostream&);//const;
    istream &cit(istream&);

    /*void afis()
    {
        Cantina :: afis();
        cout<<"Mnacarea: "<<numeM<<", Gramajul: "<<gramaj<<", Felul: "<<felMancare<<" ";
        cout<<"Bautura: "<<numeB<<", Ml: "<<ml<<", Acidulat? "<<acidulat<<" ";
        cout<<"Pretul meniului: "<<pret_meniu<<", Desert: "<<desert;
    }
     */

    void costTotal()
    {
        int z;
        cout<<"Clientul este student? Daca da apasati 1, daca nu 0.\n";
        cin>>z;
        if(z == 0)
            cout<<"Costul total pe meniurile cumparate este: "<<this->pret_meniu * (float)nrTotal<<endl;
        else
        {
            cout<<"Costul pe meniurile cumparate este: "<<this->pret_meniu * (float)nrTotal<<endl;
            cout<<"Aplicam reducerea de stundent de 10%, costul total fiind de: "<< (float)nrTotal * (this->pret_meniu - this->pret_meniu * 0.1 ) <<endl;
        }
    }
    void cost_gram()
    {
        cout<<"Costul pe 100 de grame este: "<< this->pretM * 100 / this->gramaj << endl;

        cout<<"Costul pe 100 de ml este: "<< this->pretB * 100 / this->ml << endl;
    }
};

ostream &Meniu :: afis(ostream &out)//const
{
    Cantina :: afis(out);
    out << "Numele mancarii este: "<<this->numeM<<endl;
    out << "Gramajul este: " << this->gramaj << endl;
    out << "Pretul mancarii este: "<<this->pretM<<endl;

    out << "Numele bauturii este: "<<this->numeB<<endl;
    out << "Ml: " << this->ml << endl;
    out << "Pretul bauturii este: "<<this->pretB<<endl;

    out<<"Pretul meniului: "<<this->pret_meniu<<endl;
    out<<"Desertul ales este: "<<this->desert<<endl;

    return out;

}

istream &Meniu :: cit(istream &in)
{
    Cantina :: cit(in);
    cout << "Numele mancarii este: ";
    in.get();
    in.getline(this->numeM,100);
    cout << "Gramajul este: ";
    in>>this->gramaj;
    cout<<"Pretul mancarii este: ";
    in>>this->pretM;

    cout << "Numele bauturii este: ";
    in.get();
    in.getline(this->numeB,100);
    cout << "Ml: ";
    in>>this->ml;
    cout<<"Pretul bauturii este: ";
    in>>this->pretB;

    cout<<"Pretul meniului: ";
    in>>this->pret_meniu;
    cout<<"Ce desert doriti la meniu? ";
    in>>this->desert;

    return in;

}

class Client
{
private:
    string nume;

public:
    Client();
    Client(string nume);
    Client(const Client &c);

    Client &operator=(const Client &c);

    ~Client();

    friend istream &operator>>(istream &in, Client &c);
    friend ostream &operator<<(ostream &out, Client &c);

};

Client :: Client()
{
    this->nume = "necunoscut";
}

Client :: Client(string nume)
{
    this->nume = nume;
}

Client :: Client(const Client& c)
{
    this->nume = c.nume;
}

Client &Client :: operator =(const Client &c)
{
    if(this != &c)
    {
        this->nume = c.nume;
    }

    return *this;
}

istream &operator>>(istream &in, Client &c)
{
    cout<<"Numele clientului este: ";
    in>>c.nume;

    return in;
}

ostream &operator<<(ostream &out, Client &c)
{
    Cantina *lista[101];
    int i = 0;
    int k = 1;
    while(k == 1)
    {
        cout<<"\n 1 Pentru a adauga mancare";
        cout<<"\n 2 Pentru a adauga bautura";
        cout<<"\n 3 Pentru a adauga meniu";
        cout<<"\n 4 Pentru a afisa produsele";
        cout<<"\n 5 Stop";
        int cc, z;
        cin>>cc;
        float sum = 0;
        switch (cc) {
            case 1:{
                lista[i] = new Mancare();
                cin>>*lista[i];

                cout<<"Doriti sa vedeti cat costa mancarea pe 100 de grame? Daca da apasati 1 altfel 0.\n";
                cin>>z;
                if(z == 1)
                    lista[i]->cost_gram();
                else{}

                cout<<"Doriti sa vedeti cat costa mancarea? Daca da apasati 1 altfel 0.\n";
                cin>>z;
                if(z == 1)
                    lista[i]->costTotal();
                else{}

                /*cout<<"Doriti sa mariti portia? Daca da apasati 1 altfel 0.\n";
                cin>>z;
                if(z == 1)
                {
                    double gr;
                    cout<<"Cititi gramajul pe care vreti sa il adaugati?\n";
                    cin>>gr;
                    lista[i] += gr;
                }
                else{}*/

                i++;
                break;
            }

            case 2:{
                lista[i] = new Bautura();
                cin>>*lista[i];
                cout<<"Doriti sa vedeti cat costa bautura pe 100ml? Daca da apasati 1 altfel 0.\n";
                cin>>z;
                if(z == 1)
                    lista[i]->cost_gram();
                else{}

                cout<<"Doriti sa vedeti cat costa bautura? Daca da apasati 1 altfel 0.\n";
                cin>>z;
                if(z == 1)
                    lista[i]->costTotal();
                else{}
                i++;
                break;
            }

            case 3:{
                lista[i] = new Meniu();
                cin>>*lista[i];
                cout<<"Doriti sa vedeti cat costa meniurile? Daca da apasati 1 altfel 0.\n";
                cin>>z;
                if(z == 1)
                    lista[i]->costTotal();
                else{}
                i++;
                break;
            }

            case 4:{
                out<<"Numele clientului este: "<<c.nume<<endl;
                for(int j=0; j<i;j++)
                    cout<<*lista[j]<<endl;
                break;
            }

            case 5: {
                k = 0;
                break;
            }
        }
    }
    return out;
}

Client :: ~Client()
{
    cout<<"\nDestructor Client\n";
}

int main() {

    /*Mancare m;
    cin>>m;
    cout<<m;
    m.cost_gram();*/

    /*Bautura b;
    cin>>b;
    cout<<b;
    b.castigTotal();*/

    /*Meniu m;
    cin>>m;
    cout<<m;
    m.castigTotal();
    */

    /*Client c;
    cin>>c;
    cout<<c;
    Mancare m;
    c+m;*/

    /*int z;
    while(true)
    {
        cout<<"Doriti sa introduceti un client? Daca da apasati 1, altfel apasati 0.\n";
        cin>>z;
        if(z == 1)
        {
            Client c;
            cin>>c;
            cout<<c;
        }
        else
            break;
    }*/

    int k = 1;
    while(k==1)
    {
        cout<<"Doriti sa introduceti un client? Daca da apasati 1, altfel 0.";
        int z;
        cin>>z;
        if(z==1)
        {
            Client c;
            cin>>c;
            cout<<c;
        }
        else
        {
            k = 0;
        }
    }
    return 0;
}
