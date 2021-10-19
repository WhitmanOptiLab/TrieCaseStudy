
#include "TrieNodeSubset.h"

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
    pCrawl->isEndOfWord = true;
}

void Trie::subsetSearch(string key){
    for(int i = 0;i < key.length();i++){
        bool visited[key.length()];
        string newStr = "";
        newStr += key[i];
        int index = key[i] - 'a';
        Node* temp = root->children[index];
        visited[i] = true;
        private_subsetSearch(temp,key,visited,newStr);
    }
}
void Trie::private_subsetSearch(Node* root,string s,bool visited[],string newStr){
    Node* tt = root;
    if(tt->isEndOfWord){
        cout << newStr << endl;
    }
    for(int i = 0;i < s.length();i++){
        //go through all of the remaining chars, if they haven't been visited then add
        //them to the string
        if(visited[i] == false){
            int index = s[i] - 'a';
            if(!tt->children[index]){
                continue;
            }
            newStr += s[i];
            visited[i] = true;
            private_subsetSearch(tt->children[index],s,visited,newStr);
            visited[i] = false;
            newStr = newStr.substr(0,newStr.length()-1);
        }
    }
}


bool Trie::search(string key){
    Node* pCrawl = root;
    for(int i = 0;i < key.length();i++){
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEndOfWord);
}
Node* Trie::getNode(){
    Node* temp = new Node();
    return temp;
}
Node::Node(){
    isEndOfWord = false;
    for(int i = 0;i < 26;i++){
        children[i] = NULL;
    }
}
