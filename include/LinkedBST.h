#include "AbstractBST.h"
using namespace std;

class LinkedNode
{
    public:
    int key;
    int data;
    LinkedNode *left;
    LinkedNode *right;

    LinkedNode(int key, int data, LinkedNode *left, LinkedNode *right)
    {
        this->key = key;
        this->data = data;
        this->left = left;
        this->right = right;
    }

};