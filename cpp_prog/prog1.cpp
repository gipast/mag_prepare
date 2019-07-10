#include <iostream>
using namespace std;

class Point{
  int x, y;
public:
  Point(){};

  Point(int _x, int _y);
  int getx() {return x;};
  int gety() {return y;};

  void set(Point&A){
    x = A.x;
    y = A.y;
  };
};

Point::Point(int _x, int _y): x(_x), y(_y) {};

class Triangle{
  Point A, B, C;
protected:
  Triangle(){};
  Triangle(Point _A, Point _B, Point _C):A(_A), B(_B), C(_C) {};

  void set_coords(Point _A, Point _B, Point _C){
    A.set(_A);
    B.set(_A);
    C.set(_A);
  }
  virtual void draw() = 0;
};

class SpecTriangle:
virtual private Triangle
{
  double angle;
public:
  SpecTriangle(double _size, double _angle);
  virtual void draw();
};

SpecTriangle::SpecTriangle(double _size, double _angle) {
  int x = 0;
  int y = 0;
  //define coords here
  Point A = Point(x, y);
  Point B = Point(x, y);
  Point C = Point(x, y);
  Triangle::set_coords(A, B, C);
};

void SpecTriangle::draw(){
  std::cout << "coords out" << '\n';
}

int main(){
  // std::cout << "/* message */message1" << '\n';
  std::cout << "/* message */" << '\n';
}
