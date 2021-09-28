#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <unistd.h>
#include <chrono>



using namespace std;
using namespace std::chrono;

const int ALPHABET_SIZE = 26;

vector<string> Dict;
//Start of GeeksForGeeks Implementation Link: https://www.geeksforgeeks.org/trie-insert-and-search/
struct Node{
    struct Node *children[ALPHABET_SIZE];
    bool isEndOfWord;
};
struct Node *getNode(void){
    struct Node *parent = new Node;
    parent->isEndOfWord = false;
    for(int i = 0;i < ALPHABET_SIZE;i++){
        parent->children[i] = NULL;
    }
    return parent;
}
void insert(struct Node *root,string key){
    struct Node *pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
bool search(struct Node *root, string key)
{
    struct Node *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEndOfWord);
}
//End of GeeksForGeeks Implementation


//randomly creating string of a specific length
string genSequence(int length){
    string ret;
    char chars[] = "abcdefghijklmnopqrstuvwxyz";
    srand( (unsigned) time(NULL) * getpid());
    ret.reserve(length);
    for (int i = 0; i < length; ++i){ 
        ret += chars[rand() % (sizeof(chars)-1)];
    }
    cout << ret << endl;
    return ret;
}
//This seems quite slow, why not just make a hash table if we are doing it this way?
void SearchForWords(struct Node* root,string s,int i,bool visited[],string newStr){
    visited[i] = true;
    newStr += s[i];
    if((newStr.length() >= 3) && search(root,newStr) == true){
        cout << newStr << endl;
    }
    for(int i = 0;i < s.length();i++){
        if(visited[i] == false){
            SearchForWords(root,s,i,visited,newStr);
        }
    }
    newStr = newStr.substr(0,newStr.length()-1);
    //newStr = "" + newStr[newStr.length()-1];
    visited[i] = false;
}

//Further Research Needed: https://en.wikipedia.org/wiki/Aho–Corasick_algorithm
//This function works, recursively goes through the trie
void subsetSearch(struct Node* root,string s,bool visited[],string newStr){
    struct Node* tt = root;
    //If its the end of a word, then add it to the collection of valid words
    if(tt->isEndOfWord){
        cout << newStr << endl;
    }
    for(int i = 0;i < s.length();i++){
        //go through all of the remaining chars, if they haven't been visited than add
        //them to the string
        if(visited[i] == false){
            int index = s[i] - 'a';
            if(!tt->children[index]){
                continue;
            }
            newStr += s[i];
            visited[i] = true;
            subsetSearch(tt->children[index],s,visited,newStr);
            visited[i] = false;
            newStr = newStr.substr(0,newStr.length()-1);
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
    
    //creating tree structure
    int Dict_size = Dict.size();
    struct Node *root = getNode();
    for(int i = 0;i < Dict_size;i++){
        insert(root,Dict[i]);
    }


    //creating a random string of x length
    int StringLength = 13;
    string testWord = genSequence(StringLength);
    //Searching for all substrings Function
    for(int i = 0;i < testWord.length();i++){
        bool visited[testWord.length()];
        string newStr = "";
        newStr += testWord[i];
        int index = testWord[i] - 'a';
        Node* temp = root->children[index];
        visited[i] = true;
        subsetSearch(temp,testWord,visited,newStr);
    }
}
