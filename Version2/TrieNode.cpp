
#include "TrieNode.h"

Trie::Trie(){
    //Set the root node as a new node
    root = getNode();
}

void Trie::insert(string key){
    Node *pCrawl = root;
    for(int i = 0;i < key.length();i++){
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            pCrawl->children[index] = new Node();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->setEndOfWord();
}
bool Trie::search(string key){
    Node* pCrawl = root;
    for(int i = 0;i < key.length();i++){
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEndOfWord());
}
Node* Trie::getRoot(){
    return root;
}
Node* Trie::getNode(){
    Node* temp = new Node();
    return temp;
}
Node::Node(){
    EndOfWord = false;
    for(int i = 0;i < 26;i++){
        children[i] = NULL;
    }
}
bool Node::isEndOfWord(){
    return EndOfWord;
}
void Node::setEndOfWord(){
    EndOfWord = true;
}
