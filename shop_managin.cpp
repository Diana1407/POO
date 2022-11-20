#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Exceptie: public exception
{
    virtual const char* what() const throw()
    {
        return "Originea nu a fost introdusa cu litera mare.\n"
               "Reintroduceti: \n";
    }
} exceptia_mea;

class Plante{
protected:
    string categorie;
    int rating; ///in sensul de cat de apreciata este de vizitatori
    double pret_intretinere;

public:
    Plante()
    {
        categorie = "necunoscuta";
        rating = 0;
        pret_intretinere = 0;
    }

    Plante(string categorie, int rating, double pret_intretinere)
    {
        this->categorie = categorie;
        this->rating = rating;
        this->pret_intretinere = pret_intretinere;
    }

    Plante(const Plante& p)
    {
        this->categorie = p.categorie;
        this->rating = p.rating;
        this->pret_intretinere = p.pret_intretinere;
    }

    Plante& operator=(const Plante& p)
    {
        if(this != &p)
        {
            this->categorie = p.categorie;
            this->rating = p.rating;
            this->pret_intretinere = p.pret_intretinere;
        }

        return *this;
    }

    double get_pretIntretinere()
    {
        return this->pret_intretinere;
    }

    friend istream &operator>>(istream &in, Plante &p);
    friend ostream &operator<<(ostream &out, const Plante &p);

    ~Plante()
    {
        cout<<"\n Destructor Plante\n";
    }

};

void eroare(float a) // doua erori tratate
{
    if(a>10)
        throw 11;
    if((int)a != a)
        throw 12.34;
}

istream &operator>>(istream &in, Plante &p)
{
    cout<<"Categoria plantei este: ";
    in>>p.categorie;
    int k = 1;
    while(k==1)
    {
        cout<<"Ratingul plantei este: ";
        float x;
        in>>x;
        try
        {
            eroare(x);
            p.rating = (int)x;
            k = 0;
        }

        catch(int)
        {
            cout<<"Valoarea introdusa este mai mare de 10, iar ratingul poate fi de la 1 la 10.\n"
                  "Reintroduceti:\n";
        }

        catch(double)
        {
            cout<<"Rating-ul este un numar intreg de la 1 la 10 si a fost introdus un float.\n"
                  "Reintroduceti: \n";
        }
    }
    cout<<"Pretul intretinerii este: ";
    in>>p.pret_intretinere;

    return in;
}

ostream &operator<<(ostream &out, const Plante &p)
{
    out<<"Categoria plantei este: "<<p.categorie<<endl;
    out<<"Ratingul plantei este: "<<p.rating<<endl;
    out<<"Pretul de intretinere este: "<<p.pret_intretinere<<endl;

    return out;
}

void eroare2(string a)
{
    for (int i = 0; i < a.size(); i++)
        if(a[i] >= '0' && a[i] <= '9')
            throw 2.3;
}

class Flori : public Plante{
protected:
    char* tip;
    string culoare;
public:
    Flori():Plante()
    {
        culoare = "necunoscuta";
        tip = new char[strlen("necunoscuta")+1];
        strcpy( this->tip,"necunoscuta");
    }

    Flori(string categorie, int rating, double pret_intretinere, string culoare, char* tip):Plante(categorie, rating, pret_intretinere)
    {
        this->culoare = culoare;
        tip = new char[strlen(tip)+1];
        strcpy( this->tip,tip);
    }

    Flori(const Flori& f):Plante(f)
    {
        this->culoare = f.culoare;
        this->tip = new char[strlen(tip)+1];
        strcpy(this->tip, f.tip);
    }

    Flori& operator=(const Flori& f)
    {
        if(this != &f)
        {
            Plante ::operator=(f);
            this->culoare = f.culoare;
            if(this->tip != NULL)
                delete [] this->tip;
            this->tip = new char[strlen(f.tip)+1];
            strcpy(this->tip, f.tip);
        }

        return *this;
    }

    friend istream &operator>>(istream &in, Flori &f);
    friend ostream &operator<<(ostream &out, const Flori &f);

    ~Flori()
    {
        if(this->tip != NULL)
            delete [] this->tip;
    }
};

