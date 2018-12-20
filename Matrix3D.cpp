//
// Created by elkanatovey on 12/19/18.
//

#include <iostream>
#include "Matrix3D.h"

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class Matrix3D.
// --------------------------------------------------------------------------------------

/**
 * default constructor
 */
Matrix3D::Matrix3D()
{
      _row1 = Vector3D();
      _row2 = Vector3D();
      _row3 = Vector3D();
}

/**
 * constructor that creates a diagonalized matrix
 * @param diagonal the value on the diagonal
 */
Matrix3D::Matrix3D(double diagonal)
{
    _row1 = Vector3D(diagonal, 0, 0);
    _row2 = Vector3D(0, diagonal, 0);
    _row3 = Vector3D(0, 0, diagonal);
}

/**
 * create matrix with given coordinates as written below
 * @param a 11
 * @param b 12
 * @param c 13
 * @param d 21
 * @param e 22
 * @param f 23
 * @param g 31
 * @param h 32
 * @param i 33
 */
Matrix3D::Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h,
                   double i)
{
    _row1 = Vector3D(a, b, c);
    _row2 = Vector3D(d, e, f);
    _row3 = Vector3D(g, h, i);
}

/**
 * create matrix with param array
 * @param coordinates coordinate array
 */
Matrix3D::Matrix3D(double coordinates[9]): Matrix3D(coordinates[0], coordinates[1], coordinates[2],
                   coordinates[3], coordinates[4], coordinates[5], coordinates[6], coordinates[7],
                   coordinates[8]) {}
/**
 *
 * @param coordinates
 */
Matrix3D::Matrix3D(double coordinates[3][3])
{
    _row1 = Vector3D(coordinates[0]);
    _row2 = Vector3D(coordinates[1]);
    _row3 = Vector3D(coordinates[2]);
}

/**
 *
 * @param a
 * @param b
 * @param c
 */
Matrix3D::Matrix3D(Vector3D a, Vector3D b, Vector3D c)
{
    _row1 = a;
    _row2 = b;
    _row3 = c;
}

/**
 * copy constructor
 * @param original t copy
 */
Matrix3D::Matrix3D(const Matrix3D &original)
{
    _row1 = original._row1;
    _row2 = original._row2;
    _row3 = original._row3;
}

/**
 * equal opretor
 * @param other what we equalize to
 * @return current matrix
 */
Matrix3D& Matrix3D::operator=(const Matrix3D &other)
{
    if(this == &other)
    {
        return *this;
    }
    _row1 = other._row1;
    _row2 = other._row2;
    _row3 = other._row3;
    return *this;
}

/**
 * adds a matrix to the current
 * @param other to add
 * @return our matrix
 */
Matrix3D& Matrix3D::operator+=(const Matrix3D &other)
{
    _row1 += other._row1;
    _row2 += other._row2;
    _row3 += other._row3;
    return *this;
}

/**
 * adds a matrix to the current
 * @param other to add
 * @return our matrix
 */
Matrix3D& Matrix3D::operator-=(const Matrix3D &other)
{
    _row1 -= other._row1;
    _row2 -= other._row2;
    _row3 -= other._row3;
    return *this;
}

/**
 * calculate matrix multiplication
 * @param other matrix t mult with
 * @return the product
 */
Matrix3D& Matrix3D::operator*=(const Matrix3D &other)
{
    Matrix3D product = *this;
   *this = (product * other);

    return *this;
}

/**
 * return result of minus as new matrix
 * @param other to minus
 * @return result
 */
Matrix3D Matrix3D::operator-(const Matrix3D &other) const
{
    return Matrix3D((_row1 - other._row1), (_row2 - other._row2), (_row3 - other._row3));
}

/**
 * return result of plus as new matrix
 * @param other to plus
 * @return result
 */
Matrix3D Matrix3D::operator+(const Matrix3D &other) const
{
    return Matrix3D((_row1 + other._row1), (_row2 + other._row2), (_row3 + other._row3));
}

