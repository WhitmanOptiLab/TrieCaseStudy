#include <iostream>
#include <fstream> 
#include <vector>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <unordered_set>




using namespace std;

//unordered Set because we only need to know if a string is present or not, not the amount
unordered_set <string> Dict;

//randomly creating string of a specific length
string genSequence(int length){
    string ret;
    char chars[] = "abcdefghijklmnopqrstuvwxyz";
    srand( (unsigned) time(NULL) * getpid());
    ret.reserve(length);
    for (int i = 0; i < length; ++i){ 
        ret += chars[rand() % (sizeof(chars)-1)];
    }
    cout << "Random Sequence of Letters: " << ret << endl;
    return ret;
}
void subSetSearch(bool visited[],int i,string str,string seq){
    visited[i] = true;
    str += seq[i];
    //If its in the hashtable print it out
    if(!(Dict.find(str) == Dict.end()) && str.length() > 3){
        cout << str << endl;
    }
    for(int id = 0;id < seq.length();id++){
        if(visited[id] == false){
            subSetSearch(visited,id,str,seq);
        }
    }
    visited[i] = false;
    str = str.substr(0,str.length()-1);
}

int main(){
    //reading file and pushing content to HashTable Dict

    ifstream file;
    file.open("WordList.txt");
    string output;
    if(file.is_open()){
        while(!file.eof()){
            file >> output;
            Dict.insert(output);
        }
    }

    //creating a random string of x length
    int StringLength = 12;
    string testSeq = genSequence(StringLength);

    auto t1 = std::chrono::high_resolution_clock::now();

    for(int i = 0;i < testSeq.length();i++){
        bool visited[testSeq.length()];
        string newStr = "";
        //newStr += testWord[i];
        //int index = testWord[i] - 'a';
        //visited[i] = true;
        subSetSearch(visited,i,newStr,testSeq);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    cout << "MilliSeconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << endl;



}
