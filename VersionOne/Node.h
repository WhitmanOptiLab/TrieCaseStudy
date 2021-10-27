
#ifndef NODE_H
#define NODE_H

using namespace std;


class Node{
    public:
       
        Node();
        Node *children[26];//Alphabet size could be smaller/bigger than 26 characters
        bool isEndOfWord();
        void setEndOfWord();
    private:
        bool EndOfWord;
};


#endif
