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
        Node *children[26];//Alphabet size could be smaller/bigger than 26 characters
        bool isEndOfWord();
        void setEndOfWord();
    private:
        bool EndOfWord;
};
class Trie{
    public:
        Trie();
        void insert(string key);
        bool search(string key);
        void subsetSearch(string key);
        //we needa get root function here for subset search
    private:
        Node* root;
        Node* getNode();
        void private_subsetSearch(Node* root,string s,bool visited[],string newStr);
};


#endif
