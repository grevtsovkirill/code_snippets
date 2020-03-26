//create class templates, allowing classes to have members that use template parameters as types
// class templates
#include <iostream>
using namespace std;

template <class T> 
class mypair {
  T a, b;
public:
  mypair (T first, T second)
  {a=first; b=second;}
  T getmax ();
};

template <class T>  // T1 - the template parameter;  
T mypair<T>::getmax () //T2: type returned by the function. T3: specifies that this function's template parameter is also the class template parameter.
{
  T retval;
  retval = a>b? a : b;
  return retval;
}


// template specialization
template <class T1> 
class mycontainer {
  T1 element;
public:
  mycontainer (T1 arg) {element=arg;}
  T1 increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
  char element;
public:
  mycontainer (char arg) {element=arg;}
  char uppercase ()
  {
    if ((element>='a')&&(element<='z'))
      element+='A'-'a';
    return element;
  }
};



int main () {
  mypair <int> myobject (100, 75);
  cout <<"myobject.getmax " << myobject.getmax()<< endl;;

  mycontainer<int> myint (7);
  mycontainer<char> mychar ('j');
  cout << "myint.increase 7 " <<  myint.increase() << endl;
  cout << "mychar.uppercase j " <<  mychar.uppercase() << endl;
  return 0;
}
