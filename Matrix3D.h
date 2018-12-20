//
// Created by elkanatovey on 12/19/18.
//

#ifndef EX3CPP_MATRIX3D_H
#define EX3CPP_MATRIX3D_H


#include "Vector3D.h"
/**
 * class for 3d matrices
 */
class Matrix3D
{

public:
    /**
     * default constructor
     */
    Matrix3D();

    /**
     * initialize by diagonal
     * @param diagonal values for diagonal
     */
    explicit Matrix3D(double diagonal);

    /**
     * constructor by value
     * @param a val
     * @param b val
     * @param c val
     * @param d val
     * @param e val
     * @param f val
     * @param g val
     * @param h val
     * @param i val
     */
    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h,
             double i);

    /**
     * costructor with array
     * @param params array of values
     */
    explicit Matrix3D(double params[9]);

    /**
     * constructor by double list
     * @param params double array
     */
    explicit Matrix3D(double params[3][3]);

    /**
     * constructor by vector
     * @param a vector1
     * @param b vector2
     * @param c vector3
     */
    Matrix3D(Vector3D a, Vector3D b, Vector3D c);

    /**
     * copy constructor
     * @param toCopy matrix to copy
     */
    Matrix3D(const Matrix3D& toCopy);

    /**
     * equal operator
     * @param other matrix
     * @return copied by value
     */
    Matrix3D& operator=(const Matrix3D& other);

    /**
     * minus matrix together
     * @param other matrix
     * @return product
     */
    Matrix3D& operator-= (const Matrix3D& other);


    /**
     * add matrix together
     * @param other matrix
     * @return product
     */
    Matrix3D& operator+= (const Matrix3D& other);

    /**
     * multiply matrix by matrix
     * @param other matrix
     * @return product
     */
    Matrix3D& operator*= (const Matrix3D& other) ;

    /**
     * minus matrix together
     * @param other matrix
     * @return product
     */
    Matrix3D operator-(const Matrix3D& other) const;

    /**
     * add matrix together
     * @param other matrix
     * @return product
     */
    Matrix3D operator+(const Matrix3D& other) const;

    /**
     * multiply matrix by matrix
     * @param other matrix
     * @return product
     */
    Matrix3D operator*(const Matrix3D& other) const;

    /**
     * multiply matrix by scalar
     * @param other scalar
     * @return product
     */
    Matrix3D& operator*= (const double& right);

    /**
     * divide matrix by scalar
     * @param other scalar
     * @return product
     */
    Matrix3D& operator/= (const double& other);

    /**
     * multiply vmatrix by vector from left
     * @param v the vector
     * @return multiplied vector
     */
    Vector3D operator* (const Vector3D& v) const;


    /**
     * read a vector from stdin
     * @param in stdin
     * @param m the matrix to read to
     * @return stdin
     */
    friend std::istream& operator>> (std::istream& in, Matrix3D& m);

    /**
     * puts a vector in stdout
     * @param out stdout
     * @param m the matrix to read from
     * @return stdout
     */
    friend std::ostream&operator<< (std::ostream& out, const Matrix3D& m);

    /**
     * get the given matrix coordinate( x, y, z respectively)
     * @param i the coordinate to get
     * @return pointer to coordinate
     */
    Vector3D& operator[] (const short& i);

    /**
     * get value of the given matrix coordinate( x, y, z respectively)
     * @param i the coordinate to get
     * @return vale of coordinate
     */
    Vector3D operator[] (const short& i) const;

    /**
     * return row as vector3d
     * @param i the row to return
     * @return the row
     */
    Vector3D& row(short& i);

    /**
     * return column as vector3d
     * @param i the column to return
     * @return the column
     */
    Vector3D column(short& i);

    /**
     * trace calculator
     * @return trace
     */
    double trace();

    /**
     * det calculator
     * @return the determinant
     */
    double determinant();

    /**
     * destructor default
     */
    ~Matrix3D() = default;

private:
    Vector3D _row1;
    Vector3D _row2;
    Vector3D _row3;
};


#endif //EX3CPP_MATRIX3D_H
