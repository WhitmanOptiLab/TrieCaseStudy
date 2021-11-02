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
        Node();
        bool isEndOfWord();
        void setEndOfWord();
        Node* getChild(int index);
        void setChild(int index);
    private:
        Node *children[26];//Alphabet size could be smaller/bigger than 26 characters
        bool EndOfWord;
};
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