istream &operator>>(istream &in, Flori &f)
{

    in >> (Plante& )f;
    int k = 1;
    while(k==1)
    {
        cout<<"Culoarea este: ";
        in>>f.culoare;
        try
        {
            eroare2(f.culoare);
            k = 0;
        }
        catch(double)
        {
            cout<<"Culoarea nu exista, formatul acesteia fiind gresit.\n"
                  "Reintroduceti:\n";
        }
    }
    cout<<"Tipul este: ";
    in.get();
    in.getline(f.tip, 101);

    return in;
}

ostream &operator<<(ostream &out, const Flori &f)
{
    out<<(Plante&) f;
    out<<"Culoarea este: "<<f.culoare<<endl;
    out<<"Tipul este: "<<f.tip<<endl;

    return out;
}

class Trandafiri: public Flori{
protected:
    string nume;
    bool a_fost_plantata;
    int stocT;
    const float pretT = 10;
public:
    Trandafiri():Flori()
    {
        this->nume = "necunoscut";
        this->stocT = 0;
        this->a_fost_plantata = false;
    }

    Trandafiri(string categorie, int rating, double pret_intretinere, string culoare, char* tip, string nume, bool a_fost_plantata, int stocT):Flori(categorie, rating, pret_intretinere, culoare, tip)
    {
        this->nume = nume;
        this->a_fost_plantata = a_fost_plantata;
        this->stocT = stocT;
    }

    Trandafiri(const Trandafiri &t):Flori(t)
    {
        this->nume = t.nume;
        this->a_fost_plantata = t.a_fost_plantata;
        this->stocT = t.stocT;
    }

    Trandafiri &operator =(const Trandafiri &t)
    {
        if(this != &t)
        {
            Flori :: operator=(t);
            this->nume = t.nume;
            this->a_fost_plantata = t.a_fost_plantata;
            this->stocT = t.stocT;
        }
        return *this;
    }

    float getPretT()
    {
        return this->pretT;
    }

    int getStocT()
    {
        return this->stocT;
    }

    friend istream &operator>>(istream &in, Trandafiri &t);
    friend ostream &operator<<(ostream &out, const Trandafiri &t);

    ~Trandafiri()
    {
        cout<<"\nDestructor Trandafiri\n";
    }

    bool verifStocT(int stoc)
    {
        if(this->stocT >= stoc)
            return true;
        else
            return false;
    }

    Trandafiri &operator>(Trandafiri t1)
    {
        if(this->pretT < t1.pretT)
            return *this;
        else
            return t1;
    }

};

void eroare3(string a)
{
    if(a[0] >= 'a' && a[0] <= 'z')
        throw 1;
}

void eroare4(int a)
{
    if(a < 0 || a > 1 )
        throw 1;
}

istream &operator>>(istream &in, Trandafiri &t)
{
    in>>(Flori&)t;
    int k = 1;
    while(k == 1)
    {
        cout<<"Numele trandafirului este: ";
        in>>t.nume;
        try
        {
            double x = t.get_pretIntretinere();
            eroare3(t.nume);
            k = 0;
        }
        catch(int)
        {
            cout<<"Numele trandafirului trebuie introdus cu litera mare, iar el a fost introdus cu litera mica.\n"
                  "Reintroduceti: \n";
        }
    }

    k = 1;

    while(k ==  1)
    {
        cout<<"A fost plantata: ";
        int x;
        in>>x;
        try
        {
            eroare4(x);
            k = 0;
            t.a_fost_plantata = x;
        }
        catch(int)
        {
            cout<<"A fost introdusa o valoare incorecta. Trebuie introdus 1 sau 0 deoarece variabila este de tip bool\n"
                  "Reintroduceti: \n";
        }
    }

    cout<<"Stocul este: ";
    in>>t.stocT;

    return in;
}

ostream &operator<<(ostream &out, const Trandafiri &t)
{
    out<<(Flori&) t;
    cout<<"Numele trandafirului este: "<<t.nume<<endl;
    cout<<"Pretul unui fir de trandafir este: "<<t.pretT<<endl;
    cout<<"A fost plantata: "<<t.a_fost_plantata<<endl;
    cout<<"Stocul trandafirilor este de: "<<t.stocT<<endl;
}

class Lalea: public Flori {
protected:
    string origine;
    const float pretL = 6.5;
    int stocL;

public:
    Lalea():Flori()
    {
        this->origine = "necunoscuta";
        this->stocL = 0;
    }

