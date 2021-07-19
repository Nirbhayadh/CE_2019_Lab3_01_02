#include <iostream>
#include "ArrayBST.h"
#include "LinkedBST.h"

using namespace std;


int main(){



cout<<"ArrayBST implementation:-"<<endl<<endl;
ArrayBST arrayBST;
arrayBST.remove(20);
arrayBST.add(20,1);
arrayBST.add(10,2);
arrayBST.add(30,7);
arrayBST.add(9,6);
arrayBST.add(40,12);
arrayBST.add(11,88);
arrayBST.add(12,57);
arrayBST.add(12,47);

arrayBST.inorder();
int max,min;
arrayBST.max(max);
arrayBST.min(min);
cout<<"Min Key: "<<min<<" and Max Key: "<<max<<endl;

cout<<boolalpha;   

cout<<99<<": "<<arrayBST.exists(99)<<endl;
cout<<20<<": "<<arrayBST.exists(20)<<endl;
cout<<10<<": "<<arrayBST.exists(10)<<endl;
cout<<35<<": "<<arrayBST.exists(35)<<endl;
cout<<91<<": "<<arrayBST.exists(91)<<endl;
arrayBST.remove(9);//leaf node
arrayBST.remove(12);//node with single child
arrayBST.remove(20);//node with both children
arrayBST.inorder();



cout<<endl<<endl<<endl<<"LinkedBST implementation:-"<<endl<<endl;


    AbstractBST *obj = new LinkedBST();
    cout << obj->isEmpty() << endl; // prints 1 if the tree is empty, 0 otherwise
    obj->add(50,50);
    obj->add(40,40);
    obj->add(60,60);
    obj->add(30,30);
    obj->add(45,45);
    obj->add(25,25);
    obj->add(55,55);
    cout << obj->exists(5) << endl; // prints 1 the given key exists in the tree, 0 otherwise

    int max_key;
    obj->max(max_key);
    cout << "The maximum key in the tree is " << max_key << endl;

    int min_key;
    obj->min(min_key);
    cout << "The minimum key in the tree is " << min_key << endl;

    obj->inorder(); // prints the keys according to inorder traversal of the tree

    cout << obj->remove(40) << endl; // prints 1 if remove is successfull, 0 otherwise
    obj->inorder(); 
}