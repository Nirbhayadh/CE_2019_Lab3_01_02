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

    // default constructor
    LinkedNode()
    {
        this->left = nullptr;
        this->right = nullptr;
    }

    // parametrized constructor
    LinkedNode(int key, int data, LinkedNode *left, LinkedNode *right)
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
    void add(LinkedNode *subtree_Root, LinkedNode *newNode); // for recurssive add
    void inorder(LinkedNode *node, char separator = ' '); // for recurssive inorder traversal
    
    // void remove(LinkedNode *subtree_Root, int delete_key); // for recurssive delete

    public:
    LinkedBST(); // constructor
    ~LinkedBST(); // destructor

    virtual bool isEmpty();
    virtual bool add(int key, int value);
    virtual void max(int &output);
    virtual void min(int &output);
    virtual bool exists(int targetkey);
    virtual bool remove(int delete_key);

    virtual void inorder();
};