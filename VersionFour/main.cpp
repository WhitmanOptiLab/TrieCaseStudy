#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <unistd.h>
#include <chrono>
//#include "Trie.h"
//#include "TrieNode.h"
//#include "TrieNodeAdv.h"
#include "TrieNodeSubset.h"

using namespace std;


vector<string> Dict;

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
    string testSeq = "testwordao";

    t->subsetSearch(testSeq);
    

    auto t2 = std::chrono::high_resolution_clock::now();
    cout << "MicroSeconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() << endl;
    
}
