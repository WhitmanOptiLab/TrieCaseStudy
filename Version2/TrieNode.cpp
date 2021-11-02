
#include "TrieNode.h"

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
Node* Node::getChild(int index){
    return children[index];
}
void Node::setChild(int index){
    children[index] = new Node();
}
