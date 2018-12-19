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
    * add a scalar to the current
    * @param the scalar
    * @return the current vector
    */
Vector3D&  Vector3D::operator+ (const double &other)
{
    _x += other;
    _y += other;
    _z += other;
    return *this;
}

/**
    * minus a scalar to the current
    * @param the scalar
    * @return the current vector
    */
Vector3D&  Vector3D::operator- (const double &other)
{
    _x -= other;
    _y -= other;
    _z -= other;
    return *this;
}

/**
 * return a new vector that is the result of -
 * @param other
 * @return
 */
Vector3D Vector3D::operator- (const Vector3D &other) const
{
    return Vector3D(_x - other._x, _y - other._y, _z - other._z);
}


/**
* minus the received vector and add new
* @param the scalar
* @return the current vector
*/
Vector3D  Vector3D::operator- () const
{
    return Vector3D(-_x, -_y, -_z);
}

/**
 * multiply a vector by a scalar and return product
 * @param other scalar
 * @return new vector product
 */
Vector3D Vector3D::operator* (const double &other) const
{
    return Vector3D(_x * other, _y * other, _z * other);
}


/**
 * divide a vector by a scalar and return product
 * @param other scalar
 * @return new vector product
 */
Vector3D Vector3D::operator/ (const double &other) const
{
    if(other == 0)
    {
        cerr<< "Error: division by 0!\n";
        return Vector3D();
    }
    return Vector3D(_x / other, _y / other, _z / other);
}

/**
 * multiply a vector by a scalar and return product
 * @param other scalar
 * @return new vector product
 */
Vector3D operator* (const double &left, const Vector3D &right)
{
    return right.operator*(left);
}

void hello() {
    std::cout << "Hello, World!" << std::endl;
}