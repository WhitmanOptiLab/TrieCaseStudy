#ifndef TRIE_H
#define TRIE_H
//#define MAX_CHAR 100
//typedef char String[MAX_CHAR+1];
#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include "Node.h"


class Trie{
    public:
        Trie();
        void insert(string key);
        bool search(string key);
        Node* getRoot();
    private:
        Node* root;
        Node* getNode();
};

#endif
