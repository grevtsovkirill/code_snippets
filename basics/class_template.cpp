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

int main () {
  mypair <int> myobject (100, 75);
  cout << myobject.getmax()<< endl;;
  return 0;
}
