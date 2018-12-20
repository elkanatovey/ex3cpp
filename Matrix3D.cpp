//
// Created by elkanatovey on 12/19/18.
//

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

Matrix3D::Matrix3D(double coordinates[3][3])
{
    _row1 = Vector3D(coordinates[0]);
    _row2 = Vector3D(coordinates[1]);
    _row3 = Vector3D(coordinates[2]);
}