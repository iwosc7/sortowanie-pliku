#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Wynik {
int numerGry;
int wynik;
};

bool porownanie(Wynik &a, Wynik &b){
    bool c;
    if(a.wynik>b.wynik){
        c=true;
    }
    else{
        c=false;
    }
     return c;//return a.wynik>b.wynik
}


int main() {
    ifstream file("snakes_count_10000.csv");  // Zmieniæ "nazwa_pliku.txt" na odpowiedni¹ nazwê pliku

    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku." << endl;
        return 1;
    }
    Wynik wynik;
    vector<Wynik> Wyniki;
    vector<string> linie;
    string linia;
    string linia2;
    int i=1;
    getline(file, linia); //"usuniecie" pierwszej linii
   while(getline(file, linia)){
    linia.erase(remove_if(linia.begin(), linia.end(), ::isspace),
        linia.end());
        stringstream ss(linia);
        while(getline(ss, linia2,',')){
            if (i%2==1){
                wynik.numerGry=stoi(linia2);
            }
            else{
                wynik.wynik=stoi(linia2);
            }
            i++;
        }
        Wyniki.push_back(wynik);

        //linie.push_back(linia);
   }


//stoi()
//cout<< linia<<endl;

/*getline(linia, linia2, ',');
wynik.numerGry = stoi(linia2);
getline(linia, linia2, ' ');
getline(linia, linia2);
wynik.wynik = stoi(linia2);*/

//Wyniki.push_back(wynik);

sort(Wyniki.begin(), Wyniki.end(),porownanie); //sortuje wektory, paramert
ofstream outfile;
outfile.open("Posortowane_wyniki.txt");
outfile.clear();
outfile<<"Numer gry, Wynik"<<endl;
for(int i=0; i<Wyniki.size(); i++){
    outfile<< Wyniki.at(i).numerGry <<", " << Wyniki.at(i).wynik<<endl;
}

//sort(v.begin(), v.end());
   /* string line;
    while (getline(file, line)) {
        cout << line << endl;
    }*/
    file.close();

    return 0;
}

