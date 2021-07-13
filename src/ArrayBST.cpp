#include <iostream>
#include "ArrayBST.h"
using namespace std;
ArrayBST::ArrayBST(){

    for (int i=0;i<MAX_NUM_NODES;i++){
        nodes[i]=NULL;
    }

}


ArrayBST::~ArrayBST(){}
    


bool ArrayBST::isEmpty(){
    return nodes[1]==NULL;

}
bool ArrayBST::add(int key, int value){
    ArrayNode *newNode=new ArrayNode(key,value);
    for(int i=1;i<MAX_NUM_NODES;){
        if(nodes[i]==NULL){
            nodes[i]=newNode;
            break;
        }
        else if(nodes[i]->key<key){
            i=i*2+1;
        }
        else{

            i=2*i;
        }
    }
}
void ArrayBST::max(int &output){
    for(int i=1;i<MAX_NUM_NODES;){
if(nodes[i*2+1]!=NULL){
    i=i*2+1;
}
else{
break;
}
output=nodes[i]->key;
    }
}
void ArrayBST::min(int &output){
    for(int i=1;i<MAX_NUM_NODES;){
if(nodes[i*2]!=NULL){
    i=i*2;
}
else{
break;
}
output=nodes[i]->key;
    }
}
bool ArrayBST::exists(int targetkey){
for(int i=1;i<MAX_NUM_NODES;){
    if (nodes[i]==NULL){
        break;
    }
    else if(nodes[i]->key==targetkey){
        return true;
    }
    else if (nodes[i]->key>targetkey){
        i=i*2;
    }
    else{
        i=i*2+1;
    }
    
    }
return false;



}

void ArrayBST::inorder(){
if(!isEmpty()){
    std::cout<<"Inorder Traversal: ";

    inorder(1);
    std::cout<<endl;
}
else{
    std::cout<<"Sorry, nothing to Traverse"<<endl;
}
}

void ArrayBST::inorder(int index){
    if(index<MAX_NUM_NODES && nodes[index]!=NULL){
        inorder(2*index);
        cout<<nodes[index]->key<<" ";
        inorder(2*index +1);
    }
}

