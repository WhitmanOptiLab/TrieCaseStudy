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

using namespace std; 

class Node{
    public:
        bool EndOfWord();
        Node();
        Node *children[26];//Alphabet size could be smaller/bigger than 26 characters
        bool isEndOfWord;
    private:
        
};
class Trie{
    public:
        Trie();
        void insert(string key);
        bool search(string key);
    private:
        Node* root;
        Node* getNode();
};


#endif
