
#include "Trie.h"
#include "Node.h"

Trie::Trie(){
    //Set the root node as a new node
    root = getNode();
}

void Trie::insert(string key){
    Node *pCrawl = root;
    for(int i = 0;i < key.length();i++){
        int index = key[i] - 'a';
        if(!pCrawl->getChild(index))
            pCrawl->setChild(index);
        pCrawl = pCrawl->getChild(index);
    }
    pCrawl->setEndOfWord();
}
bool Trie::search(string key){
    Node* pCrawl = root;
    for(int i = 0;i < key.length();i++){
        int index = key[i] - 'a';
        if(!pCrawl->getChild(index))
            return false;
        pCrawl = pCrawl->getChild(index);
    }
    return (pCrawl->isEndOfWord());
}
Node* Trie::getNode(){
    Node* temp = new Node();
    return temp;
}
Node* Trie::getRoot(){
    return root;
}
