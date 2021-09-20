//
// Created by cecca on 20/09/2021.
//
#include <iostream>
#include <string>
#include "bintree.h"
#include "eserciziBinTree.h"


using namespace std;

int main2(){

    Binary_Tree<int> tree;
    tree.insert_root(2);
    BTNode<int>* node = tree.get_root();
    BTNode<int>* b = tree.insertsx(node,3);
    BTNode<int>* a = tree.insertdx(node,2);
    BTNode<int>* c = tree.insertsx(a, 2);
    BTNode<int>* d = tree.insertdx(a, 3);
    BTNode<int>* e = tree.insertsx(b, 3);


    cout<<tree;



    aggiungiSomma(tree,tree.get_root());
    cout<<tree;

}