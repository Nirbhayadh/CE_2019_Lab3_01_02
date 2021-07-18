#include "AbstractBST.h"
#include <iostream>
using namespace std;

class LinkedNode
{
    public:
    int key;
    int data;
    LinkedNode *left;
    LinkedNode *right;

    LinkedNode(int key, int value, LinkedNode *left, LinkedNode *right)
    {
        this->key = key;
        this->data = data;
        this->left = left;
        this->right = right;
    }

};

class LinkedBST:public AbstractBST
{
    private:
    LinkedNode *root;
    void insert(LinkedNode *subtree_Root, LinkedNode *newNode);

    public:
    LinkedBST(); // constructor
    // ~LinkedBST(); // destructor

    virtual bool isEmpty();
    virtual bool add(int key, int value);
    virtual void max(int &output);
    // virtual void min(int &output);
    virtual bool exists(int targetkey);

    // virtual void inorder() = 0;

};