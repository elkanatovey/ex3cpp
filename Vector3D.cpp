// Vector3D.cpp
#include "Vector3D.h"

#include <iostream>
#include <cmath>

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



// ------------------ Operator methods ------------------------

/**
 * return a new vector that is the result of +
 * @param other
 * @return
 */
Vector3D Vector3D::operator+(const Vector3D &other) const
{
    return Vector3D(_x + other._x, _y + other._y, _z + other._z);
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
    * add a scalar to the current
    * @param the scalar
    * @return the current vector
    */
Vector3D&  Vector3D::operator+= (const double &other)
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
Vector3D&  Vector3D::operator-= (const double &other)
{
    _x -= other;
    _y -= other;
    _z -= other;
    return *this;
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

/**
* multiply current vector by scalar
* @param right scalar
* @return current vector
*/
Vector3D& Vector3D::operator*=(const double& right)
{
    _x =_x * right;
    _y = _y * right;
    _z = _z * right;
    return *this;
}


/**
* divide current vector by scalar
* @param right scalar
* @return current vector
*/
Vector3D& Vector3D::operator/=(const double& right)
{
    if(right == 0)
    {
        cerr<< "Error: division by 0!\n";
        return *this;
    }
    _x =_x / right;
    _y = _y / right;
    _z = _z / right;
    return *this;
}

/**
*
* @return the distance between the vector and another
*/
double Vector3D::operator|(const Vector3D &other) const
{
    return dist(other);
}

/**
* returns the standard inner product between 2 vectors
* @param other
* @return
*/
double Vector3D::operator* (const Vector3D& other) const
{
    return _x * other._x + _y * other._y + _z * other._z;
}

/**
 * return the angle between 2 vectors in radians
 * @param other other vector
 * @return angle
 */
double Vector3D::operator^ (const Vector3D& other) const
{
    double  radian  = (*this * other) / (norm() * other.norm());
    if (radian > 1 || radian < -1)
    {
        radian = radian / radian;
        cerr<< "Error: bad degrees!\n";
    }
    return acos(radian);
}

/**
 * read a vector from stdin
 * @param in stdin
 * @param v the vector to read to
 * @return stdin
 */
istream& operator>> (istream& in, Vector3D& v)
{
    in >> v._x;
    in >> v._y;
    in >> v._z;
    return in;

}

/**
 * puts a vector into stdout
 * @param out stdout
 * @param v vector
 * @return stdout object
 */
ostream& operator<< (ostream& out, const Vector3D& v)
{
    out << v._x << ' ' << v._y << ' ' << v._z;
    return out;
}



/**
* get the given matrix coordinate( x, y, z respectively)
* @param i the coordinate to get
* @return pointer to coordinate
*/
double& Vector3D::operator[] (const int &i)
{
    if (i == 0) { return _x; }
    if (i == 1) { return _y; }
    if (i == 2) { return _z; }
    std::cerr << "Error: invalid coordinate index!";
    return _z;
}

/**
* get value of the given matrix coordinate( x, y, z respectively)
* @param i the coordinate to get
* @return vale of coordinate
*/
double Vector3D::operator[] (const int &i) const
{
    if (i == 0) { return _x; }
    if (i == 1) { return _y; }
    if (i == 2) { return _z; }
    std::cerr << "Error: invalid coordinate index!";
    return -1;
}

/**
*
* @return the distance between the vector and 0
*/
double Vector3D::norm() const
{
    return sqrt((_x *_x) + (_y * _y) + (_z * _z));
}

/**
*
* @return the distance between the vector and another
*/
double Vector3D::dist(const Vector3D &other) const
{
    return sqrt((pow(_x - other._x, 2)) + (pow(_y - other._y, 2)) + (pow(_z - other._z, 2)));
}