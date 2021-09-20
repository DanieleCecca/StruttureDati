//
// Created by cecca on 20/09/2021.
//

#ifndef STRUTTUREDATI_ESERCIZIBINTREE_H
#define STRUTTUREDATI_ESERCIZIBINTREE_H
#include "bintree.h"
#include "../lista/linked_list.h"
#include "cmath"


using namespace std;

//ESERCIZIO 1 albero inverso scambi i figli destri con i sinistri
void inverso(Binary_Tree<int> t, BTNode<int>* nodo);
void swap(BTNode<int>* a, BTNode<int>* b);

//ESERCIZIO 2  si vuole aggiungere ad ogni foglia un figlio contenente
//la somma dei valori che appaiono nel cammino dalla radice a tale foglia
void aggiungiSomma(Binary_Tree<int> t, BTNode<int>* nodo, int somma=0);

//ESERCIZIO 3 Hanno due figli.
bool HannoDueFigli(Binary_Tree<int> a, BTNode<int>* b);

//ESERCIZIO 4 la somma delle foglie è uguale alla somma dei nodi a livello k
bool livelloK(Binary_Tree<int> a, int k);
int sommaFoglie(Binary_Tree<int> a, BTNode<int> *nodo); //deve essere root
int sommaLivelloK(Binary_Tree<int> a, int k, int livelloCorr, BTNode<int> *nodo);

//ESERCIZIO 5 restituisce un bool se nell'albero BST a è presente un valore che è presente alemno una volta nell'albero b
bool verifica(Binary_Tree<int> a, BTNode<int> *root, Binary_Tree<int> b);
bool ricerca(Binary_Tree<int> a, BTNode<int> *nodo, int value);

//ESERCIZIO 6 l'albero è un albero binario di ricerca
bool diRicerca(Binary_Tree<int> a, BTNode<int> *nodo);

//ESERCIZIO 7 salvare in una lista la media dei valori dei nodi per ogni livello k;
float sommaLivelloK(Binary_Tree<float> a, BTNode<float> *nodo, int k, int livelloCorrente);
void insMedia(Binary_Tree<float> a, Linked_list<float> &l);

//ESERCIZIO 8 stabilire se l'albero è bilanciato in altezza
int altezza(Binary_Tree<int> a, BTNode<int> *nodo);
bool is_height_balanced(const Binary_Tree<int> a);


//ESRCIZIO 9 l'albero è un alberozero-one
bool is_zero_one(const Binary_Tree<int> a);
bool verificaFigli(const Binary_Tree<int> a, BTNode<int> *nodo);

//ESERCIZIO 10 numero dei nodi 0 dell'albero
int zero_nodes(const Binary_Tree<int> a);

void swap(BTNode<int>* a, BTNode<int>* b){
    BTNode<int>* tmp;
    a=tmp;
    a=b;
    b=tmp;

}
void inverso(Binary_Tree<int> t, BTNode<int>* nodo){
    if(nodo!= nullptr){
        swap(t.sx(nodo), t.dx(nodo));
        inverso(t,t.sx(nodo));
        inverso(t,t.dx(nodo));
    }
}

void aggiungiSomma(Binary_Tree<int> t, BTNode<int>* nodo, int somma){
    if(t.leaf(nodo)){
        somma+=t.read(nodo);
        t.insertsx(nodo, somma);
    } else{
        somma+=t.read(nodo);
        if(!t.isEmpty_sx(nodo)){
            aggiungiSomma(t,t.sx(nodo),somma);
        }
        if(!t.isEmpty_dx(nodo)){
            aggiungiSomma(t,t.dx(nodo),somma);
        }
    }
}

bool HannoDueFigli(Binary_Tree<int> t, BTNode<int>* nodo){
    bool sx= false;
    bool dx=false;
    if(t.leaf(nodo)){
        return true;
    }
    else{
        if(!t.sx(nodo)){
           sx = HannoDueFigli(t, t.sx(nodo));
        }

        if(!t.dx(nodo)){
            dx = HannoDueFigli(t, t.dx(nodo));
        }

    }
    return sx && dx;
}


int sommaFoglie(Binary_Tree<int> a, BTNode<int> *nodo){
    int somma=0;
    if(a.leaf(nodo)){
        somma=a.read(nodo);
    }
    else{
        if(!a.sx(nodo)){
            somma+=sommaFoglie(a, a.sx(nodo));
        }
        if(!a.dx(nodo)){
            somma+=sommaFoglie(a, a.dx(nodo));
        }
    }
    return somma;
}

int sommaLivelloK(Binary_Tree<int> a, int k, int livelloCorr, BTNode<int> *nodo){
    int somma=0;
    if(k==livelloCorr){
        somma=a.read(nodo);
    }
    else{
        if(!a.sx(nodo)){
            somma+=sommaLivelloK(a,k,livelloCorr+1, a.sx(nodo));
        }
        if(!a.dx(nodo)){
            somma+=sommaLivelloK(a,k,livelloCorr+1, a.dx(nodo));
        }
    }
    return somma;
}

