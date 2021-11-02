#ifndef TRIE_H
#define TRIE_H
//#define MAX_CHAR 100
//typedef char String[MAX_CHAR+1];
#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <unistd.h>


using namespace std; 

class Node{
    public:
        Node(){
            EndOfWord = false;
            for(int i = 0;i < 26;i++){
                children[i] = NULL;
            }
        }
        void setEndOfWord(){
            EndOfWord = true;
        }
        bool isEndOfWord(){
            return EndOfWord;
        }
        Node* getChild(int index){
            return children[index];
        }
        void setChild(int index){
            children[index] = new Node();
        }
    private:
        Node *children[26];//Alphabet size could be smaller/bigger than 26 characters
        bool EndOfWord;
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
                if(!pCrawl->getChild(index))
                    pCrawl->setChild(index);
                pCrawl = pCrawl->getChild(index);
            }
            pCrawl->setEndOfWord();
        }
        bool search(string key){
            Node* pCrawl = root;
            for(int i = 0;i < key.length();i++){
                int index = key[i] - 'a';
                if(!pCrawl->getChild(index))
                    return false;
                pCrawl = pCrawl->getChild(index);
            }
            return (pCrawl->isEndOfWord());
        }
        Node* getRoot(){
            return root;
        }
    private:
        Node* root;
        Node* getNode(){
            Node* temp = new Node();
            return temp;
        }
};


#endif