    Lalea(string categorie, int rating, double pret_intretinere, string culoare, char* tip, string origine, int stocL):Flori(categorie, rating, pret_intretinere, culoare, tip)
    {
        this->origine = origine;
        this->stocL = stocL;
    }

    Lalea(const Lalea &l):Flori(l)
    {
        this->origine = l.origine;
        this->stocL = l.stocL;
    }

    Lalea &operator=(const Lalea &l)
    {
        if(this != &l)
        {
            Flori ::operator=(l);
            this->origine = l.origine;
            this->stocL = l.stocL;
        }

        return *this;
    }

    float getPretL()
    {
        return this->pretL;
    }

    int getStocL()
    {
        return this->stocL;
    }

    friend istream& operator>>(istream &in, Lalea &l);
    friend ostream& operator<<(ostream &out, const Lalea &l);

    bool verifStocL(int stoc)
    {
        if(this->stocL >= stoc)
            return true;
        else
            return false;
    }

};

istream &operator >>(istream &in, Lalea &l)
{
    in>>(Flori&) l;
    int k = 1;
    while(k == 1)
    {
        cout<<"Originea lalelei este: ";
        in>>l.origine;
        try
        {
            if(l.origine[0] < 'A' || l.origine[0] > 'Z')
                throw exceptia_mea;
            k = 0;
        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }
    }

    cout<<"Stocul lalelelor este de: ";
    in>>l.stocL;

    return in;
}

ostream &operator <<(ostream &out, const Lalea &l)
{
    out<<(Flori&) l;
    cout<<"Originea lalelei este: "<<l.origine<<endl;
    cout<<"Pretul pe fir de lalea este de: "<<l.pretL<<endl;
    cout<<"Stocul lalelelor este de: "<<l.stocL<<endl;
}


//template < class T> class Comanda{
//    vector <T> buchet;
//    int nr_flori;
//    string data;
//
//public:
//    Comanda()
//    {
//        buchet = {};
//        nr_flori = 0;
//        data = "necunoscuta";
//    }
//
//    Comanda(vector<T> buchet, int nr_flori, string data)
//    {
//        this->buchet = buchet;
//        this->nr_flori = nr_flori;
//        this->data = data;
//    }
//
//    Comanda(const Comanda &c)
//    {
//        this->buchet = c.buchet;
//        this->nr_flori = c.nr_flori;
//        this->data = c.data;
//    }
//
//    Comanda &operator = (const Comanda &c)
//    {
//        if(this != &c)
//        {
//            this->buchet = c.buchet;
//            this->nr_flori = c.nr_flori;
//            this->data = c.data;
//        }
//    }
//
//    virtual ~Comanda() {
//        cout<<"\nDestructor Comanda\n";
//    }
//
//    const vector<T> &getBuchet() const {
//        return buchet;
//    }
//
//    void setBuchet(const vector<T> &buchet) {
//        Comanda::buchet = buchet;
//    }
//
//    double getNrFlori() const {
//        return nr_flori;
//    }
//
//    void setNrFlori(int nr_flori) {
//        Comanda::nr_flori = nr_flori;
//    }
//
//    const string &getData() const {
//        return data;
//    }
//
//    void setData(const string &data) {
//        Comanda::data = data;
//    }
//
//
//    friend istream &operator>>(istream &in, Comanda<T> &c){
//
////        cout<<"Categoria plantei este: ";
////        in>>c.
////        int k = 1;
////        while(k==1)
////        {
////            cout<<"Ratingul plantei este: ";
////            float x;
////            in>>x;
////            try
////            {
////                eroare(x);
////                p.rating = (int)x;
////                k = 0;
////            }
////
////            catch(int)
////            {
////                cout<<"Valoarea introdusa este mai mare de 10, iar ratingul poate fi de la 1 la 10.\n"
////                      "Reintroduceti:\n";
////            }
////
////            catch(double)
////            {
////                cout<<"Rating-ul este un numar intreg de la 1 la 10 si a fost introdus un float.\n"
////                      "Reintroduceti: \n";
////            }
////
////        }
////        cout<<"Pretul intretinerii este: ";
////        in>>p.pret_intretinere;
////
////        cout<<"Data comenzii este: ";
////        in>>c.data;
////        cout<<"Numarul de flori este: ";
////        in>>c.nr_flori;
////        for(int i = 0; i < c.nr_flori; i++)
////        {
////            cout<<"Buchetul este: ";
////            in>>c.buchet[i];
////        }
////
//        return in;
//    }
//
//    friend ostream&operator<<(ostream &out, const Comanda<T> &c){
//        //out<<(Flori&) c;
//        out<<"Data comenzii este: "<<c.data<<endl;
//        out<<"Numarul de flori este de: "<<c.nr_flori<<endl;
//        for(int i = 0; i < c.nr_flori; i++)
//        {
//            out<<"Buchetul este: \n";
//            out<<c.buchet[i]<<endl;
//        }
//
//        return out;
//    }
//};

