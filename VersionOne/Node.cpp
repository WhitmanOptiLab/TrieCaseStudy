
#include <iostream>
#include "Node.h"

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

