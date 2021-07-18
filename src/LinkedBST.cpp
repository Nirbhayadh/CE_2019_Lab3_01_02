#include "LinkedBST.h"

LinkedBST::LinkedBST()
{
    root = nullptr;
}

bool LinkedBST::isEmpty()
{
    return root == nullptr;
}

bool LinkedBST::add(int key,int value)
{
    if(exists(key))
    {
        cout << "Duplicate Key!!! Please insert a unique key." << endl;
        return false;
    }
    LinkedNode *newNode = new LinkedNode(key, value, nullptr, nullptr);
    if(isEmpty())
    {
        this->root = newNode;
        return true;
    }
    else
    {
        add(this->root,newNode);
        return true;
    }
}

void LinkedBST::add(LinkedNode *subtree_Root, LinkedNode *newNode)
{
    if(newNode->key > subtree_Root->key)
    {
        if(subtree_Root->right != nullptr)
        {
            add(subtree_Root->right,newNode);
        }
        else
        {
            subtree_Root->right = newNode;
        }
    }
    else
    {
        if(newNode->key < subtree_Root->key)
        {
            if(subtree_Root->left != nullptr)
            {
                add(subtree_Root->left, newNode);
            }
            else
            {
                subtree_Root->left = newNode;
            }
        }
    }
}

void LinkedBST::max(int &output)
{
    if(!isEmpty())
    {
        LinkedNode *temp = this->root;
        while(temp->right != nullptr)
        {
            temp = temp->right;
        }
        output = temp->key;
    }
    else
    {
        cout << "The tree is empty" << endl;
    }
}

void LinkedBST::min(int &output)
{
    if(!isEmpty())
    {
        LinkedNode *temp = this->root;
        while(temp->left != nullptr)
        {
            temp = temp->left;
        }
        output = temp->key;
    }
    else
    {
        cout << "The tree is empty" << endl;
    }
}

bool LinkedBST::exists(int targetkey)
{
    if(this->isEmpty())
    {
        return false;
    }
    LinkedNode *temp = this->root;
    while(temp != nullptr)
    {
        if(temp->key == targetkey)
        {
            break;
        }
        if(targetkey > temp->key)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if(temp == nullptr)
    {
        return false;
    }
    return true;
}
