
#ifndef NODE_H
#define NODE_H

using namespace std;


class Node{
    public:
       
        Node();
        //Node *children[26];
        bool isEndOfWord();
        void setEndOfWord();
        Node* getChild(int index);
        void setChild(int index);
    private:
        Node *children[26];//Alphabet size could be smaller/bigger than 26 characters
        bool EndOfWord;
};


#endif
