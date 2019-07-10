#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public:
  Rectangle (int,int);
  int area () {return (width*height);}
};

//Constructor - allowing the class to initialize member variables or allocate storage.
//executed once, when a new object of that class is created.
//never return values, they simply initialize the object.
Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4);
  Rectangle rectb (5,6);
  //Rectangle rectx(1); // candidate constructor not viable: requires 2 arguments, but 1 was provided
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}
