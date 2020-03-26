#include <iostream>
using namespace std;


void duplicate (int& a)
{
  a*=2;
}

string concatenate (const string& a, const string& b)
//string concatenate (  string& a,   string& b)
{
  //  a=a+b;
  return a+b;
}

int main() {
  int a=5;               // initial value: 5
  int b(3);              // initial value: 3
  int c{2};              // initial value: 2
  int result;            // initial value undetermined
  
  a = a + b;
  //  cin >> a >> b;
  
  result = a - c;
  
  cout << result<< endl;
  
  
  
  int n=0, i=0;
//   for ( n=0,  i=5 ; n<i ; ++n, --i) {
//       cout <<  " n = "<<  n << ", i = " <<i<<endl; 
//     }
  //cout << "allert "<< '\a'<< endl;
  cout << "  1. Initialize arrays and ";
  int a0[5];
  int a1[5] = {1, 2, 3};  // other element will be set as the default value
  cout << "  2. Get their Length"  <<endl;
 
  int size = sizeof(a1) / sizeof(*a1);
  cout << "The size of int array a1 is: " << size<< ", composed " <<sizeof(a1) <<  ", and sizeof(*a1)"<< sizeof(*a1)  << endl;

  double a2[5] = {1, 2, 3};  // other element will be set as the default value
  int size_a2=sizeof(a2) / sizeof(*a2); 
  cout << "The size of int array a2 is: " << size<< ", composed " <<sizeof(a2) <<  ", and sizeof(*a2)"<< sizeof(*a2)  << endl;

  char test;
  //  int size_char=sizeof(test) / sizeof(*test); 
  cout << "The size of char : "  << ", composed sizeof  " <<sizeof(test)   << endl;

  char a3[5] = {'1', '2', '3'};  // other element will be set as the default value
  int size_a3=sizeof(a3) / sizeof(*a3); 
  cout << "The size of int array a3 is: " << size<< ", composed " <<sizeof(a3) <<  ", and sizeof(*a3)"<< sizeof(*a3)  << endl;

  cout << "[Version 2] The contents of a1 are:";

  //wrong 
  char a4[5] = "321";  
  //for (int& item: a1) {
  for (char& item: a4) {
    //duplicate(item);
    cout << " " << item;
  }
  cout << endl;

  string mystring,mystring1,mystring2;
  mystring1 = "This is";
  mystring2 = " a string";
  mystring=concatenate(mystring1,mystring2);
  cout << mystring<< endl;
  cout <<"mod1 = "<< mystring1 <<", mod2 = "<< mystring2<< endl;
//   for (auto c: a3){ cout<< " "<<c;
//   }

  // 5. Modify Element
  a1[0] = 4;
  // 6. Sort
  sort(a1, a1 + size);

}
