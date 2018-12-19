#include "Vector3D.h"

#include <iostream>

using namespace std;

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Vector3D.
// --------------------------------------------------------------------------------------

/**
 * default constructor
 */
Vector3D::Vector3D() : Vector3D(0.0, 0.0, 0.0) {}

/**
 * receives 3 doubles and initializes Vector3D
 * @param x
 * @param y
 * @param z
 */
Vector3D::Vector3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

/**
 * creates Vector3D with array of doubles
 * @param params double array
 */
Vector3D::Vector3D(double params[3]): Vector3D(params[0], params[1], params[2]) {}



/**
 *add second vector to first
 * @param other
 * @return
 */
Vector3D& Vector3D::operator+=(const Vector3D &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}


/**
 *minus second vector to first
 * @param other
 * @return
 */
Vector3D& Vector3D::operator-=(const Vector3D &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

/**
 * return a new vector that is the result of +
 * @param other
 * @return
 */
Vector3D Vector3D::operator+(const Vector3D &other)
{
    return Vector3D(_x + other._x, _y + other._y, _z + other._z);
}

/**
 * return a new vector that is the result of -
 * @param other
 * @return
 */
Vector3D Vector3D::operator- (const Vector3D &other)
{
    return Vector3D(_x - other._x, _y - other._y, _z - other._z);
}




void hello() {
    std::cout << "Hello, World!" << std::endl;
}