#include <iostream>
#include <vector>
using namespace std;

class Glowna
{
  std::vector<class Obserwator*> patrzacy;
  int Licznik;
  public:
      void dolacz(Obserwator *obs)
      {
         patrzacy.push_back(obs);
      }
     /* void usun(Obserwator *obs)
      {
          patrzacy.pop_back();
      }
      */
        void dzialaj(int wartosc)
        {
         Licznik=wartosc;
         powiadom();
        }
        void powiadom();

        int zwrocWartosc()
        {
            return Licznik;
        }



};
class Obserwator
{

  int przezCo;
  Glowna *gdzie;
  public:
      virtual void zaktualizuj()=0;
      Obserwator(Glowna *g1,int d)
      {

          gdzie=g1;
          przezCo=d;

          gdzie->dolacz(this);


      }
  protected:
    Glowna *przekieruj()
    {
        return gdzie;
    }
    int jakaWartosc()
    {
        return przezCo;
    }

};
class obserwujDzielenie:public Obserwator
{

    public:
    obserwujDzielenie(Glowna *g1,int dziel):Obserwator(g1,dziel){}
    void zaktualizuj()
    {

        int licznik=przekieruj()->zwrocWartosc();
        int mianownik=jakaWartosc();
    /*
        if(mianownik==0){std::cout<<"Nie wolno dzielic przez zero! "<<'\n';exit(-1);}
        else std::cout<<"Wynik dzielenia: "<<licznik<<" przez: "<<mianownik<<" wynosi: "<<licznik/mianownik<<'\n';
        */
        mianownik==0?std::cout<<"Nie wolno dzielic przez zero! "<<'\n':std::cout<<"Wynik dzielenia: "<<licznik<<" przez: "<<mianownik<<" wynosi: "<<licznik/mianownik<<'\n';
        ///Prostsza wersja
        mianownik==0?exit(-1):(void)mianownik;
    }
};
void Glowna::powiadom()
{
    for(unsigned int i=0;i<patrzacy.size();i++)
        patrzacy[i]->zaktualizuj();
}
int main()
{
    Glowna g1;


    obserwujDzielenie o1(&g1,0);


    g1.dzialaj(10);



    return 0;
}
