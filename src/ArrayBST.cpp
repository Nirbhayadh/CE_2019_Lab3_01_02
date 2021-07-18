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
    if(exists(key)){
        cout<<key<<" already exists in the tree!"<<endl;
    }
    else{
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
        cout<<"Added:-  Key: "<<key<<" with Value: "<<value<<endl;

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

bool ArrayBST::remove(int targetkey){
if(exists(targetkey)){
int temp=1;
while(nodes[temp]!=NULL && nodes[temp]->key!=targetkey){

    if(nodes[temp]->key>targetkey){
        temp=temp*2;
    }
    else{
        temp=temp*2+1;
    }
}
// CASE1: LEAF NODE
if(nodes[temp*2]==NULL && nodes[temp*2+1]==NULL){
    nodes[temp]=NULL;

}

// CASE2: ELEMENT WITH SINGLE CHILD
else if(nodes[temp*2]==NULL || nodes[temp*2+1]==NULL){

    if(nodes[temp*2]!=NULL){
        arrangeTree(temp*2);
    }
    else{
        arrangeTree(temp*2+1);
    }

}
// CASE3: ELEMENT WITH BOTH CHILDREN
else{
int temp_right=temp*2+1;
while(nodes[temp_right*2]!=NULL){
    temp_right=temp_right*2;
}
    nodes[temp]=nodes[temp_right];

if(nodes[temp_right*2+1]==NULL){
    nodes[temp_right]=NULL;
}
else{
    arrangeTree(temp_right*2+1);
}




}
cout<<"Removed: "<<targetkey<<endl;
return true;
}
else {
    cout<<targetkey<<" doesn't exist to be removed"<<endl;
    return false;
}
}
// Function that arranges the tree, incase it gets broken after removing its element
    void ArrayBST::arrangeTree(int temp_root){
        int x=(temp_root/2);
        nodes[x]=nodes[temp_root];
        nodes[temp_root]=NULL;
        if(nodes[temp_root*2]!=NULL){
            arrangeTree(temp_root*2);
        }
        if(nodes[temp_root*2+1]!=NULL){
            arrangeTree(temp_root*2+1);
        }
    }
