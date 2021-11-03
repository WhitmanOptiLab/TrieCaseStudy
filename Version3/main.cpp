#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <unistd.h>
#include <chrono>
//#include "Trie.h"
//#include "TrieNode.h"
#include "TrieNodeAdv.h"
//#include "TrieNodeSubset.h"

using namespace std;

int COUNT = 0;
vector<string> Dict;

void subSetSearch(Trie* t, bool visited[],int i,string str,string seq){
    
    visited[i] = true;
    str += seq[i];
    if(t->search(str)){
        cout << str << endl;
    }
    for(int id = 0;id < seq.length();id++){
        if(visited[id] == false){
            subSetSearch(t,visited,id,str,seq);
        }
    }
    visited[i] = false;
    str = str.substr(0,str.length()-1);
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
    
    string testSeq = "aynvkpuueq";

    for(int i = 0;i < testSeq.length();i++){
        bool visited[testSeq.length()];
        for(int x = 0;x < (sizeof(visited)/sizeof(bool));x++){
            visited[x] = false;
        }
        string newStr = "";
        subSetSearch(t,visited,i,newStr,testSeq);
    }

      //run this for the tire node subset class

    

    auto t2 = std::chrono::high_resolution_clock::now();
    cout << "MicroSeconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() << endl;
    
    cout << "bobobob" << endl;

   /*
    auto t1 = std::chrono::high_resolution_clock::now();
    t->subsetSearch("prohceuybwhn");
    auto t2 = std::chrono::high_resolution_clock::now();
    cout << "MicroSeconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() << endl;
    */
    
    
}
