#pragma once

#define MAX_NUM_NODES 128

#include "AbstractBST.h"

class ArrayNode{
    public:
    int key;
    int value;

    ArrayNode(int k, int val){
        key=k;
        value=val;
    }

};

class ArrayBST: public AbstractBST{

    public:
    ArrayBST();
    ~ArrayBST();

    bool isEmpty();
    bool add(int key, int value);
    void max(int &output);
    void min(int &output);
    bool exists(int targetkey);
    bool remove(int targetkey);

    void inorder();

    private:
    ArrayNode *nodes[MAX_NUM_NODES];
    void inorder(int index);
    void arrangeTree(int temp_root);

};