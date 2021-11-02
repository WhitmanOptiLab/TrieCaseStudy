
#include "TrieNodeSubset.h"

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

void Trie::subsetSearch(string key){
    for(int i = 0;i < key.length();i++){
        bool visited[key.length()];
        string newStr = "";
        newStr += key[i];
        int index = key[i] - 'a';
        Node* temp = root->getChild(index);
        visited[i] = true;
        private_subsetSearch(temp,key,visited,newStr);
    }
}
void Trie::private_subsetSearch(Node* root,string s,bool visited[],string newStr){
    Node* tt = root;
    if(tt->isEndOfWord()){
        cout << newStr << endl;
    }
    for(int i = 0;i < s.length();i++){
        //go through all of the remaining chars, if they haven't been visited then add
        //them to the string
        if(visited[i] == false){
            int index = s[i] - 'a';
            if(!tt->getChild(index)){
                continue;
            }
            newStr += s[i];
            visited[i] = true;
            //Node* xx = tt->getChild(index);
            private_subsetSearch(tt->getChild(index),s,visited,newStr);
            visited[i] = false;
            newStr = newStr.substr(0,newStr.length()-1);
        }
    }
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
