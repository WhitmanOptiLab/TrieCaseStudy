
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
Node* Node::getChild(int index){
    return children[index];
}
void Node::setChild(int index){
    children[index] = new Node();
}
