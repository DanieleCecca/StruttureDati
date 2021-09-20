//
// Created by cecca on 20/09/2021.
//

#include <iostream>
#include <string>
#include "tree.h"
#include "eserciziTree.h"


using namespace std;

void inline newline();

int main1(){

    Tree<int> mario;
    mario.insert_root(1);
    TNode<int>* a = mario.get_root();
    mario.insert_child(a,2);
    TNode<int>* rm = mario.insert_child(a,3);
    mario.insert_child(rm, 4);
    mario.insert_child(rm, 5);
    TNode<int>* rm1 = mario.insert_child(rm, 6);
    mario.insert_child(rm, 7);
    mario.insert_child(a,8);

    cout <<  "ESKER " <<  mario << endl;


    cout<<larghezza(mario, mario.get_root());




    return 0;
}

void inline newline(){
    std::cout << std::endl;
}