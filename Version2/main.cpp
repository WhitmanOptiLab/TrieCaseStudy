#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <unistd.h>
#include <chrono>
//#include "Trie.h"
#include "TrieNode.h"
//#include "TrieNodeAdv.h"
//#include "TrieNodeSubset.h"

using namespace std;

vector<string> Dict;

void private_subsetSearch(Node* root,string s,int i,bool visited[],string newStr){
    //cout << newStr << endl;
    if(root->isEndOfWord){
        cout << newStr << endl;
    }
    for(int i = 0;i < s.length();i++){
        if(visited[i] == false){
            int index = s[i] - 'a';
            if(!root->children[index]){
                continue;
            }
            visited[i] = true;
            newStr += s[i];
            private_subsetSearch(root->children[index],s,i,visited,newStr);
            newStr = newStr.substr(0,newStr.length()-1);
            //newStr = "" + newStr[newStr.length()-1];
            visited[i] = false;
        }
    }
}

int main(){
    //reading file and pushing content to vector Dict
    ifstream file;
    file.open("WordList.txt");
    string output;
    if(file.is_open()){
        while(!file.eof()){
            file >> output;
            Dict.push_back(output);
        }
    }
    Trie* t = new Trie();
    int Dict_size = Dict.size();
    //Node* root = t->getNode();
    for(int i = 0;i < Dict_size;i++){
        t->insert(Dict[i]);
    }


    auto t1 = std::chrono::high_resolution_clock::now();
    string testSeq = "testwordevenbiggervxz";

    /*

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

    */
   for(int i = 0;i < testSeq.length();i++){
       bool visited[testSeq.length()];
       string newStr = "";
       //newStr += testSeq[i];
       //int index = testSeq[i] - 'a';
       Node* temp = (t->getRoot());
       //visited[i] = true;
       private_subsetSearch(temp,testSeq,i,visited,newStr);
   }
    
    

    auto t2 = std::chrono::high_resolution_clock::now();
    cout << "MilliSeconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << endl;

    /*
    auto t1 = std::chrono::high_resolution_clock::now();
    t->subsetSearch("todaywasanexcellentday");
    auto t2 = std::chrono::high_resolution_clock::now();
    cout << "MilliSeconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << endl;
    */
}
