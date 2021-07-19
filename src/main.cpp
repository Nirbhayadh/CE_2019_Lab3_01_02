#include <iostream>
#include "ArrayBST.h"
using namespace std;


int main(){



cout<<"ArrayBST:-"<<endl;
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




}