template < class T, int lungime> class lista{
private:
    T *vec;
public:
    lista(T arr[])
    {
        this->vec = new T[lungime];
        for(int i=0; i<lungime; i++)
            vec[i] = arr[i];
    }
    void print()
    {
        for (int i = 0; i < lungime; i++)
            cout << vec[i]<<" ";
        cout << endl;
    }

    void afis_trandafiri(int stoc)
    {
        for(int i =0; i < lungime; i++)
        {
            Trandafiri t;
            T a;
            a = dynamic_cast<Trandafiri*>(&t);

            if(a->getStocT()>stoc)
                cout<<vec[i]<<" ";
        }
    }

    void afis_lalele(int stoc)
    {
        for(int i =0; i < lungime; i++)
        {
            Lalea l;
            T *a = dynamic_cast<Lalea*>(&l);
            if(a->getStocL()>stoc)
                cout<<vec[i]<<" ";
        }
    }
};



class Meniu {
private:
    static Meniu* instance;
    Meniu() {
//        cout<<"Apasati urmatoarele taste pt diferite comenzi: \n"
//              "0 - iesire din program\n"
//              "1 - cumpararea unui trandafir\n"
//              "2 - cumpararea unei lalele\n"
//              "3 - puteti verifca care produs este mai rentabil \n"
//              "4 - afisare \n";
    }

    Meniu(const Meniu &m) = delete;
    Meniu &operator=(const Meniu &m) = delete;
public:
    static Meniu* getInstance() {
        if (instance == NULL) {
            instance = new Meniu;
        }
        return instance;
    }

    Trandafiri *t = new Trandafiri[1];
    //t = new Trandafiri[1];
    Lalea *l = new Lalea[1];
    //l = new Lalea[1];

    void afis()
    {
        cout<<"Apasati urmatoarele taste pt diferite comenzi: \n"
              "0 - iesire din program \n"
              "1 - cumpararea unui trandafir \n"
              "2 - cumpararea unei lalele \n"
              "3 - puteti verifca care produs este mai rentabil \n"
              "4 - verificare daca puteti da comanda in functie de stocul disponibil \n"
              "5 - afisare de trasaturi plante \n"
              "6 - afisare \n"
              "7 - set\n";
    }



    void comanda1()
    {
        cin >> t[0];
        lista<Trandafiri, 1> ob(t);
    }

    void comanda2()
    {
        cin >> l[0];
        lista<Lalea, 1> ob(l);
    }

    int comanda3()
    {
        double p = l[0].get_pretIntretinere();
        if(t[0].getPretT() - p > l[0].getPretL() - p) /// 1 e mai rentabil, 0 mai putin rentabil
            return 1;
        else
            return 0;
    }

    void comanda4()
    {
        int x;
        cout<<"Ce doriti sa cumparati: 1 - trandafiri, 2 - lalele\n";
        cin>>x;
        if(x == 1)
        {
            int z;
            cout<<"Cititi cate fire de trandafir doriti sa cumparati: \n";
            cin>>z;
            if(t[0].verifStocT(z) ==  true)
            {
                cout<<"Puteti sa le cumparati.\n"
                      "Doriti sa vedeti cat va costa? Daca da apasati 1, altfel 0.\n";
                int y;
                cin>>y;
                if(y == 1)
                    cout<<z*t[0].getPretT();
                else{}
            }

            else
                cout<<"Nu le puteti cumpara.\n";
        }

        else
        {
            int z;
            cout<<"Cititi cate fire de lalele doriti sa cumparati: \n";
            cin>>z;
            if(l[0].verifStocL(z) ==  true)
            {
                cout<<"Puteti sa le cumparati.\n"
                      "Doriti sa vedeti cat va costa? Daca da apasati 1, altfel 0.\n";
                int y;
                cin>>y;
                if(y == 1)
                    cout<<z*l[0].getPretL();
                else{}

            }
            else
                cout<<"Nu le puteti cumpara.\n";
        }
    }

