#include "LinkedBST.h"

LinkedBST::LinkedBST()
{
    root = nullptr;
}

LinkedBST::~LinkedBST()
{
    delete root;
}

bool LinkedBST::isEmpty()
{
    return root == nullptr;
}

// Recurssive add node
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

// To find the node with the maximum key in the tree
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

// To find the node with the minimum key in the tree
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

// To search for a particular node with a given key
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

// Recurssive Inorder Traversal
void LinkedBST::inorder() {
    cout << "Inorder traversal of the BST is: " << endl;
    this->inorder(this->root);
    cout << endl;
}

void LinkedBST::inorder(LinkedNode *root_node, char separator) {
    if (root_node != nullptr) {
        inorder(root_node->left);
        cout << root_node->key << separator;
        inorder(root_node->right);
    } 
}

// Iterative Delete Node
bool LinkedBST::remove(int delete_key)
{
    bool deleted = false;
    LinkedNode *previous = nullptr;
    LinkedNode *current = this->root;

    while(current != nullptr && current->key != delete_key)
    {
        previous = current;
        if(delete_key > current->key)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    if(current == nullptr)
    {
        cout << "Key = " << delete_key << " not found in the BST" << endl;
        return deleted;
    }

    if(current->left == nullptr && current->right == nullptr)
    {
        if(previous == nullptr)
        {
            delete current;
            deleted = true;
        }
        if(current == previous->left)
        {
            previous->left = nullptr;
            delete current;
            deleted = true;
        }
        else
        {
            previous->right = nullptr;
            delete current;
            deleted = true;
        }
    }
    else if(current->left == nullptr || current->right == nullptr)
    {
        LinkedNode *newCurrent;
        if(current->left == nullptr)
        {
            newCurrent = current->right;
        }
        else
        {
            newCurrent = current->left;
        }

        // if node to be deleted (current) is the root
        if(previous == nullptr) 
        {
            delete current;
            deleted = true;
        }

        if(current == previous->left)
        {
            previous->left = newCurrent;
        }
        else
        {
            previous->right = newCurrent;
        }
        
        delete current;
        deleted = true;
    }

    // node to be deleted has two children
    else
    {
        LinkedNode *p = nullptr;
        LinkedNode *temp;

        temp = current->right;
        while(temp->left != nullptr)
        {
            p = temp;
            temp = temp->left;
        }

        if(p != nullptr)
        {
            p->left = temp->right;
        }
        else
        {
            current->right = temp->right;
        }
        current->key = temp->key;
        delete temp;
        deleted = true;
    }
    return deleted;
}
