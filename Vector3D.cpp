#include "Vector3D.h"

#include <iostream>

using namespace std;

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Point.
// --------------------------------------------------------------------------------------

Vector3D::Vector3D() : Vector3D(0.0, 0.0, 0.0) {}

Vector3D::Vector3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}


Vector3D::Vector3D(double params[3]): Vector3D(params[0], params[1], params[2]) {}


void hello() {
    std::cout << "Hello, World!" << std::endl;
}