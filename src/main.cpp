#include <iostream>
#include "ArrayBST.h"
using namespace std;


int main(){


ArrayBST a;
a.add(20,1);
a.add(10,2);
a.add(30,7);
a.add(35,3);
a.add(25,6);
a.add(15,5);
a.add(5,4);
a.add(15,41);

a.inorder();
int max,min;
a.max(max);
a.min(min);
cout<<"Min Key: "<<min<<" and Max Key: "<<max<<endl;

cout<<boolalpha;   

cout<<99<<": "<<a.exists(99)<<endl;
cout<<20<<": "<<a.exists(20)<<endl;
cout<<10<<": "<<a.exists(10)<<endl;
cout<<35<<": "<<a.exists(35)<<endl;
cout<<91<<": "<<a.exists(91)<<endl;


}