/**
 * return result of mult as new matrix
 * @param other to mult
 * @return result
 */
Matrix3D Matrix3D::operator* (const Matrix3D &other) const
{
    Matrix3D product = Matrix3D();
    for (int i = 0; i < 3; i++)
    {
        Vector3D temp = Vector3D(other._row1[i], other._row2[i], other._row3[i]);
        product._row1[i] = _row1 * temp;
        product._row2[i] = _row2 * temp;
        product._row3[i] = _row3 * temp;
    }
    return product;
}

/**
 * adds a matrix to the current
 * @param other to add
 * @return our matrix
 */
Matrix3D& Matrix3D::operator*=(const double &right)
{
    _row1 = _row1 * right;
    _row2 = _row2 * right;
    _row3 = _row3 * right;
    return *this;
}

/**
 * adds a matrix to the current
 * @param other to add
 * @return our matrix
 */
Matrix3D& Matrix3D::operator/=(const double &right)
{
    _row1 = _row1 / right;
    _row2 = _row2 / right;
    _row3 = _row3 / right;
    return *this;
}

/**
 * multiplies a matrix by a vector
 * @param v vector
 * @return product
 */
Vector3D Matrix3D::operator* (const Vector3D &v) const
{
    return Vector3D(_row1 * v, _row2 * v, _row3 * v);
}

/**
 * same as vector3d
 * @param in same as prev
 * @param m matrix
 * @return input
 */
std::istream &operator>>(std::istream &in, Matrix3D &m)
{
    in >> m._row1;
    in >> m._row2;
    in >> m._row3;
    return in;
}

/**
 * same as vector3d
 * @param in same as prev
 * @param m matrix
 * @return input
 */
std::ostream &operator<<(std::ostream &out, const Matrix3D &m)
{
    out << m._row1 << std::endl << m._row2 << std::endl << m._row3 << std::endl;
    return out;
}

/**
* get value of the given matrix coordinate( x, y, z respectively)
* @param i the coordinate to get
* @return  coordinate
*/
Vector3D &Matrix3D::operator[](const short &i)
{
    if (i == 0) { return _row1; }
    if (i == 1) { return _row2; }
    if (i == 2) { return _row3; }
    std::cerr << "Error: invalid coordinate index!";
    exit(-1);
}

/**
* get value of the given matrix coordinate( x, y, z respectively)
* @param i the row val to get
* @return  coordinate
*/

Vector3D Matrix3D::operator[](const short &i) const {
    if (i == 0) { return _row1; }
    if (i == 1) { return _row2; }
    if (i == 2) { return _row3; }
    std::cerr << "Error: invalid coordinate index!";
    exit(-1);
}

/**
* get value of the given matrix coordinate( x, y, z respectively)
* @param i the row vector to get
* @return  coordinate
*/

Vector3D &Matrix3D::row(short &i)
{
    if(i > 2)
    {
        std::cerr << "Error: invalid coordinate index!";
        exit(-1);
    }
    return (*this)[i];
}

/**
* get value of the given matrix coordinate( x, y, z respectively)
* @param i the column vector to get
* @return  coordinate
*/

Vector3D Matrix3D::column(short &i)
{
    if(i > 2)
    {
        std::cerr << "Error: invalid coordinate index!";
        exit(-1);
    }
    return Vector3D(_row1[i], _row2[i], _row3[i]);
}


double Matrix3D::trace()
{
    return _row1[0] + _row2[1] + _row3[2];
}

double Matrix3D::determinant()
{
    return _row1[0] * (_row2[1] * _row3[2] - _row2[2] * _row3[1]) - _row1[1] * (_row2[0] *
    _row3[2] - _row2[2] * _row3[0]) + _row1[2] * (_row2[0] * _row3[1] - _row2[1] * _row3[0]);
}


