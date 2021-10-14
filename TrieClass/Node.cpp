
#include <iostream>
#include "Node.h"

Node::Node(){
    isEndOfWord = false;
    for(int i = 0;i < 26;i++){
        children[i] = NULL;
    }
}
