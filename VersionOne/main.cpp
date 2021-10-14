#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include "Trie.h"

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
    cout << t->search("alms") << endl;
}