bool livelloK(Binary_Tree<int> a, int k) {
    int somma1 = sommaFoglie(a, a.get_root());
    int somma2 = sommaLivelloK(a, k, 1, a.get_root());

    return somma1 == somma2 ? true : false;
}

bool ricerca(Binary_Tree<int> a, BTNode<int> *nodo, int value) {
    if (value == a.read(nodo)) {
        return true;
    } else if (value < a.read(nodo) && !a.isEmpty_sx(nodo)) {
        return ricerca(a, a.sx(nodo), value);
    } else if (value > a.read(nodo) && !a.isEmpty_dx(nodo)) {
        return ricerca(a, a.dx(nodo), value);
    } else if (a.leaf(nodo)) {
        return false;
    }

}

bool verifica(Binary_Tree<int> a, BTNode<int> *root, Binary_Tree<int> b) {
    if (ricerca(b, b.get_root(), a.read(root))) {
        return true;
    } else {
        bool sinistro = false;
        bool destro = false;
        if (!a.isEmpty_sx(root)) {
            sinistro = verifica(a, a.sx(root), b);
        }
        if (!a.isEmpty_dx(root)) {
            destro = verifica(a, a.dx(root), b);
        }
        return sinistro || destro;
    }
}

bool diRicerca(Binary_Tree<int> a, BTNode<int> *nodo){
    bool verificaDx = false;
    bool verificaSx = false;
    if (a.leaf(nodo)) {
        return true;
    } else if (!a.isEmpty_sx(nodo)) {
        if (a.read(a.sx(nodo)) < a.read(nodo)) {
            verificaSx = diRicerca(a, a.sx(nodo));
        }
    }
    if (!a.isEmpty_dx(nodo)) {
        if (a.read(a.dx(nodo)) > a.read(nodo)) {
            verificaDx = diRicerca(a, a.dx(nodo));
        }
    }
    return verificaDx && verificaSx;
}

float sommaLivelloK(Binary_Tree<float> a, BTNode<float> *nodo, int k, int livelloCorrente) {
    if (livelloCorrente == k) {
        return a.read(nodo);
    } else {
        float sum = 0;
        if (!a.isEmpty_sx(nodo)) {
            sum += sommaLivelloK(a, a.sx(nodo), k, livelloCorrente + 1);
        }
        if (!a.isEmpty_dx(nodo)) {
            sum += sommaLivelloK(a, a.dx(nodo), k, livelloCorrente + 1);
        }
        return sum;
    }
}

void insMedia(Binary_Tree<float> a, Linked_list<float> &l) {
    int i = 0;
    float media = 0;
    do {
        media = sommaLivelloK(a, a.get_root(), i, 0) / pow(2, i);
        if (media != 0) {
            l.push_back(media);
            i++;
        }

    } while (media != 0);
}

int altezza(Binary_Tree<int> a, BTNode<int> *nodo) {
    if (nodo == nullptr) {
        return -1;
    } else {
        return (std::max(altezza(a, a.sx(nodo)), altezza(a, a.dx(nodo)))) + 1;
    }
}

bool is_height_balanced(const Binary_Tree<int> a) {
    return abs(altezza(a, a.sx(a.get_root())) - altezza(a, a.dx(a.get_root()))) <= 1 || a.isEmpty();
}

bool verificaFigli(const Binary_Tree<int> a, BTNode<int> *nodo) {
    if (a.leaf(nodo)) {
        return true;
    } else {
        bool verificaSx = false;
        bool verificaDx = false;
        if (!a.isEmpty_sx(nodo)) {
            if (a.read(a.sx(nodo)) == 0 && a.read(nodo) == 1 ||
            (a.read(a.sx(nodo)) == 1 && a.read(nodo) == 0)) {
                verificaSx = verificaFigli(a, a.sx(nodo));
            }
        }
        if (!a.isEmpty_dx(nodo)) {
            if (a.read(a.dx(nodo)) == 0 && a.read(nodo) == 1 ||
            (a.read(a.dx(nodo)) == 1 && a.read(nodo) == 0)) {
                verificaDx = verificaFigli(a, a.dx(nodo));
            }
        }
        if(verificaDx && verificaSx){std::cout<<"\n"<<"true";}
        else{std::cout<<"\n"<<"false";}
        return verificaDx && verificaSx;
    }
}

int zero_nodes(const Binary_Tree<int> a, BTNode<int> *nodo) {
    int conta = 0;
    if (nodo == nullptr) {
        return 0;
    } else {
        if (a.read(nodo) == 0) {
            conta++;
        }
        conta += zero_nodes(a, a.sx(nodo));
        conta += zero_nodes(a, a.sx(nodo));
        return conta;
    }
}

bool is_zero_one(const Binary_Tree<int> a){
    if(a.read(a.get_root())!=0){
        return false;
    } else{
        return verificaFigli(a,a.get_root());
    }
}



#endif //STRUTTUREDATI_ESERCIZIBINTREE_H
