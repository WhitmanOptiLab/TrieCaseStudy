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
        Node(){
            isEndOfWord = false;
            for(int i = 0;i < 26;i++){
                children[i] = NULL;
            }
        }
        Node *children[26];//Alphabet size could be smaller/bigger than 26 characters
        bool isEndOfWord;
    private:
        
};
class Trie{
    public:
        Trie(){
            root = getNode();
        }
        void insert(string key){
            Node *pCrawl = root;
            for(int i = 0;i < key.length();i++){
                int index = key[i] - 'a';
                if(!pCrawl->children[index])
                    pCrawl->children[index] = new Node();
                pCrawl = pCrawl->children[index];
            }
            pCrawl->isEndOfWord = true;
        }
        bool search(string key){
            Node* pCrawl = root;
            for(int i = 0;i < key.length();i++){
                int index = key[i] - 'a';
                if(!pCrawl->children[index])
                    return false;
                pCrawl = pCrawl->children[index];
            }
            return (pCrawl->isEndOfWord);
        }
    private:
        Node* root;
        Node* getNode(){
            Node* temp = new Node();
            return temp;
        }
};


#endif
