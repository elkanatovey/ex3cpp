//
// Created by elkanatovey on 12/19/18.
//

#ifndef EX3CPP_MATRIX3D_H
#define EX3CPP_MATRIX3D_H


#include "Vector3D.h"

class Matrix3D {

public:
    Matrix3D();

    explicit Matrix3D(double diagonal);

    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h,
            double i);

    explicit Matrix3D(double params[9]);

    explicit Matrix3D(double params[3][3]);

    Matrix3D(Vector3D a, Vector3D b, Vector3D c);

    Matrix3D(const Matrix3D& toCopy);

    Matrix3D& operator=(const Matrix3D& other);

    Matrix3D& operator-= (const Matrix3D& other);

    Matrix3D& operator+= (const Matrix3D& other);

    Matrix3D& operator*= (const Matrix3D& other) ;

    Matrix3D operator-(const Matrix3D& other) const;

    Matrix3D operator+(const Matrix3D& other) const;

    Matrix3D operator*(const Matrix3D& other) const;

    Matrix3D& operator*= (const double& right);

    Matrix3D& operator/= (const double& other);

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
    Vector3D& operator[] (const int& i);

    /**
     * get value of the given matrix coordinate( x, y, z respectively)
     * @param i the coordinate to get
     * @return vale of coordinate
     */
    Vector3D operator[] (const int& i) const;

    Vector3D& row(short& i);

    Vector3D& column(short& i);

    double trace();

    double determinant();

private:
    Vector3D _row1;
    Vector3D _row2;
    Vector3D _row3;

};


#endif //EX3CPP_MATRIX3D_H
