#include "LinkedBST.h"

int main()
{
    LinkedBST obj;
    cout << obj.isEmpty() << endl;
    cout << obj.add(50,50) << endl;
    cout << obj.add(40,40) << endl;
    cout << obj.add(60,60) << endl;
    cout << obj.add(30,30) << endl;
    cout << obj.exists(5) << endl;

    int max_key;
    obj.max(max_key);
    cout << "The maximum key in the tree is " << max_key << endl;


}