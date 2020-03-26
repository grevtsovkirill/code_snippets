// overloading class constructors
#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public:
  Rectangle ();
  Rectangle (int,int);
  int area (void) {return (width*height);}
};
//functional form
// default constructor 
Rectangle::Rectangle () {
  width = 5;
  height = 5;
}

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}


//uniform declaration of constructors:
class Circle {
  double radius;
public:
  Circle(double r) { radius = r; }
  double circum() {return 2*radius*3.14159265;}
  double area() {return radius*radius*3.14159265;}
};



// Member initialization in constructors
//
class Cylinder {
  Circle base;
  double height;
public:
  Cylinder(double r, double h) : base (r), height(h) {} // <- member initializer list
  double volume() {return base.area() * height;}
};



int main () {
  Rectangle rect (3,4);
  Rectangle rectb; // default constructor
  //Rectangle rectx(); // default constructor NOT called : warning: empty parentheses interpreted as a function declaration 
  Rectangle rectx2{}; 
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  //cout << "rectx area: " << rectx.area() << endl;//error: base of member reference is a function; perhaps you meant to call it with no arguments?
  cout << "rectx2 area: " << rectx2.area() << endl;
  //uniform:
  Circle foo (10.0);   // functional form
  Circle bar = 20.0;   // assignment init.
  Circle baz {30.0};   // uniform init.
  Circle qux = {40.0}; // POD-like

  cout << "foo's circumference: " << foo.circum() << '\n';


  Cylinder fooCyl (10,20);

  cout << "fooCyl's volume: " << fooCyl.volume() << '\n';
  return 0;
}
