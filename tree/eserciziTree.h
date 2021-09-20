//
// Created by cecca on 20/09/2021.
//

#ifndef STRUTTUREDATI_ESERCIZITREE_H
#define STRUTTUREDATI_ESERCIZITREE_H

#include <iostream>
#include "tree.h"
#include "../queue/queue.h"
#include "../lista/linked_list.h"

//ESERCIZIO 1 larghezza trova la largehzza max
int larghezza(Tree<int> t, TNode<int> *nodo);

//ESERCIZIO 2 numero di foglie
int n_leaf(const Tree<int> &a, TNode<int> *nodo);

//ESERCIZIO 3 nodi in t di livello k
int livelloK(const Tree<int> a, TNode<int> *nodo, int k, int livelloCorrente);


int larghezza(Tree<int> t, TNode<int> *nodo) {
    int count = 0;
    int max = 0;
    if (nodo != nullptr) {
        Queue<TNode<int> *> q;
        q.push(nodo);
        max = 1;
        while (!q.empty()) {
            count = 0;
            nodo = q.read();

            for (LNode<TNode<int> *> *el = nodo->childs.begin(); !nodo->childs.end(el); el = nodo->childs.next(el)) {
                q.push(nodo->childs.read(el));
                count++;
            }
            if (max < count) {
                max = count;
            }
            q.pop();

        }
    }
    return max;
}

int n_leaf(const Tree<int> &a, TNode<int> *nodo) {
    int count = 0;
    if (a.leaf(nodo)) {
        return 1;
    } else {
        for (LNode<TNode<int> *> *el = nodo->childs.begin(); !nodo->childs.end(el); el = nodo->childs.next(
                el)) {//LNode<TNode<int>*>* el lista dei nodi figli
            count += n_leaf(a, nodo->childs.read(el));
        }
        return count;
    }

}

int livelloK(const Tree<int> a, TNode<int> *nodo, int k, int livelloCorrente){
    int count = 0;
    if (livelloCorrente==k) {
        return 1;
    } else {
        for (LNode<TNode<int> *> *el = nodo->childs.begin(); !nodo->childs.end(el); el = nodo->childs.next(
                el)) {//LNode<TNode<int>*>* el lista dei nodi figli
            count += livelloK(a, nodo->childs.read(el),k,livelloCorrente+1);
        }
        return count;
    }

}

#endif //STRUTTUREDATI_ESERCIZITREE_H
