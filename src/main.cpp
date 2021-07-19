#include "LinkedBST.h"

int main()
{
    LinkedBST obj;
    cout << obj.isEmpty() << endl; // prints 1 if the tree is empty, 0 otherwise
    obj.add(50,50);
    obj.add(40,40);
    obj.add(60,60);
    obj.add(30,30);
    obj.add(45,45);
    obj.add(25,25);
    obj.add(55,55);
    cout << obj.exists(5) << endl; // prints 1 the given key exists in the tree, 0 otherwise

    int max_key;
    obj.max(max_key);
    cout << "The maximum key in the tree is " << max_key << endl;

    int min_key;
    obj.min(min_key);
    cout << "The minimum key in the tree is " << min_key << endl;

    obj.inorder(); // prints the keys according to inorder traversal of the tree

    cout << obj.remove(40) << endl; // prints 1 if remove is successfull, 0 otherwise
    obj.inorder(); 
}