//
// Created by cecca on 20/09/2021.
//

#ifndef STRUTTUREDATI_LISTAESERCIZI_H
#define STRUTTUREDATI_LISTAESERCIZI_H

#ifndef ESERCIZI_LISTESERCIZI_H
#define ESERCIZI_LISTESERCIZI_H

#include "linked_list.h"
#include <string>


using namespace std;

void ordinaListString(Linked_list<string> &l){
    for (LNode<string>* i = l.begin(); !l.end(i) ; i = l.next(i)) {
        for (LNode<string>* j = i; !l.end(j) ; j = l.next(j)) {
            if(l.read(i).length()>l.read(j).length()){
                string tmp;
                tmp=l.read(i);
                l.write(l.read(j),i);
                l.write(tmp,j);
            }
        }
    }
}



class eo_strings {
public:
    // inserisce inserisce una stringa nella corrispondente lista
    void inserisci(string s);
    // rimuove la stringa dalla corrispondente lista
    void rimuovi(string s);
    // rimuove le stringhe di lunghezza pari che iniziano con il carattere c
    void rimuovi(char c);
    // restituisce il numero di stringhe di lunghezza pari
    int freq_pari();
    // visualizza le stringhe di lunghezza dispari ordinate per lunghezza
    void visualizza_dispari();
private:
    Linked_list<string> pari;
    Linked_list<std::string> dispari;
};

void eo_strings::inserisci(string s) {
    s.length()%2==0 ? pari.push_back(s) : dispari.push_back(s);
}

void eo_strings::rimuovi(string s) {
    s.length()%2==0 ? pari.erase(pari.find(s)) : dispari.erase(dispari.find(s));
}

void eo_strings::rimuovi(char c) {
    for (LNode<string>* nodo = pari.begin(); !pari.end(nodo) ; nodo = pari.next(nodo)) {
        if(pari.read(nodo).front()==c){
            pari.erase(nodo);
        }
    }
}

int eo_strings::freq_pari() {
    return pari.size();
}

void eo_strings::visualizza_dispari() {
    ordinaListString(dispari);
    cout<<dispari;
}



#endif //STRUTTUREDATI_LISTAESERCIZI_H