    void comanda5(list<Plante> li)
    {
        li.push_back(t[0]);
        //li.push_back(l[0]);
        cout<<"Doriti sa vedeti doar trasaturile plantei? Daca da apasati 1, altefl 0\n";
        int x;
        cin>>x;
        if(x == 1)
        {
            list<Plante>::iterator it;
            for (it = li.begin(); it != li.end(); it++)
                cout << '\n' << *it;
            cout<<endl;
        }
        else{}
    }

    void comanda6()
    {
        lista<Lalea, 1> ob(l);
        lista<Trandafiri,1>obb(t);
        ob.print();
        cout<<endl;
        obb.print();
    }

    /**void afis2(list<Trandafiri> tt, list<Lalea> ll)
    {
        tt.push_back(t[0]);
        ll.push_back(l[0]);
        list<Trandafiri>::iterator it;
        for (it = tt.begin(); it != tt.end(); it++)
            cout << '\n' << *it;
        cout<<endl;

        list<Lalea>::iterator i;
        for (i = ll.begin(); i != ll.end(); i++)
            cout << '\n' << *i;
        cout<<endl;
    }*/

    void afis3()
    {
        set<Trandafiri, greater<>> p;
        Trandafiri t1;
        Trandafiri t2;
        Trandafiri t3;
        cin>>t1>>t2>>t3;
        p.insert(t1);
        p.insert(t2);
        p.insert(t3);
        set<Trandafiri> :: iterator it;
        for(it = p.begin(); it != p.end(); it++)
            cout<<*it<<" ";
    }

    void deleteInstanta()
    {
        if(instance != NULL)
            delete instance;
        instance = nullptr;
    }

};
Meniu* Meniu:: instance = nullptr;

int main() {

    /*Flori f;
    cin>>f;
    cout<<f;

    Trandafiri t;
    cin>>t;
    cout<<t;*/

    /*Plante *pp;
    pp = new Plante[2];
    cin>>pp[0];
    cin>>pp[1];
    cout<<pp[0];
    cout<<pp[1];

    lista<Plante, 2> ob(pp);

    ob.print();*/

    /*Plante p;
    cin>>p;
    cout<<p; */

    /*Flori f;
    cin>>f;
    cout<<f;*/

    /*Trandafiri t;
    cin>>t;
    cout<<t;*/

    /*Lalea l;
    cin>>l;
    cout<<l;*/

    /**Lalea *pp;
    pp = new Lalea[1];
    cin>>pp[0];
    cout<<pp[0];


    lista<Lalea, 1> ob(pp);

    ob.print();

    ob.afis_lalele(10);*/


    list<Plante> li;
    list<Trandafiri> tt;
    list<Lalea> ll;


    Meniu *m;
    m = Meniu::getInstance();

    int k = 1;
    while(k)
    {
        m->afis();
        int x;
        cin>>x;

        if(x == 0)
            k = 0;

        if(x == 1)
        {
            m->comanda1();
        }

        if(x == 2)
        {
            m->comanda2();
        }

        if(x == 3)
        {
            int r = m->comanda3();
            if(r == 1)
                cout<<"Trandafirii sunt mai rentabili\n";
            else
                cout<<"Lalelele sunt mai rentabile\n";

        }

        if(x == 4)
        {
            m->comanda4();
        }

        if(x == 5)
        {
            m->comanda5(li);
        }

        if(x == 6)
        {
            m->comanda6();
        }

        if(x == 7)
        {
            cout<<"Doriti sa afisati cati trandafiri diferiti cumparati? Daca da apasati 1, altfel 0 ";
            int z;
            cin>>z;
            if(z == 1)
                m->afis();
            else{}
        }
    }
    m->deleteInstanta();

    return 0;
}
